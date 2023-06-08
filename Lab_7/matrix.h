#ifndef MATRIX_H
#define MATRIX_H
#include <string>
#include <QString>


class Matrix{
    int size;
    double** matrix;
    double trace;
public:
    Matrix(int size);
    ~Matrix();
    void setCell(const QString& value, int i, int j);
    void printMatrix();
    double calculateMatrixTrace();
    bool checkTrace();
};

#endif // MATRIX_H
