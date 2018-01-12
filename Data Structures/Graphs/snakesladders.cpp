/* In this program we have a snakes and ladder 1-36 grid. Our aim is to find the 
minimum number of dice throw such that we can reach the top! We achieve this by
making a directional graph of with 37 nodes and all the possible vertices. Then we
simply apply Breadth Field Search with some modification. */

#include<bits/stdc++.h>
using namespace std;
template<typename T>
class graph
{
	map<T, list<T> > M;
public:
	void addEdge(T u, T v, bool bd = true)
	{
		M[u].push_back(v);
		if(bd)
			M[v].push_back(u);
	}
	int shortestDistance(T src, T dest)
	{
		queue<T> q;
		map<T,int> distance;
		map<T,T> parent;
		for(auto i:M)
				distance[i.first]=10000;
		q.push(src);
		distance[src]=0;
		parent[src]=src;
		while(!q.empty())
		{
			T node = q.front();
			q.pop();
			for(auto c:M[node])
			{
				if(distance[c]==10000)
				{
					q.push(c);
					distance[c] = distance[node] + 1;
					parent[c]=node;
				}
			}
		}
		//to show the path taken!
		T temp = dest;
		while(temp!=src)
		{
			cout<<temp<<"<-";
			temp=parent[temp];
		}
		cout<<endl;
		return distance[dest];
	}
};
int main()
{
	graph<int> X;
	
	//this accounts for snakes and ladder jumps.
	vector<int> board(37,0);
	board[2]=13;
	board[5]=2;
	board[9]=18;
	board[18]=11;
	board[17]=-13;
	board[20]=-14;
	board[24]=-8;
	board[20]=-14;
	board[24]=-8;
	board[25]=-10;
	board[32]=-2;
	board[34]=-22;
	for(int i=0;i<=36;i++)
		for(int j=1;j<=6;j++)
		{
			int v = i+j+board[i+j]; //i is current position, j is possible dice throw #, board[i+j] is jump.
			X.addEdge(i,v,false);
		}
	cout<<X.shortestDistance(1,36); 

}


