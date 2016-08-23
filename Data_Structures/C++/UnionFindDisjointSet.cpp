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
class UnionFind
{
	private: vector<int> parent, rank;
	public:
	UnionFind(int N)
	{
		for(int i=0; i<N; i++)
		{
			parent.push_back(0);
			rank.push_back(i);
		}
	}

	//traverse through the sets to find an element with itself a parent. This is the root.
	int findSet(int i)
	{
		if (parent[i] == i)
		{
			return i;
		}
		return parent[i] = findSet(parent[i]);//path compression
	}

	bool isSameSet(int i, int j)
	{
		return findSet(i) == findSet(j);
	}
	//Rank is the level of the tree
	void unionSet(int i, int j)
	{
		if (!isSameSet)
		{
			int x = findSet(i);
			int y = findSet(j);
			if (rank[x] > rank[y])
			{
				parent[y] = x;
			}
			else
			{
				parent[x] = y;
				if (rank[x] == rank[y])
				{
					rank[y]++;
				}
			}
		}
	}

	int numDisjointSets()
	{
		int count = 0;
		//one for loop,  findSet same as parent
		for(int i=0; i<parent.size(); i++)
		{
			if (parent[i] == i) count++;
		}
		return count;
	}

	int sizeOfSet(int i)
	{
		int count = 0;
		for(int j=0; j<parent.size(); j++)
		{
			if (i != j && isSameSet(i, j))
			{
				count++;
			}
		}

		cout << count << endl;
		
	}
}