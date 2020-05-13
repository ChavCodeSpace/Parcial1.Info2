#ifndef CLIENT_H
#define CLIENT_H
#include <unordered_map>
#include <iostream>

using namespace std;

class Client
{
private:
    unordered_map<char, array<int, 20>> sala_cine;//{filas, asientos}
public:
    Client();
    void asignar_asiento(char fila, int numeo_asiento);

};

#endif // CLIENT_H
