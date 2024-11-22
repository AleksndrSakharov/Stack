#pragma once
#include "Stack.h"
const int MaxLength = 255;
class TFormula
{
private:
    char Formula[MaxLength];
    char PostfixForm[MaxLength];
public:
    TFormula (char form[]);
    int FormulaChecker (int Brackets[], int size);
    int FormulaConverter(void);
    double FormulaCalculator(void);
};