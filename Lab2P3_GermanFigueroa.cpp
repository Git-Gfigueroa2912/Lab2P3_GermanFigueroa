#include <iostream>
#include <locale>
using namespace std;

void creacionLogo(){
    int número;
    do {
        cout << " Ingrese el tamaño del logo (numero impar mayor a 5): ";
        cin >> número;

    } while (número < 5 || número % 2 == 0);

    for (int i = 0; i < número; i++) {
        for (int j = 0; j < número; j++) {
            bool dibujar = false;

            if (j == número - 1) {
                dibujar = true;
            }
            if (i <= número / 2) {

                if (j == i || j == (número / 2) - i) {
                    dibujar = true;
                }
            }else{

                if (j == i || j == (número / 2) + (i - (número / 2))) {
                    dibujar = true;
                }
            }
            if (dibujar) {
                cout << "*";

            }else{
                cout << " ";
            }
        }
        cout << endl;
    }
}
void numerosNarcicistas() {
    int número;
    cout << " Ingrese un numero entero positivo: ";
    cin >> número;

    if (número <= 0) {
        return;
    }
    int temp = número;
    int cantidadDigitos = 0;
    while (temp > 0) {
        cantidadDigitos++;
        temp /= 10;
    }
    temp = número;
    int suma = 0;
    while (temp > 0) {
        int digito = temp % 10;
        suma += (int)(digito, cantidadDigitos);
        temp /= 10;
    }
    if (suma == número) {
        cout << número << " Es un numero narcicista! " << endl;
    }
    else {
        cout << número << " No es un numero narcicista (la suma dio " << suma << ")" << endl;
    }
}
void conjeturaCollatz(){
    long long número;
    cout << "Ingrese un numero entero positivo mayor a 0: ";
    cin >> número;

    if (número <= 0) {
        return;
    }

    int pasos = 0;
    long long temp = número;

    while (temp > 1) {
        if (temp % 2 == 0) {
            temp /= 2;
        }
        else {
            temp = 3 * temp + 1;
        }
        pasos++;
    }

    cout << "Resultado: El numero " << número << " tomo " << pasos << " pasos para llegar a 1" << endl;
}
void arregloMontaña() {
    int array[8];
    for (int i = 0; i < 8; i++) {
        do {
            cout << "Ingrese un numero al arreglo (pos: " << i << "): ";
            cin >> array[i];
        } while (array[i] < 0);
    }

    int i = 0;
    while (i < 7 && array[i] < array[i + 1]) {
        i++;
    }

    if (i == 0 || i == 7) {
        cout << "Resultado: El arreglo ingresado NO es una montana" << endl;
        return;
    }

    while (i < 7 && array[i] > array[i + 1]) {
        i++;
    }

    if (i == 7) {
        cout << "Resultado: ¡El arreglo ingresado ES una montana!" << endl;
    }
    else {
        cout << "Resultado: El arreglo ingresado NO es una montana" << endl;
    }
}

int main(){
    setlocale(LC_ALL, "spanish");
    int opcion;
    do {
        cout << " --- MENU PRINCIPAL ---" << endl;
        cout << " 1. Visual Studio Logo " << endl;
        cout << " 2. Números narcicistas" << endl;
        cout << " 3. Conjetura de Coliatz " << endl;
        cout << " 4. Arreglo Montaña " << endl;
        cout << " 0. Salir del programa" << endl;
        cout << " Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "1. Visual Studio Logo " << endl;
                creacionLogo();
                break;
            
            case 2:
                cout << "2. Números narcicistas " << endl;
                numerosNarcicistas();
                break;

            case 3:
                cout << "3. Conjetura de Collatz " << endl;
                conjeturaCollatz();
                break;

            case 4:
                cout << "4. Arreglo Montaña " << endl;
                arregloMontaña();
                break;

            case 0:
                cout << " Saliendo del programa " << endl;
                break;

            default:
                cout << " Opcion invalida " << endl;

        }

    } while (opcion != 0);
}





