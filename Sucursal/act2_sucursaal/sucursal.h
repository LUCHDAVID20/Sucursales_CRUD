#pragma once
#include "ConexionBD.h"
#include <iostream>
#include <mysql.h>
#include <string>
using namespace std;

class sucursal {
public:
    short id_sucursal;
    string nombres, ubicacion, fecha_inauguracion;
    int cantidad_trabajadores = 0, activo;

    // Constructor por defecto
    sucursal() {}

    // Constructor con parámetros
    sucursal(short id_s, string nom, string ub, int c_t,  string f_i, int ac) {
        id_sucursal = id_s;
        nombres = nom;
        ubicacion = ub;
        fecha_inauguracion = f_i;
        cantidad_trabajadores = c_t;
        activo = ac;
    }

    // Métodos Set
    void setId_sucursal(short s) { id_sucursal = s; }
    void setNombres(string n) { nombres = n; }
    void setUbicacion(string u) { ubicacion = u; }
    void setFecha_inauguracion(string f) { fecha_inauguracion = f; }
    void setCantidad_trabajadores(int ct) { cantidad_trabajadores = ct; }
    void setActivo(int a) { activo = a; }

    // Métodos Get
    short getId_sucursal() { return id_sucursal; }
    string getNombres() { return nombres; }
    string getUbicacion() { return ubicacion; }
    string getFecha_inauguracion() { return fecha_inauguracion; }
    int getCantidad_trabajadores() { return cantidad_trabajadores; }
    int getActivo() { return activo; }

    // Método para insertar en la base de datos
    void crear() {
        int q_estado = 0;
        ConexionBD cn = ConexionBD();
        cn.abrir_conexion();
        if (cn.getConector()) {
            string ct = to_string(cantidad_trabajadores);
            string ac = to_string(activo);
            string consulta = "INSERT INTO sucursales(nombre, ubicacion, cantidad_trabajadores, fecha_inauguracion, activo) VALUES ('" + nombres + "','" + ubicacion + "', '" + ct + "', '" + fecha_inauguracion + "', " + ac + ");";
            const char* c = consulta.c_str();
            q_estado = mysql_query(cn.getConector(), c);

            if (!q_estado) {
                cout << "Ingreso de datos exitoso .... " << endl;
            }
            else {
                cout << "Consulta fallida"  << endl;
            } //<< mysql_error(cn.getConector())
        }
        else {
            cout << "Conexion fallida" << endl;
        }
        cn.cerrar_conexion();
    }


    void leer() {
        int q_estado = 0;
        ConexionBD cn = ConexionBD(); 
        MYSQL_ROW fila;
        MYSQL_RES* resultado;
        cn.abrir_conexion();
        if (cn.getConector()) {
            cout << "________________Lectura de Datos__________________" << endl;
            string consulta = "SELECT id_sucursal, nombre, ubicacion, cantidad_trabajadores, fecha_inauguracion, IF(activo = 1, 'Si tiene activos', 'No tiene activos') as activo FROM sucursales;";

            const char* c = consulta.c_str();
            q_estado = mysql_query(cn.getConector(), c);

            if (!q_estado) {
                resultado = mysql_store_result(cn.getConector());
                while (fila = mysql_fetch_row(resultado)) {
                    cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5]  << endl;
                }
            }
            else {
                cout << "Consulta fallida" << endl;
            }
        }
        else {
            cout << "Fallo la conexion" << endl;
        }
        cn.cerrar_conexion();
    }

    void actualizar() {
        int q_estado = 0;
        ConexionBD cn = ConexionBD();
        cn.abrir_conexion();
        if (cn.getConector()) {
            string ct = to_string(cantidad_trabajadores);
            string ac = to_string(activo);          
            string consulta = "UPDATE sucursales SET "
       
                "nombre='" + nombres + "', "
                "ubicacion='" + ubicacion + "', "
                "cantidad_trabajadores=" + ct + ", "
                "fecha_inauguracion='" + fecha_inauguracion + "', "
                "activo=" + ac +
                " WHERE id_sucursal=" + to_string(id_sucursal) + ";";
            const char* c = consulta.c_str();
            q_estado = mysql_query(cn.getConector(), c);

            if (!q_estado) {
                cout << "Ingreso de datos exitoso .... " << endl;
            }
            else {
                cout << "Consulta fallida" << endl;
            }
        }
        else {
            cout << "Conexion fallida" << endl;
        }
        cn.cerrar_conexion();

    }


    void borrar() {
        int q_estado = 0;
        ConexionBD cn = ConexionBD();
        cn.abrir_conexion();
        if (cn.getConector()) {
            string ct = to_string(cantidad_trabajadores);
            string ac = to_string(activo);
            string consulta = "delete from sucursales WHERE id_sucursal=" + to_string(id_sucursal) + ";";
            const char* c = consulta.c_str();
            q_estado = mysql_query(cn.getConector(), c);

            if (!q_estado) {
                cout << "Eliminacion de datos exitoso .... " << endl;
            }
            else {
                cout << "Eliminacion fallida" << endl;
            }
        }
        else {
            cout << "Conexion fallida" << endl;
        }
        cn.cerrar_conexion();

    }






};
