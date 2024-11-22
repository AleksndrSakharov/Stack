#include "ExpressionChecker.h"

bool ExpressionChecker::CheckBrackets(string exp){
    Stack<char> st;
    for (size_t i = 0; i < exp.size(); i++){
        if (exp[i] == '('){
            st.Push('(');
        }
        else if (exp[i] == ')'){
            if (st.isEmpty()) return false;
            st.Pop();
        }
    }
    return st.isEmpty();
}