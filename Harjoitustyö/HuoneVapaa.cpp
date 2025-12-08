#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include "HuoneVapaa.h"
#include "VarausStruct.h"


using namespace std;


//Aliohjelma joka tarkistaa että varattava huone on vapaa
bool HuoneVapaa(int huoneenNumero) {

	// Avataan varaus tiedosto, jos tiedostoa ei ole huone on vapaa
		ifstream input("Varaukset.txt");

		// Jos tiedostoa ei ole huone on vapaa
		if (!input) {
			return true;
		}
			string rivi;

			// Haetaan tiedostosta löytyykö valittua huonetta
			while (getline(input, rivi)) {
				stringstream ss(rivi);
				string osa;
				int count = 0;

				// Jos löytyy huone on varattu
				while (getline(ss, osa, ';')) {
					count++;
					if (count == 2 && stoi(osa) == (huoneenNumero)) {
						return false;
					}
				}
			}
			
			// Jos ei löydy, huone on vapaa
			return true;
}