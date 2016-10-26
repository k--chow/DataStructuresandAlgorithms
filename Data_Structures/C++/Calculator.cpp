#include <algorithm>
#include <vector>
#include <tuple>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <queue>
#include <unordered_map>
using namespace std;

unordered_map<string, string> variables;
unordered_map<char, int> precedence; //for comparing operator precedence

//double sin(double value)

//double cos(double value)

//double log(double value)

double conversion(string a) {
    if (variables.count(a)) {
        return stod(variables[a]);
    }
    return stod(a);
}

double addition(string a, string b)
{
    return conversion(a) + conversion(b);
}

double subtraction(string a, string b)
{
    return conversion(a) - conversion(b);
}

double multiplication(string a, string b)
{
    return conversion(a) * conversion(b);
}

double divide(string a, string b)
{
    return conversion(a)/conversion(b);
}

//double division(double a, double b)
//check for divide by zero

//exponentiation by binary decomposition
double exponentiation(string a, string exponent)
{
    return pow(conversion(a), conversion(exponent));

}

double evaluate(string expression)
{
    return 0;
}

bool isOperator(char c)
{
    if (c == '*' || c == '+' || c == '-' || c == '/' || c == '^' || c == '(' || c ==')') return true;
    return false;

}

//parse variable assignments
//if word is let

//parse white space

int main()
{
    variables["Pi"] = "3.14169";
    variables["e"] = "2.718";
    precedence['^'] = 3;
    precedence['*'] = 2;
    precedence['/'] = 2;
    precedence['+'] = 1;
    precedence['-'] = 1;
    string line;
    while (getline(cin, line))
    {
        if (line == "quit") {
            break;
        }
        //tokenize
        vector<string> tokens;
        stack<char> s;
        string current = "";
        //cout << "made it here 0" << endl;
        for (int i=0; i<line.size(); i++)
        {
            if (!isspace(line[i]))
            {
                if (!isOperator(line[i]))
                {
                    current += line[i];
                } else {
                    if (!current.empty())
                    {
                        tokens.push_back(current);
                        current = "";
                    }
                    if (line[i] == '(')
                    {
                        s.push('(');
                    } else if (line[i] == ')')
                    {
                        while (s.top() != '(')
                        {
                            tokens.push_back(string(1, s.top()));
                            s.pop();
                        }
                        s.pop();
                    } else if (s.empty() || s.top() == '(') {
                        s.push(line[i]);
                    }
                    else {
                        //compare precedence with top of stack

                        //if larger than top, fine
                        if (precedence[line[i]] > precedence[s.top()])
                        {
                            s.push(line[i]);
                        }

                        //if smaller than top, pop until larger then push
                        else if (precedence[line[i]] < precedence[s.top()])
                        {
                            while(precedence[line[i]] < precedence[s.top()])
                            {
                                tokens.push_back(string(1, s.top()));
                                s.pop();
                                if (s.empty()) break;
                            }
                            s.push(line[i]);
                        }
                        //if same precedence two conditionals
                        else
                        {
                            if (precedence[line[i]] == 3)
                            {
                                s.push(line[i]);
                            } else {
                                tokens.push_back(string(1, s.top()));
                                s.pop();
                                s.push(line[i]);
                            }
                        }

                            //if 3 thats good right to left

                            //else left to right, pop then push

                    }
                }


            }
        }
        //cout << "made it here 1" << endl;
        tokens.push_back(current);
        while (!s.empty()) {
            tokens.push_back(string(1, s.top()));
            s.pop();
        }
        //cout << "made it here 2" << endl;
        //evaluate the expression
        stack<string> eval;
        for(int i=0; i<tokens.size(); i++)
        {
            cout << tokens[i] << endl;
            if (isOperator(tokens[i][0]))
            {
                string b = eval.top(); eval.pop();
                string a = eval.top(); eval.pop();
                if (tokens[i][0] == '^')
                {
                    eval.push(to_string(exponentiation(a, b)));
                } else if (tokens[i][0] == '*')
                {
                    eval.push(to_string(multiplication(a, b)));
                } else if (tokens[i][0] == '/')
                {
                    eval.push(to_string(divide(a, b)));
                } else if (tokens[i][0] == '+')
                {
                    eval.push(to_string(addition(a, b)));
                } else if (tokens[i][0] == '-')
                {
                    eval.push(to_string(subtraction(a, b)));
                }
            } else {
                eval.push(tokens[i]);
            }
        }
        cout << eval.top() << endl;





    }
}
//4 + 3 / (2 - 4/2)
//there is problem with () causing extra token
//exceptions - undeclared variable, division by zero
//hash map variables - parse
//if token first char isletter
//if divide by zero is zero
//trig functions


//what if I add parenthesis?
//2 + 3 * 4 - 5
//5234*-+
//5234
//+-*
//char by char, if letters use map

//order is (), ^, */, +-

//cases
//(2 + 4 * 3)
//(4 * 3) + 2
