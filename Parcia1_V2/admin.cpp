#include "admin.h"

int Admin::getSala() const
{
    return sala;
}

void Admin::setSala(int value)
{
    sala = value;
}

int Admin::getAsientos() const
{
    return asientos;
}

void Admin::setAsientos(int value)
{
    asientos = value;
    for(int i=0; i<7;i++){
        Salas.at(sala) = asientos;
    }
}

void Admin::promocion()
{

//    for(int i=0; i<7;i++){
//       if (Salas.at(i)>50){
//           setPrecio();

//       }
//    }
}



Admin::Admin()
{

}
