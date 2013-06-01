#include<stdio.h>
#include<malloc.h>
struct TNode {
    int data;
    struct TNode *lc, *rc;
    TNode() {
        lc = NULL, rc = NULL;
    }
};
typedef TNode* Tree;

void PreCreateTree(Tree& root)
{
    int data;
    scanf("%d", &data);
    if (data == -1) {
	return;
    }
    root       = (Tree)malloc(sizeof(TNode));
    root->data = data;
    PreCreateTree(root->lc);
    PreCreateTree(root->rc);
}
void PreTraverse(Tree root) 
{
loop:
    if (root) {
        printf("%d", root->data);
        PreTraverse(root->lc);
	root = root->rc;
	goto loop;
    }
}
void InTravese(Tree root)
{
loop:
    if (root) {
        InTravese(root->lc);
	printf("%d", root->data);
	root = root->rc;
	goto loop;
    }
}
int main()
{
    Tree root;
    PreCreateTree(root);
    PreTraverse(root);
    InTravese(root);
    return 0;
}
