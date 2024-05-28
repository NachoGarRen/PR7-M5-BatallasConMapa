#ifndef ENEMIGOFINAL_H
#define ENEMIGOFINAL_H

#include "Personaje.h"
#include <iostream>
using namespace std;

class EnemigoFinal : public Personaje {
private:
    int superAtaque1;
    int superAtaque2;

public:
    EnemigoFinal(string nombre, int posX, int posY);

    void usarSuperAtaque(Personaje& objetivo);

    int getSuperAtaque1() const;
    int getSuperAtaque2() const;

    void setSuperAtaque1(int valor);
    void setSuperAtaque2(int valor);
};

#endif
