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
    Client(string nume = "", string prenume = "", string email = "", string cnp = "", string adresa = "", string telefon = "")
            : Persoana(nume, prenume, email, cnp), adresa(adresa), telefon(telefon) {}

    string getAdresa() const { return adresa; }
    string getTelefon() const { return telefon; }

    void setAdresa(string newAdresa) { adresa = newAdresa; }
    void setTelefon(string newTelefon) { telefon = newTelefon; }
};

#endif
