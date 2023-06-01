#include "Inchiriere.h"
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
//    cout << "Introduceti ID-ul autovehiculului: ";
//    is >> inchiriere.idAutovehicul;

    cout << "Introduceti numele clientului: ";
    is >> inchiriere.nume;

    cout << "Introduceti prenumele clientului: ";
    is >> inchiriere.prenume;

    cout << "Introduceti adresa de email a clientului: ";
    is >> inchiriere.email;

    cout << "Introduceti CNP clientului: ";
    is >> inchiriere.cnp;

    cout << "Introduceti adresa clientului: ";
    cin.ignore();
    getline(is, inchiriere.adresa);

    cout << "Introduceti numarul de telefon al clientului: ";
    is >> inchiriere.telefon;

    cout << "Introduceti data inchirierii: ";
    cin.ignore();
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
