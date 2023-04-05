#ifndef INCHIRIERE_H
#define INCHIRIERE_H

#include <iostream>
#include <string> 

using namespace std;

class Inchiriere
{
public:
    Inchiriere(int idInchiriere = 0, int idMasina = 0, string nume = "NECUNOSCUT", string prenume = "NECUNOSCUT");
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

    string Info();
    string ConversieLaSir_PentruFisier();

private:
    char SEPARATOR_PRINCIPAL_FISIER = ';';
    int idInchiriere;
    int idMasina;
    string nume;
    string prenume;

    int ID_INCHIRIERE = 0;
    int ID_MASINA = 1;
    int NUME = 2;
    int PRENUME = 3;

};

#endif