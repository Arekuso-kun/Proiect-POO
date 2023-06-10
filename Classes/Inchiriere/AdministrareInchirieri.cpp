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

bool AdministrareInchirieri::ModificaInchiriereDinFisier(int idInchiriere, Inchiriere inchiriereModificata)
{
    int nrInchirieri = 0;
    vector<Inchiriere> inchirieri = GetInchirieri(nrInchirieri);

    for (int i = 0; i < nrInchirieri; i++) {
        if (inchirieri[i].getIdInchiriere() == idInchiriere) {
            inchirieri[i] = inchiriereModificata;

            ofstream fisier(numeFisier);
            if (fisier.is_open()) {
                for (int j = 0; j < nrInchirieri; j++) {
                    fisier << inchirieri[j].ConversieLaSir_PentruFisier() << endl;
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

vector<Inchiriere> AdministrareInchirieri::CautaInchiriere(string nume, string prenume, string email, string cnp, int idInchiriere, int idAutovehicul) {
    vector<Inchiriere> results;

    int nrInchirieri = 0, index = 1;

    vector<Inchiriere> inchirieri = AdministrareInchirieri::GetInchirieri(nrInchirieri);

    string numeCautat = Utility::toLowercase(nume);
    string prenumeCautat = Utility::toLowercase(prenume);
    string emailCautat = Utility::toLowercase(email);
    string cnpCautat = Utility::toLowercase(cnp);

    for (Inchiriere inchiriere : inchirieri) {
        if( index > nrInchirieri ) break;
        string numeGasit = Utility::toLowercase(inchiriere.getNume());
        string prenumeGasit = Utility::toLowercase(inchiriere.getPrenume());
        string emailGasit = Utility::toLowercase(inchiriere.getEmail());
        string cnpGasit = Utility::toLowercase(inchiriere.getCNP());

        if ((!nume.empty() && (numeGasit.find(numeCautat)) == -1) ||
            (!prenume.empty() && (prenumeGasit.find(prenumeCautat)) == -1) ||
            (!email.empty() && (emailGasit.find(emailCautat)) == -1) ||
            (!cnp.empty() && (cnpGasit.find(cnpCautat)) == -1) ||
            (idInchiriere != -1 && inchiriere.getIdInchiriere() != idInchiriere) ||
            (idAutovehicul != -1 && inchiriere.getIdAutovehicul() != idAutovehicul)) {
            continue;
        }

        results.push_back(inchiriere);
        index++;
    }

    return results;
}

Inchiriere AdministrareInchirieri::CautaInchiriereDupaID(int idInchiriere) {
    int nrInchirieri = 0;
    vector<Inchiriere> inchirieri = GetInchirieri(nrInchirieri);

    for (Inchiriere inchiriere : inchirieri) {
        if (inchiriere.getIdInchiriere() == idInchiriere) {
            return inchiriere;
        }
    }
    return Inchiriere();
}
