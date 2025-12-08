#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include "NäytäKaikkiVaraukset.h"
#include "VarausStruct.h"


using namespace std;


// Aliohjelma joka tulostaa kaikki varaukset
void NäytäKaikkiVaraukset() {


	// Avataan tiedosto, johon varaukset on tallennettu
	ifstream input("Varaukset.txt");

	// Jos tiedostoa ei löydy annetaan virhe
	if (!input.is_open()) {
		cout << "Tiedostoa ei löytynyt!" << endl;
		return;
	}

	if (input) {
		string rivi;
		varauksenTiedot t = {};

		//Haetaan eri osat ja tulostetaan ne
		while (getline(input, rivi)) {
			stringstream ss(rivi);
			string osa;
			int count = 0;

			// asiakasnumero
			while (getline(ss, osa, ';')) {
				count++;
				if (count == 1) {
					t.asiakasnumero = stoi(osa);
					cout << "Asiakasnumero on: " << t.asiakasnumero << endl;
				}

				// Huoneen numero
				if (count == 2) {
					t.huoneenNumero = stoi(osa);
					cout << "Huoneen numero on: " << t.huoneenNumero << endl;
				}

				// Varaajan nimi		
				if (count == 3) {
					t.nimi = osa;
					cout << "Varaajan nimi on: " << t.nimi << endl;
				}

				// Öiden määrä			
				if (count == 4) {
					t.yöMäärä = stoi(osa);
					cout << "Haluttu öiden määrä on: " << t.yöMäärä << endl;
				}

				// Yhden yön hinta			
				if (count == 5) {
					t.hinta = stoi(osa);
					cout << "Yhden yön hinta on: " << t.hinta << endl;
				}

				// koko laskun summa			
				if (count == 6) {
					t.summa = stoi(osa);
					cout << "Koko laskun summa on: " << t.summa << endl;
				}
			}

			cout << "\n" << endl;

		}
	}
}