#include "service.h"

void Service::adaugaSrv(const string& denumire, int ore, const string& tip, const string& profesor) {
	Disciplina disciplina{ denumire, ore, tip, profesor };

	validator.valideazaDisciplina(disciplina);
	repo.adaugaRepo(disciplina);
}


void Service::modificaSrv(const string& denumire, int ore, const string& tip, const string& profesor) {
	Disciplina disciplina{ denumire, ore, tip, profesor };

	validator.valideazaDisciplina(disciplina);
	repo.modificaRepo(disciplina);
}


void Service::stergeSrv(const string& denumire, const string& profesor) {
	repo.stergeRepo(denumire, profesor);
}


const Disciplina& Service::cautaSrv(const string& denumire, const string& profesor) {
	return repo.get_disciplina(denumire, profesor);
}


const VectorDinamic<Disciplina>& Service::getAll() noexcept {
	return this->repo.getAll();
}

VectorDinamic<Disciplina> Service::sort(bool(*cmpKey)(const Disciplina&, const Disciplina&)) {
	VectorDinamic<Disciplina> discipline{ repo.getAll() };
	if (cmpKey != nullptr) {
		int n = discipline.getLungime();
		for (int i = 0; i < n - 1; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (!cmpKey(discipline[i], discipline[j])) {
					// Swap the elements
					Disciplina aux = discipline[i];
					discipline[i] = discipline[j];
					discipline[j] = aux;
				}
			}
		}
	}
	return discipline;
}


VectorDinamic<Disciplina> Service::filter(const function<bool(const Disciplina&)>& fct) {
	VectorDinamic<Disciplina> rezultat;
	for (const auto& disciplina : repo.getAll()) {
		if (fct(disciplina)) {
			rezultat.push_back(disciplina);
		}
	}
	return rezultat;
}

VectorDinamic<Disciplina> Service::filterOre(int ore) {
	return filter([ore](const Disciplina& disciplina) {
		return disciplina.get_ore() == ore;
	});
}

VectorDinamic<Disciplina> Service::filterProfesor(const string& profesor) {
	return filter([profesor](const Disciplina& disciplina) {
		return disciplina.get_profesor() == profesor;
	});
}

VectorDinamic<Disciplina> Service::sortDenumire() {
	return sort(cmpDenumire);
}

VectorDinamic<Disciplina> Service::sortOre() {
	return sort(cmpOre);
}

VectorDinamic<Disciplina> Service::sortProfTip() {
	return sort(cmpProfTip);
}


