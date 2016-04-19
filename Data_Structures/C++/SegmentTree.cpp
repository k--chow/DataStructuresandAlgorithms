#include <algorithm>
#include <vector>
#include <tuple>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
using namespace std;

typedef pair<int, int> p;

class SegmentTree {

    public:
    int s;//size
    vector<int> backing; //backup array
    vector<int> tree; //sum of each node
    vector<p> range; //left node of each node
    int sum;


    SegmentTree(vector<int> arr)
    {

        this->backing = arr;
        this->s = arr.size();
        for(int i=0; i<4*s; i++)
        {
            tree.push_back(0);
            range.push_back(make_pair(0, 0));
        }
        build(0, s-1, 0);
    }
    //recursive function to build the abstract tree, costs n^2, redo this recursively.
    void build(int start_index, int end_index, int tree_index)
    {
        range[tree_index].first = start_index; //left index
        range[tree_index].second = end_index; // right index
        //termination condition
        if (start_index == end_index)
        {

            this->tree[tree_index] = backing[start_index];
            //cout << "Index: " << tree_index << " " << start_index << ":" << end_index << " " << tree[start_index] << endl;
            return;
        }

        int sum = 0;
        //add up all nodes from start to end
        for(int i=start_index; i<end_index+1; i++)
        {
            sum+=this->backing[i];
        }

        //set tree[index] to the result
        this->tree[tree_index] = sum;

        //cout << "Index: " << tree_index << " " << start_index << ":" << end_index << " " << sum << endl;

        //build left node
        build(start_index, (start_index + end_index)/2, (tree_index * 2) + 1);


        //build right node
        build((start_index + end_index)/2 + 1, end_index, (tree_index * 2) + 2);
    }
    //recursive function to query the segment/fenwick tree sum
    //solutions - save pairs of the index, use left/right for determining
    void c_sum_query(int i, int j, int index) // a dd to a running sum
    {

    	if (index == 0 && sum != 0)
    	{
    		this->sum = 0;
    	}
        //use range and check
        //orange - parts of it in it but parts of it not - continue on
        //traverse again

        //green - all a part of it, return sum on this
        if (range[index].first >= i && range[index].second <= j)
        {
            sum += tree[index];
            return;
        }
        //red all are NOT a part of this, return 0 on this
        else if ((range[index].first < i && range[index].second < i) || (range[index].first > i && range[index].second > i))
        {
            return;
        }
        else //orange node
        {
            c_sum_query(i, j, (2 * index) + 1); //left
            c_sum_query(i, j, (2 * index) + 2); //right
        }

    }

};

