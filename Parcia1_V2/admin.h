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
    void imprimir_sala();//metodo para imprimir la sala de cine

};

#endif // ADMIN_H
