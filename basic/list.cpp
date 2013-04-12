#include "list.h"
#include <stdlib.h>
#include <iostream>
#include <malloc.h>
using namespace std;
bool CreateList(LpList& head, int eof)
{
    if (NULL == head) {
      return -1;
    }
    int data;
    LpList p1, p2;
    p1 = p2 = head;
    cin>>data;
    while(data != eof) {
      if (NULL == (p2 =  new List())) {
        return -1;
      }
      p2->data = data;
      p1->next = p2;
      p1       = p2;
      cin>>data;
    }
    return 0;
}

bool DeleteElementByIndex(LpList& head, int index)
{
    if (NULL == head || index < 0) {
      return -1;
    }
    LpList p1 = head; 
    LpList p2 = head ->next;
    int count = index;
    while (p2 && --count) {
      p1 = p2;
      p2 = p2->next;
    }
    if (0 == count) {
      p1->next = p2->next;
      free(p2);
    } else {
      return -1;
    }
    return 0;
}

bool DeleteElementByContent(LpList& head, int data)
{
    if (NULL == head) {
      return -1;
    }
    LpList p1 = head; 
    LpList p2 = head ->next;
    while (p2 && p2->data != data) {
      p1 = p2;
      p2 = p2->next;
    }
    if (p2) {
      p1->next = p2->next;
      free(p2);
    } else {
      return -1;
    }
    return 0;

}

bool SortList(LpList& head)
{
    LpList s = head, p = head, node = head->next;
    while (node) {
        s           = head;
	int data    = node->data;
	while (s->next != node && (data > s->next->data)) {
	    s = s->next;
	}
        if (s->next == node) {
	    p = node, node = node->next;
	    continue;
	} else {
	    p->next     = node->next;
	    node->next  = s->next;
	    s->next     = node;
	    node        = p->next;
	}
    }
}
bool TraverseList(const LpList& head)
{
    if (NULL == head) {
      return -1;
    }
    LpList p1 = head->next;
    while (NULL != p1) {
      cout<<p1->data<<" ";
      p1 = p1->next;
    }
    cout<<endl;
    return 0;
}

int main()
{
    LpList head = new List();
    CreateList(head, 5);
    TraverseList(head);
    SortList(head);
    TraverseList(head);
}
