#include "..//include/Random.h"
#include <iostream>
#include <ctime>
#include <iostream>
#include <vector>
#include <ctime>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

Random::Random()
{
    seed();
}



//
// Generate a random number between 0 and 1
// return a uniform number in [0,1].
double Random::unifRand()
{
    return rand() / double(RAND_MAX);
}
//
// Generate a random number in a real interval.
// param a one end point of the interval
// param b the other end of the interval
// return a inform rand numberin [a,b].
double Random::unifRand(double a, double b)
{
    return (b-a)*unifRand() + a;
}
//
// Generate a random integer between 1 and a given value.
// param n the largest value
// return a uniform random value in [1,...,n]
long Random::unifRand(long n)
{

    if (n < 0) n = -n;
    if (n==0) return 0;
    /* There is a slight error in that this code can produce a return value of n+1
    **
    **  return long(unifRand()*n) + 1;
    */
    //Fixed code
    long guard = (long) (unifRand() * n) +1;
    return (guard > n)? n : guard;
}
//
// Reset the random number generator with the system clock.
void Random::seed()
{
    srand(time(0));
}
