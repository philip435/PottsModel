#include <iostream>
#include <vector>
#include <ctime>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/Matrix.h"
#include <cmath>
#include "discpp.h"

using namespace std;
double zmat[100][100];

int main(){
    /*
    int n = 64;  // SIZE OF MATRIX
    int m = 6;  // START VALUE OF ALL ELEMETS
    int Q = 10;  // DEGRE OF FREEDOM
    int T = 20;  // FUNDAMENTAL TEMPRATURE
    int S = 100;  // NUMBER OF SWEEPS
    int J = 1;  // COUPLING CONSTANT

    Matrix matrix(n,m,Q,T,S,J); // SET MATRIX
    matrix.run();    // RUN THE MATRIX
    matrix.printMatrix();   // PRINT OUT MATRIX
*/
    int n = 100, i, j;
  double   fpi = 3.1415927 / 180.0, step, x, y;
  Dislin g;

  step = 360.0/ (n - 1);
  for (i = 0; i < n; i++)
  { x = i * step;
    for (j = 0; j < n; j++)
    { y = j * step;
      zmat[i][j] = 2 * sin (x * fpi) *sin (y * fpi);
    }
  }

  g.metafl ("cons");
  g.disini ();
  g.pagera ();
  g.hwfont ();

  g.titlin ("3-D Colour Plot of the Function", 2);
  g.titlin ("F(X,Y) = 2 * SIN(X) * SIN(Y)", 4);

  g.name   ("X-axis", "x");
  g.name   ("Y-axis", "y");
  g.name   ("Z-axis", "z");

  g.intax  ();
  g.autres (n, n);
  g.axspos (300, 1850);
  g.ax3len (2200, 1400, 1400);

  g.graf3  (0.0, 360.0, 0.0, 90.0, 0.0, 360.0, 0.0, 90.0,
            -2.0, 2.0, -2.0, 1.0);
  g.crvmat ((double *) zmat, n, n, 1, 1);

  g.height (50);
  g.title  ();
  g.disfin ();
  return 0;
}
