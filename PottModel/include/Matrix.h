#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
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
        const double Kb = 1.3806503e-23;
        std::vector<vector<int> > matrix;
        void sweep();
        int getNeighborH(int i, int j);
        int getNeighborV(int i, int j);
        int getKp(int i);
        int getHamiltonian(int i, int j, int l);
        void setCONSTANTS(int n, int Q, int T, int S, int J);
        void initiateValues(int m);
        void setSize();
};

#endif // MATRIX_H
