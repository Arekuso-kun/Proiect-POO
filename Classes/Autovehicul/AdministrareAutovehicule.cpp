#include "AdministrareAutovehicule.h"
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

vector<Autovehicul> AdministrareAutovehicule::GetAutovehicule(int &nrAutovehicule) {
    vector<Autovehicul> autovehicule(NR_MAX_AUTOHEHICULE);
    ifstream fisier(numeFisier);
    string linieFisier;
    nrAutovehicule = 0;

    while (getline(fisier, linieFisier))
        autovehicule[nrAutovehicule++] = Autovehicul(linieFisier);

    fisier.close();
    return autovehicule;
}

bool AdministrareAutovehicule::StergeAutovehiculDupaID(int idAutovehicul)
{
    int nrAutovehicule=0;
    vector<Autovehicul> autovehicule = GetAutovehicule(nrAutovehicule);

    for (auto it = autovehicule.begin(); it != autovehicule.end(); ++it) {
        if (it->getID() == idAutovehicul) {
            autovehicule.erase(it);

            ofstream fisier(numeFisier);
            if (fisier.is_open()) {
                for (int i = 0; i < nrAutovehicule-1; i++) {
                    fisier << autovehicule[i].ConversieLaSir_PentruFisier() << endl;
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