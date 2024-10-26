/*
Enunciado: Haga un programa C++ que permita que dos jugadores jueguen Tic-Tac-Toe.

Participantes del grupo:
Diego Gonzalez - 1096184
Mario Senra - 1116752
Rafael Peralta - 1114441
Jaime Hernandez - 1099041

Fecha de realizacion: 12/11/2023
*/

#include <iostream>

using namespace std;

string jugador1, jugador2;

char tablero[3][3] = {
    {'-', '-', '-'},
    {'-', '-', '-'},
    {'-', '-', '-'}
};

char simbolo = 'X';
string nombreJugadorActual = "";
bool hayGanador = false, empate = false;

void ImprimirTablero() {
    system("CLS");

    cout << "Tablero: " << endl;

    cout << "   1   2   3" << endl;

    cout << "  *---*---*---*" << endl;

    for (int i = 0; i < 3; i++) {
        cout << i + 1 << " | ";

        for (int j = 0; j < 3; j++) {
            cout << tablero[i][j] << " | ";
        }
        cout << endl << "  *---*---*---*" << endl;
    }
}

bool TableroLleno() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tablero[i][j] == '-') {
                return false;
            }
        }
    }
    return true;
}

void CambiarTurno() {
    if (nombreJugadorActual.empty()) {
        nombreJugadorActual = jugador1;
    }
    else {
        simbolo = (simbolo == 'X') ? 'O' : 'X';
        nombreJugadorActual = (nombreJugadorActual == jugador1) ? jugador2 : jugador1;
    }
}

void ImprimirGanador() {
    ImprimirTablero();
    cout << "Ganador: " << nombreJugadorActual << " (" << simbolo << ")" << endl;
    hayGanador = true;
}

void HayGanador() {
    for (int i = 0; i < 3; i++)
    {
        if (tablero[i][0] == tablero[i][1] && tablero[i][0] == tablero[i][2] && tablero[i][0] != '-')
        {
            ImprimirGanador();
            
        }
    }

    for (int j = 0; j < 3; j++)
    {
        if (tablero[0][j] == tablero[1][j] && tablero[0][j] == tablero[2][j] && tablero[0][j] != '-')
        {
            ImprimirGanador();
        }
    }

    if ((tablero[0][0] == tablero[1][1] && tablero[0][0] == tablero[2][2] && tablero[0][0] != '-') ||
        (tablero[0][2] == tablero[1][1] && tablero[0][2] == tablero[2][0] && tablero[0][2] != '-'))
    {
        ImprimirGanador();
    }

    if (TableroLleno() && hayGanador == false)
    {
        ImprimirTablero();
        cout << "Se ha producido un empate" << endl;
        empate = true;
    }

}

void Jugar() {
    int fila, columna;
    bool terminaTurno = false;
    cout << "Turno de " << nombreJugadorActual << " (" << simbolo << ")" << endl;

    while (!terminaTurno) {
        cout << "Ingrese la jugada (columna fila): ";

        while (!(cin >> fila >> columna) || fila < 1 || fila > 3 || columna < 1 || columna > 3) {
            cout << "Entrada invalida, ingrese la jugada correctamente (columna fila): ";
            cin.clear();
            cin.ignore();
        }

        if (tablero[columna - 1][fila - 1] == '-') {
            tablero[columna - 1][fila - 1] = simbolo;
            terminaTurno = true;
        }
        else {
            cout << "Esta casilla esta ocupada, ingrese la jugada correctamente (columna fila)\n ";
        }

    }

    HayGanador();
    CambiarTurno();
}

int main() {
    cout << "Ingrese el nombre del jugador #1 (X): ";
    cin >> jugador1;

    cout << "Ingrese el nombre del jugador #2 (O): ";
    cin >> jugador2;

    CambiarTurno();

    while (hayGanador == false && empate == false)
    {
        ImprimirTablero();
        Jugar();
    }

    return 0;
}