#ifndef ANGAJAT_H
#define ANGAJAT_H

#include <iostream>
#include <string>
#include "../Persoana.h"

using namespace std;

class Angajat : public Persoana {
private:
    string functie;
    int salariu;

public:
    Angajat(string nume = "", string prenume = "", string email = "", string cnp = "", string functie = "", int salariu = -1)
            : Persoana(nume, prenume, email, cnp), functie(functie), salariu(salariu) {}

    string getFunctie() const {return functie;}
    int getSalariu() const {return salariu;}

    void setFunctie(const string& newFunctie) {functie = newFunctie;}
    void setSalariu(int newSalariu) {salariu = newSalariu;}
};

#endif
