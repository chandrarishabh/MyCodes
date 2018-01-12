#include<iostream>
#include<list>
using namespace std;

class Graph{
	int v;//No. of vertices
	list<int>* l; 
public:
	Graph(int V)
	{
		v=V; 
		l=new list<int>[v];
	}

	void addEdge(int u, int v, bool bidir=true)
	{
		l[u].push_back(v);
		if(bidir)
			l[v].push_back(u);
	}
	void printAdjL()
	{
		for(int i=0;i<v;i++)
		{
			cout<<i<<" : ";
			for(list<int>::iterator x=l[i].begin();x!=l[i].end();x++)
				cout<<*x<<',';
			cout<<endl; 
		}
	}

};
int main()
{
	Graph X(5);
	X.addEdge(0,1);
	X.addEdge(0,4);
	X.addEdge(4,1);
	X.addEdge(4,3);
	X.addEdge(1,3);
	X.addEdge(2,1);
	X.addEdge(2,3);
	X.printAdjL();
}