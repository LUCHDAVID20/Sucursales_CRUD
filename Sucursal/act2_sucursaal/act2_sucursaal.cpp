#include <iostream>
#include "sucursal.h"
using namespace std;

int main() {
    short id_sucursal = 0;
    string nombres, ubicacion, fecha_inauguracion;
    int cantidad_trabajadores, activo;
    int opcion;

    do {
        cout << "\n___________ Menu de Sucursales ___________\n";
        cout << "1. Crear sucursal\n";
        cout << "2. Leer sucursales\n";
        cout << "3. Actualizar sucursal\n";
        cout << "4. Eliminar sucursal\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1: {
            cout << "\nIngrese Nombres: ";
            getline(cin, nombres);
            cout << "Ingrese Ubicacion: ";
            getline(cin, ubicacion);
            cout << "Ingrese Fecha Inauguracion: ";
            getline(cin, fecha_inauguracion);
            cout << "Ingrese Cantidad de Trabajadores: ";
            cin >> cantidad_trabajadores;
            cout << "Activo (1 para Si, 0 para No): ";
            cin >> activo;
            cin.ignore();

            sucursal e(0, nombres, ubicacion, cantidad_trabajadores, fecha_inauguracion, activo);
            e.crear();
            break;
        }
        case 2: {
            sucursal e;
            e.leer();
            break;
        }
        case 3: {
            cout << "\nIngrese el ID a modificar: ";
            cin >> id_sucursal;
            cin.ignore();
            cout << "Ingrese Nombres: ";
            getline(cin, nombres);
            cout << "Ingrese Ubicacion: ";
            getline(cin, ubicacion);
            cout << "Ingrese Fecha Inauguracion: ";
            getline(cin, fecha_inauguracion);
            cout << "Ingrese Cantidad de Trabajadores: ";
            cin >> cantidad_trabajadores;
            cout << "Activo (1 para Si, 0 para No): ";
            cin >> activo;
            cin.ignore();

            sucursal e(id_sucursal, nombres, ubicacion, cantidad_trabajadores, fecha_inauguracion, activo);
            e.actualizar();
            break;
        }
        case 4: {
            cout << "\nIngrese el ID a eliminar: ";
            cin >> id_sucursal;
            sucursal e;
            e.setId_sucursal(id_sucursal);
            e.borrar();
            break;
        }
        case 5:
            cout << "\nSaliendo...\n";
            break;
        default:
            cout << "\nOpcion no valida, intente de nuevo.\n";
        }

    } while (opcion != 5);

    return 0;
}
