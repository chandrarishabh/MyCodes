#include<iostream>
#include<map>
#include<queue>
#include<list>
using namespace std;

template<typename T>
class Graph
{
	map<T,list<T> > X;
public:
	void addEdge(T u, T v, bool bidir=true)
	{
		X[u].push_back(v);
		if(bidir)
			X[v].push_back(u);		
	}
	void print()
	{
		for(auto o:X)
		{
			cout<<o.first<<"->";
			for(auto i:o.second)
				cout<<i<<',';
			cout<<endl;
		}  
	}
	//BFS - Breadth First Search
	void BFS(T src)
	{
		queue<T> q;
		map<T,bool> check;
		q.push(src);
		check[src] = true;
		while(!q.empty())
		{
			T node = q.front();
			cout<<node<<" ";
			q.pop();
			for(auto i:X[node])
			{
				if(!check[i])
				{
					check[i]=true;
					q.push(i);
				}
			}
		}
		cout<<endl;
	}
	void shortPathBFS(T src)
	{
		queue<T> q;
		map<T,int> distance;
		map<T,T> parent;//Not in use in this function.
		for(auto x:X)
			distance[x.first]=INT8_MAX;
		q.push(src);
		distance[src]=0;
		parent[src]=src;
		while(!q.empty())
		{
			T node = q.front();
			q.pop();
			for(auto i:X[node])
			{
				if(distance[i]==INT8_MAX)
				{
					q.push(i);
					parent[i]=node;
					distance[i]=distance[node]+1;
				}
			}
		}
		for(auto c:X)
			cout<<"distance of "<<c.first<<" from source is "<<distance[c.first]<<endl;

	}
};
int main()
{
	Graph<int> X;
	X.addEdge(0,1);
	X.addEdge(0,4);
	X.addEdge(1,2);
	X.addEdge(2,4);
	X.addEdge(2,3);
	X.addEdge(4,3);
	X.addEdge(5,3);
	X.BFS(2);
}