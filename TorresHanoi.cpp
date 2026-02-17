#include "TorresHanoi.h"

// Constructor
TorresHanoi::TorresHanoi(int n) : numDiscos(n), movimientos(0) {
    // Inicializar la primera torre con los discos
    for (int i = n; i >= 1; i--) {
        torre1.push(i);
    }
}

// Mostrar el estado actual de las torres
void TorresHanoi::mostrarTorres() {
    cout << "\n--- Estado actual de las torres ---\n";
    cout << "Torre 1: ";
    mostrarPila(torre1);
    cout << "\nTorre 2: ";
    mostrarPila(torre2);
    cout << "\nTorre 3: ";
    mostrarPila(torre3);
    cout << "\n";
}

// Función auxiliar para mostrar una pila
void TorresHanoi::mostrarPila(stack<int> pila) {
    if (pila.empty()) {
        cout << "(vacía)";
        return;
    }
    vector<int> temp;
    while (!pila.empty()) {
        temp.push_back(pila.top());
        pila.pop();
    }
    // Mostrar en orden inverso (base a tope)
    for (int i = temp.size() - 1; i >= 0; i--) {
        cout << "[" << temp[i] << "] ";
    }
}

// Mover disco de una torre a otra
bool TorresHanoi::moverDisco(int origen, int destino) {
    stack<int>* torreOrigen = nullptr;
    stack<int>* torreDestino = nullptr;

    // Obtener referencias a las torres según el número
    if (origen == 1) torreOrigen = &torre1;
    else if (origen == 2) torreOrigen = &torre2;
    else if (origen == 3) torreOrigen = &torre3;

    if (destino == 1) torreDestino = &torre1;
    else if (destino == 2) torreDestino = &torre2;
    else if (destino == 3) torreDestino = &torre3;

    // Validar movimiento
    if (torreOrigen->empty()) {
        return false;
    }

    if (!torreDestino->empty() && torreOrigen->top() > torreDestino->top()) {
        return false;
    }

    // Realizar el movimiento
    int disco = torreOrigen->top();
    torreOrigen->pop();
    torreDestino->push(disco);
    movimientos++;

    // Guardar en historial
    historial.push_back({disco, {origen, destino}});
    
    cout << "Movimiento " << movimientos << ": Disco " << disco
         << " de Torre " << origen << " a Torre " << destino << "\n";

    return true;
}

// Resolver las Torres de Hanoi de forma recursiva
void TorresHanoi::resolver() {
    int totalMovimientos = (1 << numDiscos) - 1;  // 2^n - 1

    cout << "Resolviendo Torres de Hanoi con " << numDiscos << " discos...\n";
    cout << "Total de movimientos necesarios: " << totalMovimientos << "\n";
    cout << "==================================\n";

    mostrarTorres();

    // Llamar a la función recursiva
    resolverRecursivo(numDiscos, 1, 3, 2);

    cout << "\n✓ ¡Torres de Hanoi resuelto en " << movimientos << " movimientos!\n";
}

// Función auxiliar recursiva para resolver
void TorresHanoi::resolverRecursivo(int n, int origen, int destino, int auxiliar) {
    // Caso base: si solo hay 1 disco, moverlo directamente
    if (n == 1) {
        moverDisco(origen, destino);
        mostrarTorres();
        return;
    }

    // Paso 1: Mover n-1 discos de origen a auxiliar usando destino como auxiliar
    resolverRecursivo(n - 1, origen, auxiliar, destino);

    // Paso 2: Mover el disco más grande de origen a destino
    moverDisco(origen, destino);
    mostrarTorres();

    // Paso 3: Mover n-1 discos de auxiliar a destino usando origen como auxiliar
    resolverRecursivo(n - 1, auxiliar, destino, origen);
}

// Mostrar historial de movimientos
void TorresHanoi::mostrarHistorial() {
    cout << "\n--- Historial de movimientos ---\n";
    for (int i = 0; i < historial.size(); i++) {
        cout << i + 1 << ". Disco " << historial[i].first
             << ": Torre " << historial[i].second.first
             << " → Torre " << historial[i].second.second << "\n";
    }
}

// Obtener número de movimientos realizados
int TorresHanoi::obtenerMovimientos() {
    return movimientos;
}
