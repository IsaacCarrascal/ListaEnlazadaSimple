#pragma once
#include "Node.h"


class List{
private:
	Node* root=nullptr, *aux=nullptr;
	
public:
	void Add() {
		aux = root;
		if (aux == nullptr) {
			root = new Node;
		}
		else {
			while (aux->checkNext()) {
				aux = aux->getNext();
			}
			aux->createNext();
			
		}
	}

	void Print() {
		aux = root;
		int i = 0;
		while (aux != nullptr) {
			std::cout << "Nodo " << i << ": " << aux->getContent() << std::endl;
			aux = aux->getNext();
			i++;
		}
	}
	void Search() {
		int toSearch, i=0, counter=0;
		askToSearch();
		toSearch = receiveInput();
		aux = root;
		while (aux != nullptr) {
			if (aux->getContent() == toSearch) {
				std::cout<<"Contenido: "<<toSearch<<" encontrado en nodo "<<i<<std::endl;
				counter++;
			}
			i++;
			aux = aux->getNext();

		}
		if (counter == 0)
			std::cout << "No encontrado" << std::endl;
		
	}
	void Delete() {
		askToDel();
		int toDelete = receiveInput();
		aux = root;
		Node* aux2 = nullptr;;
		if (root->getContent() == toDelete) {
			aux = root->getNext();
			delete root;
			root = aux;
		}
		else {
			while (aux!=nullptr && aux->peekNext() != toDelete) {
				aux = aux->getNext();
			}
			if (aux != nullptr) {
				aux2 = aux->jumpNext();
				aux->deleteNext();
				aux->setNext(aux2);
			}
			else {
				std::cout << "No encontrado" << std::endl;
			}
		}
	}

	void askToDel() {
		std::cout << "Digite el contenido a eliminar: ";
	}
	void askToSearch() {
		std::cout << "Digite el contenido a buscar: ";
	}
	int receiveInput() {
		int typed;
		std::cin >> typed;
		return typed;
	}
};

