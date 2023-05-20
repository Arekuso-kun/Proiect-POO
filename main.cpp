#include <iostream>
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
    Inchiriere* inchirieri = adminInchirieri.GetInchirieri(nrInchirieri);
    if (nrInchirieri != 0)
        nextIdInchiriere = inchirieri[nrInchirieri - 1].getIdInchiriere() + 1;
}

void update_nrAutovehicule_nextIdAutovehicul(int& nrAutovehicule, int& nextIdAutovehicul, AdministrareAutovehicule adminAutovehicule)
{
    Autovehicul* autovehicule = adminAutovehicule.GetAutovehicule(nrAutovehicule);
    if (nrAutovehicule != 0)
        nextIdAutovehicul = autovehicule[nrAutovehicule - 1].getID() + 1;
}

int main()
{
    int optiune;
    int nrInchirieri=0, nextIdInchiriere=0, nrAutovehicule=0, nextIdAutovehicul=0;

    AdministrareInchirieri adminInchirieri = AdministrareInchirieri();
    update_nrInchirieri_nextIdInchiriere(nrInchirieri, nextIdInchiriere, adminInchirieri);

    AdministrareAutovehicule adminAutovehicule = AdministrareAutovehicule();
    update_nrAutovehicule_nextIdAutovehicul(nrAutovehicule, nextIdAutovehicul, adminAutovehicule);

    Inchiriere* inchirieri = adminInchirieri.GetInchirieri(nrInchirieri);
    Inchiriere inchiriere;

    Autovehicul* autovehicule = adminAutovehicule.GetAutovehicule(nrAutovehicule);
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
        cout << "\nAlegeti o optiune...";
        cin >> optiune;
        cout << endl;
        switch (toupper(optiune))
        {
            case 1:
            {
                inchiriere = Inchiriere();
                cin >> inchiriere;
                break;
            }

            case 2:
            {
                cout << inchiriere;
                break;
            }

            case 3:
            {
                inchirieri = adminInchirieri.GetInchirieri(nrInchirieri);
                for (int i = 0; i < nrInchirieri; i++) {
                    cout << inchirieri[i].Info() << endl;
                }
                break;
            }

            case 4:
            {
                update_nrInchirieri_nextIdInchiriere(nrInchirieri, nextIdInchiriere, adminInchirieri);
                inchiriere.setIdInchiriere(nextIdInchiriere);
                adminInchirieri.AdaugaInchiriere(inchiriere);
                break;
            }

            case 7:
            {
                autovehicul = Autovehicul();
                cin >> autovehicul;
                break;
            }

            case 8:
            {
                cout << autovehicul.Info();
                break;
            }

            case 9:
            {
                autovehicule = adminAutovehicule.GetAutovehicule(nrAutovehicule);
                for (int i = 0; i < nrAutovehicule; i++) {
                    cout << autovehicule[i].Info() << endl;
                }
                break;
            }

            case 10:
            {
                update_nrAutovehicule_nextIdAutovehicul(nrAutovehicule, nextIdAutovehicul, adminAutovehicule);
                autovehicul.setID(nextIdAutovehicul);
                adminAutovehicule.AdaugaAutovehicul(autovehicul);
                break;
            }

            case 0:
                exit(0);

            default:
                cout << "Optiune invalida. Va rugam selectati o optiune valida.\n";
        }
        cin.ignore();
        cin.get();
    }while(true);
    return 0;
}