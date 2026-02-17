#include "TorresHanoi.h"

int main() {
    int n;

    cout << "╔════════════════════════════════╗\n";
    cout << "║    TORRES DE HANOI EN C++       ║\n";
    cout << "╚════════════════════════════════╝\n\n";

    cout << "¿Cuántos discos desea usar? (1-8 recomendado): ";
    cin >> n;

    // Validar entrada con ciclos
    while (cin.fail() || n <= 0 || n > 10) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Entrada inválida. Ingrese un número entre 1 y 10: ";
        cin >> n;
    }

    // Crear objeto de la clase TorresHanoi
    TorresHanoi hanoi(n);

    // Resolver el problema
    hanoi.resolver();

    // Mostrar historial
    hanoi.mostrarHistorial();

    cout << "\nTotal de movimientos realizados: " << hanoi.obtenerMovimientos() << "\n";

    return 0;
}
