//EXERCISE 3
#include <iostream>
using namespace std;
#include "ArrayStack.h"

int main()
{
    ArrayStack<int> stack1, stack2;
    int stackTop;

    stack1.push(1);
    stack1.push(2);
    stack2.push(3);
    stack2.push(4);
    stack1.pop();
    stackTop = stack2.peek();
    stack1.push(stackTop);
    stack1.push(5);
    stack2.pop();
    stack2.push(6);

    cout << "Stack1: " << endl;
    stack1.display();
    cout << "Stack2: " << endl;
    stack2.display();

    system("pause");
	return 0;
}

////EXERCISE 2
//#include <iostream> 
//#include<string> 
//#include "ArrayStack.h" 
//using namespace std;
////void pseudocode(char ch[], ArrayStack<int> &stack);
//
//int main()
//{
//	int operand2, operand1;
//
//	int stackTop;
//	ArrayStack<int> stack;
//	char StackInfo[5];
//	cout << " The stack info is : ";
//	for (int i = 0; i < 5; i++)
//	{
//		cin >> StackInfo[i];
//	}
//
//
//	for (int i = 0; i < 5; i++)
//	{
//		cout << StackInfo[i];
//	}
//
//	//cout << "Stack top is: " << stack.peek()<<endl;
//	cout << endl;
//
//	for (int i = 0; i < 5; i++)
//	{
//		cout << StackInfo[i] << endl;
//		//stack.push(StackInfo[i]-'0'); 
//
//
//
//		//if (StackInfo[i] == '+' || StackInfo[i] == '-' || StackInfo[i] == '/' || StackInfo[i] == '*')
//
//		if (isdigit(StackInfo[i]))
//		{
//			stack.push(StackInfo[i] - '0');
//			//op = StackInfo[i];
//		}
//
//		else
//		{
//			/*int ia = StackInfo[i];
//			stack.push(ia);*/
//			stackTop = stack.peek();
//			cout << stackTop << endl;
//			operand2 = stack.peek();
//			stack.pop();
//			stackTop = stack.peek();
//			cout << stackTop << endl;
//			operand1 = stackTop;
//			stack.pop();
//
//
//			switch (StackInfo[i])
//			{
//			case '+': stack.push(operand1 + operand2);
//				break;
//			case '-': stack.push(operand1 - operand2);
//				break;
//			case '*': stack.push(operand1 * operand2);
//				break;
//			case '/': stack.push(operand1 / operand2);
//				break;
//			}
//
//			cout << " The result was " << stack.peek();
//
//
//			/*if (StackInfo[i] == '+')
//			{
//				result = operand1 + operand2;
//				stack.push(result);
//				cout << " The result was " << result;
//			}
//
//			else if (StackInfo[i] == '-')
//			{
//				result = operand1 - operand2;
//				stack.push(result);
//				cout << " The result was " << result;
//			}
//
//			else if (StackInfo[i] == '/')
//			{
//				result = operand1 / operand2;
//				stack.push(result);
//				cout << " The result was " << result;
//			}
//
//			else if (StackInfo[i] == '*')
//			{
//				result = operand1 * operand2;
//				stack.push(result);
//				cout <<" The result was "<< result;
//			}
//			*/
//			stack.display();
//			//pseudocode(StackInfo, stack);
//		}
//	}
//	return 0;
//
//}


////EXERCISE 1
//#include<iostream>
//#include <string>
//#include "ArrayStack.h"
//using namespace std;
//
//// Checks the string  aString  to verify that braces match.  
//
// // Returns true ifaString  contains matching braces, false otherwise.  
//bool checkBraces(string aString)
//{
//    ArrayStack<char> aStack;
//    bool balancedSoFar = true;
//    int i = 0;
//    while (balancedSoFar and i < aString.length())
//    {
//        char ch = aString[i];
//            i++; // Push an open brace  
//            if (ch == '{')
//                aStack.push('{');   // Close brace  
//            else if (ch  ==  '}')
//            {
//                if (!aStack.isEmpty())
//                    aStack.pop();    // Pop a matching open brace              
//                else                  // No matching open brace                 
//                    balancedSoFar = false;
//            } // Ignore all characters other than braces      
//    }
//    if (balancedSoFar and aStack.isEmpty())
//        return true;
//    else
//        return false;
//}
//
//int main()
//{
//    string aString{ "{a{b}c}" };
//    int size = aString.length();
//    if (checkBraces(aString))
//        cout << "It is balanced" << endl;
//    else
//        cout << "It is not balanced" << endl;
//
//    return 0;
//}