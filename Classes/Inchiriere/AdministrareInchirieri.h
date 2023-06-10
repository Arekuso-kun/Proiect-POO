#ifndef ADMINISTRAREINCHIRIERI_H
#define ADMINISTRAREINCHIRIERI_H

#include <iostream>
#include <string> 
#include "Inchiriere.h"

using namespace std;

class AdministrareInchirieri
{
public:
    AdministrareInchirieri(string numeFisier = "Inchirieri.txt");
    ~AdministrareInchirieri();
    void AdaugaInchiriere(Inchiriere inchiriere);
    vector<Inchiriere> GetInchirieri(int& nrInchirieri);
    bool StergeInchiriereDupaID(int idInchiriere);
    bool ModificaInchiriereDinFisier(int idInchiriere, Inchiriere inchiriereModificata);
    vector<Inchiriere> CautaInchiriere(string nume, string prenume, string email, string cnp, int idInchiriere, int idAutovehicul);
    Inchiriere CautaInchiriereDupaID(int idInchiriere);

private:
    string numeFisier;
    static const int NR_MAX_INCHIRIERI = 50;

};

#endif