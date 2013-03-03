#include<iostream>
using namespace std;
template <typename T>
struct LinkNode {
    struct LinkNode* next;
    T data;
    LinkNode() {
        next = NULL;
    }
};
typedef struct LinkNode<int> *LinkList;
bool CreateList(LinkList head, int n)
{
    if (head == NULL) return false;
    LinkList p1, p2;
    p2 = p1 = head;
    int data;
    for (int i = 0; i < n; ++i) {
        p2 = new LinkNode<int>();
	if (p2 == NULL) return false;
        cin>>data;
	p2->data = data;
	p1->next = p2;
	p1 = p2;
    }
    return true;
    
}
bool Delete(LinkList head, int data)
{
    LinkList p2 = head->next, p1 = head;
    while (p2) {
        if (p2->data == data) {
	    p1->next = p2->next;
            delete p2;
	    p2 = NULL;
	    break;
	} else {
	    p1 = p2, p2 = p2->next;
	}
    }
    return true;
}
bool insert(LinkList head, int data)
{
    LinkList p1 = head, temp = NULL;
    while (p1->next) {
        p1 = p1->next;
    }

    temp = new LinkNode<int>();
    if (temp == NULL) return false;
    temp->data = data;
    p1->next = temp;
    return true;
}
bool Display(LinkList head) 
{
    LinkList p1 = head->next;
    while (p1) {
        cout<<p1->data<<" ";
	p1 = p1->next;
    }
    cout<<endl;
    return true;
}
int main()
{
    int n;
    LinkList head = new LinkNode<int>();
    cin>>n;
    CreateList(head, n);
    Display(head);
    cin>>n;
    Delete(head, n);
    Display(head);
    insert(head, n);
    Display(head);
    return 0;
}
