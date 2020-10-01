#include<iostream>
using namespace std;
class node
{
public:
	int data;
	node* next;
	node(int d)
	{
		data = d;
		next = NULL;
	}
};
void insertAtTail(node* &head, int d)
{
	node* temp = new node(d);
	if (head == NULL)
		head = temp;
	else
	{
		node* root = head;
		while (root->next != NULL)
			root = root->next;
		root->next = temp;
	}
}
void buildList(node* &head)
{
	int n;
	cin >> n;
	while (n != -1)
	{
		insertAtTail(head, n);
		cin >> n;
	}
}
void print(node* head)
{
	while (head != NULL)
	{
		cout << head->data << "->";
		head = head ->next;
	}
	cout << endl;
}
node* midPoint(node*head)
{
	if (head == NULL || head->next == NULL)
		return head;
	node*slow = head;
	node*fast = head->next;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
node* merge(node* a, node* b)
{
	if (a == NULL)
		return b;
	if (b == NULL)
		return a;

	node* c;
	if (a->data < b->data)
	{
		c = a;
		c->next = merge(a->next, b);
	}
	else
	{
		c = b;
		c->next = merge(a, b->next);
	}
	return c;
}
node* mergeSort(node* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	node* mid = midPoint(head);
	node* a = head;
	node* b = mid->next;
	mid->next = NULL;
	a = mergeSort(a);
	b = mergeSort(b);
	node* c = merge(a, b);
	return c;
}
int main()
{
	node* head = NULL;
	buildList(head);
	print(head);
	head = mergeSort(head);
	print(head);
}