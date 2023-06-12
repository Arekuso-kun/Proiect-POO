#ifndef AUTOVEHICUL_H
#define AUTOVEHICUL_H

#include <iostream>
#include <string>
#include "../Utility.h"

using namespace std;

class Autovehicul : public Utility
{
private:
    char SEPARATOR_PRINCIPAL_FISIER = ';';

    int id;
    string marca;
    string model;
    string categorie;
    int cost_zi;
    bool disponibil;
    int capacitate_motor;
    int nr_locuri;
    int nr_portiere;
    int volum_portbagaj;
    string transmisie;
    bool aer_conditionat;
    string tip_combustibil;

    int ID = 0;
    int MARCA = 1;
    int MODEL = 2;
    int CATEGORIE = 3;
    int COST_ZI = 4;
    int DISPONIBIL = 5;
    int CAPACITATE_MOTOR = 6;
    int NR_LOCURI = 7;
    int NR_PORTIERE = 8;
    int VOLUM_PORTBAGAJ = 9;
    int TRANSMISIE = 10;
    int AER_CONDITIONAT = 11;
    int TIP_COMBUSTIBIL = 12;

    static const int NR_CARACTERISTICI = 13;

public:
    Autovehicul(int id = -1, string marca = "NECUNOSCUT", string model = "NECUNOSCUT", string categorie = "NECUNOSCUT", int cost_zi = -1,
                bool disponibil = false, int capacitate_motor = -1, int nr_locuri = -1, int nr_portiere = -1,
                int volum_portbagaj = -1, string transmisie = "NECUNOSCUT", bool aer_conditionat = false, string tip_combustibil = "NECUNOSCUT");
    Autovehicul(string linieFisier);
    ~Autovehicul();

    int getID() const  { return id; }
    string getMarca() const { return marca; }
    string getModel() const { return model; }
    string getCategorie() const { return categorie; }
    int getCostZi() const { return cost_zi; }
    bool isDisponibil() const { return disponibil; }
    int getCapacitateMotor() const { return capacitate_motor; }
    int getNrLocuri() const  { return nr_locuri; }
    int getNrPortiere() const  { return nr_portiere; }
    int getVolumPortbagaj() const  { return volum_portbagaj; }
    string getTransmisie() const  { return transmisie; }
    bool hasAerConditionat() const  { return aer_conditionat; }
    string getTipCombustibil() const  { return tip_combustibil; }

    void setID(int newId) { id = newId; }
    void setMarca(string newMarca) { marca = newMarca; }
    void setModel(string newModel) { model = newModel; }
    void setCategorie(string newCategorie) { categorie = newCategorie; }
    void setCostZi(int newCostZi) { cost_zi = newCostZi; }
    void setDisponibil(bool newDisponibil) { disponibil = newDisponibil; }
    void setCapacitateMotor(int newCapacitateMotor) { capacitate_motor = newCapacitateMotor; }
    void setNrLocuri(int newNrLocuri) { nr_locuri = newNrLocuri; }
    void setNrPortiere(int newNrPortiere) { nr_portiere = newNrPortiere; }
    void setVolumPortbagaj(int newVolumPortbagaj) { volum_portbagaj = newVolumPortbagaj; }
    void setTransmisie(string newTransmisie) { transmisie = newTransmisie; }
    void setAerConditionat(bool newAerConditionat) { aer_conditionat = newAerConditionat; }
    void setTipCombustibil(string newTipCombustibil) { tip_combustibil = newTipCombustibil; }

    string Info() const;
    string ConversieLaSir_PentruFisier() const;
    friend istream& operator>>(istream& is, Autovehicul& autovehicul);
    friend ostream& operator<<(ostream& os, Autovehicul& autovehicul);

    void citireAutovehiculExistent();

    static string selecteazaCategorieAutovehicul();
    static bool selecteazaDisponibilitateAutovehicul();
    static string selecteazaTransmisieAutovehicul();
    static bool selecteazaAerConditionatAutovehicul();
    static string selecteazaCombustibilAutovehicul();
};

#endif
