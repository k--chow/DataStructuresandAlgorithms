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
    while (1)
    {
        int a, b;
        vector<int> aArr, bArr;
        cin >> a >> b;

        if (a == 0 && b == 0) break;
        for(int i=0; i<a; i++)
        {
            int aa;
            cin >> aa;
            aArr.push_back(aa);
        }

        for(int i=0; i<b; i++)
        {
            int bb;
            cin >> bb;
            bArr.push_back(bb);
        }

        //sort bArr
        sort (bArr.begin(), bArr.end());
        string ans = "N";
        //if something larger, get index
        int index;
        for(int i=0; i<aArr.size(); i++)
        {
            index = 2;
            for(int j=0; j<bArr.size(); j++)
            {
                if (bArr[j] > aArr[i]) {
                        index = j;
                        //cout << bArr[j] << " " << index << endl;
                        break;
                }

            }

            if (index < 2) {
                    ans = "Y";
                    break;
            }

        //smaller is closer

        }


        cout << ans << endl;


    }
}
