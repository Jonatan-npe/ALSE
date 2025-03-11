#include <iostream>
#include <stdexcept> // Para usar std::invalid_argument
using namespace std;

// Función para sumar dos enteros
int suma(int a, int b) {
    return a + b;
}

// Función para restar dos enteros
int resta(int a, int b) {
    return a - b;
}

// Función para multiplicar dos enteros
float multiplicacion(int a, int b) {
    return static_cast<float>(a) * b; // Convertir a float para mayor precisión
}

// Función para dividir dos enteros
float division(int a, int b) {
    if (b == 0) {
        throw invalid_argument("No se puede dividir por 0");
    }
    return static_cast<float>(a) / b; // Convertir a float para mayor precisión
}

int main(int argc, char const *argv[]) {
    cout << "Ingrese dos numeros enteros junto con su operación (a operacion b): ";
    int a, b;
    char operacion;

    cin >> a >> operacion >> b;
    if (cin.fail()) {
        cout << "Error al leer los datos, ingreselos de la forma (a operacion b)" << endl;
        cout << "Ingrese a y b como numeros enteros y operacion como un caracter" << endl;
        throw invalid_argument("Entrada no valida");
    }

    cout << "a: " << a << " b: " << b << " operacion: " << operacion << endl;

    // Realizar la operación correspondiente
    try {
        switch (operacion) {
            case '+':
                cout << "La suma de " << a << " + " << b << " es: " << suma(a, b) << endl;
                break;
            case '-':
                cout << "La resta de " << a << " - " << b << " es: " << resta(a, b) << endl;
                break;
            case '*':
                cout << "La multiplicacion de " << a << " * " << b << " es: " << multiplicacion(a, b) << endl;
                break;
            case '/':
                cout << "La division de " << a << " / " << b << " es: " << division(a, b) << endl;
                break;
            default:
                cout << "Operacion no valida, ingreselo de la forma (a operacion b)" << endl;
                return 1;
        }
    } catch(const std::exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}