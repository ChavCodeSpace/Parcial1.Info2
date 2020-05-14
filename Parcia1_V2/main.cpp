#include "admin.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string leer(string file);
void imprimir(string file);
void escribir_peli(string file,string nombre, string genero, string duracion, int sala, int hora, string clasi);
void escribir_estreno(string file,string nombre, string genero, string duracion, int sala, int hora, string clasi, string fecha);
string char2bin(string texto);
string codi2(string b, int n);

string directorio = "../Data_base/";// directorio de la base de datos

int main()
{
    //variables
    int u=0, opt=0, n=4, opt2=0;
    string admin_pass;
    string t, b;
    string aux1;
    bool flag1=true;

    Admin admin;//Objeto administrador
    while (flag1){
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
                cout<<"2. Agregar proximo estreno"<<endl;
                cout<<"3. Generar Reporte de Ventas"<<endl;
                cin>>opt;
             }
             switch (opt){
             case 1:{
                 string nombre, gen, dur, clas;
                 int sala=0, h, sillas;

                 cout<<"Nombre de la pelicula"<<endl;
                 getline(cin, nombre);
                 cout<<"Genero"<<endl;
                 getline(cin, gen);
                 cout<<"Duracion(min)"<<endl;
                 getline(cin, dur);
                 cout<<"Sala de proyeccion"<<endl;
                 cin>>sala;
                 if (sala > 4){
                     cout<<"solo hay 4 salas"<<endl;
                     break;
                 }
                 cout<<"Hora de proyeccion (24h sin puntos)"<<endl;
                 cin>>h;
                 cout<<"Clasificacion de la pelicula"<<endl;
                 cin>>clas;
                 cout<<"Cuantos hay disponibles para la venta"<<endl;
                 cin>>sillas;

                 escribir_peli(directorio+"cartelera",nombre,gen,dur,sala,h,clas);
                 admin.setSala(sala);
                 admin.agregar_sala(sala, sillas);
                 break;
             }
             case 2:{
                 string nombre_es, gen_es, dur_es, clas_es;
                 int sala=0, h;
                 string date="";

                 cout<<"Nombre de la pelicula"<<endl;
                 getline(cin, nombre_es);
                 cout<<"Genero"<<endl;
                 getline(cin, gen_es);
                 cout<<"Duracion(min)"<<endl;
                 getline(cin, dur_es);
                 cout<<"Sala de proyeccion"<<endl;
                 cin>>sala;
                 if (sala > 4){
                     cout<<"solo hay 4 salas"<<endl;
                     break;
                 }
                 cout<<"Hora de proyeccion (24h sin puntos)"<<endl;
                 cin>>h;
                 cout<<"Clasificacion de la pelicula"<<endl;
                 cin>>clas_es;
                 cout<<"Fecha de estreno"<<endl;
                 cin>>date;

                 escribir_estreno(directorio+"estrenos",nombre_es,gen_es,dur_es,sala,h,clas_es,date);

             }
             }
        }
        else if(u==2){
            bool flag2=true;
            while(flag2){
                cout<<"Bienvenido"<<endl;
                cout<<"Que desea hacer?"<<endl;
                cout<<"1. Ver cartelera"<<endl;
                cout<<"2. Comprar boleta"<<endl;
                cout<<"3. Ver Proximas Peliculas"<<endl;
                cout<<"4. Salir"<<endl;
                cin>>opt2;
                if (opt2 == 1){
                    imprimir(directorio+"cartelera");
                }
                else if (opt2==2){
                    int aux_sala=0;
                    float cobro=0;

                    imprimir(directorio+"cartelera");
                    cout<<"Sala 1: General 2D 7900"<<endl;
                    cout<<"Sala 2: General 3D 10800"<<endl;
                    cout<<"Sala 3: VibroSound 2D 9900"<<endl;
                    cout<<"Sala 4: Vibrosound 3D 11900"<<endl;
                    cout<<"Ingrese la sala de la pelicula que desea ver"<<endl;
                    cin>>aux_sala;
                    admin.precio(aux_sala);
                    admin.imprimir_sala();
                    cout<<"El precio de la boleta es: "<<admin.getPrecio_boletas()<<endl;
                    cout<<"Ingrese el dinero"<<endl;
                    cin>>cobro;
                    if (cobro < admin.getPrecio_boletas()){
                        cout<<"Dinero Insuficiente"<<endl;
                    }else{
                        float temp=0;
                        temp = cobro - admin.getPrecio_boletas();
                        cout<<"Sobrante: "<<temp<<endl;
                    }

                }else if(opt2==3){
                    imprimir(directorio+"estrenos");
                }else{
                    cout<<"Hasta luego"<<endl;
                    flag2=false;
                }
            }
        }else{
            cout<<"Hasta luego"<<endl;
            flag1=false;
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

void imprimir(string file){
    ifstream archivo;
    string aux, aux2,aux3,aux4,aux5,aux6;
    archivo.open(file);
    if(!archivo.is_open()){
        cout<<"Error abriendo el archivo"<<endl;
        exit(1);
    }else{
        while(!archivo.eof()){
            for(string line; getline(archivo, line);){
                for (unsigned int i = 0; i<line.find("/");++i){//hasta que encuentra el primer /
                    aux += line.at(i);
                }
                for (unsigned int i = line.find("/")+1; i<line.find(":");++i){//del / a los :
                    aux2 += line.at(i);
                }
                for (unsigned int i = line.find(":")+1; i<line.find(",");++i){//e los : a la ,
                    aux3 += line.at(i);
                }
                for (unsigned int i = line.find(",")+1; i<line.find(";");++i){//de la , a el ;
                    aux4 += line.at(i);
                }
                for (unsigned int i = line.find(";")+1; i<line.find(".");++i){//del ; al .
                    aux5 += line.at(i);
                }
                for (unsigned int i = line.find(".")+1; i<line.length();++i){//del . al final
                    aux6 += line.at(i);
                }
                cout<<aux<<"|"<<aux2<<"|"<<aux3<<"|"<<aux4<<"|"<<aux5<<"|"<<aux6<<endl;
                aux="";aux2="";aux3="";aux4="";aux5="";aux6="";//se resetean las variables auxiliares para la siguiente linea de texto
                //cout<<endl;
            }
        }
        cout<<endl;
        archivo.close();
    }
}

void escribir_peli(string file,string nombre, string genero, string duracion, int sala, int hora, string clasi){
    ofstream archivo;
    archivo.open(file, ios::app);

    if(!archivo.is_open()){
        cout<<"Error abriendo el archivo"<<endl;
        exit(1);
    }else{
        archivo<<nombre<<"/"<<genero<<":"<<duracion<<","<<sala<<";"<<hora<<"."<<clasi<<endl;
        archivo.close();
    }
}

void escribir_estreno(string file,string nombre, string genero, string duracion, int sala, int hora, string clasi, string fecha){
    ofstream archivo;
    archivo.open(file, ios::app);

    if(!archivo.is_open()){
        cout<<"Error abriendo el archivo"<<endl;
        exit(1);
    }else{
        archivo<<nombre<<"/"<<genero<<":"<<duracion<<","<<sala<<";"<<hora<<"."<<clasi<<"-"<<fecha<<endl;
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

