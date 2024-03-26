#include <iostream>
#include "Moduls.h"

//Variables globales
int countRotationsValue = 0;

//Funciones
int **createMatrix(int dimension){
    //Función encargada de crear una matriz de cualquier dimensión
    //recibe un dato entero que especifica la dimensión de la matriz
    //retorna la matriz creada

    int **newMatrix = new int *[dimension];
    int centerCoord = dimension / 2, value = 1;

    for(int i = 0; i < dimension; i++){
        newMatrix[i] = new int[dimension];

        for(int j = 0; j < dimension; j++){
            if(i == centerCoord && j == centerCoord){
                newMatrix[i][j] = 0; //cambio
            }else{
                newMatrix[i][j] = value;
                value++;
            }
        }
    }
    return newMatrix;
};
void deleteMemoryUsed(int **matrix, int dimension){
    for(int i = 0; i < dimension; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
}
int countRotations(){
    //función que se encarga de monitorear las veces que rota la matriz
    //no recibe parametros
    //constantemente se debe llamar para hacer seguimiento usando la variable
    //global

    return countRotationsValue++;
}
int **changeMatrix(int **defaultMatrix, int dimension){
    //Esta función se encarga de hacer el giro de la matriz 90 grados
    //recibe un puntero que apunta a un array de arrays
    //retorna la matriz modificada

    int **oldMatrix = createMatrix(dimension);

    int staticColumns = dimension-1;
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            *(*(defaultMatrix+i)+j) = *(*(oldMatrix+j)+staticColumns);
            //cambio de valores con un valor estatico
        }
        staticColumns--;
    }
    countRotations(); //rastrea la cantidad de giros
    deleteMemoryUsed(oldMatrix, dimension);
    return defaultMatrix;
}


void showMatrix(int **matrix, int dimension){
    //función que muestra la matriz en consola
    //recibe la dimension de la matriz
    //no retorna datos

    for(int i = 0; i < dimension;i++){
        for(int j = 0; j < dimension; j++){
            std::cout << matrix[i][j] << ' ';
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;

}
bool compareValue(int **originalMatrix, int **matrixChange, int posComparisonValue, int array[]){
    //Funcion que compara los valores de las matrices respecto a la clave
    //Recibe dos matrices, un arreglo, y un valor entero
    //Retorna un booleano

    int comparisonValue = array[posComparisonValue]; //Con esto saco el valor del arreglo para hacer la comparacion
    int fil = array[0], col = array[1]; //Fila y columna en donde esta el valor en cada matriz

    switch(comparisonValue){
    case -1:
        return (matrixChange[fil][col] <= originalMatrix[fil][col]);

    case 0:
        return (matrixChange[fil][col] != originalMatrix[fil][col]);

    case 1:
        return (matrixChange[fil][col] >= originalMatrix[fil][col]);
    }
    return false;
}

