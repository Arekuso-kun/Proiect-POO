#ifndef ADMINISTRAREAUTOHEHICULE_H
#define ADMINISTRAREAUTOHEHICULE_H

#include <iostream>
#include <string> 
#include "Autovehicul.h"

using namespace std;

class AdministrareAutovehicule
{
public:
    AdministrareAutovehicule(string numeFisier = "Autovehicule.txt");
    ~AdministrareAutovehicule();
    void AdaugaAutovehicul(Autovehicul autovehicul);
    Autovehicul* GetAutovehicule(int& nrAutovehicule);

private:
    string numeFisier;
    static const int NR_MAX_AUTOHEHICULE = 50;

};

#endif