#include <iostream>
using namespace std;
struct TreeNode
{
    char data;
    TreeNode *fChild = NULL;
    TreeNode *nSib = NULL;
};
TreeNode *newNode(char x)
{
    TreeNode *q = new TreeNode();
    q->data = x;
    q->fChild = q->nSib = NULL;
    return q;
};
TreeNode *addChild(TreeNode *p, char x)
{
    TreeNode *q = newNode(x);
    if (p == NULL)
        p = q;
    else
    {
        p->fChild = q;
    }
    return q;
}
TreeNode *addSib(TreeNode *p, char x)
{
    TreeNode *q = newNode(x);
    if (p == NULL)
        p = q;
    else
    {
        p->nSib = q;
    }
    return q;
}
void preOrder(TreeNode *p)
{
    if (p != NULL)
    {
        TreeNode *q = p->fChild;
        cout << p->data << '-';
        preOrder(q);
        if (q != NULL)
        {
            q = q->nSib;
            while (q != NULL)
            {
                preOrder(q);
                q = q->nSib;
            }
        }
    }
}
void inOrder(TreeNode *p)
{
    if (p != NULL)
    {
        TreeNode *q = p->fChild;
        inOrder(q);
        cout << p->data << '-';
        if (q != NULL)
        {
            q = q->nSib;
            while (q != NULL)
            {
                inOrder(q);
                q = q->nSib;
            }
        }
    }
}
void postOrder(TreeNode *p)
{
    if (p != NULL)
    {
        TreeNode *q = p->fChild;
        postOrder(q);
        if (q != NULL)
        {
            q = q->nSib;
            while (q != NULL)
            {
                postOrder(q);
                q = q->nSib;
            }
        }
        cout << p->data << '-';
    }
}
int main()
{
    TreeNode *T = newNode('A');
    TreeNode *A = T, *B, *C, *D, *E, *F, *G, *H, *I, *J, *K, *L, *M, *N, *P, *Q;
    B = addChild(A, 'B');
    C = addSib(B, 'C');
    D = addSib(C, 'D');
    E = addSib(D, 'E');
    F = addSib(E, 'F');
    G = addSib(F, 'G');
    //
    H = addChild(D, 'H');
    //
    I = addChild(E, 'I');
    J = addSib(I, 'J');
    P = addChild(J, 'P');
    Q = addSib(P, 'Q');
    //
    K = addChild(F, 'K');
    L = addSib(K, 'L');
    M = addSib(L, 'M');
    //
    N = addChild(G, 'N');
    cout << "\n=========PREORDER==========" << endl;
    preOrder(T);
    cout << "\n=========INORDER==========" << A->fChild->data << endl;
    inOrder(T);
    cout << "\n=========POSTORDER==========" << A->fChild->data << endl;
    postOrder(T);
    return 0;
}