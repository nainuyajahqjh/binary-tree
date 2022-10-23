#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node
{   
public:
	int data;
	Node*left;
	Node*right;
	Node(int val)
	{this->data=val;this->left=NULL,this->right=NULL;}
};
Node*createBst(Node*root,int val)
{
	if(root==NULL)
       {  root=new Node(val);}
   else if(root->data<=val)
   	{ root->left=createBst(root->left,val);}
   else {root->right=createBst(root->right,val);}
   	return root; 
}
void inorder(Node*root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
void level_order(Node*root)
{
	queue<Node*>q;
	q.push(root);
	while(!q.empty())
	{
		Node*current=q.front();
		cout<<current->data<<" ";
		if(current->left!=NULL)q.push(current->left);
		if(current ->right!=NULL)q.push(current->right);
		q.pop();
	}
}
bool search(Node*root,int val)
{
	if(root==NULL)return false;
	else if(root->data==val)return true;
	else if(root->data<=val)search(root->left,val);
	else search(root->right,val);
}
int max_height(Node*root)
{
	Node*curr1=root;
	Node*curr2=root;
	int count1=0;
	int count2=0;
	while(curr1->left!=NULL){curr1=curr1->left;count2++;}
	while(curr2->right!=NULL){curr2=curr2->right;count1++;}
	int z=max(count1,count2);
	return z;
}
int min(Node*root)
{
	Node*curr=root;
	while(curr->left!=NULL)curr=curr->left;
	return curr->data;
}
int max(Node*root)
{
	Node*curr=root;
	while(curr->right!=NULL)curr=curr->right;
	return curr->data;
}
int main(void)
{
   Node*root=NULL;
  root=createBst(root,1);
   root=createBst(root,2);
   root=createBst(root,3);
   root=createBst(root,4);
   inorder(root);
   int n;
   cout<<endl;
   cout<<"Enter the data to be searched!";
   cout<<endl;
    cin>>n;
    if(search(root,n))cout<<"The element is found!";
    else cout<<"Element is not found!";
    cout<<endl;
    cout<<"The level order traversal of the tree is : ";
    level_order(root);
    cout<<endl;
    cout<<"The minimum value of thr tree is: ";
    cout<<max(root);
    cout<<endl;
    cout<<"The maximum value of the root is : ";
    cout<<min(root);
    cout<<endl;
    cout<<"The maximum height of the tree is : ";
    cout<<max_height(root);
}