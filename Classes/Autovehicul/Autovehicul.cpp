#include "Autovehicul.h"
#include <iostream>
#include <string>
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

string Autovehicul::Info() const {
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
    cout << "Introduceti marca autovehiculului: ";
    cin.ignore();
    getline(is, autovehicul.marca);

    cout << "Introduceti modelul autovehiculului: ";
    getline(is, autovehicul.model);

    int optiune = -1;
    cout << "Selectati categoria autovehiculului: " << endl;
    cout << "1. Compact" << endl;
    cout << "2. Berlina" << endl;
    cout << "3. Break" << endl;
    cout << "4. SUV" << endl;
    cout << "5. Coupe" << endl;
    cout << "6. Cabrio" << endl;
    cout << "Introduceti o optiune... ";
    while (optiune < 1 || optiune > 6) {
        is >> optiune;

        switch (optiune) {
            case 1:
                autovehicul.categorie = "Compact";
                break;
            case 2:
                autovehicul.categorie = "Berlina";
                break;
            case 3:
                autovehicul.categorie = "Break";
                break;
            case 4:
                autovehicul.categorie = "SUV";
                break;
            case 5:
                autovehicul.categorie = "Coupe";
                break;
            case 6:
                autovehicul.categorie = "Cabrio";
                break;
            default:
                cout << "Optiune invalida. Va rugam selectati o optiune valida... ";
                break;
        }
    }

    cout << "Introduceti costul pe zi al autovehiculului (RON): ";
    is >> autovehicul.cost_zi;

    optiune = -1;
    cout << "Selectati disponibilitatea autovehiculului: " << endl;
    cout << "0. Indisponibil" << endl;
    cout << "1. Disponibil" << endl;
    cout << "Introduceti o optiune... ";
    while (optiune < 0 || optiune > 1) {
        is >> optiune;

        switch (optiune) {
            case 0:
            case 1:
                break;
            default:
                cout << "Optiune invalida. Va rugam selectati o optiune valida... ";
                break;
        }
    }
    autovehicul.disponibil = (optiune == 1);

    cout << "Introduceti capacitatea motorului autovehiculului (cm^3): ";
    is >> autovehicul.capacitate_motor;

    cout << "Introduceti numarul de pasageri al autovehiculului: ";
    is >> autovehicul.nr_pasageri;

    cout << "Introduceti numarul de portiere al autovehiculului: ";
    is >> autovehicul.nr_portiere;

    cout << "Introduceti volumul portbagajului autovehiculului (L): ";
    is >> autovehicul.volum_portbagaj;

    optiune = -1;
    cout << "Selectati tipul de transmisie al autovehiculului: " << endl;
    cout << "1. Manuala" << endl;
    cout << "2. Automata" << endl;
    cout << "Introduceti o optiune... ";
    while (optiune < 1 || optiune > 2) {
        is >> optiune;

        switch (optiune) {
            case 1:
                autovehicul.transmisie = "Manuala";
                break;
            case 2:
                autovehicul.transmisie = "Automata";
                break;
            default:
                cout << "Optiune invalida. Va rugam selectati o optiune valida... ";
                break;
        }
    }

    optiune = -1;
    cout << "Selectati daca autovehiculul are aer conditionat: " << endl;
    cout << "0. Nu" << endl;
    cout << "1. Da" << endl;
    cout << "Introduceti o optiune... ";
    while (optiune < 0 || optiune > 1) {
        is >> optiune;

        switch (optiune) {
            case 0:
            case 1:
                break;
            default:
                cout << "Optiune invalida. Va rugam selectati o optiune valida... ";
                break;
        }
    }
    autovehicul.aer_conditionat = (optiune == 1);

    optiune = -1;
    cout << "Selectati tipul de combustibil al autovehiculului: " << endl;
    cout << "1. Benzina" << endl;
    cout << "2. Motorina" << endl;
    cout << "3. Electric" << endl;
    cout << "Introduceti o optiune... ";
    while (optiune < 1 || optiune > 3) {
        is >> optiune;

        switch (optiune) {
            case 1:
                autovehicul.tip_combustibil = "Benzina";
                break;
            case 2:
                autovehicul.tip_combustibil = "Motorina";
                break;
            case 3:
                autovehicul.tip_combustibil = "Electric";
                break;
            default:
                cout << "Optiune invalida. Va rugam selectati o optiune valida... ";
                break;
        }
    }

    return is;
}