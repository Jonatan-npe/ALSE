#include <iostream>
#include <stdexcept> // Para std::invalid_argument
#include <cstdlib>   // Para std::stoi
using namespace std;

// Función para sumar dos enteros
float suma(int a, int b) {
    return a + b;
}

// Función para restar dos enteros
float resta(int a, int b) {
    return a - b;
}

// Función para multiplicar dos enteros
float multiplicacion(int a, int b) {
    return a * b;
}

// Función para dividir dos enteros
float division(int a, int b) {
    if (b == 0) {
        throw invalid_argument("No se puede dividir por 0");
    }
    return static_cast<float>(a) / b; // Convertir a float para mayor precisión
}

// Definir un tipo de función de callback
typedef float (*CallbackFuntion)(int, int);

// Función para ejecutar una función de callback con dos enteros
float ejecutarCallback(CallbackFuntion funcion, int a, int b) {
    return funcion(a, b);
}

int main(int argc, char const *argv[]) {
    try {
        // Verificar que se pasen exactamente 4 argumentos
        if (argc != 4) {
            throw invalid_argument("Error en la cantidad de argumentos");
        }

        int a, b;
        char operacion;

        // Convertir los argumentos a enteros y char
        a = stoi(argv[1]);
        operacion = argv[2][0];
        b = stoi(argv[3]);

        // Verificar si la conversión fue exitosa
        if (cin.fail()) {
            throw invalid_argument("Error en la conversión de argumentos");
        }

        cout << "a: " << a << " b: " << b << " operacion: " << operacion << endl;

        // Definir la función de callback y el nombre de la operación
        CallbackFuntion funcion = nullptr;
        string nombreFuncion;

        // Seleccionar la operación basada en el carácter de operación
        switch (operacion) {
            case '+':
                funcion = suma;
                nombreFuncion = "suma";
                break;
            case '-':
                funcion = resta;
                nombreFuncion = "resta";
                break;
            case '*':
                funcion = multiplicacion;
                nombreFuncion = "multiplicacion";
                break;
            case '/':
                funcion = division;
                nombreFuncion = "division";
                break;
            default:
                throw invalid_argument("Operacion no valida");
        }

        // Ejecutar la función de callback y mostrar el resultado
        cout << "La " << nombreFuncion << " de " << a << " " << operacion << " " << b << " es: " << ejecutarCallback(funcion, a, b) << endl;
    } catch (const std::exception& e) {
        // Manejar errores de conversión y operación
        cout << "Error: " << e.what() << endl;
        cout << "Ingrese a y b como numeros enteros y operacion como un caracter" << endl;
        return 1;
    }

    return 0;
}