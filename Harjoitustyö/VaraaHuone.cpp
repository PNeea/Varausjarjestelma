#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include "VaraaHuone.h"
#include "HuoneVapaa.h"
#include "KaikkiHuoneetVarattuja.h"
#include "VarausStruct.h"


using namespace std;


//Aliohjelma jolla varataan huone
void VaraaHuone(int HuoneidenMäärä) {

	varauksenTiedot t;

	bool aNumeroVarattu;
	int valinta;
	bool KäyttäjäValitsee;


	// Jos kaikki huoneet on varattu käyttäjä saa virheen
	if (KaikkiHuoneetVarattuja(HuoneidenMäärä)) {
		cout << "Kaikki huoneet ovat varattuina." << endl;
		cout << "Ohjelma lopetetaan." << endl;
		exit(0);
	}


	// Arvotaan asiakasnumero
	t.asiakasnumero = 10000 + rand() % 90000;
	cout << "Asiakasnumero on: " << t.asiakasnumero << endl;

	// Tarkistetaan ettei samaa asiakasnumeroa anneta kahdelle asiakkaalle
	do {
		aNumeroVarattu = false;

		ifstream input("Varaukset.txt");
		if (input) {
			string rivi;


			while (getline(input, rivi)) {
				stringstream ss(rivi);
				string osa;
				int count = 0;


				while (getline(ss, osa, ';')) {
					count++;
					if (count == 1 && stoi(osa) == (t.asiakasnumero)) {
						aNumeroVarattu = true;
						break;
					}
				}
				if (aNumeroVarattu == false)
					break;
			}
			// Jos asiakasnumero on jo olemassa arvotaan uusi
			if (aNumeroVarattu == true) {
				cout << "Asiakasnumero " << t.asiakasnumero << " on jo varattu." << endl;
				cout << "\nArvotaan uusi numero: ";
				t.asiakasnumero = 10000 + rand() % 90000;
				cout << "\nUusi asiakasnumero on: " << endl;
			}
		}
	} while (aNumeroVarattu);

	bool Hyväksytään = false;

	while (Hyväksytään == false) {
		// Käyttäjä voi valita haluaako hän valita huoneen numeron itse, vai arvotaanko se
		cout << "\nMiten haluat varata huoneen?" << endl;
		cout << "Valitse itse (1)" << endl;
		cout << "Arvo huone (2)" << endl;
		cin >> valinta;

		// Jos virheellinen toiminto syötetään saadaan virhe
		if (!cin) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Virheellinen toiminto syötetty.";
		}

		// käyttäjä valitsee huoneen numeron itse
		if (valinta == 1) {
			KäyttäjäValitsee = true;
			cout << "\nValitse huoneen numero (1-" << HuoneidenMäärä << ")." << endl;
			cin >> t.huoneenNumero;
			Hyväksytään = true;

			if (t.huoneenNumero < 1 || t.huoneenNumero > HuoneidenMäärä) {
				cout << "Valitse huone väliltä 1-" << HuoneidenMäärä << "." << endl;
				Hyväksytään = false;
			}
		}

		// käyttäjä haluaa että huone arvotaan
		else if (valinta == 2) {
			KäyttäjäValitsee = false;
			cout << "\nArvotaan huone." << endl;
			t.huoneenNumero = rand() % HuoneidenMäärä + 1;
			cout << "Huoneen numero on: " << t.huoneenNumero << endl;
			Hyväksytään = true;
		}
	}

	// Varmistetaan ettei samaa huonetta varata kahdesti
	// Jos huone on jo varattu pyydetään/arvotaan uusi
	while (!HuoneVapaa(t.huoneenNumero)) {
		if (KäyttäjäValitsee == true) {
			cout << "Huone " << t.huoneenNumero << " on jo varattu." << endl;

			while (true) {
				cout << "Valitse uusi huone: ";
				cin >> t.huoneenNumero;

				// Jos virheellinen toiminto syötetään saadaan virhe
				if (!cin) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Virheellinen huoneen numero annettu. Anna huoneen numero uudelleen." << endl;
					continue;
				}

				if (t.huoneenNumero < 1 || t.huoneenNumero > HuoneidenMäärä) {
					cout << "Valitse uusi huone (1-" << HuoneidenMäärä << ")" << endl;
					continue;
				}

				break;
			}
		}
		else if (KäyttäjäValitsee == false) {
			cout << "Huone " << t.huoneenNumero << " on jo varattu." << endl;
			cout << "Arvotaan uusi huone: " << endl;
			t.huoneenNumero = rand() % HuoneidenMäärä + 1;
			cout << "Uusi huone on: " << t.huoneenNumero << endl;
		}
	}

	bool nimiOK = true;
	// Tyhjennetään syöte ettei siihen jää mitään
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	while (true) {

		// Kysytään käyttäjältä varaajan nimi
		cout << "\nAnna varaajan nimi: " << endl;
		getline(cin, t.nimi);

		// Tarkistetaan että nimi on sallittu, ei sisällä numeroita
		for (unsigned char c : t.nimi) {
			if (!isalpha(c) && c != ' ' && c != '-') {
				nimiOK = false;
			}
		}

		if (nimiOK == true) {
			break;
		}

		// Jos nimi on virheellinen pyydetään uutta
		if (nimiOK == false) {
			cout << "Virheellinen nimi. Anna nimi uudelleen.";
			nimiOK = true;
			continue;
		}
	}

	// kysytään kuinka monta yötä käyttäjä haluaa olla
	while (1) {
		cout << "\nKuinka monta yötä olet?" << endl;
		cin >> t.yöMäärä;

		if (!cin) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		// Yö määrä voidaan valita 1 ja 1000 väliltä
		if (t.yöMäärä < 1 || t.yöMäärä > 1000) {
			cout << "Virheellinen yö määrä valittu." << endl;
			cout << "Anna yö määrä uudestaan." << endl;
		}
		else
			break;
	}


	// Määritellään hinnat
	t.hinta = 80 + rand() % 21;
	t.summa = t.hinta * t.yöMäärä;


	// Tulostetaan varauksen tiedot
	cout << "\nVarauksen tiedot: \n";

	cout << "Asiakasnumero: " << t.asiakasnumero << endl;
	cout << "Huoneen numero on: " << t.huoneenNumero << endl;
	cout << "Varaajan nimi: " << t.nimi << endl;;
	cout << "Haluttu öiden määrä: " << t.yöMäärä << endl;
	cout << "Yhden yön hinta on: " << t.hinta << endl;
	cout << "Laskun summa on: " << t.summa << endl;
	cout << endl;


	// Tallennetaan koko varaus tiedostoon
	ofstream Varaukset;

	// Jokainen varaus tallennetaan omalle rivilleen
	Varaukset.open("Varaukset.txt", ios::app);

	if (!Varaukset.is_open()) {
		cout << "Tiedostoa ei löytynyt!" << endl;
	}
	else
		cout << "Varaus tallennettu!" << endl;

	// Varauksen tiedot erotellaan ; -merkillä
	Varaukset << t.asiakasnumero << ";" << t.huoneenNumero << ";" << t.nimi << ";" << t.yöMäärä << ";" << t.hinta << ";" << t.summa << endl;
	cout << "\n";

	Varaukset.close();


}
