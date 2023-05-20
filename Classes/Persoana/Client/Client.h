#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include "../Persoana.h"

using namespace std;

class Client : public Persoana {
protected:
    string adresa;
    string telefon;

public:
    Client(string nume = "", string prenume = "", string email = "", int varsta = 0, string adresa = "", string telefon = "")
            : Persoana(nume, prenume, email, varsta), adresa(adresa), telefon(telefon) {}

    string getAdresa() { return adresa; }
    string getTelefon() { return telefon; }

    void setAdresa(string newAdresa) { adresa = newAdresa; }
    void setTelefon(string newTelefon) { telefon = newTelefon; }
};

#endif
