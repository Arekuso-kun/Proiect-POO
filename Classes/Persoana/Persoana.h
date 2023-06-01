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
    string cnp;

public:
    Persoana(string nume, string prenume, string email, string cnp)
            : nume(nume), prenume(prenume), email(email), cnp(cnp) {}

    string getNume() const {return nume;}
    string getPrenume() const {return prenume;}
    string getEmail() const {return email;}
    string getCNP() const {return cnp;}

    void setNume(string newNume) {nume = newNume;}
    void setPrenume(string newPrenume) {prenume = newPrenume;}
    void setEmail(string newEmail) {email = newEmail;}
    void setCNP(string newCNP) { cnp = newCNP;}
};

#endif
