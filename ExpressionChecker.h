#pragma once
#include "Table.h"


class ExpressionChecker{
public:
    bool CheckBrackets(string exp){
    Stack<int> str;
    Table<int, int> t("(", ")");
    for ( int i = 0; i < exp.size(); i++){
        if (exp[i] == '(') {
            str.Push(i);
        }
        if (exp[i] == ')') {
            if (str.IsEmpty()){
                t.AppendRow(nullopt, i);
            }
            else{
                t.AppendRow(str.Pop(), i);
            }
        }
    }
    if(!str.IsEmpty()){
        while (!str.IsEmpty())
        {
            t.AppendRow(str.Pop(), nullopt);
        }
    }
    t.Print();
    return str.IsEmpty();
}
};