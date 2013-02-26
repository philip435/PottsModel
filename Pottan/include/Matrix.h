#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include "Random.h"
#include <windows.h>
using namespace std;
class Matrix
{
    public:
        Matrix(int n, int m, int Q, int T, int S, int J);
        void printMatrix();
        void run();
    protected:
    private:
        int n, Q, T, S, J;
        const double Kb = 1.0;//1.3806503e-23;
        Random random;
        HANDLE hConsole = GetStdHandle (STD_OUTPUT_HANDLE);

        std::vector<vector<int> > matrix;
        void sweep();
        int getNeighborH(int i, int j);
        int getNeighborV(int i, int j);
        int getKp(int i);
        int getHamiltonian(int i, int j, int l);
        void setCONSTANTS(int n, int Q, int T, int S, int J);
        void initiateValues(int m);
        void setSize();
        void setColor(int i);

};

#endif // MATRIX_H
