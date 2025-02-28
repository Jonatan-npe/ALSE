#include <iostream>
#include <cmath>

// Definir la estructura de un punto en 2D
struct Point
{
    double x, y;
};

// Función para calcular la distancia entre dos puntos
/*Como puede modificar la declaración de la función para que sea mas eficiente en el manejo de memoria?
Teniendo en cuenta que solo necesita leer los valores, pero no modificarlos*/
double calcularDistancia(const Point &p1, const Point &p2)
{
    // Usar la fórmula de distancia euclidiana
    return pow(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2), 0.5);
}

// Función para leer las coordenadas de varios puntos
void leerPuntos(Point puntos[], const int &n)
{
    char respuesta;
    std::cout << "¿Desea ingresar los puntos manualmente? (s/n): ";
    std::cin >> respuesta;

    // Verificar si la respuesta es 's' o 'n', tener en cuenta mayúsculas y minúsculas
    if (respuesta == 's' || respuesta == 'S')
    {
        // Leer las coordenadas de cada punto
        for (int i = 0; i < n; i++)
        {
            std::cout << "Ingrese las coordenadas del punto " << i + 1 << " (x y): ";
            std::cin >> puntos[i].x >> puntos[i].y;
        }
    }
    else
    {
        // Usar puntos predeterminados
        std::cout << "Usando puntos predeterminados...\n";
        for (int i = 0; i < n; i++)
        {
            puntos[i] = {i * 3.0, i * 4.0};
            /*Cambie la definicion de los puntos predeterminados
            ya que causaba un error el hecho de que el usuario podia elegir
            un tamaño menor o mayor a 4 (era la cantidad de predeterminados),
            causando un error en la ejecucion */
        }
    }
}

// Función para calcular la distancia más cercana desde un punto específico
double calcularDistanciaMasCercana(Point puntos[], int n, const Point &pUsuario, int &indiceCercano)
{
    // Inicializar la distancia mínima con la distancia al primer punto
    double distanciaMinima = calcularDistancia(puntos[0], pUsuario);
    indiceCercano = 0;

    // Recorrer el resto de los puntos para encontrar el más cercano
    for (int i = 1; i < n; i++)
    {
        double distanciaActual = calcularDistancia(puntos[i], pUsuario);

        // Actualizar la distancia mínima y el índice del punto más cercano si se encuentra uno más cercano
        if (distanciaActual < distanciaMinima)
        {
            distanciaMinima = distanciaActual;
            indiceCercano = i;
        }
    }

    return distanciaMinima;
}
/*BONO:
Escribir una función que reciba un arreglo de puntos y devuelva la distancia total de los puntos que conforman el arreglo si estos fueran recorridos en orden.
*/

// Función para calcular la distancia total de un arreglo de puntos recorridos en orden
double calcularDistanciaTotal(Point puntos[], int n)
{
    double distanciaTotal = 0.0;
    // Sumar las distancias entre puntos consecutivos
    for (int i = 0; i < n - 1; i++)
    {
        distanciaTotal += calcularDistancia(puntos[i], puntos[i + 1]);
    }
    return distanciaTotal;
}

// Función para mostrar el punto más cercano y la distancia
void mostrarResultado(Point puntos[], int indiceMasCercano, double distancia)
{
    // Mostrar las coordenadas del punto más cercano y la distancia a este
    std::cout << "El punto más cercano es: (" << puntos[indiceMasCercano].x << ", " << puntos[indiceMasCercano].y << ")\n";
    std::cout << "La distancia al punto más cercano es: " << distancia << std::endl;
}

int main()
{
    int n;
    // Leer el número de puntos
    do
    {
        std::cout << "Ingrese el número de puntos (mínimo 2): ";
        std::cin >> n;
        if (n < 2)
        {
            std::cout << "Se necesitan al menos 2 puntos para calcular las distancias.\n";
        }
    } while (n < 2);

    // Arreglo de estructuras para almacenar las coordenadas (x y)
    Point puntos[n]; 

    // Leer los puntos (manual o predeterminado)
    leerPuntos(puntos, n);

    // Ingresar el punto del usuario
    Point pUsuario;
    std::cout << "Ingrese las coordenadas del punto desde el que calcular la distancia (x, y): ";
    std::cin >> pUsuario.x >> pUsuario.y;

    // Calcular la distancia más cercana
    int indiceMasCercano;
    double distancia = calcularDistanciaMasCercana(puntos, n, pUsuario, indiceMasCercano);

    // Mostrar el resultado
    mostrarResultado(puntos, indiceMasCercano, distancia);

    // Calcular la distancia total de los puntos recorridos en orden
    double distanciaTotal = calcularDistanciaTotal(puntos, n);
    std::cout << "La distancia total de los puntos recorridos en orden es: " << distanciaTotal << std::endl;

    return 0;
}
