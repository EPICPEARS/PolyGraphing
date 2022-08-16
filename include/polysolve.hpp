#ifndef POLYSOLVE_H
#define POLYSOLVE_H

#include <iostream>
#include <math.h>
#include <SDL.h>

using namespace std;


class PolyNomialSolver
{
private:
    int *terms;
    double roots[2];
    static const int detail = 5000;
    int poly_degree;
    

public:
    PolyNomialSolver(int argc, char *argv[]);
    void RealRoots();
    void PrintRoots();
    void GetPoints(SDL_Renderer *rend);
   
};

#endif