#ifndef ANGAJAT_H
#define ANGAJAT_H

#include <iostream>
#include <string>
#include "../Persoana.h"

using namespace std;

class Angajat : public Persoana {
private:
    string functie;
    double salariu;

public:
    Angajat(const string& nume, const string& prenume, const string& email, int varsta,
            const string& functie, double salariu)
            : Persoana(nume, prenume, email, varsta), functie(functie), salariu(salariu) {}

    const string& getFunctie() const {return functie;}
    double getSalariu() const {return salariu;}

    void setFunctie(const string& newFunctie) {functie = newFunctie;}
    void setSalariu(double newSalariu) {salariu = newSalariu;}
};

#endif
