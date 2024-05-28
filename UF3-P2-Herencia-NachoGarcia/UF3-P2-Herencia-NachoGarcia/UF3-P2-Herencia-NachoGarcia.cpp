#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <thread>
#include <chrono> 
#include <Windows.h> 
#include "Personaje.h"
#include "EnemigoFinal.h"
using namespace std;
#ifdef _WIN32
    void ClearConsoleScreen() {
        COORD coordScreen = { 0, 0 };
        DWORD cCharsWritten;
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        DWORD dwConSize;
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        GetConsoleScreenBufferInfo(hConsole, &csbi);
        dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

        FillConsoleOutputCharacter(hConsole, (TCHAR)' ', dwConSize, coordScreen, &cCharsWritten);

        GetConsoleScreenBufferInfo(hConsole, &csbi);
        FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
        SetConsoleCursorPosition(hConsole, coordScreen);
    }
#else
    void ClearConsoleScreen() {
        cout << "\033[2J\033[1;1H";
    }
#endif


void MostrarPantallaCombate(Personaje& heroe, Personaje& enemigo, int danioHeroe, int danioEnemigo) {
    ClearConsoleScreen();
    cout << "Pantalla de Combate con Enemigo:\n\n";
    cout << "Vida del heroe: " << heroe.getVida() << "\tVida del enemigo: " << enemigo.getVida() << "\n\n";
    cout << "Heroe ataca a Enemigo con " << danioHeroe << " de danyo\n";
    enemigo.recibirAtaque(danioHeroe);
    if (enemigo.getVida() <= 0) {
        enemigo.setVida(0);
    }
    this_thread::sleep_for(chrono::seconds(3));
    ClearConsoleScreen();
    if (enemigo.getVida() != 0) {
        cout << "Pantalla de Combate con Enemigo:\n\n";
        cout << "Vida del heroe: " << heroe.getVida() << "\tVida del enemigo: " << enemigo.getVida() << "\n\n";
        cout << "Enemigo contrataca con " << danioEnemigo << " de danyo\n";
        heroe.recibirAtaque(danioEnemigo);
        if (heroe.getVida() <= 0) {
            heroe.setVida(0);
            cout << "Game Over! El heroe ha sido derrotado.\n";
            exit(0);
        }
        this_thread::sleep_for(chrono::seconds(3));
    }
}

void MostrarPantallaCombateEnemigoFinal(Personaje& heroe, EnemigoFinal& enemigoFinal, int danioHeroe, int danioEnemigo) {
    ClearConsoleScreen();
    cout << "Pantalla de Combate con Enemigo Final:\n\n";
    cout << "Vida del heroe: " << heroe.getVida() << "\tVida del enemigo final: " << enemigoFinal.getVida() << "\n\n";
    cout << "Heroe ataca a Enemigo Final con " << danioHeroe << " de danyo\n";
    enemigoFinal.recibirAtaque(danioHeroe);
    if (enemigoFinal.getVida() <= 0) {
        enemigoFinal.setVida(0);
    }
    this_thread::sleep_for(chrono::seconds(3)); 
    ClearConsoleScreen();
    if (enemigoFinal.getVida() != 0) {
        cout << "Pantalla de Combate con Enemigo Final:\n\n";
        cout << "Vida del heroe: " << heroe.getVida() << "\tVida del enemigo final: " << enemigoFinal.getVida() << "\n\n";
        enemigoFinal.usarSuperAtaque(heroe);
        if (heroe.getVida() <= 0) {
            heroe.setVida(0);
            cout << "Game Over! El heroe ha sido derrotado.\n";
            exit(0);
        }
        this_thread::sleep_for(chrono::seconds(3));
    }
}


int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    int tamanoTablero = 7;
    int numeroEnemigos = tamanoTablero - 2;

    int posXHeroe = rand() % tamanoTablero; 
    Personaje heroe("Heroe", posXHeroe, 0);
    heroe.setVida(450);
    heroe.setAtaque(10);

    int posXGuarida = rand() % tamanoTablero; 
    int guaridaY = tamanoTablero - 1; 

    EnemigoFinal enemigoFinal("Jefe Final", posXGuarida, guaridaY);
    enemigoFinal.setVida(150); 
    enemigoFinal.setSuperAtaque1(10);
    enemigoFinal.setSuperAtaque2(15);

    vector<Personaje> enemigos;
    for (int i = 0; i < numeroEnemigos; ++i) {
        int posY = i + 1; 
        int posX = rand() % tamanoTablero;
        Personaje enemigo("Enemigo", posX, posY);
        enemigo.setVida(80);
        enemigo.setAtaque(8);
        enemigos.push_back(enemigo);
    }

    while (true) {
        ClearConsoleScreen();
        cout << "Bienvenido al juego, tu eres el heroe (H) y has de llegar a la salida (S), cuidado con los enemigos invisibles!\n";
        cout << "Tablero actual:\n";
        for (int i = 0; i < tamanoTablero; ++i) {
            for (int j = 0; j < tamanoTablero; ++j) {
                if (i == heroe.getPosX() && j == heroe.getPosY()) {
                    cout << "H\t";
                }
                else if (i == posXGuarida && j == guaridaY) {
                    cout << ".\t";
                }
                else {
                    cout << ".\t"; 
                }
            }
            cout << endl;
        }
        cout << endl;

        char direccion;
        cout << "Hacia donde quieres mover al heroe? (W: arriba, A: izquierda, S: abajo, D: derecha): ";
        cin >> direccion;

        switch (direccion) {
        case 'W':
        case 'w':
            if (heroe.getPosX() > 0) {
                heroe.setPosX(heroe.getPosX() - 1);
            }
            break;
        case 'A':
        case 'a':
            if (heroe.getPosY() > 0) {
                heroe.setPosY(heroe.getPosY() - 1);
            }
            break;
        case 'S':
        case 's':
            if (heroe.getPosX() < tamanoTablero - 1) {
                heroe.setPosX(heroe.getPosX() + 1);
            }
            break;
        case 'D':
        case 'd':
            if (heroe.getPosY() < tamanoTablero - 1) {
                heroe.setPosY(heroe.getPosY() + 1);
            }
            break;
        default:
            cout << "Entrada no valida. Por favor, introduce W, A, S o D.\n";
            break;
        }

        for (auto& enemigo : enemigos) {
            if (heroe.getPosX() == enemigo.getPosX() && heroe.getPosY() == enemigo.getPosY()) {
                ClearConsoleScreen();
                MostrarPantallaCombate(heroe, enemigo, heroe.getAtaque(), enemigo.getAtaque());

                while (heroe.getVida() > 0 && enemigo.getVida() > 0) {
                    int danioHeroe = heroe.getAtaque();
                    int danioEnemigo = enemigo.getAtaque();
                    MostrarPantallaCombate(heroe, enemigo, danioHeroe, danioEnemigo);
                }
                this_thread::sleep_for(chrono::seconds(3));
            }
        }

        if (heroe.getPosX() == posXGuarida && heroe.getPosY() == guaridaY) {
            ClearConsoleScreen();
            MostrarPantallaCombateEnemigoFinal(heroe, enemigoFinal, heroe.getAtaque(), enemigoFinal.getAtaque());

            while (heroe.getVida() > 0 && enemigoFinal.getVida() > 0) {
                // Turno del héroe
                int danioHéroe = heroe.getAtaque();
                MostrarPantallaCombateEnemigoFinal(heroe, enemigoFinal, danioHéroe, 0);

                if (enemigoFinal.getVida() <= 0) {
                    cout << "El enemigo final ha sido derrotado!\n";
                    cout << "Has ganado la partida!\n";
                    break;
                }

                // Turno del enemigo final
                enemigoFinal.usarSuperAtaque(heroe);
                MostrarPantallaCombateEnemigoFinal(heroe, enemigoFinal, heroe.getAtaque(), 0);
            }

            this_thread::sleep_for(chrono::seconds(3));
            break;
        }
    }

    return 0;
}

