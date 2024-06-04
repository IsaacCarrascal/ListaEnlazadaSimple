#pragma once
#include <iostream>
#include "List.h"


class Menu
{private:
	int choice = 0;
	List list;
public:
	Menu() {
		while (choice != 5) {
			system("cls");
			printMenu();
			setChoice();
			switchChoice();
			system("pause");
		}
}

	void printMenu() {
		std::cout << "1. Agregar" << std::endl;
		std::cout << "2. Eliminar" << std::endl;
		std::cout << "3. Imprimir" << std::endl;
		std::cout << "4. Buscar" << std::endl;
		std::cout << "5. Salir" << std::endl;
		std::cout << "Digite una opcion" << std::endl;
	}

	void setChoice() {
		choice = getValidInt();
	}
	void switchChoice() {
		switch (choice) {
		case 1:
			list.Add();
			break;
		case 2:
			list.Delete();
			break;
		case 3:
			list.Print();
			break;
		case 4:
			list.Search();
			break;
		case 5:
			std::cout << "Hasta luego :)" << std::endl;
			break;
		default:
			std::cout << "Opcion no valida" << std::endl;
		}
	}
	static int getValidInt() {
		int number;

		while (!(std::cin >> number)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Opcion no valida" << std::endl;
			return 0;
		}

		return number;
	}
};

