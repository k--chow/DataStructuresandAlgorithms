#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
using namespace std;

int main()
{
    string given;
    cin >> given;
    map<string, int> dictionary;
    int counter = 0;
    for(int i=0; i<given.size(); i++)
    {
        string current = ""; current += given[i];
        if (dictionary.count(current) == 0) {
            dictionary[current] = counter;
            counter++;
        }

    }
    cout << dictionary.size() << endl;
}
