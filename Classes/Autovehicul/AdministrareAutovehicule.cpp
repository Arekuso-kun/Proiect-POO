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

vector<Autovehicul> AdministrareAutovehicule::CautaAutovehicul(string marca, string model, string categorie,
                                                               int costMin, int costMax, int idAutovehicul, bool disponibil) {
    vector<Autovehicul> results;

    int nrAutovehicule = 0, index = 1;

    vector<Autovehicul> autovehicule = AdministrareAutovehicule::GetAutovehicule(nrAutovehicule);

    string marcaCautata = Utility::toLowercase(marca);
    string modelCautat = Utility::toLowercase(model);

    for (Autovehicul autovehicul : autovehicule) {
        if( index > nrAutovehicule ) break;

        string marcaGasita = Utility::toLowercase(autovehicul.getMarca());
        string modelGasait = Utility::toLowercase(autovehicul.getModel());

        if ((!marca.empty() && (marcaGasita.find(marcaCautata)) == -1) ||
                (!model.empty() && (modelGasait.find(modelCautat)) == -1) ||
                (!categorie.empty() && autovehicul.getCategorie() != categorie) ||
                (costMin > 0 && autovehicul.getCostZi() < costMin) ||
                (costMax > 0 && autovehicul.getCostZi() > costMax) ||
                (disponibil && !autovehicul.isDisponibil()) ||
                (idAutovehicul != -1 && autovehicul.getID() != idAutovehicul)) {
            continue;
        }

        results.push_back(autovehicul);
        index++;
    }

    return results;
}

Autovehicul AdministrareAutovehicule::CautaAutovehiculDupaID(int idAutovehicul) {
    int nrAutovehicule = 0;
    vector<Autovehicul> autovehicule = GetAutovehicule(nrAutovehicule);

    for (Autovehicul autovehicul : autovehicule) {
        if (autovehicul.getID() == idAutovehicul) {
            return autovehicul;
        }
    }
    return Autovehicul();
}

bool AdministrareAutovehicule::ModificaAutovehiculDinFisier(int idAutovehicul, Autovehicul autovehiculModificat) {
    int nrAutovehicule = 0;
    vector<Autovehicul> autovehicule = GetAutovehicule(nrAutovehicule);

    for (int i = 0; i < nrAutovehicule; i++) {
        if (autovehicule[i].getID() == idAutovehicul) {
            autovehicule[i] = autovehiculModificat;

            ofstream fisier(numeFisier);
            if (fisier.is_open()) {
                for (int j = 0; j < nrAutovehicule; j++) {
                    fisier << autovehicule[j].ConversieLaSir_PentruFisier() << endl;
                }
                fisier.close();
                return true;
            } else {
                cout << "Eroare la deschiderea fisierului!" << endl;
                return false;
            }
        }
    }

    return false;
}

