#include "equation.h"
#include <ctime>
#include <iomanip>

void equation::getRandomEquationSum(int level)
{
    srand(time(NULL));
    int trueOrFalse = rand() % 2;
    if ( trueOrFalse ) this->key = 'Y';
        else this->key = 'N';
    int maxBound;
    if (level == 1) maxBound = 5;
    if (level == 2) maxBound = 10;
    if (level == 3) maxBound = 20;
    int const maxDiff = 5;
    int diff = rand()%(maxDiff) + 1;
    int plusOrMinus = rand()%2;
    if (plusOrMinus) plusOrMinus = 1;
        else plusOrMinus = -1;
    diff *= plusOrMinus;
    this->num1 = rand()%(maxBound) + 1;
    this->num2 = rand()%(maxBound) + 1;
    if (trueOrFalse){
        diff = 0;
        this->num3 = this->num1 + this->num2;
    }
    else{
        this->num3 = this->num1 + this->num2 + diff;
        if (this->num3 < 0) this->num3 = -this->num3;
   }
}
void equation::getRandomEquationSub(int level)
{
    srand(time(NULL));
    int trueOrFalse = rand() % 2;
    if ( trueOrFalse ) this->key = 'Y';
        else this->key = 'N';
    int maxBound;
    if (level == 1) maxBound = 5;
    if (level == 2) maxBound = 10;
    if (level == 3) maxBound = 20;
    int diff;
    int const maxDiff = 5;
    diff = rand()%(maxDiff) + 1;
    int plusOrMinus = rand()%2;
    if (plusOrMinus) plusOrMinus = 1;
        else plusOrMinus = -1;
    diff *= plusOrMinus;
    this->num1 = rand()%(maxBound) + 1;
    this->num2 = rand()%(maxBound) + 1;
    if (trueOrFalse){
        diff = 0;
        this->num3 = this->num1 - this->num2;
    }
    else{
        this->num3 = this->num1 - this->num2 + diff;
        if (this->num3 < 0) this->num3 *= -1;
   }
}
void equation::getRandomEquationMul(int level)
{
    srand(time(NULL));
    int trueOrFalse = rand() % 2;
    if ( trueOrFalse ) this->key = 'Y';
        else this->key = 'N';
    int maxBound;
    if (level == 1) maxBound = 5;
    if (level == 2) maxBound = 10;
    if (level == 3) maxBound = 20;
    int diff;
    int const maxDiff = 5;
    diff = rand()%(maxDiff) + 1;
    int plusOrMinus = rand()%2;
    if (plusOrMinus) plusOrMinus = 1;
        else plusOrMinus = -1;
    diff *= plusOrMinus;
    this->num1 = rand()%(maxBound) + 1;
    this->num2 = rand()%(maxBound) + 1;
    if (trueOrFalse){
        diff = 0;
        this->num3 = this->num1 * this->num2;
    }
    else{
        this->num3 = this->num1 * this->num2 + diff;
        if (this->num3 == this->num1 - this->num2) this->num3 += 3;
   }
}
void equation::getRandomEquationDiv(int level)
{
    srand(time(NULL));
    int trueOrFalse = rand() % 2;
    if ( trueOrFalse ) this->key = 'Y';
        else this->key = 'N';
    int maxBound;
    if (level == 1) maxBound = 5;
    if (level == 2) maxBound = 10;
    if (level == 3) maxBound = 20;
    int diff;
    int const maxDiff = 5;
    diff = rand()%(maxDiff) + 1;
    int plusOrMinus = rand()%2;
    if (plusOrMinus) plusOrMinus = 1;
        else plusOrMinus = -1;
    diff *= plusOrMinus;
    this->num1 = rand()%(maxBound) + 1;
    this->num2 = rand()%(maxBound) + 1;
    if (trueOrFalse){
        diff = 0;
        this->num3 = this->num1 /  this->num2;

    }
    else{
        this->num3 = this->num1 / this->num2 + diff;
        if (this->num3 == this->num1 - this->num2) this->num3 += 3;

   }
}

