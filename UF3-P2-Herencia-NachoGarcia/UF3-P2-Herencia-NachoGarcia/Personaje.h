#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <string>
#include <iostream>
using namespace std;

class Personaje {
protected:
    int vida;
    int ataque;
    string nombre;
    int posicionX;
    int posicionY;

public:
    Personaje(string nombre, int posX, int posY);

    virtual void atacar(Personaje& objetivo);
    virtual void recibirAtaque(int cantidad);

    int getVida() const;
    int getAtaque() const;
    string getNombre() const;
    int getPosX() const;
    int getPosY() const;

    void setVida(int nuevaVida);
    void setAtaque(int nuevoAtaque);
    void setNombre(string nuevoNombre);
    void setPosX(int nuevaPosX);
    void setPosY(int nuevaPosY);
};

#endif
