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
void sort(vector<int>& a)
{
  //2 to size of a
  for(int i=1; i<a.size(); i++)
  {
    int current = i;
    for(int j=i-1; j>=0; j--)
    {
      if (a[current] < a[j]) {
        int temp = a[j];
        a[j] = a[current];
        a[current] = temp;
        current = j;
      } else {
        break;
      }
    }
  }
}

int main()
{
    ios_base::sync_with_stdio(false);
    vector<int> v;
    int n; cin >> n;
    for(int i=0; i<n; i++)
    {
      int e; cin >> e;
      v.push_back(e);
    }
    sort(v);
    for(int i=0; i<n; i++)
    {
      cout << v[i] << endl;
    }

}
