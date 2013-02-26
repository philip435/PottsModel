#ifndef RANDOM_H
#define RANDOM_H


class Random
{
    public:
        Random();
        double unifRand();
        double unifRand(double a, double b);
        long unifRand(long n);
    private:
        void seed();
};

#endif // RANDOM_H
