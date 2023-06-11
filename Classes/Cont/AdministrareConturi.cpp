#include "AdministrareConturi.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

AdministrareConturi::AdministrareConturi(string numeFisier) {
    this->numeFisier = numeFisier;
}

AdministrareConturi::~AdministrareConturi() {}

void AdministrareConturi::AdaugaCont(Cont cont)
{
    ofstream fisierText(numeFisier, ios::app);
    if (fisierText.is_open())
    {
        fisierText << cont.ConversieLaSir_PentruFisier() << endl;
        fisierText.close();
    }
}

vector<Cont> AdministrareConturi::GetConturi(int& nrConturi)
{
    vector<Cont> conturi(NR_MAX_CONTURI);

    ifstream fisier(numeFisier);
    string linieFisier = "";
    nrConturi = 0;

    while (getline(fisier, linieFisier)) {
        conturi[nrConturi++] = Cont(0, linieFisier);
    }

    fisier.close();
    return conturi;
}

bool AdministrareConturi::StergeContDupaEmail(string email)
{
    int nrConturi=0;
    vector<Cont> conturi = GetConturi(nrConturi);

    for (auto it = conturi.begin(); it != conturi.end(); ++it) {
        if (it->getEmail() == email) {
            conturi.erase(it);

            ofstream fisier(numeFisier);
            if (fisier.is_open()) {
                for (int i = 0; i < nrConturi-1; i++) {
                    fisier << conturi[i].ConversieLaSir_PentruFisier() << endl;
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

bool AdministrareConturi::ModificaContDinFisier(string email, Cont contModificat)
{
    int nrConturi=0;
    vector<Cont> conturi = GetConturi(nrConturi);

    for (int i = 0; i < nrConturi; i++) {
        if (conturi[i].getEmail() == email) {
            conturi[i] = contModificat;

            ofstream fisier(numeFisier);
            if (fisier.is_open()) {
                for (int j = 0; j < nrConturi; j++) {
                    fisier << conturi[j].ConversieLaSir_PentruFisier() << endl;
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

vector<Cont> AdministrareConturi::CautaCont(string email, string tip) {
    vector<Cont> results;

    int nrConturi = 0, index = 1;

    vector<Cont> conturi = AdministrareConturi::GetConturi(nrConturi);

    string emailCautat = Utility::toLowercase(email);

    for (Cont cont : conturi) {
        if( index > nrConturi ) break;
        string emailGasit = Utility::toLowercase(cont.getEmail());

        if ((!email.empty() && (emailGasit.find(emailCautat)) == -1) ||
            (!tip.empty() && cont.getTipCont() != tip)) {
            continue;
        }

        results.push_back(cont);
        index++;
    }

    return results;
}

Cont AdministrareConturi::CautaContDupaEmail(string email) {
    int nrConturi=0;
    vector<Cont> conturi = GetConturi(nrConturi);

    for (Cont cont : conturi) {
        if (cont.getEmail() == email) {
            return cont;
        }
    }
    return Cont();
}