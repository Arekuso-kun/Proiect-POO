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
    Persoana(const string& nume, const string& prenume, const string& email, int varsta)
            : nume(nume), prenume(prenume), email(email), varsta(varsta) {}

    const string& getNume() const {
        return nume;
    }

    const string& getPrenume() const {
        return prenume;
    }

    const string& getEmail() const {
        return email;
    }

    int getVarsta() const {
        return varsta;
    }

    void setNume(const string& newNume) {
        nume = newNume;
    }

    void setPrenume(const string& newPrenume) {
        prenume = newPrenume;
    }

    void setEmail(const string& newEmail) {
        email = newEmail;
    }

    void setVarsta(int newVarsta) {
        varsta = newVarsta;
    }
};

#endif
