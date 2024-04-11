#include "domain.h"

#include <iostream>

using namespace std;

// constructor implicit
Disciplina::Disciplina() noexcept{
	this->denumire = "";
	this->ore = 0;
	this->tip = "";
	this->profesor = "";
}

// constructorul disciplinei
Disciplina::Disciplina(const string& denumire, int ore, const string& tip, const string& profesor) {
	this->denumire = denumire;
	this->ore = ore;
	this->tip = tip;
	this->profesor = profesor;
}

// destructorul
Disciplina::~Disciplina() = default;

// copia constructorului
Disciplina::Disciplina(const Disciplina& disciplina) {
	this->denumire = disciplina.denumire;
	this->ore = disciplina.ore;
	this->tip = disciplina.tip;
	this->profesor = disciplina.profesor;
}


/// GETTERS

const string& Disciplina::get_denumire() const noexcept{
	return this->denumire;
}

int Disciplina::get_ore() const noexcept{
	return this->ore;
}

const string& Disciplina::get_tip() const noexcept{
	return this->tip;
}

const string& Disciplina::get_profesor() const noexcept{
	return this->profesor;
}


/// SETTERS

[[maybe_unused]] void Disciplina::set_ore(int ore_noi) noexcept{
	this->ore = ore_noi;
}

[[maybe_unused]] void Disciplina::set_tip(const string& tip_nou) {
	this->tip = tip_nou;
}

/// TO STRING PRINTARE

string Disciplina::to_string_print() {
	return "\t\033[1;33mDenumire: \033[0m" + this->denumire + ";   \033[1;33mOre: \033[0m" + to_string(this->ore) + 
		   ";   \033[1;33mTip: \033[0m" + this->tip + ";   \033[1;33mProfesor: \033[0m" + this->profesor + ".";
}


/// OPERATORI

Disciplina& Disciplina::operator=(const Disciplina& copie) = default;

bool Disciplina::operator==(const Disciplina& copie) noexcept{
	return this->denumire == copie.denumire && this->profesor == copie.profesor;
}


/// COMPARATORI

bool cmpDenumire(const Disciplina& disc_1, const Disciplina& disc_2) noexcept{
	if (disc_1.get_denumire() < disc_2.get_denumire()) {
		return true;
	}
	return false;
}

bool cmpOre(const Disciplina& disc_1, const Disciplina& disc_2) noexcept{
	if (disc_1.get_ore() < disc_2.get_ore()) {
		return true;
	}
	return false;
}

bool cmpProfesor(const Disciplina& disc_1, const Disciplina& disc_2) noexcept{
	if (disc_1.get_profesor() < disc_2.get_profesor()) {
		return true;
	}
	return false;
}

bool cmpProfTip(const Disciplina& disc_1, const Disciplina& disc_2) noexcept{
	if (disc_1.get_profesor() > disc_2.get_profesor()) {
		return false;
	}
	else if (disc_1.get_profesor() < disc_2.get_profesor()) {
		return true;
	}
	else {
		if (disc_1.get_tip() < disc_2.get_tip()) {
			return true;
		}
		return false;
	}
}