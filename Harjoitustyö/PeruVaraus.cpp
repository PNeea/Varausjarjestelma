#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <sstream>
#include "PeruVaraus.h"
#include "VarausStruct.h"


using namespace std;


// Aliohjelma joka peruu varauksia
void PeruVaraus() {


	bool VarausLöytyi = false;
	string Poistettava;

	vector<varauksenTiedot> lista;

	ifstream input("Varaukset.txt");

	// Jos tiedostoa ei ole annetaan virhe
	if (!input.is_open()) {
		cout << "Tiedostoa ei löytynyt!" << endl;
		return;
	}

	// kysytään mikä varaus halutaan poistaa
	cout << "Minkä varauksen haluat poistaa?" << endl;
	cout << "Anna asiakasnumero tai varaajan nimi." << endl;
	cin >> Poistettava;

	if (!cin) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	if (input) {
		string rivi;

		// Haetaan varauksien tiedot
		while (getline(input, rivi)) {
			stringstream ss(rivi);
			string osa;
			int count = 0;
			varauksenTiedot t = {};


			while (getline(ss, osa, ';')) {
				count++;
				if (count == 1) {
					t.asiakasnumero = stoi(osa);
				}

				if (count == 2) {
					t.huoneenNumero = stoi(osa);
				}

				if (count == 3) {
					t.nimi = osa;
				}

				if (count == 4) {
					t.yöMäärä = stoi(osa);
				}

				if (count == 5) {
					t.hinta = stoi(osa);
				}

				if (count == 6) {
					t.summa = stoi(osa);
				}
			}

			lista.push_back(t);

		}

		input.close();

		// tarkistetaan että oikea kohde poistetaan ja poistetaan vain se
			for (int i = 0; i < lista.size(); i++) {

				if (Poistettava == (lista[i].nimi) || (Poistettava == to_string(lista[i].asiakasnumero))) {

					// Varmistetaan että käyttäjä on aivan varma poistamisesta
					cout << "Löytyi varaus: " << lista[i].nimi << endl;
					cout << "Haluatko varmasti poistaa varauksen?" << endl;
					cout << "Kyllä (k) tai Ei (e)" << endl;
					char vahvista;
					cin >> vahvista;

					// Jos vastaus on kyllä, varaus poistetaan
					if (vahvista == 'k' || vahvista == 'K') {
						lista.erase(lista.begin() + i);
						cout << "Varaus poistettiin." << endl;
						VarausLöytyi = true;
						break;
					}
					else {
						// Jos vastaus on ei, varausta ei poisteta
						cout << "Varausta ei poistettu." << endl;
					}

					break;
				}
			}

			// jos varausta ei löydy annetaan virhe
			if (VarausLöytyi == false) {
				cout << "Varausta ei löytynyt." << endl;
			}

			// kun varaus on poistettu jäljelle jäävät varaukset tallennetaan takaisin tiedostoon
			if (VarausLöytyi == true) {
				ofstream output("Varaukset.txt");

				for (auto& v : lista) {
					output
						<< v.asiakasnumero << ";"
						<< v.huoneenNumero << ";"
						<< v.nimi << ";"
						<< v.yöMäärä << ";"
						<< v.hinta << ";"
						<< v.summa << "\n";
				}
			}
	}
}

