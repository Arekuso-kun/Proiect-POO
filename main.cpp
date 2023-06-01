#include <iostream>
#include <algorithm>
#include <iomanip>
#include "Classes/Inchiriere/Inchiriere.h"
#include "Classes/Inchiriere/Inchiriere.cpp"
#include "Classes/Autovehicul/Autovehicul.h"
#include "Classes/Autovehicul/Autovehicul.cpp"
#include "Classes/Inchiriere/AdministrareInchirieri.h"
#include "Classes/Inchiriere/AdministrareInchirieri.cpp"
#include "Classes/Autovehicul/AdministrareAutovehicule.h"
#include "Classes/Autovehicul/AdministrareAutovehicule.cpp"
#include "Classes/Persoana/Angajat/Angajat.h"
#include "Classes/Persoana/Angajat/Angajat.cpp"
#include "Classes/Persoana/Client/Client.h"
#include "Classes/Persoana/Client/Client.cpp"
#include "single_include/tabulate/tabulate.hpp"

using namespace std;
using namespace tabulate;

void update_nrInchirieri_nextIdInchiriere(int& nrInchirieri, int& nextIdInchiriere, AdministrareInchirieri adminInchirieri)
{
    vector<Inchiriere> inchirieri = adminInchirieri.GetInchirieri(nrInchirieri);
    if (nrInchirieri != 0)
        nextIdInchiriere = inchirieri[nrInchirieri - 1].getIdInchiriere() + 1;
}

void update_nrAutovehicule_nextIdAutovehicul(int& nrAutovehicule, int& nextIdAutovehicul, AdministrareAutovehicule adminAutovehicule)
{
    vector<Autovehicul> autovehicule = adminAutovehicule.GetAutovehicule(nrAutovehicule);
    if (nrAutovehicule != 0)
        nextIdAutovehicul = autovehicule[nrAutovehicule - 1].getID() + 1;
}

string toLowercase(string str)
{
    string result = str;
    for (char& c : result)
    {
        c = tolower(c);
    }
    return result;
}

vector<Autovehicul> searchAutovehicul(const vector<Autovehicul>& autovehicule, const string& marca,
                                      const string& model, const string& categorie, int costMin, int costMax,
                                      bool disponibil) {
    vector<Autovehicul> results;

    string marcaCautata = toLowercase(marca);
    string modelCautat = toLowercase(model);


    for (const Autovehicul& autovehicul : autovehicule) {

        string marcaGasita = toLowercase(autovehicul.getMarca());
        string modelGasait = toLowercase(autovehicul.getModel());

        if ((!marca.empty() && (marcaGasita.find(marcaCautata)) == -1)||
            (!model.empty() && (modelGasait.find(modelCautat)) == -1)||
            (!categorie.empty() && autovehicul.getCategorie() != categorie) ||
            (costMin > 0 && autovehicul.getCostZi() < costMin) ||
            (costMax > 0 && autovehicul.getCostZi() > costMax) ||
            (disponibil && !autovehicul.isDisponibil())) {
            continue;
        }

        results.push_back(autovehicul);
    }

    return results;
}

vector<Inchiriere> searchInchiriere(const vector<Inchiriere>& inchirieri, const string& nume, const string& prenume,
                                    const string& email, int idInchiriere, int idMasina) {
    vector<Inchiriere> results;

    string numeCautat = toLowercase(nume);
    string prenumeCautat = toLowercase(prenume);
    string emailCautat = toLowercase(email);

    for (const Inchiriere& inchiriere : inchirieri) {
        string numeGasit = toLowercase(inchiriere.getNume());
        string prenumeGasit = toLowercase(inchiriere.getPrenume());
        string emailGasit = toLowercase(inchiriere.getEmail());

        if ((!nume.empty() && (numeGasit.find(numeCautat)) == -1) ||
            (!prenume.empty() && (prenumeGasit.find(prenumeCautat)) == -1) ||
            (!email.empty() && (emailGasit.find(emailCautat)) == -1) ||
            (idInchiriere != -1 && inchiriere.getIdInchiriere() != idInchiriere) ||
            (idMasina != -1 && inchiriere.getIdAutovehicul() != idMasina)) {
            continue;
        }

        results.push_back(inchiriere);
    }

    return results;
}

void afisareTabelAutovehicule(const vector<Autovehicul>& autovehicule, int nrAutovehicule)
{
    if (autovehicule.empty()) {
        cout << "Nu exista autovehicule de afisat." << endl;
        return;
    }

    Table tAutovehicule;

    tAutovehicule.add_row({"ID", "Marca", "Model", "Categorie", "Cost/zi", "Disponibil", "Capacitate motor", "Nr. pasageri", "Nr. portiere", "Volum portbagaj", "Transmisie", "Aer conditionat", "Tip Combustibil"});
    for (int i = 0; i < nrAutovehicule; i++) {
        tAutovehicule.add_row({autovehicule[i].getID() == -1 ? "N/A" : to_string(autovehicule[i].getID()),
                               autovehicule[i].getMarca(),
                               autovehicule[i].getModel(),
                               autovehicule[i].getCategorie(),
                               (autovehicule[i].getCostZi() == -1 ? "N/A" : to_string(autovehicule[i].getCostZi())) + " RON",
                               autovehicule[i].isDisponibil() ? "Da" : "Nu",
                               (autovehicule[i].getCapacitateMotor() == -1 ? "N/A" : to_string(autovehicule[i].getCapacitateMotor())) + " cm^3",
                               (autovehicule[i].getNrPasageri() == -1 ? "N/A" : to_string(autovehicule[i].getNrPasageri())),
                               (autovehicule[i].getNrPortiere() == -1 ? "N/A" : to_string(autovehicule[i].getNrPortiere())),
                               (autovehicule[i].getVolumPortbagaj() == -1 ? "N/A" : to_string(autovehicule[i].getVolumPortbagaj())) + " L",
                               autovehicule[i].getTransmisie(),
                               autovehicule[i].hasAerConditionat() ? "Da" : "Nu",
                               autovehicule[i].getTipCombustibil()});
    }

    tAutovehicule[0].format()
            .font_style({FontStyle::bold})
            .padding(1)
            .font_align(FontAlign::center);

    cout << tAutovehicule;

}

void afisareTabelInchirieri(const vector<Inchiriere>& inchirieri, int nrInchirieri)
{
    if (inchirieri.empty()) {
        cout << "Nu exista inchirieri de afisat." << endl;
        return;
    }

    Table tInchirieri;

    tInchirieri.add_row({"ID", "ID Autovehicul", "Nume", "Prenume", "CNP", "Email", "Adresa", "Telefon", "Data inchiriere", "Data returnare"});
    for (int i = 0; i < nrInchirieri; i++) {
        tInchirieri.add_row({inchirieri[i].getIdInchiriere() == -1 ? "N/A" : to_string(inchirieri[i].getIdInchiriere()),
                             inchirieri[i].getIdAutovehicul() == -1 ? "N/A" : to_string(inchirieri[i].getIdAutovehicul()),
                             inchirieri[i].getNume(),
                             inchirieri[i].getPrenume(),
                             inchirieri[i].getCNP(),
                             inchirieri[i].getEmail(),
                             inchirieri[i].getAdresa(),
                             inchirieri[i].getTelefon(),
                             inchirieri[i].getDataInchiriere(),
                             inchirieri[i].getDataReturnare()});
    }

    tInchirieri[0].format()
            .font_style({FontStyle::bold})
            .padding(1)
            .font_align(FontAlign::center);

    cout << tInchirieri;

}

int meniuCautareAutovehicul(vector<Autovehicul> autovehicule)
{
    string marca, model, categorie;
    int costMin = 0, costMax = 0, optiune, ID=-1;

    bool exitMenu = false;

    while (!exitMenu) {
        bool exitMenuSelectare = false;
        system("clear");
        cout << " FILTRE DISPONIBILE:\n";
        cout << "1. Filtru dupa marca" << (marca.empty() ? "" : " (Filtru: " + marca + ")") << '\n';
        cout << "2. Filtru dupa model" << (model.empty() ? "" : " (Filtru: " + model + ")") << '\n';
        cout << "3. Filtru dupa categorie" << (categorie.empty() ? "" : " (Filtru: " + categorie + ")") << '\n';
        cout << "4. Filtru dupa cost minim pe zi" << (costMin > 0 ? " (Filtru: " + to_string(costMin) + ")" : "") << '\n';
        cout << "5. Filtru dupa cost maxim pe zi" << (costMax > 0 ? " (Filtru: " + to_string(costMax) + ")" : "") << '\n';
        cout << '\n';
        cout << "9. Afiseaza rezultate\n";
        cout << "0. Inapoi la meniul principal\n";

        cout << "\nID autovehicul selectat: " + (ID == -1 ? "N/A" : to_string(ID)) + "\n";

        cout << "\nIntroduceti o optiune... ";
        cin >> optiune;
        cout << endl;

        switch (optiune) {
            case 1:
                cout << "Introduceti marca: ";
                cin.ignore();
                getline(cin, marca);
                break;
            case 2:
                cout << "Introduceti modelul: ";
                cin.ignore();
                getline(cin, model);
                break;
            case 3:
                cout << "Introduceti categoria: ";
                cin.ignore();
                getline(cin, categorie);
                break;
            case 4:
                cout << "Introduceti costul minim pe zi: ";
                cin >> costMin;
                break;
            case 5:
                cout << "Introduceti costul maxim pe zi: ";
                cin >> costMax;
                break;
            case 9:
            {
                vector<Autovehicul> searchResults = searchAutovehicul(autovehicule, marca, model, categorie, costMin, costMax, true);

                if (searchResults.empty()) {
                    cout << "Niciun autovehicul gasit conform filtrelor specificate." << endl;
                } else {
                    cout << "Autovehiculele gasite conform filtrelor specificate:" << endl;
                    afisareTabelAutovehicule(searchResults, searchResults.size());
                }
                while (!exitMenuSelectare) {
                    cout << endl;
                    cout << "1. Selecteaza autovehicul\n";
                    cout << "0. Inapoi la cautare\n";
                    cout << "\nIntroduceti o optiune... ";
                    cin >> optiune;
                    cout << endl;

                    switch (optiune) {
                        case 1:
                            cout << "Introdu ID autovehicul: ";
                            cin >> ID;
                            exitMenuSelectare = true;
                            break;
                        case 0:
                            exitMenuSelectare = true;
                            break;
                        default:
                            cout << "Optiune invalida. Va rugam sa selectati o optiune valida." << endl;

                            cin.ignore();
                            cin.get();
                            break;
                    }
                }

                break;
            }
            case 0:
                exitMenu = true;
                break;
            default:
                cout << "Optiune invalida. Va rugam sa selectati o optiune valida." << endl;

                cin.ignore();
                cin.get();
                break;
        }
    }
    return ID;
}

int meniuCautareInchiriere(vector<Inchiriere> inchirieri)
{
    string nume, prenume, email;
    int idInchiriere = -1, idMasina = -1, optiune;

    bool exitMenu = false;

    while (!exitMenu) {
        bool exitMenuSelectare = false;
        system("clear");
        cout << " FILTRE DISPONIBILE:\n";
        cout << "1. Filtru dupa nume" << (nume.empty() ? "" : " (Filtru: " + nume + ")") << '\n';
        cout << "2. Filtru dupa prenume" << (prenume.empty() ? "" : " (Filtru: " + prenume + ")") << '\n';
        cout << "3. Filtru dupa email" << (email.empty() ? "" : " (Filtru: " + email + ")") << '\n';
        cout << "4. Filtru dupa ID inchiriere" << (idInchiriere != -1 ? " (Filtru: " + to_string(idInchiriere) + ")" : "") << '\n';
        cout << "5. Filtru dupa ID masina" << (idMasina != -1 ? " (Filtru: " + to_string(idMasina) + ")" : "") << '\n';
        cout << '\n';
        cout << "9. Afiseaza rezultate\n";
        cout << "0. Inapoi la meniul principal\n";

        cout << "\nID inchiriere selectat: " + (idInchiriere == -1 ? "N/A" : to_string(idInchiriere)) + "\n";

        cout << "\nIntroduceti o optiune... ";
        cin >> optiune;
        cout << endl;

        switch (optiune) {
            case 1:
                cout << "Introduceti numele: ";
                cin.ignore();
                getline(cin, nume);
                break;
            case 2:
                cout << "Introduceti prenumele: ";
                cin.ignore();
                getline(cin, prenume);
                break;
            case 3:
                cout << "Introduceti email-ul: ";
                cin.ignore();
                getline(cin, email);
                break;
            case 4:
                cout << "Introduceti ID-ul inchirierii: ";
                cin >> idInchiriere;
                break;
            case 5:
                cout << "Introduceti ID-ul masinii: ";
                cin >> idMasina;
                break;
            case 9:
            {
                vector<Inchiriere> searchResults = searchInchiriere(inchirieri, nume, prenume, email, idInchiriere, idMasina);

                if (searchResults.empty()) {
                    cout << "Nicio inchiriere gasita conform filtrelor specificate." << endl;
                } else {
                    cout << "Inchirierile gasite conform filtrelor specificate:" << endl;
                    afisareTabelInchirieri(searchResults, searchResults.size());
                }
                while (!exitMenuSelectare) {
                    cout << endl;
                    cout << "1. Selecteaza inchirierea\n";
                    cout << "0. Inapoi la cautare\n";
                    cout << "\nIntroduceti o optiune... ";
                    cin >> optiune;
                    cout << endl;

                    switch (optiune) {
                        case 1:
                            cout << "Introduceti ID-ul inchirierii: ";
                            cin >> idInchiriere;
                            exitMenuSelectare = true;
                            break;
                        case 0:
                            exitMenuSelectare = true;
                            break;
                        default:
                            cout << "Optiune invalida. Va rugam sa selectati o optiune valida." << endl;

                            cin.ignore();
                            cin.get();
                            break;
                    }
                }

                break;
            }
            case 0:
                exitMenu = true;
                break;
            default:
                cout << "Optiune invalida. Va rugam sa selectati o optiune valida." << endl;

                cin.ignore();
                cin.get();
                break;
        }
    }
    return idInchiriere;
}

int main()
{
    int optiune;
    int nrInchirieri=0, nextIdInchiriere=0, nrAutovehicule=0, nextIdAutovehicul=0;
    int mod = 1;

    AdministrareInchirieri adminInchirieri = AdministrareInchirieri();
    update_nrInchirieri_nextIdInchiriere(nrInchirieri, nextIdInchiriere, adminInchirieri);

    AdministrareAutovehicule adminAutovehicule = AdministrareAutovehicule();
    update_nrAutovehicule_nextIdAutovehicul(nrAutovehicule, nextIdAutovehicul, adminAutovehicule);

    vector<Inchiriere> inchirieri = adminInchirieri.GetInchirieri(nrInchirieri);
    Inchiriere inchiriere;

    vector<Autovehicul> autovehicule = adminAutovehicule.GetAutovehicule(nrAutovehicule);
    Autovehicul autovehicul;

    int idAutovehicul = -1;
    bool infoInchiriere = false;

    do
    {
        system("clear");
        // system("cls"); // pentru windows

        if(mod == 1) {
            cout << " INCHIRIERI AUTO\n";
            cout << "1. Autentificare\n";
            cout << "2. Inregistrare\n";
            cout << "3. Inchirierile mele\n";
            cout << '\n';
            cout << " CREAZA O INCHIRIERE\n";
            cout << "4. Cauta autovehicul\n";
            cout << "5. " << (!infoInchiriere ? "Introduce" : "Modifica") << " informatii inchiriere\n";
            cout << "6. Afisare informatii inchiriere\n";
            cout << "7. Salveaza informatii inchiriere\n";
            cout << '\n';
            cout << "8. Meniu angajati\n";
            cout << "9. Meniu admin\n";
            cout << "0. Inchidere program\n";
            cout << "\nIntroduceti o optiune... ";
            cin >> optiune;
            cout << endl;
            switch (toupper(optiune)) {
                case 1: {
                    cout << "Autentificare";

                    cin.ignore();
                    cin.get();
                    break;
                }
                case 2: {
                    cout << "Inregistrare";

                    cin.ignore();
                    cin.get();
                    break;
                }
                case 3: {
                    cout << "Inchirierile mele";

                    cin.ignore();
                    cin.get();
                    break;
                }
                case 4: {
                    idAutovehicul = meniuCautareAutovehicul(autovehicule);
                    inchiriere.setIdAutovehicul(idAutovehicul);

                    break;
                }

                case 5: {
                    if(idAutovehicul != -1) {
                        cin >> inchiriere;
                        infoInchiriere = true;
                    }
                    else
                        cout << "Eroare! Nu a fost selectat un autovehicul!";

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 6: {
                    if(infoInchiriere)
                        cout << inchiriere;
                    else
                        cout << "Eroare! Nu au fost introduse informatiile!";

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 7: {
                    update_nrInchirieri_nextIdInchiriere(nrInchirieri, nextIdInchiriere, adminInchirieri);
                    inchiriere.setIdInchiriere(nextIdInchiriere);
                    adminInchirieri.AdaugaInchiriere(inchiriere);

                    idAutovehicul = -1;

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 8: {
                    string parola;
                    cout << "Introduce parola: ";
                    cin >> parola;

                    if (parola == "abc")
                        mod = 2;
                    else
                        cout << "Parola gresita!";

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 9: {
                    string parola;
                    cout << "Introduce parola: ";
                    cin >> parola;

                    if (parola == "admin")
                        mod = 3;
                    else
                        cout << "Parola gresita!";

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 0:
                    exit(0);

                default:
                    cout << "Optiune invalida. Va rugam selectati o optiune valida.\n";

                    cin.ignore();
                    cin.get();
            }
        }
        else if(mod == 2) {
            cout << " INCHIRIERI\n";
            cout << "1. Afisare inchirieri\n";
            cout << "2. Cauta inchiriere\n";
            cout << "3. Modifica inchiriere\n";
            cout << "4. Sterge inchiriere\n";
            cout << '\n';
            cout << " AUTOVEHICULE\n";
            cout << "6. Introducere informatii autovehicul\n";
            cout << "7. Afisare informatii autovehicul\n";
            cout << "8. Afisare autovehicule\n";
            cout << "9. Salvare informatii autovehicul\n";
            cout << "10. Cauta autovehicul\n";
            cout << "11. Modifica inchiriere\n";
            cout << "12. Sterge autovehicul\n";
            cout << '\n';
            cout << "13. Meniu clienti\n";
            cout << "14. Meniu admin\n";
            cout << "0. Inchidere program\n";
            cout << "\nIntroduceti o optiune... ";
            cin >> optiune;
            cout << endl;
            switch (toupper(optiune)) {
                case 1: {
                    inchirieri = adminInchirieri.GetInchirieri(nrInchirieri);
                    afisareTabelInchirieri(inchirieri, nrInchirieri);

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 2: {
                    meniuCautareInchiriere(inchirieri);

                    break;
                }

                case 3: {
                    int idStergere;
                    cout << "Introduceti ID-ul inchirierii de sters: ";
                    cin >> idStergere;

                    bool rezultat = adminInchirieri.StergeInchiriereDupaID(idStergere);
                    if (rezultat) {
                        cout << "Inchirierea a fost stearsa cu succes." << endl;
                    } else {
                        cout << "Nu s-a putut gasi inchirierea pentru stergere." << endl;
                    }

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 7: {
                    autovehicul = Autovehicul();
                    cin >> autovehicul;

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 8: {
                    cout << autovehicul;

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 9: {
                    autovehicule = adminAutovehicule.GetAutovehicule(nrAutovehicule);
                    afisareTabelAutovehicule(autovehicule, nrAutovehicule);

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 10: {
                    update_nrAutovehicule_nextIdAutovehicul(nrAutovehicule, nextIdAutovehicul, adminAutovehicule);
                    autovehicul.setID(nextIdAutovehicul);
                    adminAutovehicule.AdaugaAutovehicul(autovehicul);

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 11: {
                    meniuCautareAutovehicul(autovehicule);

                    break;
                }

                case 12: {
                    int idStergere;
                    cout << "Introduceti ID-ul autovehiculului de sters: ";
                    cin >> idStergere;

                    bool rezultat = adminAutovehicule.StergeAutovehiculDupaID(idStergere);
                    if (rezultat) {
                        cout << "Autovehiculul a fost sters cu succes." << endl;
                    } else {
                        cout << "Nu s-a putut gasi autovehiculul pentru stergere." << endl;
                    }

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 13: {
                    mod = 1;

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 14: {
                    string parola;
                    cout << "Introduce parola: ";
                    cin >> parola;

                    if (parola == "admin")
                        mod = 3;
                    else
                        cout << "Parola gresita!";

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 0:
                    exit(0);

                default:
                    cout << "Optiune invalida. Va rugam selectati o optiune valida.\n";

                    cin.ignore();
                    cin.get();
            }
        }
        else if(mod == 3) {
            cout << " CLIENTI\n";
            cout << "1. Afisare date clienti\n";
            cout << "2. Cauta client\n";
            cout << "4. Modifica date client\n";
            cout << "4. Sterge date client\n";
            cout << '\n';
            cout << " ANGAJATI\n";
            cout << "5. Introducere date angajat\n";
            cout << "6. Afisare angajat\n";
            cout << "7. Afisare date angajati\n";
            cout << "8. Salvare date angajat\n";
            cout << "9. Cauta angajat\n";
            cout << "10. Modifica date angajat\n";
            cout << "11. Sterge date angajat\n";
            cout << '\n';
            cout << " ADMINISTRATOR\n";
            cout << "12. Schimba parola\n";
            cout << '\n';
            cout << "13. Meniu clienti\n";
            cout << "14. Meniu angajati\n";
            cout << "0. Inchidere program\n";
            cout << "\nIntroduceti o optiune... ";
            cin >> optiune;
            cout << endl;
            switch (toupper(optiune)) {
                case 1: {
                    inchiriere = Inchiriere();
                    cin >> inchiriere;

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 2: {
                    cout << inchiriere;

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 3: {
                    inchirieri = adminInchirieri.GetInchirieri(nrInchirieri);
                    afisareTabelInchirieri(inchirieri, nrInchirieri);

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 4: {
                    update_nrInchirieri_nextIdInchiriere(nrInchirieri, nextIdInchiriere, adminInchirieri);
                    inchiriere.setIdInchiriere(nextIdInchiriere);
                    adminInchirieri.AdaugaInchiriere(inchiriere);

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 5: {
                    meniuCautareInchiriere(inchirieri);

                    break;
                }

                case 6: {
                    int idStergere;
                    cout << "Introduceti ID-ul inchirierii de sters: ";
                    cin >> idStergere;

                    bool rezultat = adminInchirieri.StergeInchiriereDupaID(idStergere);
                    if (rezultat) {
                        cout << "Inchirierea a fost stearsa cu succes." << endl;
                    } else {
                        cout << "Nu s-a putut gasi inchirierea pentru stergere." << endl;
                    }

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 7: {
                    autovehicul = Autovehicul();
                    cin >> autovehicul;

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 8: {
                    cout << autovehicul;

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 9: {
                    autovehicule = adminAutovehicule.GetAutovehicule(nrAutovehicule);
                    afisareTabelAutovehicule(autovehicule, nrAutovehicule);

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 10: {
                    update_nrAutovehicule_nextIdAutovehicul(nrAutovehicule, nextIdAutovehicul, adminAutovehicule);
                    autovehicul.setID(nextIdAutovehicul);
                    adminAutovehicule.AdaugaAutovehicul(autovehicul);

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 11: {
                    meniuCautareAutovehicul(autovehicule);

                    break;
                }

                case 12: {
                    int idStergere;
                    cout << "Introduceti ID-ul autovehiculului de sters: ";
                    cin >> idStergere;

                    bool rezultat = adminAutovehicule.StergeAutovehiculDupaID(idStergere);
                    if (rezultat) {
                        cout << "Autovehiculul a fost sters cu succes." << endl;
                    } else {
                        cout << "Nu s-a putut gasi autovehiculul pentru stergere." << endl;
                    }

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 13: {
                    mod = 1;

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 14: {
                    mod = 2;

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 0:
                    exit(0);

                default:
                    cout << "Optiune invalida. Va rugam selectati o optiune valida.\n";

                    cin.ignore();
                    cin.get();
            }
        }
    }while(true);
    return 0;
}