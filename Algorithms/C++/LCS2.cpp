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
void LCS(vector<int> a, vector<int> b)
{
	vector< vector<int> > dp(a.size()+1);
	for(int i=0; i<=a.size(); i++) {
		for(int j=0; j<=b.size(); j++) {
			dp[i].push_back(0);
			if (i != 0 && j != 0) {
				if (a[i-1] == b[j-1]) {
					dp[i][j] = dp[i-1][j-1] + 1;
				} else {
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				}
			}
		}
	}

    int i = a.size(), j = b.size();
    stack<int> s;
    while (i > 0 && j > 0) {
        //cout << "i: " << i-1 << " j: " << j-1 << endl;
        //cout << a[i-1] << " equals " << b[j-1] << endl;
        if (a[i-1] == b[j-1])
        {
        	s.push(a[i-1]);
            i--; j--;


        }
        else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        }
        else {
            j--;
        }

    }
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}*/

//implementation of knuth-morris-pratt
/*
int KMP(string a, string hint)
{
    vector<int> dp(hint.size(), 0);
    int i=1, j=0;
    while (i < hint.size())
    {
        if (hint[i] == hint[j]) {
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
    int hay = 0;
    int ans = 0;
    int counter = 0;
    while (hay <= a.size()) {
        if (needle == hint.size()) {
            ans++;
            needle = dp[needle-1];

        }
        if (a[hay] == hint[needle]) {
        	hay++;
            needle++;
        } else {
            if (needle != 0) {
                needle = dp[needle-1];
            } else {
                hay++;
            }
        }
        counter++;
    }

    if (needle == a.size()) ans++;

    return ans;

}*/

int main()
{
    string hint; cin >> hint;
    int N; cin >> N;
    /*
    vector<string> matrixRows(N, "");
    vector<string> matrixCols(N, "");
    for(int i=0; i<N; i++)
    {
        string given_string; cin >> given_string;
        matrixRows[i] = (given_string);
        for(int j=0; j<N; j++)
        {
            matrixCols[j] += given_string[j];
        }
    }
    vector<int> rows;
    vector<int> cols;
    //rows - KMP on it
    for(int i=0; i<N; i++) {
        //rows.push_back(KMP(matrixRows[i], hint));
    }
    //cout << endl;
    //columns - KMP on it
    for(int i=0; i<N; i++) {
        //cols.push_back(KMP(matrixCols[i], hint));
    }
    //longest common subsequence
	//LCS(rows, cols);
    cout << "hi" << endl;*/
    return 0;
}
