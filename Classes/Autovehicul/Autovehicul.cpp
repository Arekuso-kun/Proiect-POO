#include "Autovehicul.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

Autovehicul::Autovehicul(int id, string marca, string model, string categorie, int cost_zi, bool disponibil,
               int capacitate_motor, int nr_pasageri, int nr_portiere, int volum_portbagaj, string transmisie,
               bool aer_conditionat, string tip_combustibil) {
    this->id = id;
    this->marca = marca;
    this->model = model;
    this->categorie = categorie;
    this->cost_zi = cost_zi;
    this->disponibil = disponibil;
    this->capacitate_motor = capacitate_motor;
    this->nr_pasageri = nr_pasageri;
    this->nr_portiere = nr_portiere;
    this->volum_portbagaj = volum_portbagaj;
    this->transmisie = transmisie;
    this->aer_conditionat = aer_conditionat;
    this->tip_combustibil = tip_combustibil;
}

Autovehicul::Autovehicul(string linieFisier) {
    vector<string> dateFisier = split(linieFisier, SEPARATOR_PRINCIPAL_FISIER);
    if (dateFisier.size() < NR_CARACTERISTICI) {
        throw runtime_error("Date lipsa! linieFisier: " + linieFisier );
    }

    id = stoi(dateFisier[ID]);
    marca = dateFisier[MARCA];
    model = dateFisier[MODEL];
    categorie = dateFisier[CATEGORIE];
    cost_zi = stoi(dateFisier[COST_ZI]);
    disponibil = stoi(dateFisier[DISPONIBIL]);
    capacitate_motor = stoi(dateFisier[CAPACITATE_MOTOR]);
    nr_pasageri = stoi(dateFisier[NR_PASAGERI]);
    nr_portiere = stoi(dateFisier[NR_PORTIERE]);
    volum_portbagaj = stoi(dateFisier[VOLUM_PORTBAGAJ]);
    transmisie = dateFisier[TRANSMISIE];
    aer_conditionat = stoi(dateFisier[AER_CONDITIONAT]);
    tip_combustibil = dateFisier[TIP_COMBUSTIBIL];
}

Autovehicul::~Autovehicul() {}

void Autovehicul::inchiriazaMasina() {
    if (disponibil) {
        disponibil = false;
        cout << "AutovehiculAutovehicul inchiriat." << endl;
    } else {
        cout << "Autovehiculul nu este disponibil pentru inchiriat." << endl;
    }
}

void Autovehicul::returnCar() {
    if (!disponibil) {
        disponibil = true;
        cout << "Autovehicul returnat." << endl;
    } else {
        cout << "Autovehicul este deja disponibil." << endl;
    }
}

string Autovehicul::Info() {
    string info = "ID: " + to_string(id) + "\n";
    info += "Marca: " + marca + "\n";
    info += "Model: " + model + "\n";
    info += "Categorie: " + categorie + "\n";
    info += "Cost pe zi: " + to_string(cost_zi) + "\n";
    string disponibil_str = (disponibil ? "Da" : "Nu");
    info += "Disponibil: " + disponibil_str + "\n";
    info += "Capacitate motor: " + to_string(capacitate_motor) + "\n";
    info += "Numar pasageri: " + to_string(nr_pasageri) + "\n";
    info += "Numar portiere: " + to_string(nr_portiere) + "\n";
    info += "Volum portbagaj: " + to_string(volum_portbagaj) + "\n";
    info += "Transmisie: " + transmisie + "\n";
    string aer_conditionat_str = (aer_conditionat ? "Da" : "Nu");
    info += "Aer conditionat: " + aer_conditionat_str + "\n";
    info += "Tip combustibil: " + tip_combustibil + "\n";

    return info;
}

string Autovehicul::ConversieLaSir_PentruFisier() {
    string output = to_string(id) + SEPARATOR_PRINCIPAL_FISIER +
                    marca + SEPARATOR_PRINCIPAL_FISIER +
                    model + SEPARATOR_PRINCIPAL_FISIER +
                    categorie + SEPARATOR_PRINCIPAL_FISIER +
                    to_string(cost_zi) + SEPARATOR_PRINCIPAL_FISIER +
                    (disponibil ? "1" : "0") + SEPARATOR_PRINCIPAL_FISIER +
                    to_string(capacitate_motor) + SEPARATOR_PRINCIPAL_FISIER +
                    to_string(nr_pasageri) + SEPARATOR_PRINCIPAL_FISIER +
                    to_string(nr_portiere) + SEPARATOR_PRINCIPAL_FISIER +
                    to_string(volum_portbagaj) + SEPARATOR_PRINCIPAL_FISIER +
                    transmisie + SEPARATOR_PRINCIPAL_FISIER +
                    (aer_conditionat ? "1" : "0") + SEPARATOR_PRINCIPAL_FISIER +
                    tip_combustibil + SEPARATOR_PRINCIPAL_FISIER;

    return output;
}

istream& operator>>(istream& is, Autovehicul& autovehicul)
{
    cout << "Introduceti ID-ul autovehiculului: ";
    is >> autovehicul.id;

    cout << "Introduceti marca autovehiculului: ";
    is >> autovehicul.marca;

    cout << "Introduceti modelul autovehiculului: ";
    is >> autovehicul.model;

    cout << "Introduceti categoria autovehiculului: ";
    is >> autovehicul.categorie;

    cout << "Introduceti costul pe zi al autovehiculului: ";
    is >> autovehicul.cost_zi;

    cout << "Introduceti disponibilitatea autovehiculului (1 - disponibil, 0 - indisponibil): ";
    int disponibilValue;
    is >> disponibilValue;
    autovehicul.disponibil = (disponibilValue == 1);

    cout << "Introduceti capacitatea motorului autovehiculului: ";
    is >> autovehicul.capacitate_motor;

    cout << "Introduceti numarul de pasageri al autovehiculului: ";
    is >> autovehicul.nr_pasageri;

    cout << "Introduceti numarul de portiere al autovehiculului: ";
    is >> autovehicul.nr_portiere;

    cout << "Introduceti volumul portbagajului autovehiculului: ";
    is >> autovehicul.volum_portbagaj;

    cout << "Introduceti tipul de transmisie al autovehiculului: ";
    is >> autovehicul.transmisie;

    cout << "Introduceti daca autovehiculul are aer conditionat (1 - da, 0 - nu): ";
    int aerConditionatValue;
    is >> aerConditionatValue;
    autovehicul.aer_conditionat = (aerConditionatValue == 1);

    cout << "Introduceti tipul de combustibil al autovehiculului: ";
    is >> autovehicul.tip_combustibil;

    return is;
}