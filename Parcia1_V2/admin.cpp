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



}

void Admin::llenar_sala()
{
    typedef unordered_map<char, vector<int>> mapa;
    typedef vector<int> vector;
    mapa aux_map;
    vector aux_vector;
    int cont = 1;
    char temp = 'A';
    for (unsigned int i = 0; i<7;i++){
        aux_vector[i]=1;
    }
    while(cont <5){
        for (char j=temp;j<=74;j++){
            aux_map[j]=aux_vector;
        }
        sala_cine.insert(make_pair(cont, aux_map));
        cont++;
    }
}

void Admin::imprimir_sala()
{
    int aux=0;
    cout<<endl;
    for (auto it = sala_cine.begin(); it != sala_cine.end();++it){
        //int auxflag = it->first;
        cout<<"Sala "<<it->first<<endl;
        for (auto jt = (begin(it->second)); jt != end(it->second); ++jt){
            for (int i =0; i<7;i++){
                aux = jt->second[i];
                cout<<"fila "<<jt->first<<" asiento "<<aux;
            }
        }
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
