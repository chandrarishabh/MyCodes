#include<bits/stdc++.h>
using namespace std;
int K=37;
//Linked list node for seperate chaining.
template<typename T>
class node
{
	public:
	node* next;
	T data;
	string key;
	node(string K,T d)
	{
		next =NULL;
		key = K;
		data = d;
	}
	~node()//deletes entire linked list.
	{
		if(next!=NULL)
			delete next;
	}
};

template<typename T>
class hashtable
{
	int ts;
	int cs;
	node<T>** buckets; //node<T>* is data type, we want array or pointer to this datatype.
	int hashFunction(string key)
	{
		int ans = 0;
		int p = 1;
		for(int i=0;i<key.length();i++)
		{
			ans += key[i] * p;
			p=p*K;
			p%=ts;//DOUBT! maybe to keep p in int range. some modular maths being used here.
			ans%=ts;
		}
		return ans;
	}
public:
	hashtable(int d=7)
	{
		ts=d;
		cs=0;
		buckets = new node<T>*[ts];
		for(int i=0;i<ts;i++)
			buckets[i] = NULL;
	}

	void insert(string key, T data)
	{
		int i = hashFunction(key);
		node<T>* newNode = new node<T>(key, data);
		newNode->next = buckets[i];
		buckets[i] = newNode;
		cs++;
		float load = ((float)cs)/((float)ts);
		if(load>=0.7)	rehash();

	}

	void rehash()
	{
		cout<<"Rehashing!\n";
		node<T>** oldBuckets = buckets;
		int oldts = ts;
		ts = ts*2;
		cs=0;
		buckets = new node<T>*[ts];	
		for(int i=0;i<ts;i++)
			buckets[i] = NULL;
		//iterate all the elements
		for(int i=0;i<oldts;i++)
		{
			node<T>* temp = oldBuckets[i];
			while(temp!=NULL)
			{
				insert(temp->key,temp->data);
				temp=temp->next;
			}
			if(oldBuckets[i]!=NULL)	delete oldBuckets[i];
		}
		delete[] oldBuckets;
	}


	void print()
	{
		for(int i=0;i<ts;i++)
		{
			cout<<"Bucket "<<i<<" ->";
			node<T>* mover = buckets[i];
			while(mover!=NULL)
			{
				cout<<mover->key<<"->";
				mover=mover->next;
			}
			cout<<endl;
		}
	}
	void erase(string key)
	{
		int i = hashFunction(key);
		if(buckets[i]->key == key)
		{
			buckets[i]=buckets[i]->next;
			return;
		}
		node<T>* prev = buckets[i];
		node<T>* mover = prev->next;
		while(mover!=NULL)
		{
			if(mover->key == key)
			{
				prev->next=mover->next;
				delete mover;
				return;
			}
			prev = mover;
			mover=mover->next;
		}

	}
	bool isPresent(string key)
	{
		int i = hashFunction(key);
		node<T>* mover = buckets[i];
		while(mover!=NULL)
		{
			if(key==mover->key) return true;
			mover=mover->next;	
		}
		return false;
	}
	T* search(string key)
	{
		int i = hashFunction(key);
		node<T>* mover = buckets[i];
		while(mover!=NULL)
		{
			if(key==mover->key) return &(mover->data);
			mover=mover->next;	
		}
		return NULL;	
	}
	T& operator[](string key) //T& ensures that it sends the reference to original temp; 
	{						  //otherwise LHS pe nhi rkh paegay 	
		T* temp = search(key);
		if(temp==NULL)
		{
			T garbage;
			insert(key,garbage);
			T* temp =search(key);
			return *temp;
		}
		else
			return *temp;
	}
};

