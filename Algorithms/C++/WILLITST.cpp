#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <unordered_map>
using namespace std;

int main()
{
    string in;
    cin >> in;
    int last = in[in.length()-1] -'0';
    //cout << last << endl;
    if (in[0] == '-')
    {
        cout << "TAK" << endl;
    }
    else if (in == "0")
    {
        cout << "TAK" << endl;
    }
    else if (in == "1")
    {
        cout << "TAK" << endl;
    }
    else if (last == 0)
    {
        cout << "NIE" << endl;
    }
    else if (last == 1)
    {
        cout << "NIE" << endl;
    }
    else if (last == 3)
    {
        cout << "NIE" << endl;
    }
    else if (last == 5)
    {
        cout << "NIE" << endl;
    }
    else if (last == 7)
    {
        cout << "NIE" << endl;
    }
    else if (last == 9)
    {
        cout << "NIE" << endl;
    }
    else
    {
        cout << "TAK" << endl;
    }

}
