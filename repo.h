#ifndef REPO_H_
#define REPO_H_

#include "vectorDinamic.h"
#include "domain.h"
#include "exceptions.h"

#include <vector>
#include <string>

using std::vector;
using std::string;

class Repo {
private:
	//vectorul nostru
	VectorDinamic<Disciplina> discipline;

public:

	explicit Repo(const VectorDinamic<Disciplina>& discipline) :discipline{ discipline } {};

	/*
	* adaugam discipline la lista de obiecte
	* 
	* param: disciplina
	* arunca exceptii daca exista deja un obiect egal cu disciplina
	*/
	void adaugaRepo(const Disciplina& disciplina);

	/*
	* modificam o disciplina din lista de obiecte
	* 
	* param: disciplina_noua
	* arunca exceptii daca nu exista obiectul de modificat
	*/
	void modificaRepo(const Disciplina& disciplina_noua);

	/*
	* stergem o disciplina din lista de obiecte
	* 
	* param: denumirea disciplinei + numele profesorului
	* arunca exceptii daca nu gaseste disciplina de sters
	*/
	void stergeRepo(const string& denumire, const string& profesor);

	/*
	* cauta o disciplina in lista de obiecte
	* 
	* param: denumirea disciplinei + numele profesorului
	* returns: i != -1 daca disciplina exista (indexul)
	*		   i = -1 daca disciplina NU exista
	*/
	int cautaRepo(const string& denumire, const string& profesor);

	/*
	* returneaza disciplina daca exista, altfel arunca exceptie
	*/
	const Disciplina& get_disciplina(const string& denumire, const string& profesor);

	/*
	* returneaza toate disciplinele salvate
	*/
	[[nodiscard]] const VectorDinamic<Disciplina>& getAll() const noexcept;

};

#endif /* REPO_H_ */
