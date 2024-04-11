#include "repo.h"

#include <iostream>

int Repo::cautaRepo(const string& denumire, const string& profesor) {

	for (int i = 0; i < (int)this->discipline.getLungime(); ++i) {
		if (this->discipline[i].get_denumire() == denumire && this->discipline[i].get_profesor() == profesor) {
			return i;
		}
	}
	return -1;
}

void Repo::adaugaRepo(const Disciplina& disciplina) {

	const string& nume = disciplina.get_denumire();
	const string& profesor = disciplina.get_profesor();

	if (cautaRepo(nume, profesor) == -1) {
		this->discipline.push_back(disciplina);
	}
	else {
		throw RepoException("Disciplina deja exista!\n");
	}
}

void Repo::modificaRepo(const Disciplina& disciplina_noua) {

	const string& denumire = disciplina_noua.get_denumire();
	const string& profesor = disciplina_noua.get_profesor();
	int index = cautaRepo(denumire, profesor);

	if (index != -1) {
		this->discipline[index] = disciplina_noua;
	}
	else {
		throw RepoException("Disciplina nu exista!\n");
	}
}

void Repo::stergeRepo(const string& denumire, const string& profesor) {

	const int index = cautaRepo(denumire, profesor);
	if (index != -1) {
		this->discipline.erase(index);
	}
	else {
		throw RepoException("Disciplina nu exista!\n");
	}
}

const Disciplina& Repo::get_disciplina(const string& denumire, const string& profesor) {

	const int index = cautaRepo(denumire, profesor);

	if (index != -1) {
		return this->discipline[index];
	}
	else {
		throw RepoException("Disciplina nu exista!\n");
	}
}

const VectorDinamic<Disciplina>& Repo::getAll() const noexcept {
	return this->discipline;
}
