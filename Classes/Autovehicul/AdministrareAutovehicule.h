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
    vector<Autovehicul> GetAutovehicule(int& nrAutovehicule);
    bool StergeAutovehiculDupaID(int idAutovehicul);
    bool ModificaAutovehiculDinFisier(int idAutovehicul, Autovehicul autovehiculModificat);
    vector<Autovehicul> CautaAutovehicul(string marca, string model, string categorie, int costMin, int costMax, int idAutovehicul, bool disponibil);
    Autovehicul CautaAutovehiculDupaID(int idAutovehicul);

private:
    string numeFisier;
    static const int NR_MAX_AUTOHEHICULE = 50;

};

#endif