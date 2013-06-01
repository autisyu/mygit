#include<stdio.h>
LpList max(const LpList &a, const LpList &b, const LpList &c)
{
    if
    LpList &temp1    = a->data > b->data ? a : b;
    LpList &temp2    = temp1->data > c->data ? temp1 : c;
    LpList temp      = temp2;
    temp2 = temp2->next;
    return temp;
}
void MergeThreeList(const LpList &a, const LpList &b, const LpList &c, LpList &result)
{
    LpList ta = a->next, tb = b->next, tc = c->next;
    result->next = NULL;
    while (ta != NULL || tb != NULL || tc != NULL) {
        LpList temp = max(ta, tb, tc);
        result->next = temp; 
    }

}
int main()
{
}
