#include "ExpressionChecker.h"

int main(){
    ExpressionChecker str;
    cout << (str.CheckBrackets("(") ? "true" : "false");
    return 0;
}