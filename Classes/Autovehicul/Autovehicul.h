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
    int nr_pasageri;
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
    int NR_PASAGERI = 7;
    int NR_PORTIERE = 8;
    int VOLUM_PORTBAGAJ = 9;
    int TRANSMISIE = 10;
    int AER_CONDITIONAT = 11;
    int TIP_COMBUSTIBIL = 12;

    static const int NR_CARACTERISTICI = 13;

public:
    Autovehicul(int id = 0, string marca = "", string model = "", string categorie = "", int cost_zi = 0,
                bool disponibil = true, int capacitate_motor = 0, int nr_pasageri = 0, int nr_portiere = 0,
                int volum_portbagaj = 0, string transmisie = "", bool aer_conditionat = false, string tip_combustibil = "");
    Autovehicul(string linieFisier);
    ~Autovehicul();

    // Getteri
    int getID() { return id; }
    string getMarca() { return marca; }
    string getModel() { return model; }
    string getCategorie() { return categorie; }
    int getCostZi() { return cost_zi; }
    bool isDisponibil() { return disponibil; }
    int getCapacitateMotor() const { return capacitate_motor; }
    int getNrPasageri() { return nr_pasageri; }
    int getNrPortiere() { return nr_portiere; }
    int getVolumPortbagaj() { return volum_portbagaj; }
    string getTransmisie() { return transmisie; }
    bool hasAerConditionat() { return aer_conditionat; }
    string getTipCombustibil() { return tip_combustibil; }

    // Setteri
    void setID(int newId) { id = newId; }
    void setMarca(string newMarca) { marca = newMarca; }
    void setModel(string newModel) { model = newModel; }
    void setCategorie(string newCategorie) { categorie = newCategorie; }
    void setCostZi(int newCostZi) { cost_zi = newCostZi; }
    void setDisponibil(bool newDisponibil) { disponibil = newDisponibil; }
    void setCapacitateMotor(int newCapacitateMotor) { capacitate_motor = newCapacitateMotor; }
    void setNrPasageri(int newNrPasageri) { nr_pasageri = newNrPasageri; }
    void setNrPortiere(int newNrPortiere) { nr_portiere = newNrPortiere; }
    void setVolumPortbagaj(int newVolumPortbagaj) { volum_portbagaj = newVolumPortbagaj; }
    void setTransmisie(string newTransmisie) { transmisie = newTransmisie; }
    void setAerConditionat(bool newAerConditionat) { aer_conditionat = newAerConditionat; }
    void setTipCombustibil(string newTipCombustibil) { tip_combustibil = newTipCombustibil; }

    void inchiriazaMasina();
    void returnCar();

    string Info();
    string ConversieLaSir_PentruFisier();
    friend istream& operator>>(istream& is, Autovehicul& autovehicul);
};

#endif
