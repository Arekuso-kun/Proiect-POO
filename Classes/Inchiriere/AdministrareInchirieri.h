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

private:
    string numeFisier;
    static const int NR_MAX_INCHIRIERI = 50;

};

#endif