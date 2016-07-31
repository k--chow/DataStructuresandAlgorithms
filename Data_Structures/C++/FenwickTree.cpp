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

int leastSignificantBit(int n)
{
  return (n & (-n));
}


class FenwickTree
{
  private:
    vector<int> ft;//just a frequency table
  public:
    FenwickTree(int n)
    {
      ft.assign(n+1, 0);
    }
    int rsq(int q)
    {
      int sum = 0;
      for(;q; q-=leastSignificantBit(q)) sum += ft[q];
      return sum;
    }
    int rsq(int left, int right)
    {
      if (left != 1) return rsq(right) - rsq(left);
      return rsq(right);

    }
    void adjust(int value)
    {
      for(;value < ft.size(); value+=leastSignificantBit(value))
      {
        ft[value]++;
      }
    }

};

int main()
{
  FenwickTree ft(10);
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  for(int i=0; i<10; i++) ft.adjust(arr[i]);
  cout << ft.rsq(1, 10) << endl;
  cout << ft.rsq(1, 1) << endl;
}
