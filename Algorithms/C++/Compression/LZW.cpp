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
#include <set>
using namespace std;

int main()
{
    string given = "1111111111111111111111111111";
    map<int, string> dictionary;
    set<string> exists;
    int counter = 0;
    //store all single characters
    for(int i=0; i<given.size(); i++)
    {
        string current = ""; current += given[i];
        if (exists.count(current) == 0) {
            dictionary[counter] = current;
            exists.insert(current);
            counter++;
        }

    }
    vector<int> output;
    int i = 0;
    string current;
    current.push_back(given[i]);
    while (i != given.size())
    {
        i++;
        char next = given[i];
        if (exists.count(current + next)) {
            current.push_back(next);
        } else {
            output.push_back(dictionary[current]);
            dictionary[counter] = current+next;
            exists.insert(current+next);
            counter++;
            current = next;
        }

    }
    for(int i=0; i<output.size(); i++)
    {
        cout << output[i] << " ";
    }
    cout << endl;
    for(int i=0; i<output.size(); i++)
    {
        cout << dictionary[output[i]];
    }
}

//instead of initial single characters, why not start with replacing by compressions?
//why start from the previous compressed character? Causes overlap
//if not in, take previous vs current?
//start from empty string, doesn't really matter
//exercise see how much compression rate changes with different approach from above.
