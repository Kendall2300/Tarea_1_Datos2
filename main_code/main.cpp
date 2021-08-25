#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <string.h>
#include <cstdlib>
#include <array>
#include <algorithm>
using namespace std;

void insertionSort(vector<int> &lista_datos){
    int i, key, j;
    int indice=lista_datos.size();
    for(i=1; i<indice;i++){
        
        key= lista_datos[i];

        j=i-1;

        while (j>=0 && lista_datos[j]>key){
            lista_datos[j+1]=lista_datos[j];
            j = j-1;
        }
        lista_datos[j+1] = key;
    }
}


/*
*leer_archivo
*Este metodo se encarga recibir un string con el nombre del archivo a cargar o leer asi como
*de escribir el los datos leidos en un vector
*@param archivo_entrada corresponde al nombre del archivo a leer
*/
void leer_archivo(string nombre_archivo, vector<int> &lista_datos){
ifstream archivo_entrada(nombre_archivo);
char delimitador=',';
string linea;
while (getline(archivo_entrada,linea,delimitador)){
    int numero_leido=stoi(linea,nullptr);
    lista_datos.push_back(numero_leido);
}
archivo_entrada.close();
}

void obtener_nombre_entrada_salida(string &cadena, string &nombre_archivo, string &nombre_salida){
int primer_delimitador = cadena.find("<");
string cadena2 = cadena.substr(primer_delimitador+1);
int segundo_delimitador=cadena2.find(">");
nombre_archivo=cadena2.substr(0,segundo_delimitador);
primer_delimitador = cadena2.find("<");
cadena = cadena2.substr(primer_delimitador+1);
segundo_delimitador=cadena.find(">");
nombre_salida=cadena.substr(0,segundo_delimitador);
}

void escribir_archivo(string &nombre_salida, vector<int> &lista_datos){
    int indice=lista_datos.size();
    ofstream archivo_salida(nombre_salida);
    for (int i = 0; i < indice; i++)
    {
        archivo_salida << lista_datos[i] << ",";
    }
    archivo_salida.close();
}

int main(){
    ///Entrada del comando para funcionar
    string Entrada, nombre_archivo, nombre_salida;
    vector<int> lista_datos;
    getline(cin,Entrada);
    obtener_nombre_entrada_salida(Entrada, nombre_archivo, nombre_salida);
    leer_archivo(nombre_archivo,lista_datos);
    insertionSort(lista_datos);
    escribir_archivo(nombre_salida,lista_datos);

    return 0;
}