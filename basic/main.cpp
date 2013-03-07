#include "list.h"
#include<malloc.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int main()
{
    LpList head = new List();
    if (CreateList(head, 0)) {
      cout<<"CreateList error!"<<endl;
      exit(0);
    }
    if (TraverseList(head)) {
      cout<<"TraverseList error!"<<endl;
      exit(0);
    }
    if (DeleteElementByContent(head, 2)) {
      cout<<"DeleteElementByContent error"<<endl;
      exit(0);
    }
    TraverseList(head);
    return 0;
}
