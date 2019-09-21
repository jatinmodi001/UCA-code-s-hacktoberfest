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
Tree* createTree(int in[],int pre[], int start,int end,int *index)     // creating Tree
{
    if(start > end)
        return NULL;
    
    int i = search(in,start,end,pre[(*index)--]);      // finding node in inorder array
    Tree *newnode = (Tree*)malloc(sizeof(Tree));
    newnode->val = in[i];

/*	as in inorder the left part of node will be lie in the left position and
	right part of node will be lie in right position so....		*/
     
    newnode->left = createTree(in,pre,start,i-1,index);
    newnode->right = createTree(in,pre,i+1,end,index);

    /* left is taken first because in pre order is root->left->right and
     we start from end here so after root we have to find left of that node */ 
    return newnode;     
}

int main()
{
    int n;
    scanf("%d",&n);
    int inorder[n];
    int preorder[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&inorder[i]);        // scanning in-order  array
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&preorder[i]);      // scanning pre-order array
    }
    n--;
    Tree *root = createTree(inorder,preorder,0,n,&n); 

    /* here root will be the main binary tree   */

    return 0;
}
