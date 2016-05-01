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


int main()
{
    string a, b;
    a = " quetzalcoatl";
    b = " tezcatlipoca";
    //a = "abe";
    //b = "cab";
    //12 characters
    vector< vector<int> > LCS(a.size());
    for(int i=0; i<a.size(); i++)
    {
        for(int j=0; j<a.size(); j++)
        {
            LCS[i].push_back(0);
        }
    }

    for(int i=0; i<a.size(); i++)//a
    {
        string c = a.substr(0, i);
        for(int j=0; j<a.size(); j++)//b
        {
            string d = b.substr(0, j);
            //compare last characters

            //max of 3 scenarios - same last character, a-1 vs. b, and a vs. b-1
            if (c.size() == 0 || d.size() == 0)
            {
                continue;
            }
            else
            {
                if (c[c.size()-1] == d[d.size()-1]) //equal
                {
                    LCS[i][j] = LCS[i-1][j-1] + 1;
                }
                LCS[i][j] = max(max(LCS[i-1][j], LCS[i][j-1]), LCS[i][j]);
            }
        }
    }
    for(int i=0; i<a.size(); i++)
    {
        for(int j=0; j<a.size(); j++)
        {
            cout << LCS[i][j] << " ";
        }
        cout << endl;
    }


}
