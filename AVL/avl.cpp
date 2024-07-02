#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int key, height;
    int data;
    Node *left, *right;
};Node *ptr=NULL;Node *root=NULL;
int height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
Node *newNode(int key)
{
    Node *node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}
int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
Node *insert(Node *node, int key)
{
    if (node == NULL)
        return (newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}
void inorder(Node *head)
{
    if (head != 0)
    {
        inorder(head->left);
        cout << head->key <<" ";
        inorder(head->right);
    }
}
void increaseBy(Node *head, int x)
{
    if (head != 0)
    {
        increaseBy(head->left, x);
        head->key+=x;
        increaseBy(head->right,x);
    }
}
void search(Node *head, int x)
{
    if (head == NULL)
    {
        cout << "This element is not found!\n";
        return;
    }
    else
    {
        while (head != 0)
        {
            if (x > head->key)
                head = head->right;
            else if (x < head->key)
                head = head->left;
            else
            {
                cout << "This element is found!\n";
                return;
            }
        }
        cout<<"This element is not found!\n";
    }
}

void display(Node *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        display(ptr->right, level+1);
        cout<<endl;
        if (ptr == root)
            cout<<"Root->:  ";
        else
        {
            for (i = 0;i < level;i++)
                  cout<<"       ";
	    }
        cout<<ptr->key;
        display(ptr->left, level+1);
    }
}
int main()
{
    Node *root = NULL;
    int x,n,i,j,k;
    while(1)
    {
        cout<<"1.Create a AVL tree"<<endl;
        cout<<"2.Insert"<<endl;
        cout<<"3.Increase"<<endl;
        cout<<"4.Inorder Display"<<endl;
        cout<<"5.display in tree"<<endl;
        cout<<"6.search"<<endl;
        cout<<"which option to choose"<<endl;
        cin>>x;
        if(x==1)
        {
            cout<<"How many element?"<<endl;
            cin>>n;
            int a;
            for(i=0; i<n; i++)
            {
                cin>>a;
                root=insert(root,a);
            }
        }
        else if(x==2)
        {
            cout<<"Insert element"<<endl;
            cin>>k;
            insert(root,k);
        }
        else if(x==3)
        {
            cout<<"Increase"<<endl;
            cin>>j;
            increaseBy(root,j);
        }
        else if(x==4)
        {
            inorder(root);
        }
                else if(x==5)
    {
        cout<<"Display Tree:"<<endl;
            display(root,1);
            cout<<endl;
    }
    else if(x==6)
    {
        int t;
        cout<<"which element want to search : ";
            cin>>t;
            search(root,t);

    }
    cout<<endl;
    }
    return 0;
}
