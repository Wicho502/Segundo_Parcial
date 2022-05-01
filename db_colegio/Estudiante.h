#include <iostream>
#include <mysql.h>
#include <string>
#include "Persona.h"
#include "ConexionBD.h"

using namespace std;

class Estudiante : Persona {
	//Atributos

public:
	Estudiante() {}

	Estudiante(string nom, string ape, string dir, string email, string fn, int id, int cnt, int ge, int tel) : Persona(nom,ape,dir,email,fn,id,cnt,ge,tel) {
	}

	//Metodos
	//set(modificar)

	void setId_estudiante(int id) { id_estudiante = id; }
	void setCarnet(int cnt) { carnet = cnt; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	void setGenero(int ge) { genero = ge; }
	void setEmail(string email) { email = email; }
	void setFecha_nacimiento(string fn) { fecha_nacimiento = fn; }

	//get(mostrar)

	int getId_estudiante() { return id_estudiante; }
	int getCarnet() { return carnet; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	int getGenero() { return genero; }
	string getEmail() { return email; }
	string getFecha_nacimiento() { return fecha_nacimiento; }
	

	//METODOS CRUD

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(telefono);
			string c = to_string(carnet);
			string id = to_string(id_estudiante);
			string g = to_string(genero);
			string insert = "INSERT INTO estudiante(id_estudiante, carnet, nombres, apellidos, direccion, telefono, genero,email, fecha_nacimiento) VALUES('" + id + "','" + c + "','" + nombres + "','"+ apellidos + "','"+ direccion +"','" + t + "','"+ g +"','"+ email+ "',' "+ fecha_nacimiento +"); ";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso..." << endl;
			}
			else {
				cout << "xxx Error al Ingresar xxx" << endl;
			}
		}
		else {
			cout << "xx-- Error en la Conexion --xx" << endl;
		}
		cn.cerrar_conexion();
	}

	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "Select * from estudiante";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "-----------------ESTUDIANTES---------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << ". " << fila[1] << "||" << fila[2] << "||" << fila[3] << "||" << fila[4] << "||" << fila[5]<<"||" << fila[6] << "||" << fila[7] << "||"<<fila[8]<<"||" << endl;
				}
			}
			else {
				cout << "xxx Error al Ingresar Informacion xxx" << endl;
			}
		}
		else {
			cout << "xx-- Error en la Conexion --xx" << endl;
		}
		cn.cerrar_conexion();
	}

	void actualizar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(telefono);
			string c = to_string(carnet);
			string id = to_string(id_estudiante);
			string g = to_string(genero);
			string insert = "UPDATE estudiante(id_estudiante, carnet, nombres, apellidos, direccion, telefono, genero,email, fecha_nacimiento) SET ('" + id + "','" + c + "','" + nombres + "','" + apellidos + "','" + direccion + "','" + t + "','" + g + "','" + email + "',' " + fecha_nacimiento + ") WHERE (id_estudiante = " + id + "); ";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Actualizacion Exitosa..." << endl;
			}
			else {
				cout << "xxx Error en la actualizacion xxx" << endl;
			}
		}
		else {
			cout << "xx-- Error en la Conexion --xx" << endl;
		}
		cn.cerrar_conexion();
	}

	void borrar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string id = to_string(id_estudiante);
			string insert = "DELETE  FROM estudiante(id_estudiante = " + id + "); ";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Borrado Exitoso..." << endl;
			}
			else {
				cout << "xxx Error al Borrar registro xxx" << endl;
			}
		}
		else {
			cout << "xx-- Error en la Conexion --xx" << endl;
		}
		cn.cerrar_conexion();
	}

};
