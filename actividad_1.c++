#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Cliente {
private:
    int codigo;
    string nombre;
    int edad;
    string documento;
public:
    Cliente(int c, string n, int e, string d) {

        if (c <= 0) {
            throw invalid_argument("El codigo debe ser mayor que cero.");
        }

        if (n.empty()) {
            throw invalid_argument("El nombre no puede estar vacio.");
        }

        if (e < 18) {
            throw invalid_argument("La edad debe ser mayor o igual a 18.");
        }

        if (d.empty()) {
            throw invalid_argument("El documento no puede estar vacio.");
        }
        codigo = c;
        nombre = n;
        edad = e;
        documento = d;
    }
    void mostrarCliente() {
        cout << "\n DATOS: \n";
        cout << "Codigo: " << codigo << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Documento: " << documento << endl;
    }
};

int main() {
    while (true) {
        try {
            int codigo, edad;
            string nombre, documento;

            cout << "\nIngrese codigo: ";
            cin >> codigo;

            cin.ignore();

            cout << "Ingrese nombre: ";
            getline(cin, nombre);

            cout << "Ingrese edad: ";
            cin >> edad;

            cin.ignore();

            cout << "Ingrese documento: ";
            getline(cin, documento);

            Cliente c1(codigo, nombre, edad, documento);

            cout << "\nCliente registrado correctamente.\n";
            c1.mostrarCliente();

            break;
        }
        catch (invalid_argument &e) {
            cout << "\nError: " << e.what() << endl;
            cout << "Intente nuevamente.\n";
        }
    }

    return 0;
}