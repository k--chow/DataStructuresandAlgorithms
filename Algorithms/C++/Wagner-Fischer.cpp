#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

/*
This algorithm computes the Wagner-Fischer algorithm and therefore Levenschtein Distance. It involves
the operations of insertion, deletion, and replacement on a string and solves the common Edit Distance problem.
*/


int main()
{
    string a, b;
    a = " FOOD";
    b = " MONEY";
    //a = "abe";
    //b = "cab";
    //12 characters
    vector< vector<int> > WF(a.size());
    for(int i=0; i<a.size(); i++)
    {
        for(int j=0; j<a.size(); j++)
        {
            WF[i].push_back(0);
        }
    }

    for(int i=0; i<a.size(); i++)//a
    {
        string c = a.substr(1, i);
        for(int j=0; j<b.size(); j++)//b
        {
            string d = b.substr(1, j);
            //compare last characters

            //max of 3 scenarios - same last character, a-1 vs. b, and a vs. b-1
            if (c.size() == 0 || d.size() == 0)
            {
                WF[i][j] = max(i, j);
            }
            else
            {
                int cost = 1;
                if (c[c.size()-1] == d[d.size()-1]) //equal
                {
                    cost = 0;
                }
                WF[i][j] = min(min(WF[i-1][j] + 1, WF[i][j-1] + 1), WF[i-1][j-1] + cost);
            }
        }
    }
    for(int i=0; i<a.size(); i++)
    {
        for(int j=0; j<b.size(); j++)
        {
            cout << WF[i][j] << " ";
        }
        cout << endl;
    }


}

