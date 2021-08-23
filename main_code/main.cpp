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

void insertionSort(vector<int> &arr, int indice){
    int i, key, j;
    for(i=1; i<indice;i++){
        
        key= arr[i];

        j=i-1;

        while (j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}



int main(){
    ifstream archivo_entrada("archivo.txt");
    char delimitador=',';
    string linea;
    vector<int> array;
    while (getline(archivo_entrada,linea,delimitador)){
        int numero=stoi(linea,nullptr);
        array.push_back(numero);
    }
    archivo_entrada.close();
    int indice=array.size();
    insertionSort(array,indice);
    ofstream archivo_salida("archivo_resultado.txt");
    for (int i = 0; i < indice; i++)
    {
        archivo_salida << array[i] << ",";
    }
    archivo_salida.close();
    //cout << indice << " Valor del indice" << endl;
    //cout << array[0] << endl;
    return 0;
}

