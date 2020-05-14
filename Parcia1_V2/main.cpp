#include "admin.h"
#include <iostream>
#include <fstream>
#include <string>
//#include <limits>

using namespace std;

//Admin keyword: sudosu

//Funciones
string leer(string file);
void imprimir(string file);
void imprimir_reporte(string file);
void escribir_peli(string file,string nombre, string genero, string duracion, int sala, int hora, string clasi);
void escribir_estreno(string file,string nombre, string genero, string duracion, int sala, int hora, string clasi, string fecha);
void escribir_factura(string file,int s, float cash, string silla);
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
    bool flag1=true;//control para el ciclo while

    Admin admin;//Objeto administrador
    //admin.llenar_sala();//crea el cine
    //admin.imprimir_sala();//mostrar sala

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
            //codificacion de la clave
            b = char2bin(admin_pass);
            aux1 = codi2(b,n);
            t = leer(directorio+"sudo");//lee la clave encriptada del archivo
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

             case 1:{//Agregar pelicula
                 //variables para los datos de la pelicula
                 string nombre, gen, dur, clas;
                 int sala=0, h;

                 cin.ignore();//Ignora el Enter que queda en el buffer despues de escoger la opcion, ya que presentaba problemas dejando en blanco el primero string
                 cout<<"Nombre de la pelicula"<<endl;
                 getline(cin, nombre);
                 //cin.ignore(numeric_limits<streamsize>::max(),'\n');
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
                 //cout<<"Cuantos hay disponibles para la venta"<<endl;
                 //cin>>sillas;

                 //adiciona la pelicula en la cartelera
                 escribir_peli(directorio+"cartelera",nombre,gen,dur,sala,h,clas);
                 //admin.setSala(sala);
                 //admin.agregar_sala(sala, sillas);
                 break;
                }

             case 2:{//Agregar estreno
                 //variables para los datos de la pelicula que estrenara
                 string nombre_es, gen_es, dur_es, clas_es;
                 int sala=0, h;
                 string date="";

                 cin.ignore();//Ignora el Enter que queda en el buffer despues de escoger la opcion, ya que presentaba problemas dejando en blanco el primero string
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

                 //adiciona la pelicula a la cartelera de estrenos
                 escribir_estreno(directorio+"estrenos",nombre_es,gen_es,dur_es,sala,h,clas_es,date);
                 break;

                }

             case 3:{//Generar reporte
                 //Imprime todas las ventas que se han realizado
                 imprimir_reporte(directorio+"reporte");
                 break;
                }

             }
        }
        else if(u==2){//Parte del Usuario

            bool flag2=true;//control para el ciclo

            while(flag2){
                cout<<"Bienvenido"<<endl;
                cout<<"Que desea hacer?"<<endl;
                cout<<"1. Ver cartelera"<<endl;
                cout<<"2. Comprar boleta"<<endl;
                cout<<"3. Ver Proximas Peliculas"<<endl;
                cout<<"4. Salir"<<endl;
                cin>>opt2;
                if (opt2 == 1){//cartelera
                    //imprime la cartelera
                    imprimir(directorio+"cartelera");
                }
                else if (opt2==2){//compra de boletas
                    //variables auxiliares para la venta
                    int aux_sala=0;
                    float cobro=0;
                    string asiento;

                    //imprime la cartelera aqui tambien para que el usuario tenga la inforamcion disponible para la compra
                    imprimir(directorio+"cartelera");
                    cout<<endl;
                    cout<<"Sala 1: General 2D 7900"<<endl;
                    cout<<"Sala 2: General 3D 10800"<<endl;
                    cout<<"Sala 3: VibroSound 2D 9900"<<endl;
                    cout<<"Sala 4: Vibrosound 3D 11900"<<endl;
                    cout<<endl;
                    cout<<"Ingrese la sala de la pelicula que desea ver"<<endl;
                    cin>>aux_sala;
                    cout<<"Ingrese el asiento"<<endl;
                    cin>>asiento;
                    admin.precio(aux_sala);//dependiendo de la sala pone el precio a la boleta
                    //admin.imprimir_sala();
                    cout<<"El precio de la boleta es: "<<admin.getPrecio_boletas()<<endl;
                    cout<<"Ingrese el dinero"<<endl;
                    cin>>cobro;
                    //verificacion del dinero ingresado
                    if (cobro < admin.getPrecio_boletas()){
                        cout<<"Dinero Insuficiente"<<endl;
                    }else{
                        float temp=0;
                        temp = cobro - admin.getPrecio_boletas();
                        cout<<"Sobrante: "<<temp<<endl;
                    }
                    //escribe la venta generada en el reporte del dia
                    escribir_factura(directorio+"reporte",aux_sala,admin.getPrecio_boletas(), asiento);

                }else if(opt2==3){//estrenos
                    imprimir(directorio+"estrenos");
                }else{
                    //cout<<"Hasta luego"<<endl;
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
//************Funciones****************

//Funcion para leer el archivo de la clave del administrador
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

//funcion para imprimi la cartelera, tanto de estrenos como la normal
void imprimir(string file){
    ifstream archivo;
    string aux, aux2,aux3,aux4,aux5,aux6;
    archivo.open(file);
    if(!archivo.is_open()){
        cout<<"Error abriendo el archivo"<<endl;
        exit(1);
    }else{
        while(!archivo.eof()){
            //se separa cada parte del texto por los separadores y se guarda en variables auxiliares
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
                cout<<aux<<"|"<<aux2<<"|"<<aux3<<"|"<<aux4<<"|"<<aux5<<"|"<<aux6<<endl;//imprime los datos extraidos
                aux="";aux2="";aux3="";aux4="";aux5="";aux6="";//se resetean las variables auxiliares para la siguiente linea de texto
                //cout<<endl;
            }
        }
        cout<<endl;
        archivo.close();
    }
}

//funcion para escribir en la cartelera
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

//funcion para escribir en la cartelera de estrenos
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

//funcion para generar el reporte de ventas
void escribir_factura(string file, int s, float cash, string silla){
    ofstream archivo;
    archivo.open(file, ios::app);

    if(!archivo.is_open()){
        cout<<"Error abriendo el archivo"<<endl;
        exit(1);
    }else{
        archivo<<"Sala: "<<s<<" venta: "<<cash<<" asiento "<<silla<<endl;
        archivo.close();
    }

}

//funcion para mostrar el reporte de ventas
void imprimir_reporte(string file){
    string texto;
    ifstream archivo;
    archivo.open(file);
    if(!archivo.is_open()){
        cout<<"Error abriendo el archivo"<<endl;
        exit(1);
    }else{
        while(!archivo.eof()){
            getline(archivo, texto);
            cout<<texto<<endl;
        }
        cout<<endl;
        archivo.close();
    }
}

//funcion para codificar la clave ingresada por el usuario administrador, igual que en la practica 3
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

//funcion para convertir caracteres a su parte binaria, para la codificacion de la clave ingresada
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

