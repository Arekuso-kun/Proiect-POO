#include "Client.h"

Client::Client(string nume, string prenume, string email, string cnp, string adresa, string telefon) {
    this->nume = nume;
    this->prenume = prenume;
    this->email = email;
    this->cnp = cnp;
    this->adresa = adresa;
    this->telefon = telefon;
}

Client::~Client() {

}
