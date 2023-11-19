/**
 * Implementation of the functions to evaluate arithmetic expressions
 * The implementation should use the Stack data structure
 */
//You should always comments to each function to describe its PURPOSE and PARAMETERS
#include "stack.h"
#include "eval_expr.h"

/**
 * @brief Evaluate a postfix expression
 * @param postfix_expr The input expression in the postfix format.
 * @param result gets the evaluated value of the expression (by reference).
 * @return true if expression is a valid postfix expression and evaluation is done without error, otherwise false.
 */
bool evalPostfixExpr(string postfix_expr, float& result) {
    Stack<float> stack = Stack<float>(postfix_expr.length());       //create a Stack of type float and length of the input string
    float op1, op2;                                                 //declare 2 float variables to be used in evaluation
    for(char c : postfix_expr){                                     //iterate through each individual character of the input string
        if(isdigit(c)){                                             //returns true if char c is 0-9, false otherwise
            string s(1,c);                                          //create a new string that contains only char c
            stack.push(stof(s));                                    //push float equivalent of string s to top of stack
        }
        else{                                                       
            if(stack.size() < 2){                                   //less than 2 operands, and an operator is called
                cout << "Error: invalid expression!\n";             //error is called and return false
                return false;                                       
            }
            else{                                                   //>=2 operands, and an operator is called
                if(c == '*'){                                       //if multiplication
                    stack.pop(op2);                                 //pop top 2 elements from stack and push the result of multiplying them
                    stack.pop(op1);
                    stack.push(op1 * op2);
                }
                else if(c == '+'){                                  //if addition
                    stack.pop(op2);                                 //pop top 2 elements from stack and push the result of adding them
                    stack.pop(op1);
                    stack.push(op1 + op2);
                }
                else if(c == '-'){                                  //if subtraction
                    stack.pop(op2);                                 //pop top 2 elements from stack and push the result of subtracting them
                    stack.pop(op1);
                    stack.push(op1 - op2);
                }
                else if(c == '/'){                                  //if division
                    stack.pop(op2);                                 //pop the denominator from stack
                    if(op2 == 0){                                   //if zero, error is called and return false
                        cout << "Error: division by zero\n";
                        return false;
                    }
                    stack.pop(op1);                                 //pop the numerator from stack and push the result of dividing them
                    stack.push(op1 / op2);
                }
                else{                                               //if it is not an operator symbol
                    cout << "Error: unknown symbol\n";              //error is called and return false
                    return false;
                }
            }
        }
    }
    stack.pop(result);                                              //pop the top and only remaining element from the stack and assign it to result
    return true;                                                    //and return true
}

/**
 * @brief Convert an infix expression to an equivalent postfix expression
 * @param infix_expr The input expression in the infix format.
 * @return the converted postfix expression. If the input infix expression is invalid, return an empty string "";
 */
string convertInfixToPostfix(string infix_expr) {
    string postfix;                                                 //string to compile postfix output
    Stack<char> stack;                                              //stack of type char to use in evaluation
    char top;                                                       //char to assign when popping from stack
    for(char c : infix_expr){                                       //iterate through each char in the input string
        if(isdigit(c)){                                             //returns true if char c is 0-9, false otherwise
            postfix += c;                                           //append char c to end of postfix string
        }
        else{                                                       //char c is not a digit
            if(stack.isEmpty()){                                    //special case when stack is empty
                //if a legitimate operator is called when the stack is empty, push it to the stack
                if(c == '+' || c == '-' || c == '*' || c == '/' || c == '('){
                    stack.push(c);
                }
                //otherwise, error is called, and the invalid character is returned from the function
                else{
                    string error = "Error: Invalid character ";
                    error += c;
                    return error;
                }
            }
            else{                                                   //stack is not empty
                if(c == '('){                                       //if c is a (, push to top of stack
                    stack.push(c);
                }
                else if(c == ')'){                                  //if c is a ), pop all elements from the stack
                    while(stack.top() != '('){                      //until ( is encountered, and append them to 
                        stack.pop(top);                             //the postfix string
                        postfix += top;
                    }
                    stack.pop(top);                                 //discard the (
                }
                else if(c == '*' || c == '/'){                      //if c is * or /
                    while(stack.top() == '*' || stack.top() == '/'){//while the top of the stack is an equivalent
                        stack.pop(top);                             //operator, pop it from the stack and append to
                        postfix += top;                             //the postfix string
                    }                       
                    stack.push(c);                                  //push c to the top of the stack
                }
                else if(c == '+' || c == '-'){                      //if c is + or -
                    //while the top of the stack is an equivalent or greater operator, pop it from the stack
                    //and append it the postfix string
                    while(stack.top() == '*' || stack.top() == '/' || stack.top() == '+' || stack.top() == '-'){
                        stack.pop(top);
                        postfix += top;
                    }
                    stack.push(c);                                  //push c to the top of the stack
                }
                else{                                               //if c is not a legitimate operator,
                    string error = "Error: Invalid character ";     //error is called and the invalid character is
                    error += c;                                     //returned from the function
                    return error;
                }
            }
        }
    }
    while(!stack.isEmpty()){                                        //pop remaining elements from the stack and
        stack.pop(top);                                             //append them to the postfix string
        postfix += top;
    }
    return postfix;                                                 //return converted postfix string
}

/**
 * @brief Evaluate an infix expression. It's converted to a postfix expression first and then evaluated
 * @param infix_expr The input expression in the infix format.
 * @param result gets the evaluated value of the expression (by reference).
 * @return true if expression is valid and evaluation is done without error, otherwise false.
 */
bool evalInfixExpr(string infix_expr, float& result) {
    string postfix = convertInfixToPostfix(infix_expr);             //convert infix notation to postfix notation
    return evalPostfixExpr(postfix, result);                        //evalutate postfix input, setting the result to result
}