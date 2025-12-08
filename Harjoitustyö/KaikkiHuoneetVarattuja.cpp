#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include "KaikkiHuoneetVarattuja.h"
#include "VarausStruct.h"


using namespace std;


//Aliohjelma joka tarkistaa ett‰ huoneita on vapaana
bool KaikkiHuoneetVarattuja(int HuoneidenM‰‰r‰) {
	

	// Avataan varaus tiedosto, jos tiedostoa ei ole huoneet ovat vapaina
	ifstream input("Varaukset.txt");


	// Jos tiedostoa ei ole huoneita on vapaana
	if (!input) {
		return false;
	}

	string rivi;
	int count = 0;

	// Haetaan tiedostosta kuinka monta rivi‰ siin‰ on
	while (getline(input, rivi)) {
		if (!rivi.empty())
			count++;
	}

	// Jos rivej‰ on yli huoneiden max m‰‰r‰n hotelli on t‰ynn‰
	return count >= HuoneidenM‰‰r‰;
}