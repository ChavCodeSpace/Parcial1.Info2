#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string leer(string file);
void escribir_peli(string file, string genero, string duracion, int sala, int hora, string clasi);
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



    cout<<"Bienvenido"<<endl;
    cout<<"Tipo de Usuario:"<<endl;
    cout<<"1. Admin User"<<endl;
    cout<<"2. Normal User"<<endl;
    cout<<"3. Salir"<<endl;
    cin>>u;
    if (u==1){//Parte del administrador: Ingreso de datos de usuario
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
                int sal=0, h;

                cout<<"Nombre de la pelicula"<<endl;
                cin>>nombre;
                cout<<"Genero"<<endl;
                cin>>gen;
                cout<<"Duracion"<<endl;
                cin>>dur;
                cout<<"Sala de proyeccion"<<endl;
                cin>>sal;
                cout<<"Hora de proyeccion (24h sin puntos)"<<endl;
                cin>>h;
                cout<<"Clasificacion de la pelicula"<<endl;
                cin>>clas;

                escribir_peli(directorio+nombre,gen,dur,sal,h,clas);

             }
         }
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

void escribir_peli(string file, string genero, string duracion, int sala, int hora, string clasi){
    ofstream archivo;
    archivo.open(file);

    if(!archivo.is_open()){
        cout<<"Error abriendo el archivo"<<endl;
        exit(1);
    }else{
        archivo<<genero<<endl;
        archivo<<duracion<<endl;
        archivo<<sala<<endl;
        archivo<<hora<<endl;
        archivo<<clasi<<endl;
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
