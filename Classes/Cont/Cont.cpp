#include "Cont.h"

Cont::Cont(string email, string parola, string tip_cont) {
    this->email = email;
    this->parola = parola;
    this->tip_cont = tip_cont;
}

Cont::Cont(int _ignore_, string linieFisier) {
    vector<string> dateFisier = split(linieFisier, SEPARATOR_PRINCIPAL_FISIER);
    if (dateFisier.size() < NR_CARACTERISTICI) {
        throw runtime_error("Date lipsa! linieFisier: " + linieFisier );
    }

    email = dateFisier[EMAIL];
    parola = dateFisier[PAROLA];
    tip_cont = dateFisier[TIP_CONT];
}

Cont::~Cont() {

}

string Cont::ConversieLaSir_PentruFisier() const {
    string output = email + SEPARATOR_PRINCIPAL_FISIER +
                    Utility::encryptString(parola) + SEPARATOR_PRINCIPAL_FISIER +
                    tip_cont + SEPARATOR_PRINCIPAL_FISIER;

    return output;
}

istream& operator>>(istream& is, Cont& cont) {
    cout << "Introduceti email-ul: ";
    cin.ignore();
    getline(is, cont.email);

    cout << "Introduceti parola: ";
    getline(is, cont.parola);

    return is;
}

void Cont::citireContExistent() {
    string input;

    cout << "Introduceti email-ul (default: " << email << "): ";
    cin.ignore();
    getline(cin, input);
    if (!input.empty()) {
        email = input;
    }

    cout << "Introduceti parola ('ENTER' pentru a nu o modifica): ";
    getline(cin, input);
    if (!input.empty()) {
        parola = input;
    }

    cout << "(Tip cont actual: " << tip_cont << ")\n";
    tip_cont = Cont::selecteazaTipCont();

}

string Cont::selecteazaTipCont() {
    int optiune = -1;
    string tip_cont;

    cout << "Selectati tipul contului: " << endl;
    cout << "1. Client" << endl;
    cout << "2. Angajat" << endl;
    cout << "3. Administrator" << endl;
    cout << "Introduceti o optiune... ";
    while (optiune < 1 || optiune > 3) {
        cin >> optiune;

        switch (optiune) {
            case 1:
                tip_cont = "Client";
                break;
            case 2:
                tip_cont = "Angajat";
                break;
            case 3:
                tip_cont = "Administrator";
                break;
            default:
                cout << "Optiune invalida. Va rugam selectati o optiune valida... ";
                break;
        }
    }

    return tip_cont;
}
