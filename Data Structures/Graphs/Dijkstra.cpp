#include<iostream>
#include<unordered_map>
#include<list>
#include<set>
#define debug(x) cout<<#x<<" = "<<x<<endl;
using namespace std;
template<typename T>
class graph{
private:
	unordered_map<T,list<pair<T,int> > > g;
public:
	void addEdge(T u, T v, int d, bool bidir=true)
	{
		g[u].push_back(make_pair(v,d));
		if(bidir)
			g[v].push_back(make_pair(u,d));
	}
	void printGraph()
	{
		for(auto nodes:g)
		{
			cout<<nodes.first<<" : ";
			for(auto neighbours:g[nodes.first])
			{
				cout<<'('<<neighbours.first<<','<<neighbours.second<<") ";
			}
			cout<<endl;
		}
	}
	//this takes src which acts as starting point.
	void dijkstra(T src)
	{
		//we take a distance table and order table. order table is a set that sorts
		//on basis of distance of that node from starting point. minimum distance always
		//on top.
		unordered_map<T,int> distance;
		set<pair<int, T> > order;
		//setting distances of all vertices to infinity
		for(auto n:g)
			distance[n.first]=INT8_MAX;
		//starting distance is set to zero.
		distance[src]=0;
		order.insert(make_pair(distance[src],src));
		while(!order.empty())
		{
			auto top_order = order.begin();
			T cur_node = top_order->second;
			int neighbour_distance = top_order->first;
			//we delete the top most element. if it occurs again, it will be automatically added
			//to order table. this is necessary because otherwise our order table will
			//never be empty.
			order.erase(order.begin());
			//iterating over the top node.
			for(auto neighbours:g[cur_node])
			{
				int new_dist =  neighbour_distance + neighbours.second;
				if(new_dist<distance[neighbours.first])
				{
					//changing value of element in order table. elements in set cannot be directly 
					//changed. so we either delete the previous copy and add the new editied copy
					//or just make new copy if not already present.
					auto old = order.find(make_pair(distance[neighbours.first],neighbours.first));
					if(old!=order.end())
						order.erase(old);
					order.insert(make_pair(new_dist,neighbours.first));
					//also updating the distance table. this is necessary as we use distance table
					//in check condition above (line 57). missed this step, wasted 20 minutes :P
					distance[neighbours.first]=new_dist;
				}
			}
		}
		//finally iterating through each element distance from the source element.
		for(auto x:distance)
			cout<<x.first<<" : "<<x.second<<endl;
	}

	void shortestRoute_Dijkstra(T src, T dest)
	{
		unordered_map<T,pair<int,T> > distance;
		set<pair<int,T> > order;
		for(auto i:g)
		{
			distance[i.first].first=INT8_MAX;
			distance[i.first].second=src;
		}
		distance[src].first=0;
		distance[src].second=src;
		order.insert(make_pair(0,src));
		while(!order.empty())
		{
			auto top_element = order.begin();
			T cur_node = top_element->second;
			int cur_dist = top_element->first;
			order.erase(order.begin());
			for(auto neighbours : g[cur_node])
			{
				int new_dist = neighbours.second + cur_dist;
				if(new_dist<distance[neighbours.first].first)
				{
					auto old = order.find(make_pair(distance[neighbours.first].first,neighbours.first));
					if(old!=order.end())
						order.erase(old);
					order.insert(make_pair(new_dist,neighbours.first));
					distance[neighbours.first].first=new_dist;
					distance[neighbours.first].second=cur_node;					
				}
			}
		}
		T cur = dest;
		while(cur!=src)
		{
			cout<<cur<<" <- ";
			cur = distance[cur].second;
		}
		cout<<src<<endl;
	}

};
int main()
{
	graph<string> india;
	india.addEdge("Amritsar","Delhi",1);
    india.addEdge("Amritsar","Jaipur",4);
    india.addEdge("Jaipur","Delhi",2);
    india.addEdge("Jaipur","Mumbai",8);
    india.addEdge("Bhopal","Agra",2);
    india.addEdge("Mumbai","Bhopal",3);
    india.addEdge("Agra","Delhi",1);
    india.shortestRoute_Dijkstra("Delhi","Mumbai");
}