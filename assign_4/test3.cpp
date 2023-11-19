/**
 * This file tests the conversion from infix to postfix expressions.
 * Your program should be convert valid expressions correctly and handle invalid ones.
 * 
 */
#include "eval_expr.h"
#include <iostream>
using namespace std;

void testInfixExpression(string expr) {
    //cout << "Testing expression: " << expr << endl;
    float result = 0;
    bool success = evalInfixExpr(expr, result);
    if(success) {
        cout << expr << " = " << result << endl;
    } else {
        cout << expr <<" Invalid expression!" << endl;
    }
}
int main(int argc, char *argv[])
{
    cout << "Test evaluation of infix expressions " << endl;
    string infix_exprs[] = {"3+4*5", "(3+4)*5", "(3+4)*5+6", "(3+4)*5+6/7", "(3+4)*5+6/(7+8)", "(3+4)*5+6/(7+8)-9", "(3+4)*5+6/(7+8)&9"};
    for (string expr : infix_exprs) {
        cout << "------------------------------------------------------" << endl;
        cout << "Infix expr: " << expr << endl;
        cout << "Converted postfix expr: " << convertInfixToPostfix(expr) << endl;
        testInfixExpression(expr);
    }
    /*testInfixExpression("3+4*5");
    testInfixExpression("(3+4)*5");
    testInfixExpression("(3+4)*5+6");
    testInfixExpression("(3+4)*5+6/7");
    testInfixExpression("(3+4)*5+6/(7+8)");
    testInfixExpression("(3+4)*5+6/(7+8)-9");
    testInfixExpression("(3+4)*5+6/(7+8)9");*/
    return 0;
}
