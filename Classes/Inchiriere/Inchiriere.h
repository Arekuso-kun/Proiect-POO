#ifndef INCHIRIERE_H
#define INCHIRIERE_H

#include <iostream>
#include <string>
#include "../Persoana/Client/Client.h"
#include "../Utility.h"

using namespace std;

class Inchiriere : public Client, public Utility
{
private:
    char SEPARATOR_PRINCIPAL_FISIER = ';';
    int idInchiriere;
    int idMasina;

    int ID_INCHIRIERE = 0;
    int ID_MASINA = 1;
    int NUME = 2;
    int PRENUME = 3;
    int EMAIL = 4;
    int VARSTA = 5;
    int ADRESA = 6;
    int TELEFON = 7;

    static const int NR_CARACTERISTICI = 8;

public:
    Inchiriere(int idInchiriere = 0, int idMasina = 0, string nume = "", string prenume = "", string email = "",
               int varsta = 0, string adresa = "", string telefon = "");
    Inchiriere(string linieFisier);
    ~Inchiriere();

    int getIdInchiriere() { return idInchiriere; }
    int getIdMasina() { return idMasina; }
    string getNume() { return nume; }
    string getPrenume() { return prenume; }

    void setIdInchiriere(int id) { idInchiriere = id; }
    void setIdMasina(int id) { idMasina = id; }
    void setNume(string n) { nume = n; }
    void setPrenume(string p) { prenume = p; }

    string Info() const;
    string ConversieLaSir_PentruFisier();
    friend istream& operator>>(istream& is, Inchiriere& inchiriere);
    friend ostream& operator<<(ostream& os, const Inchiriere& inchiriere);
};

#endif