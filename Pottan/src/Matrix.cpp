#include "..//include/Matrix.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
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
        //system("cls");
        //Sleep(100);
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
            double Hdelta = (Hp - H);

            if(Hdelta < 0){
                matrix[i][j] = kp;
            }
            else{
                if (exp(-(float)Hdelta/(float)T/(float)Kb) <= (float)random.unifRand()){
                    matrix[i][j] = kp;
                    //cout << -(float)Hdelta/(float)T/(float)Kb << " " << (float)random.unifRand() << endl;
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
    int b;
    do{
        b = rand()%Q;
    }while(b==i);
    return b;
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
                setColor(matrix[i][j]);
            cout << " ";//matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}


void Matrix::setColor(int i){
    switch(i){
    case 1:
        SetConsoleTextAttribute (hConsole, 200 | FOREGROUND_INTENSITY);
    break;
    case 2:
        SetConsoleTextAttribute (hConsole, 112 | FOREGROUND_INTENSITY);
    break;
    case 3:
        SetConsoleTextAttribute (hConsole, 94 | FOREGROUND_INTENSITY);
    break;
    case 4:
        SetConsoleTextAttribute (hConsole, 81 | FOREGROUND_INTENSITY);
    break;
    case 5:
        SetConsoleTextAttribute (hConsole, 59 | FOREGROUND_INTENSITY);
    break;
    case 6:
        SetConsoleTextAttribute (hConsole, 255 | FOREGROUND_INTENSITY);
    break;
    case 7:
        SetConsoleTextAttribute (hConsole, 78 | FOREGROUND_INTENSITY);
    break;
    case 8:
        SetConsoleTextAttribute (hConsole, 88 | FOREGROUND_INTENSITY);
    break;
    case 9:
        SetConsoleTextAttribute (hConsole, 145 | FOREGROUND_INTENSITY);
    break;
    case 0:
        SetConsoleTextAttribute (hConsole, 125 | FOREGROUND_INTENSITY);
    break;

    default:
        break;

    }
}
