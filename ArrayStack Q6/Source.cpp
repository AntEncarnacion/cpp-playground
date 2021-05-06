#include<iostream>
#include <string>
#include "ArrayStack.h"
using namespace std;

int precedence(char ch)
{
    if (ch == '*' || ch == '/')
        return 1;
    else
        return 0;
}

string postfixExp(ArrayStack<char>& aStack, string infix)
{
    string postfixExp;
    int size = infix.length();

    for (int i = 0; i < size; i++)
    {
        switch (infix[i]) 
        {
        case '(': // Save  '('  on stack—step 2              
            aStack.push(infix[i]);
            break;
        case '+': // Process stack operators of greater precedence—step 3  
            while (!aStack.isEmpty() && aStack.peek() != '(' && precedence(infix[i]) <= precedence(aStack.peek()))
            {
                postfixExp = postfixExp + aStack.peek();
                aStack.pop();
            }
            aStack.push(infix[i]); // Save the operator  
            break;
            case '-': // Process stack operators of greater precedence—step 3  
            while (!aStack.isEmpty() && aStack.peek() != '(' && precedence(infix[i]) <= precedence(aStack.peek()))
            {
                postfixExp = postfixExp + aStack.peek();
                aStack.pop();
            }
            aStack.push(infix[i]); // Save the operator  
            break;
            case '*': // Process stack operators of greater precedence—step 3  
            while (!aStack.isEmpty() && aStack.peek() != '(' && precedence(infix[i]) <= precedence(aStack.peek()))
            {
                postfixExp = postfixExp + aStack.peek();
                aStack.pop();
            }
            aStack.push(infix[i]); // Save the operator  
            break;
            case '/': // Process stack operators of greater precedence—step 3  
            while (!aStack.isEmpty() && aStack.peek() != '(' && precedence(infix[i]) <= precedence(aStack.peek()))
            {
                postfixExp = postfixExp + aStack.peek();
                aStack.pop();
            }
            aStack.push(infix[i]); // Save the operator  
            break;

        case ')': //Pop stack until matching ' ('— step 4  
            while (aStack.peek() != '(')
            {
                postfixExp = postfixExp + aStack.peek();
                aStack.pop();
            }
            aStack.pop(); // Remove the open parenthesis  
            break;
        default: // Append operand to end of postfix expression—step 1              
            postfixExp = postfixExp + infix[i];
            break;

        }
    }

    // Append topostfixExp t he operators remaining in the stack—step 5  

    while (!aStack.isEmpty())
    {
        postfixExp = postfixExp + aStack.peek();
        aStack.pop();
    }
    return postfixExp;
}


int main()
{
    ArrayStack<char> stack;
    string infix;
    bool validation = false;



    do
    {
        cout << "Enter infix: ";
        getline(cin, infix);
        if (infix.length() != 0)
            validation = true;
        else
        {
            system("clear");
            cout << "Error! Please enter an infix expression!" << endl;
        }
    } while (!validation);

    cout << "The post fix expression of: " << infix << "\nIs: " << postfixExp(stack, infix) << endl;
    
    return 0;
}