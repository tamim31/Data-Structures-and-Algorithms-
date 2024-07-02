#include<bits/stdc++.h>
using namespace std;
int p=0;
class Node
{
    public:
    int data;
    Node *left,*right;
};
    Node *r=NULL;Node *ptr=NULL;Node *pp=NULL;Node *qq=NULL;
void creation()
    {
        int item,n,i,t,k=0,tt=1;
    cout<<"number of nodes : ";
    cin>>n;
    cout<<" nodes : "<<endl;
    for(i=0;i<n;i++)
    {
        pp=new Node;
        cin>>item;
        pp->data=item;//pp holo amr array te je data ace
        pp->left=NULL;
        pp->right=NULL;
        if(i==0) r=pp;//0 index data ta root
        else
        {
            qq=r;//root
            while(1)
            {
                if(pp->data>qq->data) //qq data holo root ta,pp jake ami array teke tolchi              /16
//pp greater than qq,pp will add into right side of qq
//(cheak kore bosabo qq right empty kina
//empty na takle qq right right a bosbe;
              //8  18
                {
                    if(qq->right==NULL)
                    {
                        qq->right=pp;
                        break;
                    }
                    else
                    {
                        qq=qq->right;
                    }
                }
                else
                {
                    if(qq->left==NULL)
                    {
                        qq->left=pp;
                        break;
                    }
                    else
                    {
                        qq=qq->left;
                    }
                }
            }
        }
    }

    }
    void insertion(Node *p, Node *q)
{
    if (r== NULL)
    {
        r = new Node;
        r->data = q->data;
        r->left = NULL;
        r->right = NULL;
        cout<<"Root Node is Added"<<endl;
        return;
    }
    if (r->data == q->data)
    {
        cout<<"data already added in the root"<<endl;
        return;
    }
     if(p->data >q->data)
        //q holo new data,,p holo root,,p take q choto hole root left side q add hobe
    {
        if (p->left != NULL)
        {
            insertion(p->left,q);
	    }
	else
	   {
            p->left =q;
            (p->left)->left = NULL;
            (p->left)->right = NULL;
            cout<<"node is added "<<endl;
            return;
        }
    }
    else//q jodi root take boro ba soman hole root right side q add hobe
    {
        if (p->right != NULL)
        {
            insertion(p->right,q);
        }
        else
        {
            p->right = q;
            (p->right)->left = NULL;
            (p->right)->right = NULL;
            cout<<"node is added "<<endl;
            return;
        }
    }
}
void root(Node *r)
  {
     Node *temp=r;
        if(temp==NULL)
        {
            return;
        }
        cout<<"Root of the BST :  "<<temp->data<<endl;
  }


  void min(Node *r)
  {
     Node *temp=r;
        if(temp==NULL)
        {
            return;
        }
        while(temp->left!=NULL)
        {
            temp=temp->left;
        }
        cout<<"min value of the BST : "<<temp->data<<endl;
  }
  void max(Node *r)
  {
     Node *temp=r;
        if(temp==NULL)
        {
            return;
        }
        while(temp->right!=NULL)
        {
            temp=temp->right;
        }
        cout<<"max value of the BST : "<<temp->data<<endl;
  }
  void predecessor(Node *r,int item)
{
    int k=0;Node *temp=r;
    if(temp==NULL)
    {
        cout<<" Predecessor is absent "<<endl;
    }
    while(temp!=NULL)
    {
        if(temp->data==item)
        {
            p=1;
            if(temp->left!=NULL)//predessor holo jtogola choto data ace ,tar modhe boro ta
            {
                temp=temp->left;
                while(temp->right!=NULL)
                    {
                        temp=temp->right;
                    }
          cout<<"Predecessor of node "<<item<<" is "<<temp->data<<endl;
                return;
            }
            else if(k>0)
            {
                cout<<"Predecessor of node "<<item<<" is "<<k<<endl;
                //9 10 14//10 predec 9
                return;
            }
            else
            {
                cout<<" Predecessor is absent "<<endl;
                return;
            }
        }

        else if(item>temp->data)//item=8
        {
            k=temp->data;
            temp=temp->right;
        }
        else
        {
            temp=temp->left;
        }
    }
}

void successor(Node *r,int item)
{
        int k=0;Node *temp=r;
        if(temp==NULL)
        {
                cout<<" successor is absent "<<endl;
                return;
        }
        while(temp!=NULL)
        {
                if(item==temp->data)
                {
                        p=1;
                        if(temp->right!=NULL)//successor holo jto gola boro data ace tar modhe choto ta
                        {
                                temp=temp->right;
                                while(temp->left!=NULL)
                                {
                                        temp=temp->left;
                                }
                cout<<"successor of node "<<item<<" is "<<temp->data<<endl;
                                return;
                        }
                        else if(k>0)
                        {
                cout<<"successor of node "<<item<<" is "<<k<<endl;//root o successor hoy//7 6 8
                                return;
                        }
                        else
                        {
                                cout<<" successor is absent "<<endl;
                                return;
                        }
                }
                else if(item<temp->data)
                {
                        k=temp->data;
                        temp=temp->left;
                }
                else
                        temp=temp->right;
        }
}

    void inorder(Node *r)
{
        Node *temp=r;
        if(temp==NULL)
        {
            return;
        }
        inorder(temp->left);
        cout<<temp->data<<" ";
        inorder(temp->right);
        return;
}
void postorder(Node *r)
{
    Node *temp=r;
        if(temp==NULL)
        {
            return;
        }
        postorder(temp->left);
        postorder(temp->right);
        cout<<temp->data<<"  ";
}
void preorder(Node *r)
{
    Node *temp=r;
        if(temp==NULL)
        {
            return;
        }
        cout<<temp->data<<"  ";
        preorder(temp->left);
        preorder(temp->right);
}
void display(Node *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        display(ptr->right, level+1);
        cout<<endl;
        if (ptr == r)
            cout<<"Root->:  ";
        else
        {
            for (i = 0;i < level;i++)
                  cout<<"       ";
	    }
        cout<<ptr->data;
        display(ptr->left, level+1);
    }
}
Node* FindMin(Node *r) {
   if(r== NULL)
    {
      return 0;
    }
   if(r->left != NULL)
   {
      return FindMin(r->left);
   }
   return r;
}
void search(Node* r, int key, Node* parent)
{
    if (r==NULL) {
        cout << "search Key "<<key<<" is not found in BST";
        return;
    }
    if (r->data == key)
    {
        if (parent ==NULL)
        {
            cout << "The node with key " << key << " is root node"<<endl;
        }
        else if (key < parent->data)
        {
            cout<<"search key "<<key<<" is the left node of the node with key "<<parent->data<<endl;
        }
        else
        {
            cout<<"search key "<<key<<" is the right node of the node with key "<< parent->data<<endl;
        }
        return;
    }
    if (key < r->data)
        {
        return search(r->left, key, r);
        }
    return search(r->right, key, r);
}
Node *LCARecursive(Node* r, int x, int y)
{
    if (r== NULL) {
        return NULL;
    }
    if (r->data > max(x, y)) {
        return LCARecursive(r->left, x, y);
    }
    else if (r->data < min(x, y)) {
        return LCARecursive(r->right, x, y);
    }
    return r;
}
//computation of lowest common ancestors may be useful, for instance,
//as part of a procedure for determining the distance between pairs of nodes in a tree:
void LCA(Node* r, int x, int y)
{
    Node* lca = LCARecursive(r, x, y);
    if (lca !=NULL)
    {
        cout << "LCA is " << lca->data << endl;
    }
    else
    {
        cout << "LCA does not exist"<<endl;
    }
}
void findFloorCeil(Node* r, Node* &floor, Node* &ceil, int key)
{
    if (r ==NULL) {
        return;
    }
    if (r->data == key)
    {
        floor = r;
        ceil = r;
    }
    else if (key < r->data)
    {
        ceil = r;
        findFloorCeil(r->left, floor, ceil, key);
    }
    else
    {
        floor = r;
        findFloorCeil(r->right, floor, ceil, key);
    }
}

Node* Delete( Node *r, int key) {
     if(r == NULL)
    {
        cout<<"node with "<<key <<" wanted to delete is absent in BST "<<endl;
     return NULL;
    }
    if(r->data > key)//key data jake ami delete korbo,, r data is root
    {
      r->left = Delete(r->left, key);
    }
   else if(key > r->data)
    {
      r->right = Delete(r->right, key);
    }
    else
     {

     if(r->left == NULL && r->right == NULL)//leaf node mane child na takle
        {
        delete(r);
        r= NULL;
        }
     else if(r->left == NULL)//sodo right child takle,,left child na takle
     {
        Node *temp = r;
        r= r->right;
        delete temp;
     }
     else if(r->right == NULL)//sodo left child takle,,right child na takle
     {

        Node *temp = r;
        r = r->left;
        delete temp;
     }
     else if(r->right!= NULL && r->left!= NULL)
     {
         Node *temp ;
         temp= FindMin(r->right);//inorder successor madome small data search kora
        r->data = temp->data;
        r->right = Delete(r->right, temp->data);
     }
  }
  return r;
}
int main()
{
    int level,ch;Node *temp;
    while(1)
    {
  cout<<"1.BST Creat   2.Insert  3.Inorder   4.Preorder   5.Postorder  6.Display  7.Min  "<<endl;
cout<<"8.Max  9.Root  10.Successor   11.Predecessor  12.Delete   13.Search  14.LAC  15.findFloorCeil"<<endl;
    cout<<endl;
        cout<<"Enter your choice : ";
        cin>>ch;
        cout<<endl;
        if(ch==1)
        {
            creation();
        }
        else if(ch==2)
        {
            temp = new Node;
            cout<<"data to be inserted : ";
	    cin>>temp->data;
            insertion(r, temp);
        }
    else if(ch==3)
        {
    cout<<"inorder"<<endl;
    inorder(r);
    cout<<endl;}
    else if(ch==4)
        {
    cout<<"preorder"<<endl;
    preorder(r);
    cout<<endl;}
    else if(ch==5)
        {
    cout<<"postorder"<<endl;
    postorder(r);
    cout<<endl;}
    else if(ch==6)
    {
        cout<<"Display BST:"<<endl;
            display(r,1);
            cout<<endl;
    }
    else if(ch==7)
    {
        min(r);
    }
    else if(ch==8)
    {
        max(r);
    }
    else if(ch==9)
    {
        root(r);
    }
    else if(ch==10)
    {
        p=0;
            int item;
            cout<<"Enter the value: ";
            cin>>item;
            successor(r,item);
            if(p==0)
                cout<<" successor is absent "<<endl;
    }
    else if(ch==11)
    {
        p=0;
            int item;
            cout<<"Enter the value: ";
            cin>>item;
            predecessor(r,item);
            if(p==0)
                cout<<"Invalid predecessor"<<endl;
    }
    else if(ch==12)
    {
        int item;
        cout<<"data want to be deleted : ";
	    cin>>item;
        Delete(r,item);
    }
     else if(ch==13)
    {
            int kk,ll=0,mm;
        cout<<"search key : ";
    cin>>kk;
    search(r,kk,NULL);
    }
    else if(ch==14)
    {
        int x,y;
        cout<<"x : ";
        cin>>x;
        cout<<"y : ";
        cin>>y;
        LCA(r,x,y);
    }
    else if(ch==15)
    {
        for(int i = 0; i < 15; i++)
       {
           Node *floor = NULL, *ceil = NULL;
           findFloorCeil(r,floor,ceil,i);
             cout << setw(2) << i << " �> ";
        cout <<setw(4)<< (floor? floor->data: -1);
        cout<<setw(4) << (ceil? ceil->data: -1) << endl;
        }

    }

        else break;}
}
