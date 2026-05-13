#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <limits> // Para limpiar el buffer de entrada

using namespace std;

// Variables Globales
double notas[5];
string nombreEstudiante = "No registrado";
double promedioFinal = 0;

// Funcion para validar que la entrada sea un numero
void validarEntrada() {
    if (cin.fail()) {
        cin.clear(); // Limpia el estado de error
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora caracteres invalidos
        cout << "Error: Por favor ingrese un valor numerico valido.\n";
    }
}

void operacionesBasicas() {
    int opMat;
    double n1, n2;
    cout << "\n--- SUBMENÚ DE OPERACIONES ---" << endl;
    cout << "1. Suma\n2. Resta\n3. Multiplicacion\n4. Division\nElija: ";
    cin >> opMat;
    validarEntrada();

    cout << "Ingrese primer numero: "; cin >> n1; validarEntrada();
    cout << "Ingrese segundo numero: "; cin >> n2; validarEntrada();

    switch(opMat) {
        case 1: cout << "Resultado Suma: " << n1 + n2 << endl; break;
        case 2: cout << "Resultado Resta: " << n1 - n2 << endl; break;
        case 3: cout << "Resultado Multiplicacion: " << n1 * n2 << endl; break;
        case 4:
            if(n2 != 0) cout << "Resultado Division: " << n1 / n2 << endl;
            else cout << "Error: No se puede dividir para cero." << endl;
            break;
        default: cout << "Opcion de operacion no valida." << endl;
    }
}

void registroDeNotas() {
    double suma = 0, mayor, menor;
    int aprobados = 0, reprobados = 0;

    cout << "\nIngrese nombre del estudiante: ";
    cin.ignore();
    getline(cin, nombreEstudiante);

    for(int i = 0; i < 5; i++) {
        do {
            cout << "Ingrese nota " << i + 1 << " (0-10): ";
            cin >> notas[i];
            if (cin.fail() || notas[i] < 0 || notas[i] > 10) {
                cout << "Nota invalida. Intente de nuevo." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        } while(true);

        suma += notas[i];
        if(i == 0) mayor = menor = notas[i];
        if(notas[i] > mayor) mayor = notas[i];
        if(notas[i] < menor) menor = notas[i];
        if(notas[i] >= 7) aprobados++;
        else reprobados++;
    }
    promedioFinal = suma / 5;
    cout << "\n--- PROCESAMIENTO COMPLETADO ---" << endl;
    cout << "Promedio: " << promedioFinal << "\nNota Mayor: " << mayor << "\nNota Menor: " << menor << endl;
    cout << "Aprobados: " << aprobados << " | Reprobados: " << reprobados << endl;
}

void guardarEnArchivo() {
    // Crea el archivo resultados.txt o añade informacion si ya existe
    ofstream archivo("resultados.txt", ios::app);

    if (archivo.is_open()) {
        time_t t = time(0);
        char* fecha = ctime(&t);

        archivo << "========================================" << endl;
        archivo << "ESTUDIANTE: " << nombreEstudiante << endl;
        archivo << "LENGUAJE UTILIZADO: C++" << endl;
        archivo << "FECHA DE REGISTRO: " << fecha;
        archivo << "PROMEDIO OBTENIDO: " << promedioFinal << endl;
        archivo << "NOTAS: ";
        for(int i = 0; i < 5; i++) archivo << notas[i] << " ";
        archivo << "\n========================================\n" << endl;

        archivo.close();
        cout << "\nDatos guardados exitosamente en 'resultados.txt'." << endl;
    } else {
        cout << "Error al crear o abrir el archivo." << endl;
    }
}

int main() {
    int opcion;
    do {
        cout << "\n--- APLICATIVO INTERACTIVO UTA ---" << endl;
        cout << "1. Operaciones basicas\n2. Registro de notas\n3. Guardar resultados\n4. Salir\nOpcion: ";
        cin >> opcion;

        if(cin.fail()) {
            validarEntrada();
            continue;
        }

        switch(opcion) {
            case 1: operacionesBasicas(); break;
            case 2: registroDeNotas(); break;
            case 3: guardarEnArchivo(); break;
            case 4: cout << "Saliendo del programa..." << endl; break;
            default: cout << "Opcion no valida." << endl;
        }
    } while(opcion != 4);

    return 0;
}
