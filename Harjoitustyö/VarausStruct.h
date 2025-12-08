#pragma once

#include <string>
#include <vector>


// Luodaan structi varaukselle
struct varauksenTiedot {

	int asiakasnumero = 0;
	int huoneenNumero = 0;
	std::string nimi = " ";
	int yöMäärä = 0;
	int hinta = 0;
	int summa = 0;

};

varauksenTiedot tallennaVaraus(
	int asiakasnumero,
	int huoneenNumero,
	std::string nimi,
	int yöMäärä,
	int hinta,
	int summa
);

// Luodaan oma struct huoneiden määrälle
struct huoneidenMäärä {
	int HuoneidenMäärä = 0;
};

huoneidenMäärä tallennaMäärä(
	int HuoneidenMäärä
);



