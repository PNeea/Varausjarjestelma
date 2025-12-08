// P‰‰valikko

// Sis‰llytet‰‰n aliohjelmat p‰‰valikkoon
#include <iostream>
#include <fstream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include "VaraaHuone.h"
#include "TulostaVaraus.h"
#include "EtsiVaraus.h"
#include "PeruVaraus.h"
#include "N‰yt‰KaikkiVaraukset.h"
#include "VarausStruct.h"


using namespace std;


//P‰‰ohjelma, joka kutsuu muita ohjelmia
int main() {

	// M‰‰ritell‰‰n kieliasetukset ja randomisoija
	setlocale(LC_ALL, "FI_fi");
	srand(time(0));

	int toiminto;

	varauksenTiedot t;
	huoneidenM‰‰r‰ h;

	// Tulostetaan otsikko
	cout << "----------------------------------" << endl;
	cout << "\n	Hotellin p‰‰valikko" << endl;
	cout << "\n----------------------------------" << endl;
	

	// Luodaan tiedosto hotellin huoneiden m‰‰r‰lle
	ifstream input("HuoneidenM‰‰r‰.txt");

	// Jos tiedosto on olemassa luetaan huoneiden m‰‰r‰ sielt‰
	if (input.is_open()) {
		input >> h.HuoneidenM‰‰r‰;
		cout << "\nHotellissa on " << h.HuoneidenM‰‰r‰ << " huonetta." << endl;
	}
	else {
		// jos tiedostoa ei ole arvotaan huoneiden m‰‰r‰
		h.HuoneidenM‰‰r‰ = 30 + rand() % 41;
		cout << "\nHotellissa on " << h.HuoneidenM‰‰r‰ << " huonetta." << endl;

		// Tallennetaan huoneiden m‰‰r‰ tiedostoon
		ofstream output;

		output.open("HuoneidenM‰‰r‰.txt");
		output << h.HuoneidenM‰‰r‰;

		// Jos tiedostoa ei ole  annetaan virhe
		if (!output.is_open()) {
			cout << "Tiedostoa ei lˆytynyt!" << endl;
		}
	}
	

	while (true)
	{
		// Esitell‰‰n mahdolliset toiminnot
		cout << "\n 1. Varaa Huone \n 2. N‰yt‰ uusin varaus \n 3. Etsi varaus \n 4. Peru varaus \n 5. N‰yt‰ kaikki varaukset" << endl;
		cout << "\n(0 lopettaa ohjelman)" << endl;
		cout << "\n----------------------------------" << endl;

		//Pyydet‰‰n k‰ytt‰j‰‰ syˆtt‰m‰‰n haluttu toiminto
		cout << "\nSyˆt‰ haluttu toiminto: ";
		cin >> toiminto;

		cout << "\n";

		// Tyhjennet‰‰n syˆte, jos virheellinen syˆte on annettu
		if (!cin) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Virheellinen toiminto syˆtetty." << endl;
		}

		// 0 painamalla ohjelma lopetetaan
		if (toiminto == 0) {
			cout << "Ohjelma lopetetaan." << endl;
			break;
		}

		// switch case rakenne, jolla kutsutaan eri toimintoja
		switch (toiminto)
		{

		case 1:
			VaraaHuone(h.HuoneidenM‰‰r‰);
			break;
		case 2:
			TulostaVaraus();
			break;
		case 3:
			EtsiVaraus();
			break;
		case 4:
			PeruVaraus();
			break;
		case 5:
			N‰yt‰KaikkiVaraukset();
			break;

		default: break;
		}

		cout << "\n----------------------------------" << endl;
	}

	return 0;

}
