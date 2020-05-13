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
}

Admin::Admin()
{

}
