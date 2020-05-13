#include "admin.h"
#include "client.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string leer(string file);
void escribir_peli(string file,string nombre, string genero, string duracion, int sala, int hora, string clasi);
string char2bin(string texto);
string codi2(string b, int n);

string directorio = "../Data_base/";// directorio de la base de datos

int main()
{
    //variables
    int u=0, opt=0, n=4;
    string admin_pass;
    string t, b;
    string aux1;

    Admin admin;//Objeto administrador

    cout<<"Bienvenido"<<endl;
    cout<<"Eres:"<<endl;
    cout<<"1. Administrador"<<endl;
    cout<<"2. Cliente"<<endl;
    cout<<"3. Salir"<<endl;
    cin>>u;

    if (u==1){//Parte del administrador


        cout <<"Ingrese password"<<endl;
        cin >>admin_pass;
        b = char2bin(admin_pass);
        aux1 = codi2(b,n);
        t = leer(directorio+"sudo");
        if (t != aux1)
            cout<<"Clave incorrecta"<<endl;
        else{
            cout<<"Bienvenido"<<endl;
            cout<<"Que desea realizar?"<<endl;
            cout<<"1. Agregar Pelicula"<<endl;
            cin>>opt;
         }
         switch (opt){
             case 1:{
                string nombre, gen, dur, clas;
                int sala=0, h, sillas;

                cout<<"Nombre de la pelicula"<<endl;
                cin>>nombre;                
                cout<<"Genero"<<endl;
                cin>>gen;                
                cout<<"Duracion(min)"<<endl;
                cin>>dur;                
                cout<<"Sala de proyeccion"<<endl;
                cin>>sala;
                admin.setSala(sala);
                cout<<"Hora de proyeccion (24h sin puntos)"<<endl;
                cin>>h;
                cout<<"Clasificacion de la pelicula"<<endl;
                cin>>clas;
                cout<<"Cuantos asientos disponibles"<<endl;
                cin>>sillas;
                admin.setAsientos(sillas);
                cout<<"Precio de la boleta"<<endl;

                escribir_peli(directorio+"cartelera",nombre,gen,dur,sala,h,clas);


             }
         }
    }
    else if(u==2){
        cout<<"Bienvenido"<<endl;
        cout<<"Que desea hacer?"<<endl;
        cout<<"1. Ver cartelera"<<endl;
        cout<<"2. Comprar boleta"<<endl;
    }
    //cout << "Hello World!" << endl;
    return 0;

}


string leer(string file){
    ifstream archivo;
    archivo.open(file);

    string textoLinea,texto;

    if(!archivo.is_open()){
        cout<<"Error abriendo el archivo"<<endl;
        exit(1);
    }else{
        while (!archivo.eof()) {
            getline(archivo,textoLinea);
            //cout<<textoLinea;
            texto+=textoLinea;
        }
        cout<<endl;
        archivo.close();
    }
    return texto;
}

void escribir_peli(string file,string nombre, string genero, string duracion, int sala, int hora, string clasi){
    ofstream archivo;
    archivo.open(file, ios::app);

    if(!archivo.is_open()){
        cout<<"Error abriendo el archivo"<<endl;
        exit(1);
    }else{
        archivo<<nombre<<"/"<<genero<<"/"<<duracion<<"/"<<sala<<"/"<<hora<<"/"<<clasi<<endl;
        archivo.close();
    }
}

string codi2(string b, int n){
    string aux, aux_bloq, resultado="";

    cout<<endl;
    for(unsigned int i=0; i<b.length(); i+=n){
        string grupo = b.substr(i,n);
        aux = grupo;
        for(unsigned int i=0; i<grupo.length(); i++){
            if (i<(grupo.length()-1)){
                grupo[i+1]=aux[i];
            }else {
                grupo[0]=aux[i];
            }
        }
        aux_bloq=grupo;
        resultado+=aux_bloq;
    }
    //for(unsigned int i=0; i<resultado.length(); i+=n){
    //    cout<<resultado.substr(i,n)<<endl;
    //}
    //escribir(directorio+nombre,resultado);
    return resultado;
}

string char2bin(string texto){
    string binario = "";
    int letra;
    for (unsigned int i=0; i<texto.length(); i++) {
        string binLetra[8];
        letra = texto[i];
        for (int j=7;j>=0;j--) {
            binLetra[j]=letra%2+48;
            letra/=2;
        }
        for(int j=0; j<8; j++){
            //cout<<binLetra[j];
            binario += binLetra[j];
        }
        //cout<<endl;
    }
    return binario;
}
