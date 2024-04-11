#include "ui.h"

#include <iostream>
#include <limits>

#define RESET   "\033[0m"
#define GREEN   "\033[1;32m"
#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;36m"
#define MAGENTA "\033[1;35m"


void clearInputBuffer() {
	if (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

void Ui::adaugaUi() {
	string denumire, tip, profesor;
	int ore = 0;

	cout << BLUE << "Introduceti disciplina:\n" << RESET;
	cout << "Denumire: ";
	cin >> denumire;

	cout << "Ore pe saptamana: ";
	cin >> ore;
	clearInputBuffer();

	cout << "Tip: ";
	cin >> tip;

	cout << "Nume profesor: ";
	cin >> profesor;

	controller.adaugaSrv(denumire, ore, tip, profesor);
}

void Ui::modificaUi() {
	string denumire, tip, profesor;
	int ore = 0;

	cout << BLUE << "Introduceti numele materiei si a profesorului:\n" << RESET;
	cout << "Denumire: ";
	cin >> denumire;

	cout << "Nume profesor: ";
	cin >> profesor;

	cout << "Ore noi pe saptamana: ";
	cin >> ore;
	clearInputBuffer();

	cout << "Tip nou: ";
	cin >> tip;

	controller.modificaSrv(denumire, ore, tip, profesor);
}

void Ui::stergeUi() {
	string denumire, profesor;

	cout << BLUE << "Introduceti numele materiei si a profesorului:\n" << RESET;
	cout << "Denumire: ";
	cin >> denumire;

	cout << "Nume profesor: ";
	cin >> profesor;

	controller.stergeSrv(denumire, profesor);
}

void Ui::cautaUi() {
	string denumire, profesor;

	cout << BLUE << "Introduceti numele materiei si a profesorului:\n" << RESET;
	cout << "Denumire: ";
	cin >> denumire;

	cout << "Nume profesor: ";
	cin >> profesor;

	Disciplina disciplina = controller.cautaSrv(denumire, profesor);
	cout << MAGENTA << "\nDisciplina ta este:\n " << disciplina.to_string_print() << '\n';
}

void Ui::filterUi() {
	int optiune = 0;
	cout << BLUE << "Introduceti 1 pentru filtrare dupa ore sau 2, dupa profesor.\n\n" << RESET;

	cout << BLUE << "Optiunea este: " << RESET;
	cin >> optiune;
	clearInputBuffer();

	if (optiune == 1) {
		int ore = 0;
		cout << "Ore: ";
		cin >> ore;
		clearInputBuffer();
		VectorDinamic <Disciplina> filtrat = controller.filterOre(ore);
		cout << GREEN << "Disciplinele filtrate sunt:\n" << RESET;
		printDiscipline(filtrat);
	}
	else if (optiune == 2) {
		string profesor;
		cout << "Nume profesor: ";
		cin >> profesor;
		VectorDinamic <Disciplina> filtrat = controller.filterProfesor(profesor);
		cout << GREEN << "Disciplinele filtrate sunt:\n" << RESET;
		printDiscipline(filtrat);
	}
	else {
		cout << RED << "Optiune invalida!!\n" << RESET;
	}

}

void Ui::sortUi() {
	int optiune = 0;
	cout << BLUE << "Introduceti o optiune de mai jos:\n";
	cout << "1." << RESET << " pentru sortare dupa " << YELLOW <<"denumire; \n" << RESET;
	cout << BLUE << "2." << RESET << " pentru sortare dupa " << YELLOW << "numarul de ore\n" << RESET;
	cout << BLUE << "3." << RESET << " pentru sortare dupa " << YELLOW << "profesor + tip.\n\n" << RESET;

	cout << BLUE << "Optiunea este: " << RESET;
	cin >> optiune;
	clearInputBuffer();

	if (optiune == 1) {
		VectorDinamic <Disciplina> sortat = controller.sortDenumire();
		cout << GREEN << "Disciplinele sortate sunt:\n" << RESET;
		printDiscipline(sortat);
	}
	else if (optiune == 2) {
		VectorDinamic <Disciplina> sortat = controller.sortOre();
		cout << GREEN << "Disciplinele sortate sunt:\n" << RESET;
		printDiscipline(sortat);
	}
	else if (optiune == 3) {
		VectorDinamic <Disciplina> sortat = controller.sortProfTip();
		cout << GREEN << "Disciplinele sortate sunt:\n" << RESET;
		printDiscipline(sortat);
	}
	else {
		cout << RED << "Optiune invalida!!\n" << RESET;
	}

}

void Ui::printDiscipline(const VectorDinamic<Disciplina>& discipline) {
	if (!discipline.empty()) {
		for (Disciplina disciplina : discipline) {
			cout << disciplina.to_string_print() << '\n';
		}
	}
	else {
		cout << RED << "Nu exista astfel de discipline!\n" << RESET;
	}
}

void Ui::printAll() {
	const VectorDinamic<Disciplina>& discipline = controller.getAll();
	cout << '\n' << MAGENTA << "Lista disciplinelor:\n" << RESET;
	if (!discipline.empty()) {
		for (Disciplina disciplina : discipline) {
			cout << disciplina.to_string_print() << '\n';
		}
		cout << '\n';
	}
	else
		cout << RED << "Nu exista discipline inca!\n\n" << RESET;
}

void Ui::menu() {
	cout << '\n';
	cout << YELLOW << "-----------Meniul disciplinelor:-----------\n" << RESET;
	cout << YELLOW << "1." << RESET << " Adauga disciplina;\n";
	cout << YELLOW << "2." << RESET << " Modifica disciplina;\n";
	cout << YELLOW << "3." << RESET << " Sterge disciplina;\n";
	cout << YELLOW << "4." << RESET << " Cauta disciplina;\n";
	cout << YELLOW << "5." << RESET << " Filtreaza disciplina (dupa nr. ore/ profesor);\n";
	cout << YELLOW << "6." << RESET << " Sorteaza disciplinele (dupa denumire/ nr. ore/ profesor + tip;\n";
	cout << YELLOW << "0." << RESET << " Exit.\n";
	cout << YELLOW << "------------------------------------------------------------------\n\n" << RESET;
}

void Ui::run() {
	int comanda = -1;

	controller.adaugaSrv("mate", 4, "real", "Alexe");
	controller.adaugaSrv("info", 6, "real", "Alexe");
	controller.adaugaSrv("mate", 2, "uman", "Ionescu");

	while (true) {
		printAll();
		menu();

		cout << BLUE << "Introduceti comanda: " << RESET;
		cin >> comanda;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			comanda = -1;
		}
		cout << '\n';

		switch (comanda) {
		case 0:
			cout << BLUE << "La revedere!\n" << RESET;
			return;
		case 1:
			try {
				adaugaUi();
				cout << GREEN << "Disciplina adaugata cu succes!\n" << RESET;
			}
			catch (RepoException& e) {
				cout << RED << e.get_mesaj() << RESET;
			}
			catch (ValidatorException& ve) {
				cout << RED << ve.get_mesaj() << RESET;
			}
			break;
		case 2:
			try {
				modificaUi();
				cout << GREEN << "Disciplina modificata cu succes!\n" << RESET;
			}
			catch (RepoException& e) {
				cout << RED << e.get_mesaj() << RESET;
			}
			catch (ValidatorException& ve) {
				cout << RED << ve.get_mesaj() << RESET;
			}
			break;
		case 3:
			try {
				stergeUi();
				cout << GREEN << "Disciplina stearsa cu succes!\n" << RESET;
			}
			catch (RepoException& e) {
				cout << RED << e.get_mesaj() << RESET;
			}
			catch (ValidatorException& ve) {
				cout << RED << ve.get_mesaj() << RESET;
			}
			break;
		case 4:
			try {
				cautaUi();
			}
			catch (RepoException& e) {
				cout << RED << e.get_mesaj() << RESET;
			}
			catch (ValidatorException& ve) {
				cout << RED << ve.get_mesaj() << RESET;
			}
			break;
		case 5:
			try {
				filterUi();
			}
			catch (RepoException& e) {
				cout << RED << e.get_mesaj() << RESET;
			}
			catch (ValidatorException& ve) {
				cout << RED << ve.get_mesaj() << RESET;
			}
			break;
		case 6:
			try {
				sortUi();
			}
			catch (RepoException& e) {
				cout << RED << e.get_mesaj() << RESET;
			}
			catch (ValidatorException& ve) {
				cout << RED << ve.get_mesaj() << RESET;
			}
			break;
		default:
			cout << RED << "Comanda invalida!!\n\n" << RESET;
		}
		
	}
}