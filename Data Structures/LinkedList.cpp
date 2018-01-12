#include<bits/stdc++.h>
using namespace std;

//node prototype
class node{
public:
	int data;
	node* next;
	node(int d)
	{
		data=d;
		next=NULL;
	}
};
//creating head and tail
	node* head=NULL;
	node* tail=NULL;
//Note that head and tail are just pointer names. They can only point to nodes, they are not node themselves. 

//function to find length of linked list or number of nodes in linked list
int ListLength(node* head)
{
	int x=0;
	while(head!=NULL)
	{
		head=head->next;
		x++;
	}
	return x;
}


//function to add element at front
void insertFront(node* &head, int d)
{
	node* newNode = new node(d);
	newNode->next = head;
	head = newNode;
}

//function to add element at back
void insertBack(node* &head, int d)
{
	node* newNode = new node(d);
	if(head==NULL)
	{
		head=newNode;
	}
	else
	{
		node* mover = head;
		while(mover->next!=NULL)
		{
			mover=mover->next;
		}
		mover->next=newNode;
	}
}

void insertMiddle(node* &head, node* &tail, int pos, int d)
{
	
	int x = ListLength(head);
	if(pos==0)
		insertFront(head,d); //if position is zero, then it means add element after 0 node which is equivalent to insertFront.
	else if(pos>x) cout<<"Overflow!";
	else
	{
		node* jumper = head; //creating jumper pointer that will jump to different nodes.
		for(int jumps=0;jumps<pos-1;jumps++) //in 2 jumps, it is at 3rd node, thats why pos-1 is upper limit of jump. 
		{
			jumper=jumper->next;
		}

		node* temp= jumper->next; //temp stores address of next node.
		node* newNode = new node(d);
		newNode->next = temp;
		jumper->next = newNode;

	}
}

//function to print elements of linked list
void printList(node* head)
{
	cout<<endl;
	if(head==NULL) cout<<"Linked List is empty!\n";
	while(head!=NULL)
	{
		cout<<head->data<<"-->";
		head=head->next;
	}
	cout<<endl;
}

//function to take input
void takeInput(node* &head)
{
	int n;
	cin>>n;
	while(n!=-1)
	{
		//insertFront(head,n);
		insertBack(head,n);
		cin>>n;
	}

}

//function to find middle node
node* middleNode(node* head)
{
	node* slow= head;
	node* fast=head;
	while(fast->next!=NULL && fast->next->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}

void reverseList(node* &head, node* &tail)
{
	if(head==NULL || head->next==NULL)
		return ;
	node* prev=NULL;
	node* current =head;
	tail=current;
	node* N;
	while(current!=NULL)
	{
		//updating N 
		N=current->next;
		current->next=prev;
		prev=current;
		current=N;
	}
	head=prev;
}

//function to find element recursively in a linked list.
bool recSearch(node* head, int key)
{
	if(head==NULL)
		return false;
	if(head->data==key)
		return true;
	return recSearch(head->next,key);
}


//this recursively reverses a linked list O(n^2)
node* recReverse(node* head)
{
	//base case
	if(head==NULL||head->next==NULL)
		return head;
	//otherwise
	node* smallHead = recReverse(head->next);
	node* temp=smallHead;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next = head;
	head->next=NULL;
	return smallHead;
}

//more optimised reversing using recursion O(n)
node* reverseRecOptimised(node*head)
{
	if(head==NULL||head->next==NULL)
		return head;
	node* smallHead=reverseRecOptimised(head->next);
	head->next->next=head;
	head->next = NULL;
	return smallHead;
}

//merging two sorted linked list using recursion
node* sorted(node*head1, node*head2)
{
	node *combinedHead=NULL;
	node *nextHead=NULL;
	
	if(head1==NULL) return head2;
	else if (head2==NULL) return head1;

	if(head1->data > head2->data)
	{
		combinedHead=head2;
		nextHead=sorted(head1,head2->next);
	}
	else if(head1->data<=head2->data)
	{
		combinedHead=head1;
		nextHead= sorted(head1->next,head2);
	}

	combinedHead->next = nextHead;
	return combinedHead;

}
//function to merge sort linked list.
node* MergeSort(node* head)
{
	if(head->next==NULL || head==NULL)
			return head;

	node* head1   = head;
	node* tail1   = middleNode(head);
	node* head2   = tail1->next;
	tail1->next   =NULL;

	head1 = MergeSort(head1);
	head2 = MergeSort(head2);

	return sorted(head1, head2); 
}

// //function to check if there is a cycle in linked list and breaks it! //Not tested!
void cycledetection(node* head)
{
	bool flag=false;
	node* fast=head;
	node* slow=head;
	while(slow!=NULL && fast!=NULL && fast->next!=NULL)  // use && not || because if any condition is false then we have to stop the loop
	{
		fast=fast->next->next;
		slow=slow->next;
		if(fast==slow)
			{
				flag=true;
				while(head->next!=slow->next)
				{
					head = head->next;
					slow = slow->next;
				}
				slow->next=NULL;

				break;
			}
	}
	
}

node* getTail(node* head)
{
	node* temp=head;
	while(temp->next!=NULL)
		temp=temp->next;
	return temp;
} 		


int main()
{


	takeInput(head);
	printList(head);
	// int pos,d;
	// cin>>pos>>d;
	// insertMiddle(head,tail,pos,d);
	// printList(head);
	//cout<<endl<<middleNode(head)->data;
	// reverseList(head,tail);
	// printList(head);
	// cout<<recSearch(head,5);
	// head = reverseRecOptimised(head);
	// printList(head);
	// node* head1=NULL;
	// node* head2=NULL;
	// takeInput(head1);
	// takeInput(head2);
	// printList(head1);
	// printList(head2);
	// node* head3=sorted(head1,head2);
	// printList(head3);

	//printList(MergeSort(head));
	return 0;
}