#include<vector>

#ifndef STACK_H
#define STACK_H
template<typename T>
class stack
{
	vector<T> arr;
public:
	T top();
	void pop()
	{
		arr.pop_back();
	}
	void push(T d)
	{
		arr.push_back(d);
	}
	bool isEmpty()
	{
		if(arr.size()==0)
			return true;
		else
			return false;
	}
};

template<typename T>
T stack<T>::top()
{
	return arr[arr.size()-1];
}
#endif