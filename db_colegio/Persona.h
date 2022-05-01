#include <iostream>


using namespace std;

class Persona {
	//Atributos
protected: string nombres, apellidos, direccion, email, fecha_nacimiento;
		 int id_estudiante = 0,carnet = 0,genero = 0, telefono = 0;

		 //Constructor
protected:
	Persona() {

	}
	Persona(string nom, string ape, string dir, string email, string fn, int id, int cnt, int ge, int tel) {
		nombres = nom;
		apellidos = ape;
		direccion = dir;
		email = email;
		fecha_nacimiento = fn;
		id_estudiante = id;
		carnet = cnt;
		genero = ge;
		telefono = tel;
	}
};