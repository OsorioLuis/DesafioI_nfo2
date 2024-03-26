#ifndef MODULS_H
#define MODULS_H
/**
 * @brief changeMatrix
 * @param defaultMatrix
 * @param dimension
 * @return
 */
int **changeMatrix(int **defaultMatrix, int dimension);
int **createMatrix(int dimension);
void showMatrix(int **matrix, int dimension);
void deleteMemoryUsed(int **matrix, int dimension);
bool compareValue(int **originalMatrix, int **matrixChange, int posComparisonValue, int array[]);
int countRotations();

#endif // MODULS_H
