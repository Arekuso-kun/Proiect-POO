#include "Inchiriere.h"
#include <iostream>
#include <string> 
#include <sstream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string str, char delimiter) {
    vector<string> tokens;
    char* token = strtok(&str[0], &delimiter);

    while (token != NULL) {
        tokens.push_back(string(token));
        token = strtok(NULL, &delimiter);
    }

    return tokens;
}

Inchiriere::Inchiriere(int idInchiriere, int idMasina, string nume, string prenume)
{
    this->idInchiriere = idInchiriere;
    this->idMasina = idMasina;
    this->nume = nume;
    this->prenume = prenume;
}

Inchiriere::Inchiriere(string linieFisier) {
    vector<string> dateFisier = split(linieFisier, SEPARATOR_PRINCIPAL_FISIER);

    idInchiriere = stoi(dateFisier[ID_INCHIRIERE]);
    idMasina = stoi(dateFisier[ID_MASINA]);
    nume = dateFisier[NUME];
    prenume = dateFisier[PRENUME];
}

Inchiriere::~Inchiriere()
{

}

string Inchiriere::Info() 
{
    string info = "ID inchiriere: " + to_string(idInchiriere) + "\n" + 
    "ID masina: " + to_string(idMasina) + "\n" +
    "Nume: " + nume + "\n" +
    "Prenume: " + prenume + "\n";
    return info;
}

string Inchiriere::ConversieLaSir_PentruFisier()
{
    string output = to_string(idInchiriere) + SEPARATOR_PRINCIPAL_FISIER + 
    to_string(idMasina) + SEPARATOR_PRINCIPAL_FISIER + 
    nume + SEPARATOR_PRINCIPAL_FISIER + 
    prenume + SEPARATOR_PRINCIPAL_FISIER;

    return output;
}