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

using namespace std;

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

vector<Autovehicul> searchAutovehicul(const vector<Autovehicul>& autovehicule, const string& marca,
                                      const string& model, const string& categorie, int costMin, int costMax,
                                      bool disponibil) {
    vector<Autovehicul> results;

    for (const Autovehicul& autovehicul : autovehicule) {
        // Check if the Autovehicul matches the specified filters
        if ((!marca.empty() && !autovehicul.getMarca().find(marca)) ||
            (!model.empty() && !autovehicul.getModel().find(model)) ||
            (!categorie.empty() && autovehicul.getCategorie() != categorie) ||
            (costMin > 0 && autovehicul.getCostZi() < costMin) ||
            (costMax > 0 && autovehicul.getCostZi() > costMax) ||
            (disponibil && !autovehicul.isDisponibil())) {
            continue;  // Skip to the next Autovehicul if any filter doesn't match
        }

        results.push_back(autovehicul);  // Add matching Autovehicul to results
    }

    return results;
}

void afisareTabel(const vector<Autovehicul>& autovehicule)
{
    // Verifică dacă vectorul este gol
    if (autovehicule.empty()) {
        cout << "Nu exista autovehicule de afisat." << endl;
        return;
    }

    // Header-ul tabelului
    cout << "---------+---------------+---------------+-------------+-----------+--------------+------------+------------+-------------+----------------+---------------+---------------+" << endl;
    cout << "|   ID   |     Marca     |     Model     |  Categorie  |  Cost/Zi  |  Capacitate  |     Nr.    |     Nr.    |    Volum    |   Transmisie   |      Aer      |      Tip      |" << endl;
    cout << "|        |               |               |             |           |     motor    |  Pasageri  |  Portiere  |  Portbagaj  |                |  Conditionat  |  Combustibil  |" << endl;
    cout << "---------+---------------+---------------+-------------+-----------+--------------+------------+------------+-------------+----------------+---------------+---------------+" << endl;

    // Iterează prin fiecare obiect Autovehicul și afișează detaliile sub forma de rând în tabel
    for (const Autovehicul& autovehicul : autovehicule) {
        cout << "| " << setw(6) << left << autovehicul.getID() << " |";
        cout << " " << setw(13) << left << autovehicul.getMarca() << " |";
        cout << " " << setw(13) << left << autovehicul.getModel() << " |";
        cout << " " << setw(11) << left << autovehicul.getCategorie() << " |";
        cout << " " << setw(9) << left << to_string(autovehicul.getCostZi()) + " RON" << " |";
//        cout << " " << setw(13) << left << (autovehicul.isDisponibil() ? "Da" : "Nu") << " |";
        cout << " " << setw(12) << left << to_string(autovehicul.getCapacitateMotor()) + " cm^3" << " |";
        cout << " " << setw(10) << left << autovehicul.getNrPasageri() << " |";
        cout << " " << setw(10) << left << autovehicul.getNrPortiere() << " |";
        cout << " " << setw(11) << left << to_string(autovehicul.getVolumPortbagaj()) + " L" << " |";
        cout << " " << setw(14) << left << autovehicul.getTransmisie() << " |";
        cout << " " << setw(13) << left << (autovehicul.hasAerConditionat() ? "Da" : "Nu") << " |";
        cout << " " << setw(13) << left << autovehicul.getTipCombustibil() << " |" << endl;
    }

    cout << "---------+---------------+---------------+-------------+-----------+--------------+------------+------------+-------------+----------------+---------------+---------------+" << endl;
}

int main()
{
    int optiune;
    int nrInchirieri=0, nextIdInchiriere=0, nrAutovehicule=0, nextIdAutovehicul=0;

    AdministrareInchirieri adminInchirieri = AdministrareInchirieri();
    update_nrInchirieri_nextIdInchiriere(nrInchirieri, nextIdInchiriere, adminInchirieri);

    AdministrareAutovehicule adminAutovehicule = AdministrareAutovehicule();
    update_nrAutovehicule_nextIdAutovehicul(nrAutovehicule, nextIdAutovehicul, adminAutovehicule);

    vector<Inchiriere> inchirieri = adminInchirieri.GetInchirieri(nrInchirieri);
    Inchiriere inchiriere;

    vector<Autovehicul> autovehicule = adminAutovehicule.GetAutovehicule(nrAutovehicule);
    Autovehicul autovehicul;

    do
    {
        system("clear");
        // system("cls"); // pentru windows
        cout << " INCHIRIERI\n";
        cout << "1. Introducere informatii inchiriere\n";
        cout << "2. Afisare inchiriere\n";
        cout << "3. Afisare inchirieri din fisier\n";
        cout << "4. Salvare inchiriere in fisier\n";
        cout << "5. Cauta inchiriere dupa id\n";
        cout << "6. Cauta inchiriere dupa nume\n";
        cout << '\n';
        cout << " AUTOVEHICULE\n";
        cout << "7. Introducere informatii autovehicul\n";
        cout << "8. Afisare autovehicul\n";
        cout << "9. Afisare autovehicule din fisier\n";
        cout << "10. Salvare autovehicul in fisier\n";
        cout << "11. Cauta autovehicul dupa id\n";
        cout << "12. Cauta autovehicul dupa categorie\n";
        cout << '\n';
        cout << "0. Inchidere program\n";
        cout << "\nIntroduceti o optiune... ";
        cin >> optiune;
        cout << endl;
        switch (toupper(optiune))
        {
            case 1:
            {
                inchiriere = Inchiriere();
                cin >> inchiriere;

                cin.ignore();
                cin.get();
                break;
            }

            case 2:
            {
                cout << inchiriere;

                cin.ignore();
                cin.get();
                break;
            }

            case 3:
            {
                inchirieri = adminInchirieri.GetInchirieri(nrInchirieri);
                for (int i = 0; i < nrInchirieri; i++) {
                    cout << inchirieri[i].Info() << endl;
                }

                cin.ignore();
                cin.get();
                break;
            }

            case 4:
            {
                update_nrInchirieri_nextIdInchiriere(nrInchirieri, nextIdInchiriere, adminInchirieri);
                inchiriere.setIdInchiriere(nextIdInchiriere);
                adminInchirieri.AdaugaInchiriere(inchiriere);

                cin.ignore();
                cin.get();
                break;
            }

            case 7:
            {
                autovehicul = Autovehicul();
                cin >> autovehicul;

                cin.ignore();
                cin.get();
                break;
            }

            case 8:
            {
                cout << autovehicul.Info();

                cin.ignore();
                cin.get();
                break;
            }

            case 9:
            {
                autovehicule = adminAutovehicule.GetAutovehicule(nrAutovehicule);
                for (int i = 0; i < nrAutovehicule; i++) {
                    cout << autovehicule[i].Info() << endl;
                }

                cin.ignore();
                cin.get();
                break;
            }

            case 10:
            {
                update_nrAutovehicule_nextIdAutovehicul(nrAutovehicule, nextIdAutovehicul, adminAutovehicule);
                autovehicul.setID(nextIdAutovehicul);
                adminAutovehicule.AdaugaAutovehicul(autovehicul);

                cin.ignore();
                cin.get();
                break;
            }

            case 11:
            {
                string marca, model, categorie;
                int costMin = 0, costMax = 0;

                bool exitMenu = false;

                while (!exitMenu) {
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
                                afisareTabel(searchResults);
                            }

                            cin.ignore();
                            cin.get();
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

                break;
            }

            case 0:
                exit(0);

            default:
                cout << "Optiune invalida. Va rugam selectati o optiune valida.\n";

                cin.ignore();
                cin.get();
        }
    }while(true);
    return 0;
}