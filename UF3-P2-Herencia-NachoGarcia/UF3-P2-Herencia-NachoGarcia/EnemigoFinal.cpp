#include "EnemigoFinal.h"
#include <random>
#include <iostream>
using namespace std;

EnemigoFinal::EnemigoFinal(string nombre, int posX, int posY)
    : Personaje(nombre, posX, posY) {
    superAtaque1 = 20;
    superAtaque2 = 30;
}

void EnemigoFinal::usarSuperAtaque(Personaje& objetivo) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 2);
    int seleccion = dis(gen);

    if (seleccion == 1) {
        cout << nombre << " usa Super Ataque 1 contra " << objetivo.getNombre() << "!\n";
        objetivo.recibirAtaque(superAtaque1);
    }
    else {
        cout << nombre << " usa Super Ataque 2 contra " << objetivo.getNombre() << "!\n";
        objetivo.recibirAtaque(superAtaque2);
    }
}

int EnemigoFinal::getSuperAtaque1() const {
    return superAtaque1;
}

int EnemigoFinal::getSuperAtaque2() const {
    return superAtaque2;
}

void EnemigoFinal::setSuperAtaque1(int valor) {
    superAtaque1 = valor;
}

void EnemigoFinal::setSuperAtaque2(int valor) {
    superAtaque2 = valor;
}
