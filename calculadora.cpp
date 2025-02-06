#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int opcion, numero1, numero2;
    float resultado;

    system("cls");
    cout << "CALCULADORA" << endl;
    cout << "Seleccione una operacion:" << endl;
    cout << "1) Suma" << endl;
    cout << "2) Resta" << endl;
    cout << "3) Multiplicacion" << endl;
    cout << "4) Division" << endl;
    cout << "Opcion: ";
    cin >> opcion;

    if (opcion >= 1 && opcion <= 4) {
        cout << "Ingrese el primer numero: ";
        cin >> numero1;
        cout << "Ingrese el segundo numero: ";
        cin >> numero2;

        switch (opcion) {
            case 1:
                resultado = numero1 + numero2;
                cout << "El resultado de la suma es: " << resultado << endl;
                break;
            case 2:
                resultado = numero1 - numero2;
                cout << "El resultado de la resta es: " << resultado << endl;
                break;
            case 3:
                resultado = numero1 * numero2;
                cout << "El resultado de la multiplicacion es: " << resultado << endl;
                break;
            case 4:
                if (numero2 != 0) {
                    resultado = (float)numero1 / numero2;
                    cout << "El resultado de la division es: " << resultado << endl;
                } else {
                    cout << "Error: No se puede dividir por cero." << endl;
                }
                break;
        }
    } else {
        cout << "Opcion invalida, por favor seleccione una opcion entre 1 y 4." << endl;
    }

    return 0;
}
