
#include "VarausStruct.h"

// Määritellään varauksen muuttujat
varauksenTiedot tallennaVaraus(
	int asiakasnumero,
	int huoneenNumero,
	std::string nimi,
	int yöMäärä,
	int hinta,
	int summa
) {
	varauksenTiedot t;

	t.asiakasnumero = asiakasnumero;
	t.huoneenNumero = huoneenNumero;
	t.nimi = nimi;
	t.yöMäärä = yöMäärä;
	t.hinta = hinta;
	t.summa = summa;

	return t;
};

// Määritellään huoneiden määrän muuttuja
huoneidenMäärä tallennaMäärä(
	int HuoneidenMäärä
) {
	huoneidenMäärä h;

	h.HuoneidenMäärä = HuoneidenMäärä;

	return h;
}