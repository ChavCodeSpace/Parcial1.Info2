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
    //Se definen dos variables mapa y vector para usarlas como auxiliares para llenar el mapa grande
    //Luego del llenado de las variables auxiliares se insertan en el mapa principal
    typedef unordered_map<char, vector<int>> mapa;
    typedef vector<int> vector;
    mapa aux_map;
    vector aux_vector;
    int cont = 1;
    char temp = 'A';
    for (unsigned int i = 0; i<7;i++){
        aux_vector.push_back(0);
    }
    while(cont <5){
        for (char j=temp;j<=74;j++){
            aux_map[j]=aux_vector;
        }
        sala_cine.insert(make_pair(cont, aux_map));
        cont++;
    }
}

void Admin::imprimir_salas()
{
    //La idea es recorrer todo el mapa con el uso de iteradores para sacar los datos e imprimirlos en pantalla
    cout<<endl;
    for (auto it = sala_cine.begin(); it != sala_cine.end();++it){
        //int auxflag = it->first;
        cout<<"Sala "<<it->first<<endl;//imprime la primera clave, que es la sala
        for (auto jt = (begin(it->second)); jt != end(it->second); ++jt){
            cout <<jt->first<<" ";//imprime la clave del segundo mapa que es la fila
            for(auto j : jt->second){
                cout << jt->second[j];//imprime los asientos
            }
            cout<<endl;
        }
        cout<<endl;
    }
}

void Admin::print_sala(int s)
{
    for(auto it = sala_cine.begin(); it != sala_cine.end();++it){
        if (s == it->first){
            cout<<"Sala "<<it->first<<endl;//imprime la primera clave, que es la sala
            for (auto jt = (begin(it->second)); jt != end(it->second); ++jt){
                cout <<jt->first<<" ";
                for(auto j : jt->second){
                    cout << jt->second[j];
                }
                cout<<endl;
            }
            cout<<endl;
        }
    }
}

void Admin::setPuesto(int s, char fila, int silla)
{
    //recorre todo el mapa y cuando entra a la sala escogida, ahi busca la fila ingresada y pone un uno en la posicion escogida por el cliente
    for(auto it = sala_cine.begin(); it != sala_cine.end();++it){
        if (s == it->first){
            for (auto jt = (begin(it->second)); jt != end(it->second); ++jt){
               if (fila == jt->first){
                    for (auto j : jt->second){
                        if (j==silla){
                            jt->second[j]=1;
                        }
                    }
               }
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
