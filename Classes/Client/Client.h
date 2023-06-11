#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>

using namespace std;

class Client {
protected:
    string nume;
    string prenume;
    string email;
    string cnp;
    string adresa;
    string telefon;

public:
    Client(string nume = "", string prenume = "", string email = "",
           string cnp = "", string adresa = "", string telefon = "");
    ~Client();

    string getAdresa() const { return adresa; }
    string getTelefon() const { return telefon; }
    string getNume() const {return nume;}
    string getPrenume() const {return prenume;}
    string getEmail() const {return email;}
    string getCNP() const {return cnp;}

    void setAdresa(string newAdresa) { adresa = newAdresa; }
    void setTelefon(string newTelefon) { telefon = newTelefon; }
    void setNume(string newNume) {nume = newNume;}
    void setPrenume(string newPrenume) {prenume = newPrenume;}
    void setEmail(string newEmail) {email = newEmail;}
    void setCNP(string newCNP) { cnp = newCNP;}
};

#endif
