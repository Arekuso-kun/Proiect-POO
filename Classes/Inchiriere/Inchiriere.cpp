#include "Inchiriere.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Inchiriere::Inchiriere(int idInchiriere, int idMasina, string nume, string prenume, string email, int varsta, string adresa, string telefon)
                : Client(nume, prenume, email, varsta, adresa, telefon)
{
    this->idInchiriere = idInchiriere;
    this->idMasina = idMasina;
}

Inchiriere::Inchiriere(string linieFisier) {
    vector<string> dateFisier = split(linieFisier, SEPARATOR_PRINCIPAL_FISIER);

    if (dateFisier.size() < NR_CARACTERISTICI) {
        throw runtime_error("Date lipsa! linieFisier: " + linieFisier );
    }

    idInchiriere = stoi(dateFisier[ID_INCHIRIERE]);
    idMasina = stoi(dateFisier[ID_MASINA]);
    nume = dateFisier[NUME];
    prenume = dateFisier[PRENUME];
    email = dateFisier[EMAIL];
    varsta = stoi(dateFisier[VARSTA]);
    adresa = dateFisier[ADRESA];
    telefon = dateFisier[TELEFON];
}

Inchiriere::~Inchiriere() {}

string Inchiriere::Info() const {
    string info = "ID inchiriere: " + to_string(idInchiriere) + "\n";
    info += "ID masina: " + to_string(idMasina) + "\n";
    info += "Nume: " + nume + "\n";
    info += "Prenume: " + prenume + "\n";
    info += "Email: " + email + "\n";
    info += "Varsta: " + to_string(varsta) + "\n";
    info += "Adresa: " + adresa + "\n";
    info += "Telefon: " + telefon + "\n";
    return info;
}

string Inchiriere::ConversieLaSir_PentruFisier() {
    string output = to_string(idInchiriere) + SEPARATOR_PRINCIPAL_FISIER +
                    to_string(idMasina) + SEPARATOR_PRINCIPAL_FISIER +
                    nume + SEPARATOR_PRINCIPAL_FISIER +
                    prenume + SEPARATOR_PRINCIPAL_FISIER +
                    email + SEPARATOR_PRINCIPAL_FISIER +
                    to_string(varsta) + SEPARATOR_PRINCIPAL_FISIER +
                    adresa + SEPARATOR_PRINCIPAL_FISIER +
                    telefon + SEPARATOR_PRINCIPAL_FISIER;
    return output;
}

istream &operator>>(istream &is, Inchiriere &inchiriere) {
    cout << "Introduceti ID-ul masinii: ";
    is >> inchiriere.idMasina;

    cout << "Introduceti numele clientului: ";
    is >> inchiriere.nume;

    cout << "Introduceti prenumele clientului: ";
    is >> inchiriere.prenume;

    cout << "Introduceti adresa de email a clientului: ";
    is >> inchiriere.email;

    cout << "Introduceti varsta clientului: ";
    is >> inchiriere.varsta;

    cout << "Introduceti adresa clientului: ";
    cin.ignore();
    getline(is, inchiriere.adresa);

    cout << "Introduceti numarul de telefon al clientului: ";
    is >> inchiriere.telefon;

    return is;
}

ostream& operator<<(ostream& os, const Inchiriere& inchiriere)
{
    os << inchiriere.Info();
    return os;
}