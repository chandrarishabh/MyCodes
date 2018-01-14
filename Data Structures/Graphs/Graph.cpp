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
	//TOPOLOGICAL SORTING USING BFS
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

	//Cycle detection in Directed Graph using DFS
	bool cycleDetector(T node, map<T,bool> &visited, map<T,bool> &inStack)
	{
		//we mark each node visited(simple DFS) so that we donot go through them again.
		visited[node]=true;
		inStack[node]=true;

		//exploring neighbours of each node.
		for(T neighbour:g[node])
		{
			//this checks if the node is univisited or not and also if there is any cycle
			//further down that node. Base case is OR case that checks if that node was already 
			//present inStack.
			//base case
			if((!visited[neighbour]&&cycleDetector(neighbour,visited,inStack))||inStack[neighbour])
			{
				return true;
			}
		}
		//removes that node from stack after completely exploring it.
		inStack[node]=false;
		return false;
	}
	bool isCyclic()
	{
		map<T,bool> visited;
		map<T,bool> inStack;
		//this loop ensures that we check for cycle in each tree of graph forest.
		for(auto i: g)
		{
			T node = i.first;
			for(T j:g[node])
			{
				if(!visited[j])
				{
					//this cycle present checks if there is any cycle further in that node.
					bool cyclePresent = cycleDetector(j,visited,inStack);
					if(cyclePresent)
						return true;
				}
			}
		}
		return false;
 	}

 	//Cycle detection in undirected graph using BFS
 	bool CD_BFS(T src)
 	{
 		queue<T> q;
 		map<T,bool> visited;
 		map<T,int> parent;
 		q.push(src);
 		visited[src] = true;
 		parent[src]=src;
 		while(!q.empty())
 		{
 			T dad = q.front();
 			q.pop();
 			for(T x:g[dad])
 			{
 				//already visited and is not parent node!
 				if(visited[x]==true&&parent[dad]!=x)
 				{
 					cout<<"Cycle Present!\n";
 					return true;
 				}
 				else if(!visited[x])
 				{
 					visited[x]=true;
 					parent[x]=dad;
 					q.push(x);
 				}
 				
 			}
 		}
 		cout<<"Cycle not present!\n";
 		return false;
 	}

 	//Cycle detection in undirected graph using DFS
 	bool CD_DFS_helper(T node, T parent, map<T,bool> &visited)
	{
		visited[node]=true;
		for(auto neighbour:g[node])
		{
			if(visited[neighbour]!=true)
			{
				bool c = CD_DFS_helper(neighbour, node, visited);
				if(c) return true;
			}
			else if(visited[node]==true&&neighbour!=parent)
				return true;
		}
		return false;
	}
 	bool CD_DFS()
	 	{
	 		map<T,bool> visited;
	 		for(auto i : g)
	 		{
	 			T node = i.first;
	 			if(visited[node]!=true)
	 			{
	 				bool check = CD_DFS_helper(node, node, visited);
	 				if(check)
	 					return true;
	 			}
	 		}
	 		return false;
	 	}

};
int main()
{
	graph<int> g;
	g.addEdge(1,0);
	g.addEdge(1,2);
	g.addEdge(4,0);
	g.addEdge(4,2);
	cout<<endl<<g.CD_DFS();
};