#include "Autovehicul.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Autovehicul::Autovehicul(int id, string marca, string model, string categorie, int cost_zi, bool disponibil,
               int capacitate_motor, int nr_locuri, int nr_portiere, int volum_portbagaj, string transmisie,
               bool aer_conditionat, string tip_combustibil) {
    this->id = id;
    this->marca = marca;
    this->model = model;
    this->categorie = categorie;
    this->cost_zi = cost_zi;
    this->disponibil = disponibil;
    this->capacitate_motor = capacitate_motor;
    this->nr_locuri = nr_locuri;
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
    nr_locuri = stoi(dateFisier[NR_LOCURI]);
    nr_portiere = stoi(dateFisier[NR_PORTIERE]);
    volum_portbagaj = stoi(dateFisier[VOLUM_PORTBAGAJ]);
    transmisie = dateFisier[TRANSMISIE];
    aer_conditionat = stoi(dateFisier[AER_CONDITIONAT]);
    tip_combustibil = dateFisier[TIP_COMBUSTIBIL];
}

Autovehicul::~Autovehicul() {}

string Autovehicul::Info() const {
    string info = "ID: " + (id == -1 ? "N/A" : to_string(id)) + "\n";
    info += "Marca: " + marca + "\n";
    info += "Model: " + model + "\n";
    info += "Categorie: " + categorie + "\n";
    info += "Cost pe zi: " + to_string(cost_zi) + "\n";
    string disponibil_str = (disponibil ? "Da" : "Nu");
    info += "Disponibil: " + disponibil_str + "\n";
    info += "Capacitate motor: " + to_string(capacitate_motor) + "\n";
    info += "Numar locuri: " + to_string(nr_locuri) + "\n";
    info += "Numar portiere: " + to_string(nr_portiere) + "\n";
    info += "Volum portbagaj: " + to_string(volum_portbagaj) + "\n";
    info += "Transmisie: " + transmisie + "\n";
    string aer_conditionat_str = (aer_conditionat ? "Da" : "Nu");
    info += "Aer conditionat: " + aer_conditionat_str + "\n";
    info += "Tip combustibil: " + tip_combustibil + "\n";

    return info;
}

string Autovehicul::ConversieLaSir_PentruFisier() const {
    string output = to_string(id) + SEPARATOR_PRINCIPAL_FISIER +
                    marca + SEPARATOR_PRINCIPAL_FISIER +
                    model + SEPARATOR_PRINCIPAL_FISIER +
                    categorie + SEPARATOR_PRINCIPAL_FISIER +
                    to_string(cost_zi) + SEPARATOR_PRINCIPAL_FISIER +
                    (disponibil ? "1" : "0") + SEPARATOR_PRINCIPAL_FISIER +
                    to_string(capacitate_motor) + SEPARATOR_PRINCIPAL_FISIER +
                    to_string(nr_locuri) + SEPARATOR_PRINCIPAL_FISIER +
                    to_string(nr_portiere) + SEPARATOR_PRINCIPAL_FISIER +
                    to_string(volum_portbagaj) + SEPARATOR_PRINCIPAL_FISIER +
                    transmisie + SEPARATOR_PRINCIPAL_FISIER +
                    (aer_conditionat ? "1" : "0") + SEPARATOR_PRINCIPAL_FISIER +
                    tip_combustibil + SEPARATOR_PRINCIPAL_FISIER;

    return output;
}

string Autovehicul::selecteazaCategorieAutovehicul() {
    int optiune = -1;
    string categorie;

    cout << "Selectati categoria autovehiculului: " << endl;
    cout << "1. Compact" << endl;
    cout << "2. Berlina" << endl;
    cout << "3. Break" << endl;
    cout << "4. SUV" << endl;
    cout << "5. Coupe" << endl;
    cout << "6. Cabrio" << endl;
    cout << "Introduceti o optiune... ";

    while (optiune < 1 || optiune > 6) {
        cin >> optiune;

        switch (optiune) {
            case 1:
                categorie = "Compact";
                break;
            case 2:
                categorie = "Berlina";
                break;
            case 3:
                categorie = "Break";
                break;
            case 4:
                categorie = "SUV";
                break;
            case 5:
                categorie = "Coupe";
                break;
            case 6:
                categorie = "Cabrio";
                break;
            default:
                cout << "Optiune invalida. Va rugam selectati o optiune valida... ";
                break;
        }
    }

    return categorie;
}

bool Autovehicul::selecteazaDisponibilitateAutovehicul() {
    int optiune = -1;
    bool disponibil;

    cout << "Selectati disponibilitatea autovehiculului: " << endl;
    cout << "1. Disponibil" << endl;
    cout << "2. Indisponibil" << endl;
    cout << "Introduceti o optiune... ";
    while (optiune < 1 || optiune > 2) {
        cin >> optiune;

        switch (optiune) {
            case 1:
                disponibil = true;
                break;
            case 2:
                disponibil = false;
                break;
            default:
                cout << "Optiune invalida. Va rugam selectati o optiune valida... ";
                break;
        }
    }

    return disponibil;
}

string Autovehicul::selecteazaTransmisieAutovehicul() {
    int optiune = -1;
    string transmisie;

    cout << "Selectati tipul de transmisie al autovehiculului: " << endl;
    cout << "1. Manuala" << endl;
    cout << "2. Automata" << endl;
    cout << "Introduceti o optiune... ";
    while (optiune < 1 || optiune > 2) {
        cin >> optiune;

        switch (optiune) {
            case 1:
                transmisie = "Manuala";
                break;
            case 2:
                transmisie = "Automata";
                break;
            default:
                cout << "Optiune invalida. Va rugam selectati o optiune valida... ";
                break;
        }
    }

    return transmisie;
}

bool Autovehicul::selecteazaAerConditionatAutovehicul() {
    int optiune = -1;
    bool aerConditionat;

    cout << "Selectati daca autovehiculul are aer conditionat: " << endl;
    cout << "1. Da" << endl;
    cout << "2. Nu" << endl;
    cout << "Introduceti o optiune... ";
    while (optiune < 1 || optiune > 2) {
        cin >> optiune;

        switch (optiune) {
            case 1:
                aerConditionat = true;
                break;
            case 2:
                aerConditionat = false;
                break;
            default:
                cout << "Optiune invalida. Va rugam selectati o optiune valida... ";
                break;
        }
    }

    return aerConditionat;
}

string Autovehicul::selecteazaCombustibilAutovehicul() {
    int optiune = -1;
    string combustibil;

    cout << "Selectati tipul de combustibil al autovehiculului: " << endl;
    cout << "1. Benzina" << endl;
    cout << "2. Motorina" << endl;
    cout << "3. Electric" << endl;
    cout << "Introduceti o optiune... ";
    while (optiune < 1 || optiune > 3) {
        cin >> optiune;

        switch (optiune) {
            case 1:
                combustibil = "Benzina";
                break;
            case 2:
                combustibil = "Motorina";
                break;
            case 3:
                combustibil = "Electric";
                break;
            default:
                cout << "Optiune invalida. Va rugam selectati o optiune valida... ";
                break;
        }
    }

    return combustibil;
}

istream& operator>>(istream& is, Autovehicul& autovehicul)
{
    string input;
    int int_input;
    cout << "Introduceti marca autovehiculului: ";
    is.ignore();
    getline(is, autovehicul.marca);

    cout << "Introduceti modelul autovehiculului: ";
    getline(is, autovehicul.model);

    cout << endl;
    autovehicul.categorie = Autovehicul::selecteazaCategorieAutovehicul();

    cout << endl << "Introduceti costul pe zi al autovehiculului (RON): ";
    is >> input;
    while(!Utility::validareDoarCifre(input)) {
        cout << "Raspunsul trebuie sa contina doar cifre, reintroduceti raspunsul...";
        is >> input;
    }
    int_input = stoi(input);
    autovehicul.cost_zi = int_input;

    cout << endl;
    autovehicul.disponibil = Autovehicul::selecteazaDisponibilitateAutovehicul();

    cout << endl << "Introduceti capacitatea motorului autovehiculului (cm^3): ";
    is >> input;
    while(!Utility::validareDoarCifre(input)) {
        cout << "Raspunsul trebuie sa contina doar cifre, reintroduceti raspunsul...";
        is >> input;
    }
    int_input = stoi(input);
    autovehicul.capacitate_motor = int_input;

    cout << "Introduceti numarul de locuri al autovehiculului: ";
    is >> input;
    while(!Utility::validareDoarCifre(input)) {
        cout << "Raspunsul trebuie sa contina doar cifre, reintroduceti raspunsul...";
        is >> input;
    }
    int_input = stoi(input);
    autovehicul.nr_locuri = int_input;

    cout << "Introduceti numarul de portiere al autovehiculului: ";
    is >> input;
    while(!Utility::validareDoarCifre(input)) {
        cout << "Raspunsul trebuie sa contina doar cifre, reintroduceti raspunsul...";
        is >> input;
    }
    int_input = stoi(input);
    autovehicul.nr_portiere = int_input;

    cout << "Introduceti volumul portbagajului autovehiculului (L): ";
    is >> input;
    while(!Utility::validareDoarCifre(input)) {
        cout << "Raspunsul trebuie sa contina doar cifre, reintroduceti raspunsul...";
        is >> input;
    }
    int_input = stoi(input);
    autovehicul.volum_portbagaj = int_input;

    cout << endl;
    autovehicul.transmisie = Autovehicul::selecteazaTransmisieAutovehicul();

    cout << endl;
    autovehicul.aer_conditionat = Autovehicul::selecteazaAerConditionatAutovehicul();

    cout << endl;
    autovehicul.tip_combustibil = Autovehicul::selecteazaCombustibilAutovehicul();

    return is;
}

ostream& operator<<(ostream& os, Autovehicul& autovehicul)
{
    os << autovehicul.Info();
    return os;
}

void Autovehicul::citireAutovehiculExistent() {
    string input = "0";

    cout << "Introduceti marca autovehiculului (default: " << marca << "): ";
    cin.ignore();
    getline(cin, input);
    if (!input.empty()) {
        marca = input;
    }

    cout << "Introduceti modelul autovehiculului (default: " << model << "): ";
    getline(cin, input);
    if (!input.empty()) {
        model = input;
    }

    cout << endl << "(Se va inlocui urmatoarea categorie: " << categorie << ")\n";
    categorie = Autovehicul::selecteazaCategorieAutovehicul();

    cout << endl << "Introduceti costul pe zi al autovehiculului (RON) (default: " << to_string(cost_zi) << "): ";
    cin.ignore();
    getline(cin, input);
    while(!Utility::validareDoarCifre(input) && !input.empty()) {
        cout << "Raspunsul trebuie sa contina doar cifre, reintroduceti raspunsul...";
        getline(cin, input);
    }
    if (!input.empty()) {
        cost_zi = stoi(input);
    }

    cout << endl << "(Anterior autovehiculul" << (!disponibil ? " nu" : "" ) << " era disponibil)\n";
    disponibil = Autovehicul::selecteazaDisponibilitateAutovehicul();

    cout << endl << "Introduceti capacitatea motorului autovehiculului (cm^3) (default: " << to_string(capacitate_motor) << "): ";
    cin.ignore();
    getline(cin, input);
    while(!Utility::validareDoarCifre(input) && !input.empty()) {
        cout << "Raspunsul trebuie sa contina doar cifre, reintroduceti raspunsul...";
        getline(cin, input);
    }
    if (!input.empty()) {
        capacitate_motor = stoi(input);
    }

    cout << "Introduceti numarul de locuri al autovehiculului (default: " << to_string(nr_locuri) << "): ";
    getline(cin, input);
    while(!Utility::validareDoarCifre(input) && !input.empty()) {
        cout << "Raspunsul trebuie sa contina doar cifre, reintroduceti raspunsul...";
        getline(cin, input);
    }
    if (!input.empty()) {
        nr_locuri = stoi(input);
    }

    cout << "Introduceti numarul de portiere al autovehiculului (default: " << to_string(nr_portiere) << "): ";
    getline(cin, input);
    while(!Utility::validareDoarCifre(input) && !input.empty()) {
        cout << "Raspunsul trebuie sa contina doar cifre, reintroduceti raspunsul...";
        getline(cin, input);
    }
    if (!input.empty()) {
        nr_portiere = stoi(input);
    }

    cout << "Introduceti volumul portbagajului autovehiculului (L) (default: " << to_string(volum_portbagaj) << "): ";
    getline(cin, input);
    while(!Utility::validareDoarCifre(input) && !input.empty()) {
        cout << "Raspunsul trebuie sa contina doar cifre, reintroduceti raspunsul...";
        getline(cin, input);
    }
    if (!input.empty()) {
        volum_portbagaj = stoi(input);
    }

    cout << endl << "(Se va inlocui urmatoarea transmisie: " << transmisie << ")\n";
    transmisie = Autovehicul::selecteazaTransmisieAutovehicul();

    cout << endl << "(Anterior autovehiculul" << (!aer_conditionat ? " nu" : "" ) << " avea aer conditionat)\n";
    aer_conditionat = Autovehicul::selecteazaAerConditionatAutovehicul();

    cout << endl << "(Se va inlocui urmatoarul tip de combustibil: " << tip_combustibil << ")\n";
    tip_combustibil = Autovehicul::selecteazaCombustibilAutovehicul();
}