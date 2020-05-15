#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>

using namespace std;

class Admin
{
private:
    float precio_boletas;
    int sala;
    unordered_map<int, unordered_map<char, vector<int>>> sala_cine;
    //la clave del mapa es la sala y el valor es un mapa cuya clave es la fila y el valor es un vector que se llena con ceros que representa los asientos.
    //La idea es que cuando un usuario ingrese y escoja el asiento, en el vector esta posicion se marca en 1 para mostrar que esta ocupado.

public:
    Admin();
    //get and set members
    int getSala() const;
    void setSala(int value);
    float getPrecio_boletas() const;
    void setPrecio_boletas(float value);
    //Metodos
    void precio(int s);//metodo para poner el precio del boleto dependiendo de la sala
    void promocion();//metodo para dar promociones dependiendo de los asientos disponibles
    void llenar_sala();//metodo para llenar los asientos en la sala de cine
    void imprimir_salas();//metodo para imprimir las salas de cine
    void print_sala(int s);//metodo para imprimir la sala escogida por el usuario
    void setPuesto(string puesto);

};

#endif // ADMIN_H
