#include <bits/stdc++.h>
#include <cstring>
#ifndef EQUATION_H
#define EQUATION_H


class equation
{
    public:
        char key;
        float num1;
        float num2;
        float num3;
        void getRandomEquationSum(int level);
        void getRandomEquationSub(int level);
        void getRandomEquationMul(int level);
        void getRandomEquationDiv(int level);
};

#endif
