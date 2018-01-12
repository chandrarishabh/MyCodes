#include<iostream>
#include<stdio.h>
#include<list>
#include<map>
#include<queue>
using namespace std;
//ADJACENCY LIST
template<typename T>
class graph{
private:
	map<T,list<T> > g;
public:
	void addEdge(T u, T v, bool bidir = true)
	{
		g[u].push_back(v);
		if(bidir)
			g[v].push_back(u);
	} 
	void printGraph()
	{
		for(typename map<T,list<T> >::iterator i=g.begin();i!=g.end();++i)
		{
			cout<<i->first<<" : ";
			for(typename list<T>::iterator j=i->second.begin();j!=i->second.end();++j)
			{
				cout<<*j<<' ';
			}
			cout<<endl;
		}
	}

	//Breadth First Search
	void BFS(T src)
	{
		queue<T> q;
		map<T,bool> check;
		q.push(src);
		check[src]=true;
		while(!q.empty())
		{
			T front = q.front();
			cout<<front<<" ";
			q.pop();
			for(typename list<T>::iterator i=g[front].begin();i!=g[front].end();++i)
			{
				if(!check[*i])
				{
					q.push(*i);
					check[*i]=true;
				}
			}
		}
	}

	//Depth First Search
	void DFSHelper(T src, map<T,bool> &check)
	{
		check[src]=true;
		cout<<src<<' ';
		for(typename list<T>::iterator it=g[src].begin();it!=g[src].end();++it)
		{
			if(check[*it]!=true)
				DFSHelper(*it,check);
		}
	}
	void DFS(T src)
	{
		map<T, bool> check;
		DFSHelper(src,check);
		int counter=1;
		for(typename map<T,list<T> >::iterator it=g.begin();it!=g.end();++it)
		{
			if(!check[it->first])
			{
				DFSHelper(it->first,check);
				counter++;
			}
		}
		printf("\nThere are %d components.\n",counter);
	}


	//TOPOLOGICAL SORTING USING DFS
	void TS_DFS_helper(T node, map<T, bool> &visited, list<T> &order)
	{
		visited[node]=true;
		for(T i:g[node])
		{
			if(visited[i]!=true)
			{
				TS_DFS_helper(i,visited,order);
			}
		}
		order.push_front(node);
	}
	void TS_DFS()
	{
		map<T,bool> visited;
		list<T> order;
		for(typename map<T,list<T> >::iterator it=g.begin();it!=g.end();++it)
		{
			if(visited[it->first]!=true)
				TS_DFS_helper(it->first, visited,order);
		}
		for(T i:order)
			cout<<i<<' ';	
	}

	void TS_BFS()
	{
		map<T, bool> visited;
		queue<T> q;
		map<T,int> indegrees;
		//Initialising indegrees
		for(typename map<T,list<T> >::iterator it=g.begin();it!=g.end();++it)
		{
			T node = it->first;
			indegrees[node]=0; //if any node is not present as key in map g then it is already mapped zero by default in map indegrees.
			visited[node]=false; 
		}
		//Finding indegrees
		for(typename map<T,list<T> >::iterator it=g.begin();it!=g.end();++it)
		{
			T node = it->first;
			for(T i:g[node])
			{
				indegrees[i]++;
			}
		}
		//Pushing indegree zero element
		for(typename map<T,int >::iterator it=indegrees.begin();it!=indegrees.end();++it)
		{
			T node = it->first;
			if(indegrees[node]==0)
				q.push(node);
		}
		while(!q.empty())
		{
			T front = q.front();
			cout<<front<<' ';	
			q.pop();
			for(T neighbour:g[front])
			{
				indegrees[neighbour]--;
				if(indegrees[neighbour]==0)
					q.push(neighbour);
			}
		}
		cout<<endl;
	}
};
int main()
{
	graph<string> g;
	g.addEdge("A","B",false);
	g.addEdge("B","C",false);
	g.addEdge("C","D",false);
	g.addEdge("D","E",false);
	g.addEdge("C","E",false);
	g.addEdge("A","D",false);
	g.TS_BFS();
};