#ifndef UI_H_
#define UI_H_

#include "service.h"

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::getline;

class Ui {
	Service& controller;

	void adaugaUi();

	void modificaUi();

	void stergeUi();

	void cautaUi();

	void filterUi();
	
	void sortUi();

	static void printDiscipline(const VectorDinamic<Disciplina>& discipline);

	void printAll();

	static void menu();

public:
	explicit Ui(Service& controller) noexcept: controller(controller) {

	}

	//nu lasam sa se faca copie
	Ui(const Ui& copie) = delete;

	void run();

};

void clearInputBuffer();

#endif /* UI_H_ */
