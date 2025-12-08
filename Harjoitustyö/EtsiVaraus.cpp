#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include "EtsiVaraus.h"
#include "VarausStruct.h"


using namespace std;

// Aliohjelma, jolla etsitään tietty varaus
void EtsiVaraus() {

	string Haku;
	bool VarausLöytyi = false;

	// Avataan tiedosto, johon varaukset on tallennettu
	ifstream input("Varaukset.txt");

	// Jos tiedostoa ei ole annetaan virhe
	if (!input.is_open()) {
		cout << "Tiedostoa ei löytynyt!" << endl;
		return;
	}

	// kysytään millä halutaan hakea
	cout << "Minkä varauksen haluat tulostaa?" << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, Haku);

	if (input) {
		string rivi;
		varauksenTiedot t = {};

			// Haetaan varauksien tiedot
			while (getline(input, rivi)) {
				stringstream ss(rivi);
				string osa;
				int count = 0;

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

				string HakuUpper = Haku;
				string nimiUpper = t.nimi;

				// Muutetaan nimet isoiksi kirjaimiksi, jotta voidaan hakea riippumatta kirjainkoosta.
				for (char& merkki : HakuUpper) {
					merkki = toupper((unsigned char)merkki);
				}
				for (char& merkki : nimiUpper) {
					merkki = toupper((unsigned char)merkki);
				}

				// Verrataan haluttua nimeä tai asiakasnumeroa ja tulostetaan vain sen tiedot
				if (nimiUpper.find(HakuUpper) != string::npos || Haku == to_string(t.asiakasnumero)) {
					cout << "\nAsiakasnumero on: " << t.asiakasnumero << endl;
					cout << "Huoneen numero on: " << t.huoneenNumero << endl;
					cout << "Varaajan nimi on: " << t.nimi << endl;
					cout << "Haluttu öiden määrä on: " << t.yöMäärä << endl;
					cout << "Yhden yön summa on: " << t.hinta << endl;
					cout << "Koko laskun summa on: " << t.summa << endl;

					VarausLöytyi = true;
				}
			}
			 // Jos varausta ei löydy annetaan virhe
			if (VarausLöytyi == false) {
				cout << "\nVarausta ei löytynyt." << endl;
			}
	}
}



	
	

