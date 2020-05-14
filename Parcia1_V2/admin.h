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
    unordered_map<char, array<int, 10>> sala_cine; //{sala, asientos disponibles};

public:
    Admin();
    //get and set members
    int getSala() const;
    void setSala(int value);
    float getPrecio_boletas() const;
    void setPrecio_boletas(float value);
    void precio(int s);
    void promocion();
    void agregar_sala(char fila, int puesto);
    void imprimir_sala();
};

#endif // ADMIN_H
