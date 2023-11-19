/**
 * This file tests the evaluation of postfix expressions.
 * Your program should be able to evaluate valid expressions and handle invalid ones
 * 
 */

#include "eval_expr.h"
#include <iostream>
using namespace std;

void testExpression(string expr) {
    cout << "Testing expression: " << expr << endl;
    float result = 0;
    bool success = evalPostfixExpr(expr, result);
    if(success) {
        cout << expr << " = " << result << endl << endl;
    } else {
        cout << expr <<" Invalid expression!" << endl << endl;
    }
}
int main(int argc, char *argv[])
{
    cout << "Test evaluation of postfix expressions: " << endl;
    
    testExpression("34+5*");
    testExpression("34+5*+");
    testExpression("34+5*9/");
    testExpression("34+5*9/+");
    testExpression("*34");
    testExpression("25*9+2/7+8-");
    testExpression("25@");
    testExpression("25*0/");
    return 0;
}