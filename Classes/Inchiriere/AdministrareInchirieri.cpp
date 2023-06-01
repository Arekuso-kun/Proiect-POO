#include "AdministrareInchirieri.h"
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

vector<Inchiriere> AdministrareInchirieri::GetInchirieri(int& nrInchirieri)
{
    vector<Inchiriere> inchirieri(NR_MAX_INCHIRIERI);

    ifstream fisier(numeFisier);
    string linieFisier;
    nrInchirieri = 0;

    while (getline(fisier, linieFisier))
        inchirieri[nrInchirieri++] = Inchiriere(linieFisier);

    fisier.close();
    return inchirieri;
}

bool AdministrareInchirieri::StergeInchiriereDupaID(int idInchiriere)
{
    int nrInchirieri=0;
    vector<Inchiriere> inchirieri = GetInchirieri(nrInchirieri);

    for (auto it = inchirieri.begin(); it != inchirieri.end(); ++it) {
        if (it->getIdInchiriere() == idInchiriere) {
            inchirieri.erase(it);

            ofstream fisier(numeFisier);
            if (fisier.is_open()) {
                for (int i = 0; i < nrInchirieri-1; i++) {
                    fisier << inchirieri[i].ConversieLaSir_PentruFisier() << endl;
                }
                fisier.close();
            } else {
                cout << "Eroare la deschiderea fisierului!" << endl;
            }

            return true;
        }
    }

    return false;
}