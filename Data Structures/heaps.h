#include<bits/stdc++.h>
#ifndef HEAPS_H
#define HEAPS_H
using namespace std;
class MinHeap
{
	vector<int> V;
	void heapify(int i)
	{
		int left = 2*i;
		int right = 2*i +1;
		int min_index= i;
		if(left<V.size() && V[i]>V[left])
			min_index = left;
		if(right<V.size() && V[min_index]>V[right])
			min_index = right;
		if(min_index!=i)
			{
				swap(V[min_index],V[i]);
				heapify(min_index);
			} 
	}
public:
	MinHeap()
	{
		V.push_back(-1); //This is to block the zeroth index.
	}
	void push(int d)
	{
		V.push_back(d);
		int index = V.size()-1;
		int parent = index/2;
		while(index>1&&V[index]<V[parent])
		{
			swap(V[parent],V[index]);
			index = parent;
			parent = parent/2;
		}
	}
	void pop()
	{
		 swap(V[1],V[V.size()-1]);
		 V.pop_back();
		 heapify(1);
	}
	int top()
	{
		return V[1];
	}
	bool empty()
	{
		return V.size()==1;
	}
};
#endif