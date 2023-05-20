#include "AdministrareAutovehicule.h"
#include "Autovehicul.h"
#include <iostream>
#include <fstream>
#include <string> 

using namespace std;

AdministrareAutovehicule::AdministrareAutovehicule(string numeFisier)
{
    this->numeFisier = numeFisier;
}

AdministrareAutovehicule::~AdministrareAutovehicule() {}

void AdministrareAutovehicule::AdaugaAutovehicul(Autovehicul autovehicul) {
    ofstream fisierText(numeFisier, ios::app);
    if (fisierText.is_open())
    {
        fisierText << autovehicul.ConversieLaSir_PentruFisier() << endl;
        fisierText.close();
    }
}

Autovehicul* AdministrareAutovehicule::GetAutovehicule(int &nrAutovehicule) {
    Autovehicul* autovehicule = new Autovehicul[NR_MAX_AUTOHEHICULE];
    ifstream fisier(numeFisier);
    string linieFisier;
    nrAutovehicule = 0;

    while (getline(fisier, linieFisier))
        autovehicule[nrAutovehicule++] = Autovehicul(linieFisier);

    fisier.close();
    return autovehicule;
}