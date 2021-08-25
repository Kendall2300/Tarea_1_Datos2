/**
 * @file main.cpp
 * @author Kendall Adolfo Martinez Carvajal (kendallmc@estudiantec.cr)
 * @brief Este codigo lee archivo que contiene enteros separados por coma, guarda los enteros
 * en un vector y los ordena por medio del algoritmo insertion sort para luego escribirlos en otro
 * archivo especificado
 * @version 0.1
 * @date 2021-08-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

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

/**
*@brief Este metodo se encarga de recibir un vector que luego ordena por medio del algoritmo insertion sort
*@param lista_datos corresponde al vector creado del archivo que se desea ordenar
*/
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

/**
*@brief Este metodo se encarga recibir un string con el nombre del archivo a cargar o leer asi como
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

/**
*@brief Este metodo se encarga de recibir cadenas de string con el fin de obtener el nombre del archivo a
*leer y el nombre del archivo para guardar los enteros ordenados
*
*@param cadena recibe un string con la sentencia del comando para iniciar el programa 
*@param nombre_archivo recibe un string que corresponde al nombre del archivo a leer
*@param nombre_salida recibe un string que corresponde al nombre del archivo que se desea crear
*/
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

/**
 * @brief Escribe los datos ordenados en un archivo de nombre especificado al inicio del programa
 * 
 * @param nombre_salida recibe un string que corresponde al nombre del archivo a crear
 * @param lista_datos recibe un vector que corresponde a la lista de enteros ordenados
 */
void escribir_archivo(string &nombre_salida, vector<int> &lista_datos){
    int indice=lista_datos.size();
    ofstream archivo_salida(nombre_salida);
    for (int i = 0; i < indice; i++)
    {
        archivo_salida << lista_datos[i] << ",";
    }
    archivo_salida.close();
}

/**
 * @brief El metodo principal del programa desde aqui se llaman todas las funciones para llevar a cabo los procedimientos requeridos
 * 
 * @return int Retorna un valor para terminar el programa
 */
int main(){
    string Entrada, nombre_archivo, nombre_salida;
    vector<int> lista_datos;
    getline(cin,Entrada);
    obtener_nombre_entrada_salida(Entrada, nombre_archivo, nombre_salida);
    leer_archivo(nombre_archivo,lista_datos);
    insertionSort(lista_datos);
    escribir_archivo(nombre_salida,lista_datos);

    return 0;
}