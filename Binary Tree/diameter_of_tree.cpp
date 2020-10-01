#include <bits/stdc++.h>
using namespace std;

class node
{
  public:
  int data;
  node* left;
  node* right;

  node(int d)
  {
    data= d;
    left = NULL;
    right = NULL;
  }
};

node* buildTree()
{
  int d;
  cin>>d;

  if(d==-1)
  return NULL;

  node* root = new node(d);
  root->left=buildTree();
  root->right = buildTree();
  return root;
}

class Pair
{
  public:
  int height;
  int diameter;
};

Pair diameter(node* root)
{  
  Pair p;
  if(root==NULL)
  {
    p.height = 0;
    p.diameter = 0;
    return p;
  }

  Pair left = diameter(root->left);
  Pair right = diameter(root->right);
  
  p.height = max(left.height, right.height)+1;
  p.diameter = max(left.height+right.height, max(left.diameter, right.diameter));
  return p;
}

int main()
{
  node* root = buildTree();
  Pair p = diameter(root);
  cout<<"Diameter: "<<p.diameter<<endl<<"Height: "<<p.height;
  return 0;
}

