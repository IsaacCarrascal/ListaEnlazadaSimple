#pragma once
#include <iostream>


class Node {
private:
    int content;
    Node* next;

public:
    Node() {
        askContent();
        receiveContent();
        
        next = nullptr;
    }

    int getContent() {
        return content;
    }

    void setContent(int value) {
        content = value;
    }

    void askContent() {
        std::cout << "Escriba el contenido del nodo" << std::endl;
    }
    void receiveContent() {
        int typed;
        std::cin >> typed;
        setContent(typed);
    }

    bool checkNext() {
        if (next == nullptr)
            return false;
        return true;
    }
    Node* getNext() {
        return next;
    }
    void setNext(Node* newNext) {
        next = newNext;
    }
    void createNext() {
        next = new Node;
    }

    int peekNext() {
        if (next == nullptr) {
            return NULL;
        }
        else {
            return next->getContent();
        }
    }

    Node* jumpNext() {
        return next->getNext();
    }
    void deleteNext() {
        delete next;
    }

    ~Node() {
        std::cout << "Nodo Eliminado con exito" << std::endl;
    }
};


