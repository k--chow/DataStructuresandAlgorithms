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
#include <cmath>
using namespace std;

unordered_map<string, string> variables;
unordered_map<char, int> precedence; //for comparing operator precedence
bool exceptionThrown = false;
string errorMessage = "";

double conversion(string a) {
    if (variables.count(a)) {
        //cout << "found " << a << endl;
        return stod(variables[a]);
    } else if (isalpha(a[0])) {
        exceptionThrown = true;
        errorMessage = "Undeclared-Variable";
        return 1;
    }
    return stod(a);
}

double sin(string radians)
{
    return sin((conversion(radians)*conversion("Pi"))/180.0);
}

double cos(string radians)
{
    return cos((conversion(radians)*conversion("Pi"))/180.0);
}

double log(string value)
{
    return log(conversion(value));
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
    if (conversion(b) == 0) {
        exceptionThrown = true;
        errorMessage = "Division-By-Zero";
        return conversion(a);
    }
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
    string test = "–";
    string hi = "-";
    //cout << test.size() << " "  << hi.size() << endl;
    while (getline(cin, line))
    {
        if (line == "quit") {
            break;
        }
        //tokenize
        vector<string> tokens;
        stack<char> s;
        string current = "";
        bool variableSet = false;
        string givenVariable = "";
        int i=0;
        //parse variable
        if (line.substr(0, 4) == "let ") {
            variableSet = true;
            i = 4;
            while (line[i] != '=') {
                if (!isspace(line[i])) givenVariable += line[i];
                i++;
            }
            i++;
        }
            for (; i<line.size(); i++)
            {
                if (!isspace(line[i]) && (int)line[i] < 255)
                {
                    if (line.substr(i, 3) ==  "–")
                    {
                        line[i+3] = '-';
                        i += 2;
                    }
                    else if (!isOperator(line[i]) || (line[i] == '-' && current.empty()))
                    {
                        current += line[i];
                        //cout << current.size() << current << " ";
                        if (current == "sin" || current == "cos" || current == "log")
                        {
                            string operation = current;
                            //cout << "Operation " << operation << endl;
                            current = "";
                            //calculate the value
                            while (line[++i] != ')') {
                                if (!isspace(line[i]) && line[i] != '(') current += line[i];
                            }
                            cout << current << endl;
                            //push to tokens
                            if (operation == "sin") {

                                tokens.push_back(to_string(sin(current)));
                            } else if (operation == "cos")
                            {
                                tokens.push_back(to_string(cos(current)));
                            } else if (operation == "log")
                            {
                                tokens.push_back(to_string(log(current)));
                            }
                            current = "";
                            //cout << tokens[tokens.size()-1] << endl;


                        }

                    } else {
                        if (!current.empty())
                        {
                            tokens.push_back(current);
                            //cout << current << endl;
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
            if (!current.empty()) {
                tokens.push_back(current);
                //cout << current << endl;
            }
            while (!s.empty()) {
                tokens.push_back(string(1, s.top()));
                s.pop();
            }
            //cout << "made it here 2" << endl;


            //evaluate the expression
            stack<string> eval;
            for(int i=0; i<tokens.size(); i++)
            {
                //cout << tokens[i] << endl;
                if (tokens.size() == 1) {
                    eval.push(to_string(conversion(tokens[i])));
                    break;
                }
                if (isOperator(tokens[i][0]) && tokens[i].size() == 1)
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
            if (exceptionThrown) {
                if (!variableSet) cout << errorMessage << endl;
                exceptionThrown = false;
                errorMessage = "";
            }
            else if (variableSet) {
                variables[givenVariable] = eval.top();
                givenVariable = "";
                variableSet = false;
            } else {
                cout << conversion(eval.top()) << endl;
            }
            eval.pop();






    }
}
//4 + 3 / (2 - 4/2)
//there is problem with () causing extra token DONE
//exceptions - undeclared variable, division by zero DONE
//hash map variables - parse - DONE
//if token first char isletter DONE
//if divide by zero is zero DONE
//trig functions <- this guy
//parse sin cos log DONE
//negative number case - 3 - 2 stopped working DONE
//negative variables DONE
//setting variable to undeclared variable - letters already in map?? <- this guuy
//subtract symbol not working DONE
//find letty DONE

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
