//CIRCULAR QUEUE IMPLEMENTATION
#include<iostream>
using namespace std;
#ifndef QUEUE_H
#define QUEUE_H

template<typename T>
class queue{
	int cs;
	int ms;
	int front;
	int rear;
	T *arr;
public:
	queue(int d=4)
	{
		cs=0;
		ms=d;
		front=0;
		rear=ms-1;
		arr = new T[ms];
	}
	bool full()
	{
		return cs==ms;
	}
	void push(T d)
	{
		if(full())
			cout<<"Queue is already full!\n";
		else
		{
			rear=(rear+1)%ms;
			arr[rear]=d;
			cs++;
		}
	}
	void pop()
	{
		if(cs!=0)
		{
			front=(front+1)%ms;
			cs--;
		}
		else cout<<"Queue is already empty!\n";
	}
	bool empty()
	{
		return (cs==0);
	}
	T atFront()
	{
		if(cs!=0)	return arr[front];
		else cout<<"No elements in queue to show at front!\n";
	}
};

#endif