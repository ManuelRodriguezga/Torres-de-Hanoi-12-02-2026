#pragma once
#define TORRES_HANOI_H

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class TorresHanoi {
private:
    stack<int> torre1, torre2, torre3;  // Las tres torres
    int numDiscos;
    int movimientos;
    vector<pair<int, pair<int, int>>> historial;  // Para guardar el historial de movimientos

public:
    // Constructor
    TorresHanoi(int n);

    // Mostrar el estado actual de las torres
    void mostrarTorres();

    // Función auxiliar para mostrar una pila
    void mostrarPila(stack<int> pila);

    // Mover disco de una torre a otra
    bool moverDisco(int origen, int destino);

    // Resolver las Torres de Hanoi de forma recursiva
    void resolver();

    // Función auxiliar recursiva
    void resolverRecursivo(int n, int origen, int destino, int auxiliar);

    // Mostrar historial de movimientos
    void mostrarHistorial();

    // Obtener número de movimientos realizados
    int obtenerMovimientos();
};

