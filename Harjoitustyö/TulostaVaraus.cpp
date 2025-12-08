#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include <sstream>
#include "TulostaVaraus.h"
#include "VarausStruct.h"


using namespace std;


// Aliohjelma joka tulostaa uusimman varauksen
void TulostaVaraus() {

	vector<varauksenTiedot> lista;

	string Haku;
	bool VarausLöytyi = false;


	// Avataan tiedosto, johon varaukset on tallennettu
	ifstream input("Varaukset.txt");

	// Jos tiedostoa ei löydy annetaan virhe
	if (!input.is_open()) {
		cout << "Tiedostoa ei löytynyt!" << endl;
		return;
	}

	if (input) {
		string rivi;

		// Haetaan varauksen tiedot
		while (getline(input, rivi)) {
			stringstream ss(rivi);
			string osa;
			int count = 0;
			varauksenTiedot t = {};

			// asiakasnumero
			while (getline(ss, osa, ';')) {
				count++;
				if (count == 1) {
					t.asiakasnumero = stoi(osa);
				}

				// Huoneen numero
				if (count == 2) {
					t.huoneenNumero = stoi(osa);
				}

				// Varaajan nimi
				if (count == 3) {
					t.nimi = osa;
				}

				// Öiden määrä
				if (count == 4) {
					t.yöMäärä = stoi(osa);
				}

				// Yhden yön hinta
				if (count == 5) {
					t.hinta = stoi(osa);
				}

				// koko laskun summa
				if (count == 6) {
					t.summa = stoi(osa);
				}
			}

			lista.push_back(t);

		}

		// Viimeisin/uusin varaus tulostetaan
			if (!lista.empty()) {

				varauksenTiedot viimeinen = lista.back();

				cout << "Uusin varaus tulostuu." << endl;

				cout << "\nAsiakasnumero on: " << viimeinen.asiakasnumero << endl;
				cout << "Huoneen numero on: " << viimeinen.huoneenNumero << endl;
				cout << "Varaajan nimi on: " << viimeinen.nimi << endl;
				cout << "Haluttu öiden määrä on: " << viimeinen.yöMäärä << endl;
				cout << "Yhden yön summa on: " << viimeinen.hinta << endl;
				cout << "Koko laskun summa on: " << viimeinen.summa << endl;

				VarausLöytyi = true;

			}
	}

	// Jos varausta ei löydy annetaan virhe
	if (VarausLöytyi == false) {
		cout << "\nVarausta ei löytynyt." << endl;
	}

}