#include <iostream>
#include <conio.h>
#include "Classes/Inchiriere/Inchiriere.h"
#include "Classes/Inchiriere/Inchiriere.cpp"
#include "Classes/Masina/Masina.h"
#include "Classes/Inchiriere/AdministrareInchirieri.h"
#include "Classes/Inchiriere/AdministrareInchirieri.cpp"
using namespace std;

void update_nrInchirieri_nextIdInchiriere(int& nrInchirieri, int& nextIdInchiriere, AdministrareInchirieri adminInchirieri)
{
    Inchiriere* inchirieri = adminInchirieri.GetInchirieri(nrInchirieri);
    if (nrInchirieri != 0)
        nextIdInchiriere = inchirieri[nrInchirieri - 1].getIdInchiriere() + 1;
}

int main()
{
    char optiune;
    int nrInchirieri, nextIdInchiriere;
    AdministrareInchirieri adminInchirieri = AdministrareInchirieri();
    update_nrInchirieri_nextIdInchiriere(nrInchirieri, nextIdInchiriere, adminInchirieri);
    Inchiriere* inchirieri = adminInchirieri.GetInchirieri(nrInchirieri);
    Inchiriere inchiriere = Inchiriere();

    do
    {
        system("cls");
        cout << " ---- Inchirieri ---- \n";
        cout << "I. Introducere informatii inchiriere\n";
        cout << "A. Afisare inchiriere\n";
        cout << "F. Afisare inchirieri din fisier\n";
        cout << "S. Salvare inchiriere in fisier\n";
        cout << "K. Cauta inchiriere dupa ID\n";
        cout << "L. Cauta inchiriere dupa nume\n";
        cout << "X. Inchidere program\n";
        cout << "\nAlegeti o optiune...";
        optiune = getchar();
        cout << endl;
        switch (toupper(optiune))
        {
            case 'I':
            {
                bool valid;

                string nume, prenume;
                int idMasina = 0;

                cout << "Introdu nume : ";
                cin >> nume;
                cout << "Introdu prenume : ";
                cin >> prenume;
                cout << "Introdu ID masina : ";
                cin >> idMasina;

                inchiriere = Inchiriere(nextIdInchiriere, idMasina, nume, prenume);
                getch();

                break;
            }

            case 'A':
            {
                cout << inchiriere.Info();
                getch();

                break;
            }

            case 'F':
            {
                inchirieri = adminInchirieri.GetInchirieri(nrInchirieri);

                for (int i = 0; i < nrInchirieri; i++) {
                    cout << inchirieri[i].Info() << endl;
                }
                getch();

                break;
            }

            case 'S':
            {
                update_nrInchirieri_nextIdInchiriere(nrInchirieri, nextIdInchiriere, adminInchirieri);
                inchiriere.setIdInchiriere(nextIdInchiriere);
                adminInchirieri.AdaugaInchiriere(inchiriere);
                getch();

                break;
            }

            case 'X':
                exit(0);
        }
    }while(true);
    getch();
    return 0;
}