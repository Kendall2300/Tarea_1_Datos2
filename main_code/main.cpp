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
    int indice=(sizeof(array)/sizeof(array[0]));
    insertionSort(array,indice);
    //cout << array[5] << endl;
    
    return 0;
}

