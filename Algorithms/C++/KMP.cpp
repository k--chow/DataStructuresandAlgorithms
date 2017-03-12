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
    int L;
    while (scanf("%d", &L) != EOF)
    {
        string a;
        cin >> a;
        vector<int> dp(a.size(), 0);//longest proper suffix that is prefix
        int i = 1, j=0;
        while (i < a.size())
        {
            if (a[i] == a[j]) {
                j++;
                dp[i] = j;
                i++;
            } else {//rematch based on prior info
                if (j == 0) { //crap
                    dp[i] = 0;
                    i++;
                } else {
                    j = dp[j-1];
                }
            }
        }
        int needle = 0;
        //fix now to stream
        char b;
        long long counter = 0;
        scanf("%c", &b);
        while (scanf("%c", &b) != EOF) {
        	//cout << b << " ";
            if (b == '\n') break;
            if (needle == a.size()) {
            	cout << counter - needle << endl;
                needle = dp[a.size()-1];

            }
            if (b == a[needle]) {
                needle++;
            } else {
                while (needle != 0) {
                    needle = dp[needle-1];
                    if (b == a[needle]) {
                        needle++;
                        break;
                    }
                }
            }
			counter++;
        }

        if (needle == a.size()) {
        	cout << counter - needle << endl;
            needle = dp[a.size()-1];

        }
        cout << endl;

    }
}



/*
while (hay != b.size()) {
    if (b[hay] == a[needle]) {
        hay++;
        needle++;
        if (needle == a.size()) {
            needle = dp[a.size()-1];
            cout << hay - 1 - needle << endl;
        }
    } else if (needle == 0) {
        hay++;
    }
    else {
        needle = 0;
    }
}*/
