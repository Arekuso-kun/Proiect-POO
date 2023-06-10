#include "Inchiriere.h"
#include "AdministrareInchirieri.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Inchiriere::Inchiriere(int idInchiriere, int idAutovehicul, string nume, string prenume, string email, string cnp,
                       string adresa, string telefon, string dataInchiriere, string dataReturnare)
                       : Client(nume, prenume, email, cnp, adresa, telefon)
{
    this->idInchiriere = idInchiriere;
    this->idAutovehicul = idAutovehicul;
}

Inchiriere::Inchiriere(string linieFisier) {
    vector<string> dateFisier = split(linieFisier, SEPARATOR_PRINCIPAL_FISIER);

    if (dateFisier.size() < NR_CARACTERISTICI) {
        throw runtime_error("Date lipsa! linieFisier: " + linieFisier );
    }

    idInchiriere = stoi(dateFisier[ID_INCHIRIERE]);
    idAutovehicul = stoi(dateFisier[ID_AUTOVEHICUL]);
    nume = dateFisier[NUME];
    prenume = dateFisier[PRENUME];
    email = dateFisier[EMAIL];
    cnp = dateFisier[CNP];
    adresa = dateFisier[ADRESA];
    telefon = dateFisier[TELEFON];
    dataInchiriere = dateFisier[DATA_INCHIRIERE];
    dataReturnare = dateFisier[DATA_RETURNARE];
}

Inchiriere::~Inchiriere() {}

string Inchiriere::Info() const {
    string info = "ID inchiriere: " + to_string(idInchiriere) + "\n";
    info += "ID autovehicul: " + to_string(idAutovehicul) + "\n";
    info += "Nume: " + nume + "\n";
    info += "Prenume: " + prenume + "\n";
    info += "Email: " + email + "\n";
    info += "CNP: " + cnp + "\n";
    info += "Adresa: " + adresa + "\n";
    info += "Telefon: " + telefon + "\n";
    info += "Data inchiriere: " + dataInchiriere + "\n";
    info += "Data returnare: " + dataReturnare + "\n";
    return info;
}

string Inchiriere::ConversieLaSir_PentruFisier() {
    string output = to_string(idInchiriere) + SEPARATOR_PRINCIPAL_FISIER +
                    to_string(idAutovehicul) + SEPARATOR_PRINCIPAL_FISIER +
                    nume + SEPARATOR_PRINCIPAL_FISIER +
                    prenume + SEPARATOR_PRINCIPAL_FISIER +
                    email + SEPARATOR_PRINCIPAL_FISIER +
                    cnp + SEPARATOR_PRINCIPAL_FISIER +
                    adresa + SEPARATOR_PRINCIPAL_FISIER +
                    telefon + SEPARATOR_PRINCIPAL_FISIER +
                    dataInchiriere + SEPARATOR_PRINCIPAL_FISIER +
                    dataReturnare + SEPARATOR_PRINCIPAL_FISIER;
    return output;
}

istream &operator>>(istream &is, Inchiriere &inchiriere) {
    cout << "Introduceti numele clientului: ";
    cin.ignore();
    getline(is, inchiriere.nume);

    cout << "Introduceti prenumele clientului: ";
    getline(is, inchiriere.prenume);

    cout << "Introduceti adresa de email a clientului: ";
    getline(is, inchiriere.email);

    cout << "Introduceti CNP clientului: ";
    getline(cin, inchiriere.cnp);

    cout << "Introduceti adresa clientului: ";
    getline(is, inchiriere.adresa);

    cout << "Introduceti numarul de telefon al clientului: ";
    getline(is, inchiriere.telefon);

    cout << "Introduceti data inchirierii: ";
    getline(is, inchiriere.dataInchiriere);

    cout << "Introduceti data returnarii: ";
    getline(is, inchiriere.dataReturnare);

    return is;
}

ostream& operator<<(ostream& os, const Inchiriere& inchiriere)
{
    os << inchiriere.Info();
    return os;
}

void Inchiriere::citireInchiriereExistenta() {
    string input;

    cout << "Introduceti numele clientului (default: " << nume << "): ";
    cin.ignore();
    getline(cin, input);
    if (!input.empty()) {
        nume = input;
    }

    cout << "Introduceti prenumele clientului (default: " << prenume << "): ";
    getline(cin, input);
    if (!input.empty()) {
        prenume = input;
    }

    cout << "Introduceti adresa de email a clientului (default: " << email << "): ";
    getline(cin, input);
    if (!input.empty()) {
        email = input;
    }

    cout << "Introduceti CNP clientului (default: " << cnp << "): ";
    getline(cin, input);
    if (!input.empty()) {
        cnp = input;
    }

    cout << "Introduceti adresa clientului (default: " << adresa << "): ";
    getline(cin, input);
    if (!input.empty()) {
        adresa = input;
    }

    cout << "Introduceti numarul de telefon al clientului (default: " << telefon << "): ";
    getline(cin, input);
    if (!input.empty()) {
        telefon = input;
    }

    cout << "Introduceti data inchirierii (default: " << dataInchiriere << "): ";
    getline(cin, input);
    if (!input.empty()) {
        dataInchiriere = input;
    }

    cout << "Introduceti data returnarii (default: " << dataReturnare << "): ";
    getline(cin, input);
    if (!input.empty()) {
        dataReturnare = input;
    }
}