#pragma once
#define NULL 0
typedef struct List {
    int data;
    struct List* next;
    List() {
        next = NULL;
    }
}*LpList;

bool CreateList(LpList& head, int eof);

bool DeleteElementByIndex(LpList& head, int index);

bool DeleteElementByContent(LpList& head, int data);

bool SortList(LpList& head);

bool TraverseList(const LpList& head);
