#include "admin.h"

int Admin::getSala() const
{
    return sala;
}

void Admin::setSala(int value)
{
    sala = value;
}

void Admin::promocion()
{

//    for(int i=0; i<7;i++){
//       if (Salas.at(i)>50){
//           setPrecio();

//       }
    //    }
}

void Admin::agregar_sala(char fila, int puesto)
{
    sala_cine.insert(make_pair(fila, puesto));
}

void Admin::imprimir_sala()
{
    cout<<endl;
    for (auto it = sala_cine.begin(); it != sala_cine.end();++it){
        cout<<"La sala: "<<it->first<<" tiene "<<it->second<<" asientos disponibles."<<endl;
    }
}



float Admin::getPrecio_boletas() const
{
    return precio_boletas;
}

void Admin::setPrecio_boletas(float value)
{
    precio_boletas = value;
}

void Admin::precio(int s)
{
    switch (s) {
    case 1:{
        this->setPrecio_boletas(7900);
        break;
    }
    case 2:{
        this->setPrecio_boletas(10800);
        break;
    }
    case 3:{
        this->setPrecio_boletas(9900);
        break;
    }
    case 4:{
        this->setPrecio_boletas(11900);
        break;
    }

    }
}

Admin::Admin()
{

}
