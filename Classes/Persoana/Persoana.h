#ifndef PERSOANA_H
#define PERSOANA_H

#include <iostream>
#include <string>

using namespace std;

class Persoana {
protected:
    string nume;
    string prenume;
    string email;
    int varsta;

public:
    Persoana(string nume, string prenume, string email, int varsta)
            : nume(nume), prenume(prenume), email(email), varsta(varsta) {}

    string getNume() const {return nume;}
    string getPrenume() const {return prenume;}
    string getEmail() const {return email;}
    int getVarsta() const {return varsta;}

    void setNume(string newNume) {nume = newNume;}
    void setPrenume(string newPrenume) {prenume = newPrenume;}
    void setEmail(string newEmail) {email = newEmail;}
    void setVarsta(int newVarsta) {varsta = newVarsta;}
};

#endif
