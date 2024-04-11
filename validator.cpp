#include "validator.h"

void Validator::valideazaDenumire(const string& denumire) {
	if (denumire.empty())
		throw ValidatorException("Denumire invalida!\n");
}

void Validator::valideazaOre(int ore) {
	if (ore <= 0) {
		throw ValidatorException("Numar de ore invalid!\n");
	}
}

void Validator::valideazaTip(const string& tip) {
	if (tip.empty())
		throw ValidatorException("Tip invalid!\n");
}

void Validator::valideazaProfesor(const string& profesor) {
	if (profesor.empty())
		throw ValidatorException("Numele profesorului este invalid!\n");
}

void Validator::valideazaDisciplina(const Disciplina& disciplina) {
	const string& denumire = disciplina.get_denumire();
	const int ore = disciplina.get_ore();
	const string& tip = disciplina.get_tip();
	const string& profesor = disciplina.get_profesor();
	string exceptii;

	try {
		valideazaDenumire(denumire);
	}
	catch (ValidatorException &mesaj) {
		exceptii += mesaj.get_mesaj();
	}

	try {
		valideazaOre(ore);
	}
	catch (ValidatorException& mesaj) {
		exceptii += mesaj.get_mesaj();
	}

	try {
		valideazaTip(tip);
	}
	catch (ValidatorException& mesaj) {
		exceptii += mesaj.get_mesaj();
	}

	try {
		valideazaProfesor(profesor);
	}
	catch (ValidatorException& mesaj) {
		exceptii += mesaj.get_mesaj();
	}

	if (!exceptii.empty()) {
		throw ValidatorException(exceptii);
	}

}