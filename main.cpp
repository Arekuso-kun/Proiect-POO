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
#include "Classes/Cont/Cont.h"
#include "Classes/Cont/Cont.cpp"
#include "Classes/Cont/AdministrareConturi.h"
#include "Classes/Cont/AdministrareConturi.cpp"
#include "Classes/Client/Client.h"
#include "Classes/Client/Client.cpp"
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

void afisareTabelAutovehicule(const vector<Autovehicul>& autovehicule, int nrAutovehicule)
{
    if (autovehicule.empty()) {
        cout << "Nu exista autovehicule de afisat." << endl;
        return;
    }

    Table tAutovehicule;

    tAutovehicule.add_row({"ID", "Marca", "Model", "Categorie", "Cost/zi", "Disponibil", "Capacitate motor", "Nr. locuri", "Nr. portiere", "Volum portbagaj", "Transmisie", "Aer conditionat", "Tip Combustibil"});
    for (int i = 0; i < nrAutovehicule; i++) {
        tAutovehicule.add_row({autovehicule[i].getID() == -1 ? "N/A" : to_string(autovehicule[i].getID()),
                autovehicule[i].getMarca(),
                autovehicule[i].getModel(),
                autovehicule[i].getCategorie(),
                (autovehicule[i].getCostZi() == -1 ? "N/A" : to_string(autovehicule[i].getCostZi())) + " RON",
                (autovehicule[i].isDisponibil() ? "Da" : "Nu"),
                (autovehicule[i].getCapacitateMotor() == -1 ? "N/A" : to_string(autovehicule[i].getCapacitateMotor())) + " cm^3",
                (autovehicule[i].getNrLocuri() == -1 ? "N/A" : to_string(autovehicule[i].getNrLocuri())),
                (autovehicule[i].getNrPortiere() == -1 ? "N/A" : to_string(autovehicule[i].getNrPortiere())),
                (autovehicule[i].getVolumPortbagaj() == -1 ? "N/A" : to_string(autovehicule[i].getVolumPortbagaj())) + " L",
                autovehicule[i].getTransmisie(),
                (autovehicule[i].hasAerConditionat() ? "Da" : "Nu"),
                autovehicule[i].getTipCombustibil()});
    }

    tAutovehicule[0].format()
            .font_style({FontStyle::bold})
            .padding(1)
            .font_align(FontAlign::center);

    cout << tAutovehicule << endl;

}

void afisareTabelInchirieri(const vector<Inchiriere>& inchirieri, int nrInchirieri)
{
    if (inchirieri.empty()) {
        cout << "Nu exista inchirieri de afisat." << endl;
        return;
    }

    Table tInchirieri;
    AdministrareAutovehicule adminAutovehicule = AdministrareAutovehicule();

    tInchirieri.add_row({"ID", "Autovehicul", "Nume", "Prenume", "CNP", "Email", "Adresa", "Telefon", "Data inchiriere", "Data returnare"});
    for (int i = 0; i < nrInchirieri; i++) {
        int idAutovehicul = inchirieri[i].getIdAutovehicul();
        string autovehicul = adminAutovehicule.CautaAutovehiculDupaID(idAutovehicul).getMarca() + ' ' + adminAutovehicule.CautaAutovehiculDupaID(idAutovehicul).getModel() + " (#" + to_string(idAutovehicul) + ") ";
        tInchirieri.add_row({(inchirieri[i].getIdInchiriere() == -1 ? "N/A" : to_string(inchirieri[i].getIdInchiriere())),
                             (inchirieri[i].getIdAutovehicul() == -1 ? "N/A" : autovehicul),
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

    cout << tInchirieri << endl;

}

void afisareTabelConturi(const vector<Cont>& conturi, int nrConturi)
{
    if (conturi.empty()) {
        cout << "Nu exista conturi de afisat." << endl;
        return;
    }

    Table tConturi;
    AdministrareConturi adminConturi = AdministrareConturi();

    tConturi.add_row({"Index", "Email", "Parola", "Tip Cont"});
    for (int i = 0; i < nrConturi; i++) {
        tConturi.add_row({to_string(i + 1),
                          conturi[i].getEmail(),
                          conturi[i].getParola(),
                          conturi[i].getTipCont()});
    }

    tConturi[0].format()
            .font_style({FontStyle::bold})
            .padding(1)
            .font_align(FontAlign::center);

    cout << tConturi << endl;

}

int meniuCautareAutovehicul(vector<Autovehicul> autovehicule)
{
    string marca, model, categorie;
    int costMin = 0, costMax = 0, optiune, idSelectat = -1, idAutovehicul = -1;
    AdministrareAutovehicule adminAutovehicule = AdministrareAutovehicule();
    Autovehicul autovehicul;

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
        cout << "6. Filtru dupa ID" << (idAutovehicul != -1 ? " (Filtru: " + to_string(idAutovehicul) + ")" : "") << '\n';
        cout << "7. Reseteaza filtre\n";
        cout << '\n';
        cout << "9. Afiseaza rezultate\n";
        cout << "0. Inapoi la meniul principal\n";

        string autovehiculSelectat = adminAutovehicule.CautaAutovehiculDupaID(idSelectat).getMarca() + ' ' + adminAutovehicule.CautaAutovehiculDupaID(idSelectat).getModel() + " (#" + to_string(idSelectat) + ") ";
        cout << "\nAutovehicul selectat: " + (idSelectat == -1 ? "N/A" : autovehiculSelectat) + "\n";

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
                categorie = autovehicul.selecteazaCategorieAutovehicul();
                break;
            case 4:
                cout << "Introduceti costul minim pe zi: ";
                cin >> costMin;
                break;
            case 5:
                cout << "Introduceti costul maxim pe zi: ";
                cin >> costMax;
                break;
            case 6:
                cout << "Introduceti ID-ul autovehiculului: ";
                cin >> idAutovehicul;
                break;
            case 7:
                model = "";
                marca = "";
                categorie = "";
                costMin = 0;
                costMax = 0;
                idAutovehicul = -1;
                cout << "Filtre resetate." << endl;

                cin.ignore();
                cin.get();
                break;
            case 9:
            {
                vector<Autovehicul> searchResults = adminAutovehicule.CautaAutovehicul(marca, model, categorie, costMin, costMax, idAutovehicul, true);

                if (searchResults.empty()) {
                    cout << "Niciun autovehicul gasit conform filtrelor specificate." << endl;
                    cin.ignore();
                    cin.get();
                } else {
                    cout << "Autovehiculele gasite conform filtrelor specificate:" << endl;
                    afisareTabelAutovehicule(searchResults, searchResults.size());

                    while (!exitMenuSelectare) {
                        cout << "1. Selecteaza autovehicul\n";
                        cout << "0. Inapoi la cautare\n";
                        cout << "\nIntroduceti o optiune... ";
                        cin >> optiune;
                        cout << endl;

                        switch (optiune) {
                            case 1:
                                cout << "Introduceti ID-ul autovehiculului: ";
                                cin >> idSelectat;
                                if (adminAutovehicule.CautaAutovehiculDupaID(idSelectat).getID() == -1) {
                                    idSelectat = -1;
                                    cout << "Autovehiculul cu ID-ul specificat nu a fost gasit." << endl;
                                    cin.ignore();
                                    cin.get();
                                    for (int i = 1; i <= 8; i++)
                                        cout << "\33[2K\r\033[A\r";
                                } else exitMenuSelectare = true;
                                break;
                            case 0:
                                exitMenuSelectare = true;
                                break;
                            default:
                                cout << "Optiune invalida. Va rugam sa selectati o optiune valida." << endl;

                                cin.ignore();
                                cin.get();
                                for (int i = 1; i <= 7; i++)
                                    cout << "\33[2K\r\033[A\r";
                                break;
                        }
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
    return idSelectat;
}

int meniuCautareInchiriere(vector<Inchiriere> inchirieri)
{
    string nume, prenume, email, cnp;
    int idInchiriere = -1, idAutovehicul = -1, optiune, idSelectat = -1;
    AdministrareInchirieri adminInchirieri = AdministrareInchirieri();

    bool exitMenu = false;

    while (!exitMenu) {
        bool exitMenuSelectare = false;
        system("clear");
        cout << " FILTRE DISPONIBILE:\n";
        cout << "1. Filtru dupa nume" << (nume.empty() ? "" : " (Filtru: " + nume + ")") << '\n';
        cout << "2. Filtru dupa prenume" << (prenume.empty() ? "" : " (Filtru: " + prenume + ")") << '\n';
        cout << "3. Filtru dupa email" << (email.empty() ? "" : " (Filtru: " + email + ")") << '\n';
        cout << "4. Filtru dupa CNP" << (cnp.empty() ? "" : " (Filtru: " + cnp + ")") << '\n';
        cout << "5. Filtru dupa ID inchiriere" << (idInchiriere != -1 ? " (Filtru: " + to_string(idInchiriere) + ")" : "") << '\n';
        cout << "6. Filtru dupa ID autovehicul" << (idAutovehicul != -1 ? " (Filtru: " + to_string(idAutovehicul) + ")" : "") << '\n';
        cout << "7. Reseteaza filtre\n";
        cout << '\n';
        cout << "9. Afiseaza rezultate\n";
        cout << "0. Inapoi la meniul principal\n";

        string inchiriereSelectata = adminInchirieri.CautaInchiriereDupaID(idSelectat).getNume() + ' '
                + adminInchirieri.CautaInchiriereDupaID(idSelectat).getPrenume()
                + " (#" + to_string(idSelectat) + ") ";
        cout << "\nInchiriere selectata: " + (idSelectat == -1 ? "N/A" : inchiriereSelectata) + "\n";

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
                cout << "Introduceti CNP-ul: ";
                cin.ignore();
                getline(cin, cnp);
                break;
            case 5:
                cout << "Introduceti ID-ul inchirierii: ";
                cin >> idInchiriere;
                break;
            case 6:
                cout << "Introduceti ID-ul autovehiculului: ";
                cin >> idAutovehicul;
                break;
            case 7:
                nume = "";
                prenume = "";
                email = "";
                cnp = "";
                idInchiriere = -1;
                idAutovehicul = -1;
                cout << "Filtre resetate." << endl;
                cin.ignore();
                cin.get();
                break;
            case 9:
            {
                vector<Inchiriere> searchResults = adminInchirieri.CautaInchiriere(nume, prenume, email, cnp, idInchiriere, idAutovehicul);

                if (searchResults.empty()) {
                    cout << "Nicio inchiriere gasita conform filtrelor specificate." << endl;
                    cin.ignore();
                    cin.get();
                } else {
                    cout << "Inchirierile gasite conform filtrelor specificate:" << endl;
                    afisareTabelInchirieri(searchResults, searchResults.size());

                    while (!exitMenuSelectare) {
                        cout << "1. Selecteaza inchirierea\n";
                        cout << "0. Inapoi la cautare\n";
                        cout << "\nIntroduceti o optiune... ";
                        cin >> optiune;
                        cout << endl;

                        switch (optiune) {
                            case 1:
                                cout << "Introduceti ID-ul inchirierii: ";
                                cin >> idSelectat;
                                if(adminInchirieri.CautaInchiriereDupaID(idSelectat).getIdInchiriere() == -1)
                                {
                                    idSelectat = -1;
                                    cout << "Inchirierea cu ID-ul specificat nu a fost gasita." << endl;
                                    cin.ignore();
                                    cin.get();
                                    for(int i = 1; i <= 8; i++)
                                        cout << "\33[2K\r\033[A\r";
                                }
                                else exitMenuSelectare = true;
                                break;
                            case 0:
                                exitMenuSelectare = true;
                                break;
                            default:
                                cout << "Optiune invalida. Va rugam sa selectati o optiune valida." << endl;

                                cin.ignore();
                                cin.get();
                                for(int i = 1; i <= 7; i++)
                                    cout << "\33[2K\r\033[A\r";
                                break;
                        }
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
    return idSelectat;
}

string meniuCautareCont(vector<Cont> conturi)
{
    string email, tip, emailSelectat;
    int optiune, indexSelectat = -1;
    AdministrareConturi adminConturi = AdministrareConturi();
    Cont cont;

    bool exitMenu = false;

    while (!exitMenu) {
        bool exitMenuSelectare = false;
        system("clear");
        cout << " FILTRE DISPONIBILE:\n";
        cout << "1. Filtru dupa email" << (email.empty() ? "" : " (Filtru: " + email + ")") << '\n';
        cout << "2. Filtru dupa tip cont" << (tip.empty() ? "" : " (Filtru: " + tip + ")") << '\n';
        cout << "3. Reseteaza filtre\n";
        cout << '\n';
        cout << "9. Afiseaza rezultate\n";
        cout << "0. Inapoi la meniul principal\n";

        string contSelectat = emailSelectat + " (" + adminConturi.CautaContDupaEmail(emailSelectat).getTipCont() + ") ";
        cout << "\nCont selectat: " + (emailSelectat == "" ? "N/A" : contSelectat) + "\n";

        cout << "\nIntroduceti o optiune... ";
        cin >> optiune;
        cout << endl;

        switch (optiune) {
            case 1:
                cout << "Introduceti email-ul: ";
                cin.ignore();
                getline(cin, email);
                break;
            case 2:
                tip = cont.selecteazaTipCont();
                break;
            case 3:
                email = "";
                tip = "";
                cout << "Filtre resetate." << endl;
                cin.ignore();
                cin.get();
                break;
            case 9:
            {
                vector<Cont> searchResults = adminConturi.CautaCont(email, tip);

                if (searchResults.empty()) {
                    cout << "Niciun cont gasit conform filtrelor specificate." << endl;
                    cin.ignore();
                    cin.get();
                } else {
                    cout << "Conturile gasite conform filtrelor specificate:" << endl;
                    afisareTabelConturi(searchResults, searchResults.size());

                    while (!exitMenuSelectare) {
                        cout << "1. Selecteaza cont\n";
                        cout << "0. Inapoi la cautare\n";
                        cout << "\nIntroduceti o optiune... ";
                        cin >> optiune;
                        cout << endl;

                        switch (optiune) {
                            case 1:
                                cout << "Introduceti index-ul contului: ";
                                cin >> indexSelectat;
                                if(searchResults[indexSelectat-1].getEmail() == "")
                                {
                                    indexSelectat = -1;
                                    cout << "Contul specificat nu a fost gasit." << endl;
                                    cin.ignore();
                                    cin.get();
                                    for(int i = 1; i <= 8; i++)
                                        cout << "\33[2K\r\033[A\r";
                                }
                                else {
                                    emailSelectat = searchResults[indexSelectat-1].getEmail();
                                    exitMenuSelectare = true;
                                }
                                break;
                            case 0:
                                exitMenuSelectare = true;
                                break;
                            default:
                                cout << "Optiune invalida. Va rugam sa selectati o optiune valida." << endl;

                                cin.ignore();
                                cin.get();
                                for(int i = 1; i <= 7; i++)
                                    cout << "\33[2K\r\033[A\r";
                                break;
                        }
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
    return emailSelectat;
}

int main()
{
    int optiune;
    int nrInchirieri=0, nextIdInchiriere=0, nrAutovehicule=0, nextIdAutovehicul=0, nrConturi=0;
    int mod = 1;

    AdministrareInchirieri adminInchirieri = AdministrareInchirieri();
    update_nrInchirieri_nextIdInchiriere(nrInchirieri, nextIdInchiriere, adminInchirieri);

    AdministrareAutovehicule adminAutovehicule = AdministrareAutovehicule();
    update_nrAutovehicule_nextIdAutovehicul(nrAutovehicule, nextIdAutovehicul, adminAutovehicule);

    AdministrareConturi adminConturi = AdministrareConturi();

    vector<Inchiriere> inchirieri = adminInchirieri.GetInchirieri(nrInchirieri);
    Inchiriere inchiriere;

    vector<Autovehicul> autovehicule = adminAutovehicule.GetAutovehicule(nrAutovehicule);
    Autovehicul autovehicul_meniu1;
    Autovehicul autovehicul_meniu2;

    vector<Cont> conturi = adminConturi.GetConturi(nrConturi);
    Cont cont;
    Cont cont_autentificare;
    Cont cont_verificare, cont_verificare_exista;

    int idAutovehiculSelectat_meniu1 = -1;
    bool infoInchiriere = false;
    int idInchiriereSelectat_meniu2 = -1, idAutovehiculSelectat_meniu2 = -1;
    bool infoAutovehicul = false;
    string inchiriereSelectata, autovehiculSelectat, autovehiculSelectat_client, contSelectat, ContAuthString, emailSelectat;
    bool autentificat = false;

    do
    {
        system("clear");
        // system("cls"); // pentru windows

        if(mod == 1) {
            ContAuthString = cont_verificare.getEmail() + " (" + cont_verificare.getTipCont() + ") ";
            autovehiculSelectat_client = adminAutovehicule.CautaAutovehiculDupaID(idAutovehiculSelectat_meniu1).getMarca() + ' '
                    + adminAutovehicule.CautaAutovehiculDupaID(idAutovehiculSelectat_meniu1).getModel()
                    + " (#" + to_string(idAutovehiculSelectat_meniu1) + ")";
            cout << " INCHIRIERI AUTO\n";
            cout << "1. " << (!autentificat ? "Autentificare" : "Log out") << "\n";
            cout << "2. Inregistrare\n";
            cout << "3. Inchirierile mele\n";
            cout << '\n';
            cout << "Cont curent: " << (!autentificat ? "N/A (te poti autentifica accesand optiunea \"1. Autentificare\")" : ContAuthString) << "\n";
            cout << '\n';
            cout << " CREAZA O INCHIRIERE\n";
            cout << "4. Cauta/Selecteaza autovehicul\n";
            cout << "5. " << (!infoInchiriere ? "Introduce" : "Modifica") << " informatii inchiriere\n";
            cout << "6. Afisare informatii inchiriere\n";
            cout << "7. Salveaza informatii inchiriere\n";
            cout << '\n';
            cout << "Autovehicul selectat: " << (idAutovehiculSelectat_meniu1 == -1 ? "N/A (poti selecta un autovehicul accesand optiunea \"4. Cauta/Selecteaza autovehicul\")" : autovehiculSelectat_client) << "\n";
            cout << '\n';
            cout << "8. Meniu angajati\n";
            cout << "9. Meniu admin\n";
            cout << "0. Inchidere program\n";
            cout << "\nIntroduceti o optiune... ";
            cin >> optiune;
            cout << endl;
            switch (toupper(optiune)) {
                case 1: {
                    if(!autentificat) {
                        cin >> cont_autentificare;
                        cout << endl;
                        cont_verificare = adminConturi.CautaContDupaEmail(cont_autentificare.getEmail());
                        if(cont_verificare.getEmail() != cont_autentificare.getEmail()) {
                            cout << endl << "Eroare! Nu s-a gasit niciun cont cu email-ul introdus.";
                        }
                        else if(cont_verificare.getParola() != cont_autentificare.getParola()) {
                            cout << endl << "Eroare! Parola gresita.";
                        }
                        else {
                            autentificat = true;
                            cout << endl << "Autentificare cu succes.";
                        }
                    }
                    else {
                        autentificat = false;
                        cout << endl << "Log out cu succes.";
                    }

                    cin.ignore();
                    cin.get();
                    break;
                }
                case 2: {
                    cin >> cont;
                    cont.setTipCont("Client");
                    adminConturi.AdaugaCont(cont);
                    cout << endl << "Inregistrare cu succes.";

                    cin.ignore();
                    cin.get();
                    break;
                }
                case 3: {
                    if(!autentificat) {
                        cout << "Eroare! Aceasta optiune necesita autentificare.";
                    }
                    else {
                        vector<Inchiriere> searchResults = adminInchirieri.CautaInchiriere("", "", cont_autentificare.getEmail(), "", -1, -1);

                        if (searchResults.empty()) {
                            cout << "Nicio inchiriere gasita.";
                        } else {
                            cout << "Inchirierile gasite:" << endl;
                            afisareTabelInchirieri(searchResults, searchResults.size());
                        }
                    }

                    cin.ignore();
                    cin.get();
                    break;
                }
                case 4: {
                    idAutovehiculSelectat_meniu1 = meniuCautareAutovehicul(autovehicule);
                    inchiriere.setIdAutovehicul(idAutovehiculSelectat_meniu1);

                    break;
                }

                case 5: {
                    if(idAutovehiculSelectat_meniu1 != -1) {
                        if(!infoInchiriere) {
                            cin >> inchiriere;
                            inchiriere.setEmail(cont_autentificare.getEmail());
                            infoInchiriere = true;
                        }
                        else {
                            inchiriere.citireInchiriereExistenta();
                        }
                    }
                    else
                        cout << "Eroare! Nu a fost selectat un autovehicul!";

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 6: {
                    if(!infoInchiriere)
                        cout << "Eroare! Nu au fost introduse informatiile!";
                    else
                        cout << inchiriere;

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 7: {
                    if(!infoInchiriere)
                        cout << "Eroare! Nu au fost introduse informatiile!";
                    else if(!autentificat) {
                        cout << "Eroare! Aceasta optiune necesita autentificare.";
                    }
                    else {
                        update_nrInchirieri_nextIdInchiriere(nrInchirieri, nextIdInchiriere, adminInchirieri);
                        inchiriere.setIdInchiriere(nextIdInchiriere);
                        adminInchirieri.AdaugaInchiriere(inchiriere);

                        autovehicul_meniu1 = Autovehicul(adminAutovehicule.CautaAutovehiculDupaID(idAutovehiculSelectat_meniu1));
                        autovehicul_meniu1.setDisponibil(false);
                        adminAutovehicule.ModificaAutovehiculDinFisier(idAutovehiculSelectat_meniu1, autovehicul_meniu1);

                        idAutovehiculSelectat_meniu1 = -1;
                        cout << "Salvat";
                    }

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 8: {
                    if(!autentificat) {
                        cout << "Eroare! Aceasta optiune necesita autentificare.";
                        cin.ignore();
                        cin.get();
                    }
                    else {
                        if ("Angajat" != cont_verificare.getTipCont() && "Administrator" != cont_verificare.getTipCont()) {
                            cout << "Eroare! Permisiune insuficienta.";
                            cin.ignore();
                            cin.get();
                        } else {
                            mod = 2;
                        }
                    }

                    break;
                }

                case 9: {
                    if(!autentificat) {
                        cout << "Eroare! Aceasta optiune necesita autentificare.";
                        cin.ignore();
                        cin.get();
                    }
                    else {
                        if ("Administrator" != cont_verificare.getTipCont()) {
                            cout << "Eroare! Permisiune insuficienta.";
                            cin.ignore();
                            cin.get();
                        } else {
                            mod = 3;
                            cout << "Succes.";
                        }
                    }

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
            inchiriereSelectata = adminInchirieri.CautaInchiriereDupaID(idInchiriereSelectat_meniu2).getNume() + ' '
                                  + adminInchirieri.CautaInchiriereDupaID(idInchiriereSelectat_meniu2).getPrenume()
                                  + " (#" + to_string(idInchiriereSelectat_meniu2) + ")";
            autovehiculSelectat =
                    adminAutovehicule.CautaAutovehiculDupaID(idAutovehiculSelectat_meniu2).getMarca() + ' '
                    + adminAutovehicule.CautaAutovehiculDupaID(idAutovehiculSelectat_meniu2).getModel()
                    + " (#" + to_string(idAutovehiculSelectat_meniu2) + ")";

            cout << " INCHIRIERI\n";
            cout << "1. Afisare inchirieri\n";
            cout << "2. Cauta/Selecteaza inchiriere\n";
            cout << "3. Modifica inchiriere\n";
            cout << "4. Sterge inchiriere\n";
            cout << '\n';
            cout << "Inchiriere selectata: " << (idInchiriereSelectat_meniu2 == -1
                                                 ? "N/A (poti selecta o inchiriere accesand optiunea \"2. Cauta/Selecteaza inchiriere\")"
                                                 : inchiriereSelectata) << "\n";
            cout << '\n';
            cout << " AUTOVEHICULE\n";
            cout << "5. " << (!infoAutovehicul ? "Introduce" : "Modifica")
                 << " informatii autovehicul\n"; // validare date
            cout << "6. Afisare informatii autovehicul\n";
            cout << "7. Salvare informatii autovehicul\n";
            cout << "8. Afisare autovehicule\n";
            cout << "9. Cauta/Selecteaza autovehicul\n";
            cout << "10. Modifica informatii autovehicul\n";
            cout << "11. Sterge autovehicul\n";
            cout << "12. Seteaza autovehicul ca returnat\n";
            cout << '\n';
            cout << "Autovehicul selectat: " << (idAutovehiculSelectat_meniu2 == -1
                                                 ? "N/A (poti selecta un autovehicul accesand optiunea \"10. Cauta/Selecteaza autovehicul\")"
                                                 : autovehiculSelectat) << "\n";
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
                    idInchiriereSelectat_meniu2 = meniuCautareInchiriere(inchirieri);
                    break;
                }

                case 3: {
                    string raspuns;

                    if (idInchiriereSelectat_meniu2 == -1) {
                        cout
                                << "Nu ati selectat nicio inchiriere. Va rugam selectati o inchiriere valida accesand optiunea \"2. Cauta/Selecteaza inchiriere\"."
                                << endl;
                    } else {
                        bool confirmare = false;
                        while (!confirmare) {
                            cout << "Inchiriere selectata: " << inchiriereSelectata << "\n";
                            cout << "Doriti sa modificati aceasta inchiriere? (Da/Nu): ";
                            cin >> raspuns;
                            cout << "\n";

                            if (raspuns == "Da" || raspuns == "da" || raspuns == "DA" || raspuns == "dA" ||
                                raspuns == "d" || raspuns == "D") {
                                Inchiriere inchiriereModificata = Inchiriere(
                                        adminInchirieri.CautaInchiriereDupaID(idInchiriereSelectat_meniu2));
                                inchiriereModificata.citireInchiriereExistenta();

                                bool rezultat = adminInchirieri.ModificaInchiriereDinFisier(idInchiriereSelectat_meniu2,
                                                                                            inchiriereModificata);
                                if (rezultat) {
                                    cout << "Inchirierea a fost modificata cu succes." << endl;
                                } else {
                                    cout << "Nu s-a putut gasi inchirierea pentru modificare." << endl;
                                }
                                confirmare = true;
                            } else if (raspuns == "Nu" || raspuns == "nu" || raspuns == "NU" || raspuns == "nU" ||
                                       raspuns == "n" || raspuns == "N") {
                                cout << "Modificarea inchirierii a fost anulata." << endl;
                                confirmare = true;
                            } else {
                                cout << "Raspuns invalid. Va rugam introduceti 'Da' sau 'Nu'." << endl;
                                cin.ignore();
                                cin.get();
                                for (int i = 1; i <= 5; i++)
                                    cout << "\33[2K\r\033[A\r";
                            }
                        }
                    }

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 4: {
                    string raspuns;

                    if (idInchiriereSelectat_meniu2 == -1) {
                        cout
                                << "Nu ati selectat nicio inchiriere. Va rugam selectati o inchiriere valida accesand optiunea \"2. Cauta/Selecteaza inchiriere\"."
                                << endl;
                    } else {
                        bool confirmare = false;
                        while (!confirmare) {
                            cout << "Inchiriere selectata: " << inchiriereSelectata << "\n";
                            cout << "Doriti sa stergeti aceasta inchiriere? (Da/Nu): ";
                            cin >> raspuns;
                            cout << "\n";

                            if (raspuns == "Da" || raspuns == "da" || raspuns == "DA" || raspuns == "dA" ||
                                raspuns == "d" || raspuns == "D") {
                                bool rezultat = adminInchirieri.StergeInchiriereDupaID(idInchiriereSelectat_meniu2);
                                if (rezultat) {
                                    idInchiriereSelectat_meniu2 = -1;
                                    cout << "Inchirierea a fost stearsa cu succes." << endl;
                                } else {
                                    cout << "Nu s-a putut gasi inchirierea pentru stergere." << endl;
                                }
                                confirmare = true;
                            } else if (raspuns == "Nu" || raspuns == "nu" || raspuns == "NU" || raspuns == "nU" ||
                                       raspuns == "n" || raspuns == "N") {
                                cout << "Stergerea inchirierii a fost anulata." << endl;
                                confirmare = true;
                            } else {
                                cout << "Raspuns invalid. Va rugam introduceti 'Da' sau 'Nu'." << endl;
                                cin.ignore();
                                cin.get();
                                for (int i = 1; i <= 5; i++)
                                    cout << "\33[2K\r\033[A\r";
                            }
                        }
                    }

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 5: {
                    if (!infoAutovehicul) {
                        cin >> autovehicul_meniu2;
                        infoAutovehicul = true;
                    } else {
                        autovehicul_meniu2.citireAutovehiculExistent();
                    }

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 6: {
                    if (infoAutovehicul)
                        cout << autovehicul_meniu2;
                    else
                        cout << "Eroare! Nu au fost introduse informatiile!";


                    cin.ignore();
                    cin.get();
                    break;
                }

                case 7: {
                    if (infoAutovehicul) {
                        update_nrAutovehicule_nextIdAutovehicul(nrAutovehicule, nextIdAutovehicul, adminAutovehicule);
                        autovehicul_meniu2.setID(nextIdAutovehicul);
                        adminAutovehicule.AdaugaAutovehicul(autovehicul_meniu2);
                        cout << "Autovehicul salvat";

                        infoAutovehicul = false;
                        autovehicul_meniu2 = Autovehicul();
                    } else
                        cout << "Eroare! Nu au fost introduse informatiile!";

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 8: {
                    autovehicule = adminAutovehicule.GetAutovehicule(nrAutovehicule);
                    afisareTabelAutovehicule(autovehicule, nrAutovehicule);

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 9: {
                    idAutovehiculSelectat_meniu2 = meniuCautareAutovehicul(autovehicule);
                    break;
                }

                case 10: {
                    string raspuns;

                    if (idAutovehiculSelectat_meniu2 == -1) {
                        cout << "Nu ati selectat niciun autovehicul. Va rugam selectati un autovehicul valid accesand optiunea \"10. Cauta/Selecteaza autovehicul\"...";
                    } else {
                        bool confirmare = false;
                        while (!confirmare) {
                            cout << "Autovehicul selectat: " << autovehiculSelectat << "\n";
                            cout << "Doriti sa modificati acest autovehicul? (Da/Nu): ";
                            cin >> raspuns;
                            cout << "\n";

                            if (raspuns == "Da" || raspuns == "da" || raspuns == "DA" || raspuns == "dA" ||
                                raspuns == "d" || raspuns == "D") {
                                Autovehicul autovehiculModificat = Autovehicul(
                                        adminAutovehicule.CautaAutovehiculDupaID(idAutovehiculSelectat_meniu2));
                                autovehiculModificat.citireAutovehiculExistent();

                                bool rezultat = adminAutovehicule.ModificaAutovehiculDinFisier(
                                        idAutovehiculSelectat_meniu2, autovehiculModificat);
                                if (rezultat) {
                                    cout << "Autovehiculul a fost modificat cu succes." << endl;
                                } else {
                                    cout << "Nu s-a putut gasi autovehiculul pentru modificare." << endl;
                                }
                                confirmare = true;
                            } else if (raspuns == "Nu" || raspuns == "nu" || raspuns == "NU" || raspuns == "nU" ||
                                       raspuns == "n" || raspuns == "N") {
                                cout << "Modificarea autovehicululului a fost anulata." << endl;
                                confirmare = true;
                            } else {
                                cout << "Raspuns invalid. Va rugam introduceti 'Da' sau 'Nu'." << endl;
                                cin.ignore();
                                cin.get();
                                for (int i = 1; i <= 5; i++)
                                    cout << "\33[2K\r\033[A\r";
                            }
                        }
                    }

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 11: {
                    string raspuns;

                    if (idAutovehiculSelectat_meniu2 == -1) {
                        cout << "Nu ati selectat niciun autovehicul. Va rugam selectati un autovehicul valid accesand optiunea \"10. Cauta/Selecteaza autovehicul\"...";
                    } else {
                        bool confirmare = false;
                        while (!confirmare) {
                            cout << "Autovehicul selectat: " << autovehiculSelectat << "\n";
                            cout << "Doriti sa stergeti aceast autovehicul? (Da/Nu): ";
                            cin >> raspuns;
                            cout << "\n";

                            if (raspuns == "Da" || raspuns == "da" || raspuns == "DA" || raspuns == "dA" ||
                                raspuns == "d" || raspuns == "D") {
                                bool rezultat = adminAutovehicule.StergeAutovehiculDupaID(idAutovehiculSelectat_meniu2);
                                if (rezultat) {
                                    idAutovehiculSelectat_meniu2 = -1;
                                    cout << "Autovehiculul a fost sters cu succes." << endl;
                                } else {
                                    cout << "Nu s-a putut gasi autovehiculul pentru stergere." << endl;
                                }
                                confirmare = true;
                            } else if (raspuns == "Nu" || raspuns == "nu" || raspuns == "NU" || raspuns == "nU" ||
                                       raspuns == "n" || raspuns == "N") {
                                cout << "Stergerea autovehicululului a fost anulata." << endl;
                                confirmare = true;
                            } else {
                                cout << "Raspuns invalid. Va rugam introduceti 'Da' sau 'Nu'." << endl;
                                cin.ignore();
                                cin.get();
                                for (int i = 1; i <= 5; i++)
                                    cout << "\33[2K\r\033[A\r";
                            }
                        }
                    }

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 12: {
                    string raspuns;

                    if (idAutovehiculSelectat_meniu2 == -1) {
                        cout << "Nu ati selectat niciun autovehicul. Va rugam selectati un autovehicul valid accesand optiunea \"10. Cauta/Selecteaza autovehicul\"...";
                    } else {
                        bool confirmare = false;
                        while (!confirmare) {
                            cout << "Autovehicul selectat: " << autovehiculSelectat << "\n";
                            cout << "Doriti sa setati aceast autovehicul ca returnat? (Da/Nu): ";
                            cin >> raspuns;
                            cout << "\n";

                            if (raspuns == "Da" || raspuns == "da" || raspuns == "DA" || raspuns == "dA" ||
                                raspuns == "d" || raspuns == "D") {
                                Autovehicul autovehiculReturnat = Autovehicul(
                                        adminAutovehicule.CautaAutovehiculDupaID(idAutovehiculSelectat_meniu2));
                                autovehiculReturnat.setDisponibil(true);

                                bool rezultat = adminAutovehicule.ModificaAutovehiculDinFisier(
                                        idAutovehiculSelectat_meniu2, autovehiculReturnat);
                                if (rezultat) {
                                    cout << "Autovehiculul a fost modificat cu succes." << endl;
                                } else {
                                    cout << "Nu s-a putut gasi autovehiculul pentru modificare." << endl;
                                }
                                confirmare = true;
                            } else if (raspuns == "Nu" || raspuns == "nu" || raspuns == "NU" || raspuns == "nU" ||
                                       raspuns == "n" || raspuns == "N") {
                                cout << "Returnarea autovehicululului a fost anulata." << endl;
                                confirmare = true;
                            } else {
                                cout << "Raspuns invalid. Va rugam introduceti 'Da' sau 'Nu'." << endl;
                                cin.ignore();
                                cin.get();
                                for (int i = 1; i <= 5; i++)
                                    cout << "\33[2K\r\033[A\r";
                            }
                        }
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
                    if (!autentificat) {
                        cout << "Eroare! Aceasta optiune necesita autentificare.";
                        cin.ignore();
                        cin.get();
                    } else {
                        if ("Administrator" != cont_verificare.getTipCont()) {
                            cout << "Eroare! Permisiune insuficienta.";
                            cin.ignore();
                            cin.get();
                        }
                        else {
                            mod = 3;
                        }
                    }

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
            contSelectat = emailSelectat + " (" + adminConturi.CautaContDupaEmail(emailSelectat).getTipCont() + ") ";
            cout << " CONTURI\n";
            cout << "1. Creare cont\n";
            cout << "2. Afisare conturi\n";
            cout << "3. Cauta/Selecteaza cont\n";
            cout << "4. Modifica date cont\n";
            cout << "5. Sterge cont\n";
            cout << '\n';
            cout << "Cont selectat: " << (emailSelectat.empty() ? "N/A (poti selecta un cont accesand optiunea \"3. Cauta/Selecteaza cont\")" : contSelectat) << endl;
            cout << '\n';
            cout << "6. Meniu clienti\n";
            cout << "7. Meniu angajati\n";
            cout << "0. Inchidere program\n";
            cout << "\nIntroduceti o optiune... ";
            cin >> optiune;
            cout << endl;
            switch (toupper(optiune)) {
                case 1: {
                    cin >> cont;
                    cout << endl;
                    cont.setTipCont(cont.selecteazaTipCont());
                    cont_verificare_exista = adminConturi.CautaContDupaEmail(cont.getEmail());
                    if(cont_verificare_exista.getEmail() == cont.getEmail()) {
                        cout << "Eroare! Contul deja exista!";
                    }
                    else {
                        adminConturi.AdaugaCont(cont);
                        cout << endl << "Cont salvat";
                        cont = Cont();
                    }

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 2: {
                    conturi = adminConturi.GetConturi(nrConturi);
                    afisareTabelConturi(conturi, nrConturi);

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 3: {
                    emailSelectat = meniuCautareCont(conturi);
                    break;
                }

                case 4: {
                    string raspuns;

                    if (emailSelectat.empty()) {
                        cout << "Nu ati selectat niciun cont. Va rugam selectati un cont valid accesand optiunea \"3. Cauta/Selecteaza cont\"...";
                    } else {
                        bool confirmare = false;
                        while (!confirmare) {
                            cout << "Cont selectat: " << contSelectat << endl;
                            cout << "Doriti sa modificati acest cont? (Da/Nu): ";
                            cin >> raspuns;
                            cout << "\n";

                            if (raspuns == "Da" || raspuns == "da" || raspuns == "DA" || raspuns == "dA" || raspuns == "d" || raspuns == "D") {
                                Cont contModificat = Cont(adminConturi.CautaContDupaEmail(emailSelectat));
                                contModificat.citireContExistent();

                                bool rezultat = adminConturi.ModificaContDinFisier(emailSelectat, contModificat);
                                if (rezultat) {
                                    cout << endl << "Contul a fost modificat cu succes.";
                                } else {
                                    cout << endl << "Nu s-a putut gasi contul pentru modificare.";
                                }
                                confirmare = true;
                            } else if (raspuns == "Nu" || raspuns == "nu" || raspuns == "NU" || raspuns == "nU" || raspuns == "n" || raspuns == "N") {
                                cout << endl << "Modificarea contului a fost anulata.";
                                confirmare = true;
                            } else {
                                cout << endl << "Raspuns invalid. Va rugam introduceti 'Da' sau 'Nu'.";
                                cin.ignore();
                                cin.get();
                                for(int i = 1; i <= 5; i++)
                                    cout << "\33[2K\r\033[A\r";
                            }
                        }
                    }

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 5: {
                    string raspuns;

                    if (emailSelectat.empty()) {
                        cout << "Nu ati selectat niciun cont. Va rugam selectati un cont valid accesand optiunea \"3. Cauta/Selecteaza cont\"...";
                    } else {
                        bool confirmare = false;
                        while (!confirmare) {
                            cout << "Cont selectat: " << autovehiculSelectat << "\n";
                            cout << "Doriti sa stergeti aceast cont? (Da/Nu): ";
                            cin >> raspuns;
                            cout << "\n";

                            if (raspuns == "Da" || raspuns == "da" || raspuns == "DA" || raspuns == "dA" || raspuns == "d" || raspuns == "D") {
                                bool rezultat = adminConturi.StergeContDupaEmail(emailSelectat);
                                if (rezultat) {
                                    emailSelectat = "";
                                    cout << endl << "Contul a fost sters cu succes.";
                                } else {
                                    cout << endl << "Nu s-a putut gasi contul pentru stergere.";
                                }
                                confirmare = true;
                            } else if (raspuns == "Nu" || raspuns == "nu" || raspuns == "NU" || raspuns == "nU" || raspuns == "n" || raspuns == "N") {
                                cout << endl << "Stergerea contului a fost anulata.";
                                confirmare = true;
                            } else {
                                cout << endl << "Raspuns invalid. Va rugam introduceti 'Da' sau 'Nu'.";
                                cin.ignore();
                                cin.get();
                                for(int i = 1; i <= 5; i++)
                                    cout << "\33[2K\r\033[A\r";
                            }
                        }
                    }

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 6: {
                    mod = 1;

                    cin.ignore();
                    cin.get();
                    break;
                }

                case 7: {
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