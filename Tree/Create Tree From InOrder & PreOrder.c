#include<stdio.h>
#include<stdlib.h>

typedef struct bst
{
    int val;
    struct bst* left;
    struct bst* right;
}Tree;
int search(int in[],int start,int end,int k)          // Searching given num in inorder array
{
    for(int i=start;i<=end;i++)
    {
        if(in[i] == k)
            return i;
    }
}
Tree* createTree(int in[],int post[], int start,int end,int *index)     // creating Tree
{
    if(start > end)
        return NULL;
    
    int i = search(in,start,end,post[(*index)--]);      // finding node in inorder array
    Tree *newnode = (Tree*)malloc(sizeof(Tree));
    newnode->val = in[i];

/*	as in inorder the left part of node will be lie in the left position and
	right part of node will be lie in right position so....		*/

    newnode->right = createTree(in,post,i+1,end,index);     
    newnode->left = createTree(in,post,start,i-1,index);

    /* right is taken first because in post order is left->right->root and
     we start from end here so after root we have to find right of that node */ 
    return newnode;     
}

int main()
{
    int n;
    scanf("%d",&n);
    int inorder[n];
    int postorder[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&inorder[i]);        // scanning in-order  array
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&postorder[i]);      // scanning post-order array
    }
    n--;
    Tree *root = createTree(inorder,postorder,0,n,&n); 

    /* here root will be the main binary tree   */

    return 0;
}