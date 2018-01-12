#include<bits/stdc++.h>
using namespace std;
class node
{
public:
	int data;
	node* left;
	node* right;
	node(int d)
	{
		data=d;
		left=NULL;
		right=NULL;
	}
};
//Takes input and builds tree
node* buildTree()
{
	int i;
	cin>>i;
	if(i!=-1)
	{
		node* newNode = new node(i);
		newNode->left = buildTree();
		newNode->right = buildTree();
		return newNode;
	}
	else return NULL;
}
void printTree1(node* root) //PRE-ORDER PRINTING
{
	if(root!=NULL)
	{
		cout<<root->data<<' ';
		printTree1(root->left);
		printTree1(root->right);
	}
}
void printTree2(node* root) //IN-ORDER PRINTING
{
	if(root!=NULL)
	{
		printTree2(root->left);
		cout<<root->data<<' ';
		printTree2(root->right);
	}
	else return;
}
void printTree3(node* root) //POST-ORDER PRINTING
{
	if(root!=NULL)
	{
		printTree3(root->left);
		printTree3(root->right);
		cout<<root->data<<' ';
	}
	else return;
}
//Print Nodes level wise.
void levelorderPrint(node* root)
{
	queue<node*> q;
	node* temp=NULL;
	if(root)
	{
		q.push(root);
		q.push(NULL);
	}
	while(!q.empty())
	{
		if(q.front())
		{
			temp=q.front();
			cout<<temp->data<<' ';
			q.pop();
			if(temp->left)	q.push(temp->left);
			if(temp->right)	q.push(temp->right);
		}
		/*
		when we pop one null node then only we add other null node in the queue
		given that queue is not empty. Simulate queue with paper and pen, you will
		realise yourself. Spent more than 15 minutes figuring this out.
		*/
		else
		{
			cout<<endl;
			q.pop();
			if(!q.empty())	q.push(NULL); 
		}
	}
}
//For counting number of Nodes
int countNodes(node* root)
{
	if(!root)
		return 0;
	else 
		return 1 + countNodes(root->left) + countNodes(root->right);
}
//For height of tree.
int height(node* root)
{
	if(root==NULL)
		return 0;
	else
	{
		return 1 + max(height(root->right),height(root->left));
	}
}
//Diameter longest distance between two nodes.
int diameter(node* root)
{
	if(!root)	return 0;
	else
	{
		/*
		we have three possibilities.
		if diameter is passing through root then op1, otherwise we check for diameter
		taking left and right as diameter. Then check for max out of all three.
		*/
		int op1 = height(root->left) + height(root->right);
		int op2 = diameter(root->left);
		int op3 = diameter(root->right);
		return max(op1,max(op2,op3));
	}
}
//This is a bottom up approach. This transverse each node only once unlike above which transverse each node
//multiple times. It improves time efficiency!
class Pair
{
	public:
	int diameter;
	int height;
};
Pair pairDiameter(node* root)
{
	Pair p;
	if(root==NULL)
	{
		p.height = p.diameter =0; 
		return p;
	}
	else
	{
		Pair L = pairDiameter(root->left);
		Pair R = pairDiameter(root->right);
		p.height = max(L.height,R.height) + 1;
		int opt1 = L.height + R.height;
		int opt2 = L.diameter;
		int opt3 = R.diameter;
		p.diameter = max(opt1,max(opt2,opt3));
		return p;
	}
}
// End of Bottom-up approach!
bool searchNode(node* root, int d)
{

	if(root==NULL) return false;
	if(root->data==d) return true;
	else if(searchNode(root->left,d)||searchNode(root->right,d)) return true;
}
//Searching element in BST!
node* searchBST(node* root, int d)
{
	if(root==NULL)	return NULL;
	if(root->data==d) return root;
	else if(root->data>d) return searchBST(root->left,d);
	else return searchBST(root->right,d);
}

//Making tree from inorder and preorder arrays
int i=0;
int n;
node* makeTree(int *pre, int *in, int s, int e)
{
	if(s>e)	return NULL;
	int k =-1;
	int d = pre[i];
	i++;
	node* newNode = new node(d);
	for(int j=0;j<n;j++)
	{
		if(in[j]==d)
		{
			k=j;
			break;
		}
	}
	newNode->left = makeTree(pre, in, s, k-1);
	newNode->right = makeTree(pre,in,k+1,e);	
	return newNode;
}
void mirror(node* root)
{
	if(root==NULL)
		return;
	else
	{
		swap(root->left,root->right);
		mirror(root->left);
		mirror(root->right);
	}
}
//Building tree level wise
node* buildTreeLevel()
{
	queue<node*> q;
	int d;
	cout<<"Enter root data: "; 
	cin>>d;
	if(d!=-1)
	{	
		node* newNode = new node(d);
		q.push(newNode);
		while(!q.empty())
		{
			node* temp= q.front();
			cout<<"Enter children of "<<temp->data<<" :";
			q.pop();
			int c1,c2;
			cin>>c1>>c2;
			if(c1!=-1)
			{
				temp->left = new node(c1);
				q.push(temp->left);
			}
			if(c2!=-1)
			{
				temp->right = new node(c2);
				q.push(temp->right);
			}
		}
		return newNode;
	}
	else return NULL;
}
//Bottom up approach to find if tree is height balanced!
class HB
{
public:
	int height;
	bool balanced;
};
HB heightBalanced(node* root)
{
	HB p;
	if(root==NULL)
	{
		p.height=0;
		p.balanced=true;
		return p;
	}
	HB left = heightBalanced(root->left);
	HB right = heightBalanced(root->right);
	p.height = 1 + max(left.height,right.height);
	if(left.balanced&&right.balanced&&(abs(left.height - right.height)<=1))
		p.balanced = true;
	else 
		p.balanced=false;
	return p;
}
//Searching in Binary Tree
bool isBST(node* root, int MIN=INT_MIN, int MAX=INT_MAX)
{
	if(root==NULL)
		return true;
	int d = root->data;
	if(d<=MAX&&MIN<=d&&isBST(root->left,MIN,d)&&isBST(root->right,d,MAX))
		return true;
	return false;
}
node* insertBST(node* root, int d)
{
	if(root==NULL)
	{
		root = new node(d);
	}
	else if(d<=root->data) 
	{
		root->left = insertBST(root->left,d);
	}
	else
	{
		root->right = insertBST(root->right,d);
	}
	return root;
}
node* buildBST()
{
	node* root=NULL;
	int d;
	cin>>d;
	while(d!=-1)
	{
		root = insertBST(root, d);
		cin>>d;
	}
	return root;
}
node* Array2BST(int* A, int s, int e)
{
	if(s>e)
		return NULL;
	int mid = (s+e)/2;
	node* newNode = new node(A[mid]);
	newNode->left = Array2BST(A, s, mid-1);
	newNode->right = Array2BST(A, mid+1, e);
	return newNode;
}
class LinkedList
{
public:
	node* head;
	node* tail;
};
LinkedList BST2LS(node* root)
{
	LinkedList l;
	if(root==NULL)
	{
		l.head=NULL;
		l.tail=NULL;
		return l;
	}
	else if(root->left==NULL&&root->right==NULL)
	{
		l.head = root;
		l.tail = root;
		return l;
	}
	else if(root->left==NULL&&root->right!=NULL)
	{
		LinkedList R = BST2LS(root->right);
		root->right = R.head;
		l.tail = R.tail;
		l.head = root;
	}
	else if(root->left!=NULL&&root->right==NULL)
	{
		LinkedList L = BST2LS(root->left);
		L.tail->right = root;
		l.head = L.head;
		l.tail = root;
	}
	else
	{
		LinkedList L = BST2LS(root->left);
		LinkedList R = BST2LS(root->right);
		L.tail->right = root;
		root->right = R.head;
		l.head = L.head;
		l.tail = R.tail;
	}
	return l;
}
void printList(LinkedList l)
{
	node* X = l.head;
	do
	{
		cout<<X->data<<" ";
		X=X->right;
	}while(X!=l.tail);	
}
int main()
{
	/*node* root = buildTree();
	cout<<endl;*/
	/*int pre[] = {1,2,4,5,3,7,6,8};
	int in[] =  {4,2,5,1,7,3,8,6};
	int post[] ={4,5,2,7,8,6,3,1};
	n = sizeof(in)/sizeof(int);
	node* root = makeTree(pre,in,0,n-1); 
	mirror(root);
	node* root = buildTreeLevel();*/
	/*int a[] = {0,1,2,3,4,5,6,7,8,9,10,11};
	int n = sizeof(a)/sizeof(int);
	node* root = Array2BST(a,0,n-1);
	printTree1(root);
	cout<<endl;
	printTree2(root);
	cout<<endl;
	printTree3(root);
	cout<<endl;
	levelorderPrint(root);
	cout<<"Number of nodes : "<<countNodes(root)<<endl;
	cout<<"Diameter : "<<pairDiameter(root).diameter<<endl;
	cout<<"Height : "<<pairDiameter(root).height<<endl;
	HB x = heightBalanced(root);
	cout<<isBST(root);*/
	int a[] = {0,1,2,3,4,5,6,7,8,9,10,11};
	int n = sizeof(a)/sizeof(int);
	node* root = Array2BST(a,0,n-1);
	LinkedList Q = BST2LS(root);
	printList(Q);
}




