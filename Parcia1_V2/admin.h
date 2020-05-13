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
    //sala de cine
    array<int, 7> Salas;//7 Salas de cine
    float precio_boletas;
    int sala, asientos;

public:
    Admin();
    //get and set members
    int getSala() const;
    void setSala(int value);
    int getAsientos() const;
    void setAsientos(int value);
    void setPrecio(float);
    void promocion();
    void llenar_cartelera();


};

#endif // ADMIN_H
