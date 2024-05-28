#include "Personaje.h"
#include <iostream>
using namespace std;

Personaje::Personaje(string nombre, int posX, int posY)
    : nombre(nombre), posicionX(posX), posicionY(posY) {
    vida = 100;
    ataque = 10;
}

void Personaje::atacar(Personaje& objetivo) {
    cout << nombre << " ataca a " << objetivo.getNombre() << "!\n";
    objetivo.recibirAtaque(ataque);
}

void Personaje::recibirAtaque(int cantidad) {
    vida -= cantidad;
    if (vida <= 0) {
        cout << nombre << " ha sido derrotado!\n";
    }
}

int Personaje::getVida() const {
    return vida;
}

int Personaje::getAtaque() const {
    return ataque;
}

string Personaje::getNombre() const {
    return nombre;
}

int Personaje::getPosX() const {
    return posicionX;
}

int Personaje::getPosY() const {
    return posicionY;
}

void Personaje::setVida(int nuevaVida) {
    vida = nuevaVida;
}

void Personaje::setAtaque(int nuevoAtaque) {
    ataque = nuevoAtaque;
}

void Personaje::setNombre(string nuevoNombre) {
    nombre = nuevoNombre;
}

void Personaje::setPosX(int nuevaPosX) {
    posicionX = nuevaPosX;
}

void Personaje::setPosY(int nuevaPosY) {
    posicionY = nuevaPosY;
}
