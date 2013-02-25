#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/Matrix.h"
using namespace std;

int main(){
    int n = 32;  // SIZE OF MATRIX
    int m = 1;  // START VALUE OF ALL ELEMETS
    int Q = 10;  // DEGRE OF FREEDOM
    int T = 280;  // FUNDAMENTAL TEMPRATURE
    int S = 10000;  // NUMBER OF SWEEPS
    int J = 1;  // COUPLING CONSTANT

    Matrix matrix(n,m,Q,T,S,J); // SET MATRIX
    matrix.run();    // RUN THE MATRIX
    matrix.printMatrix();   // PRINT OUT MATRIX

    return 0;
}
