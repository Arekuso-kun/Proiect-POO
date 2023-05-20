#include "AdministrareInchirieri.h"
#include "Inchiriere.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

AdministrareInchirieri::AdministrareInchirieri(string numeFisier)
{
    this->numeFisier = numeFisier;
}

AdministrareInchirieri::~AdministrareInchirieri() {}

void AdministrareInchirieri::AdaugaInchiriere(Inchiriere inchiriere)
{
    ofstream fisierText(numeFisier, ios::app);
    if (fisierText.is_open())
    {
        fisierText << inchiriere.ConversieLaSir_PentruFisier() << endl;
        fisierText.close();
    }
}

Inchiriere* AdministrareInchirieri::GetInchirieri(int& nrInchirieri)
{
    Inchiriere* inchirieri = new Inchiriere[NR_MAX_INCHIRIERI];

    ifstream fisier(numeFisier);
    string linieFisier;
    nrInchirieri = 0;

    while (getline(fisier, linieFisier))
        inchirieri[nrInchirieri++] = Inchiriere(linieFisier);

    fisier.close();
    return inchirieri;
}