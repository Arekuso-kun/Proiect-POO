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
    int idAutovehicul;
    string dataInchiriere;
    string dataReturnare;

    int ID_INCHIRIERE = 0;
    int ID_AUTOVEHICUL = 1;
    int NUME = 2;
    int PRENUME = 3;
    int EMAIL = 4;
    int CNP = 5;
    int ADRESA = 6;
    int TELEFON = 7;
    int DATA_INCHIRIERE = 8;
    int DATA_RETURNARE = 9;

    static const int NR_CARACTERISTICI = 10;

public:
    Inchiriere(int idInchiriere = -1, int idAutovehicul = -1, string nume = "NECUNOSCUT", string prenume = "NECUNOSCUT",
               string email = "NECUNOSCUT", string cnp = "", string adresa = "NECUNOSCUT", string telefon = "NECUNOSCUT",
               string dataInchiriere = "NECUNOSCUT", string dataReturnare = "NECUNOSCUT");
    Inchiriere(string linieFisier);
    ~Inchiriere();

    int getIdInchiriere() const { return idInchiriere; }
    int getIdAutovehicul() const { return idAutovehicul; }
    string getNume() const { return nume; }
    string getPrenume() const { return prenume; }
    string getDataInchiriere() const { return dataInchiriere; }
    string getDataReturnare() const { return dataReturnare; }

    void setIdInchiriere(int id) { idInchiriere = id; }
    void setIdAutovehicul(int id) { idAutovehicul = id; }
    void setNume(string n) { nume = n; }
    void setPrenume(string p) { prenume = p; }
    void setDataInchiriere(string data) { dataInchiriere = data; }
    void setDataReturnare(string data) { dataReturnare = data; }

    string Info() const;
    string ConversieLaSir_PentruFisier();
    friend istream& operator>>(istream& is, Inchiriere& inchiriere);
    friend ostream& operator<<(ostream& os, const Inchiriere& inchiriere);

    void citireInchiriereExistenta();
};

#endif
