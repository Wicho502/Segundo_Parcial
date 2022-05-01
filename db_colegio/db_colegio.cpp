#include <iostream>
#include <mysql.h>
#include "Estudiante.h"

using namespace std;

int main() {

    int opcion;
    bool repetir = true;

    string nombres, apellidos, direccion, email, fecha_nacimiento;
    int id_estudiante, carnet, genero, telefono;

    do {
        cout << "---MENU PRINCIPAL---" << endl;
        cout << "--------------------" << endl;
        cout << "1.  CREAR ESTUDIANTE" << endl;
        cout << "2.  LISTA DE ESTUDIANTES" << endl;
        cout << "3.  MODIFICAR ESTUDIANTE" << endl;
        cout << "4.  ELIMINAR ESTUDIANTE" << endl;
        cout << "0.  SALIR" << endl;

        cout << "\n\tSELECCIONE UNA OPCION: "; cin >> opcion;

        switch (opcion){
        case 1:
            cout << "Ingrese ID Estudiante: "; cin >> id_estudiante;
            cout << "Ingrese Carnet: "; cin >> carnet;
            cout << "Ingrese Nombres: "; getline(cin, nombres);
            cout << "Ingrese Apellidos: "; getline(cin, apellidos);
            cout << "Ingrese Direccion: "; getline(cin, direccion);
            cout << "Ingrese Telefono: "; cin >> telefono;
            cin.ignore();
            cout << "Ingrese Genero 0 = M, 1 = F: "; cin >> genero;
            cout << "Ingrese Email: "; cin >>email;
            cout << "Ingrese Fecha de Nacimiento: "; cin >> fecha_nacimiento;

                break;
        case 2:  
                
                break;
        case 3:
              
                break;
        case 4:
               
                
                break;
            case 0:
            repetir = false;
            break;
        }
    } while (repetir);

    Estudiante c = Estudiante(id_estudiante, carnet, nombres, apellidos, direccion, telefono, genero, email, fecha_nacimiento);
    c.crear();
    c.leer();
    c.actualizar();
    c.borrar();

	system("pause");
		return 0;
}