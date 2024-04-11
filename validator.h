#ifndef VALIDATOR_H_
#define VALIDATOR_H_

#include "exceptions.h"
#include "domain.h"

using std::string;

class Validator {
private:
	static void valideazaDenumire(const string& denumire);

	static void valideazaOre(int ore);

	static void valideazaTip(const string& tip);

	static void valideazaProfesor(const string& profesor);

public:
	static void valideazaDisciplina(const Disciplina& disciplina);
};

#endif /* VALIDATOR_H_ */
