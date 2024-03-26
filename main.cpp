#include <iostream>
#include "Moduls.h"

//variables globales
int countRotationsValue = 0;

int main(){

    int dimension;
    std::cout << "Ingresa la dimension de la matriz: ";std::cin>>dimension;

    int **dataMatrix = createMatrix(dimension);
    showMatrix(dataMatrix, dimension);

    //llamado de función de cambio
    std::cout<<std::endl;
    std::cout<<"nueva matriz"<<std::endl;
    showMatrix(changeMatrix(dataMatrix, dimension), dimension);

    deleteMemoryUsed(dataMatrix, dimension);
    return 0;

}
