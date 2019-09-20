#include<stdio.h>
#include<stdlib.h>
typedef struct Tree
{
    int data;
    struct Tree* left;
    struct Tree* right;
}Tree;

typedef struct sTree
{
    Tree* node;
    int dist;
}sTree;

typedef struct node
{
    sTree *snode;
    struct node *next;
}Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
}Queue;

typedef struct Map
{
    int key;
    int data;
}Map;

typedef struct List
{
    Map m;
    struct List* next;
}MapLinkedList;

void pushBegin(MapLinkedList **ll,int key,int val)
{
    MapLinkedList *new = (MapLinkedList*)malloc(sizeof(int));
    new->m.key = key;
    new->m.data = val;
    new->next = *ll;
    *ll = new;
}
void pushEnd(MapLinkedList **ll,int key,int val)
{
    MapLinkedList *new = (MapLinkedList*)malloc(sizeof(int));
    new->m.key = key;
    new->m.data = val;
    if((*ll) == NULL)
    {   
        new->next = *ll;
        *ll = new;
    }
    else 
    {
        MapLinkedList *itr = *ll;
        while(itr->next)
        {
            itr = itr->next;
        }
        itr->next = new;
        new->next = NULL;
    }
}
int find(MapLinkedList *l,int val)
{
    MapLinkedList *itr = l;
    while(itr)
    {
        if(itr->m.key == val)
        {
            return 1;
        }
        itr = itr->next;
    }
    return 0;
}

void push(Queue *q,sTree *n)
{
    Node *new = (Node*)malloc(sizeof(Node));
    new->snode = n;
    new->next = NULL;
    if(q->front == NULL)
    {
        q->front = new;
        q->rear = new;
    }
    else 
    {
        q->rear->next = new;
        q->rear = new;
    }
}
void pop(Queue *q)
{
    if(q->front)
    {
        q->front = q->front->next;
        if(q->front == NULL)
        {
            q->rear = NULL;
        }
    }
}

int isEmpty(Queue *q)
{
    if(q->front  == NULL)
        return 1;
    return 0;
}

Tree* Insert_BST(Tree* root,int d)
{
    if(root == NULL)
    {
        Tree* a = (Tree*)malloc(sizeof(Tree));
        a->left = NULL;
        a->right = NULL;
        a->data = d;
        return a;
    }
    if(root->data == d){}
    else if(root->data > d)
    {
        root->left = Insert_BST(root->left,d);
    }
    else
    {
        root->right = Insert_BST(root->right,d);
    }
    return root;
}
void print_BST(Tree* root)
{
    if(root == NULL)
        return;
    print_BST(root->left);
    printf("%d ",root->data);
    print_BST(root->right);
}

MapLinkedList* getMap(Tree* root,Queue *q)
{
    sTree* nn = (sTree*)malloc(sizeof(sTree));
    nn->node = root;
    nn->dist = 0;
    push(q,nn);
    MapLinkedList *mp = NULL;
    while(!isEmpty(q))
    {
        int data = q->front->snode->node->data;
        int dist = q->front->snode->dist;
        if(!find(mp,dist))
        {
            if(dist >=0)
            {
                pushEnd(&mp,dist,data);
            }
            else if(dist < 0)
            {
                pushBegin(&mp,dist,data);
            }
        }
        Node *temp = q->front;
        pop(q);
        
        if(temp->snode->node->left)
        {
            sTree *nn1 = (sTree*)malloc(sizeof(sTree));
            nn1->node = temp->snode->node->left;
            nn1->dist = temp->snode->dist - 1;
            push(q,nn1);
        }
        if(temp->snode->node->right)
        {
            sTree *nn1 = (sTree*)malloc(sizeof(sTree));
            nn1->node = temp->snode->node->right;
            nn1->dist = temp->snode->dist + 1;
            push(q,nn1);
        }
    }
    return mp;
}   

int main()
{
    Tree *bst = NULL;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        bst = Insert_BST(bst,a);
    }
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    
    MapLinkedList *l =  getMap(bst,q);
    for(MapLinkedList *itr = l;itr!= NULL;itr = itr->next)
    {
        printf("%d  ",itr->m.data);
    }
}