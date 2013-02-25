#include "..//include/Matrix.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;


Matrix::Matrix(int n, int m, int Q, int T, int S, int J){
    setCONSTANTS(n,Q,T,S, J);
    setSize();
    initiateValues(m);
}

void Matrix::run(){
    int e=0;
    while(e<S){
        sweep();
        e++;
    }
}

// MAIN SWEEP
void Matrix::sweep(){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){

            int k = matrix[i][j];
            int kp = getKp(i);

            int NeighborH = getNeighborH(i,j);
            int NeighborV = getNeighborV(i,j);

            int H = getHamiltonian(k,NeighborH,NeighborV);
            int Hp = getHamiltonian(kp,NeighborH,NeighborV);
            double Edelta = (Hp - H)/T/Kb;

            if(Edelta < 0){
                matrix[i][j] = kp;
            }
            else{
                if (exp(-Edelta/T) > rand()%2){
                    matrix[i][j] = kp;
                }
            }
        }
    }
}

int Matrix::getNeighborH(int i, int j){
    if(j+1 > n-1){
        return matrix[i][0];
    }
    else{
        return matrix[i][j+1];
    }
}

int Matrix::getNeighborV(int i, int j){
    if(i-1 < 0){
        return matrix[n-1][j];
    }
    else{
        return matrix[i-1][j];
    }
}

int Matrix::getKp(int i){
    return i+rand()%Q;
}

int Matrix::getHamiltonian(int i, int j, int l){    // (CURRENT ELEMENT, NEIGHBOR, NEIGHBOR)
    if(i==j && i==l){
        return -2*J;
    }
    else if(i!=j && i!=l){
        return 0;
    }
    else{
        return -J;
    }
}


// INITIATE FUNCTIONS


void Matrix::setCONSTANTS(int N, int q, int t, int s, int j){
    S=s;
    T=t;
    Q=q;
    n=N;
    J=j;
}

void Matrix::setSize(){
    matrix.resize(n);
    for (int i=0; i<n; i++){
        matrix[i].resize(n);
    }
}
void Matrix::initiateValues(int m){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            matrix[i][j] = m;
        }
    }
}

void Matrix::printMatrix(){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
