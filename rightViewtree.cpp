//Right view of a binary tree. 

#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std; 

int height_factor = 0; 
int global_h = 0; 

struct node
{
	struct node* left;
	struct node* right; 
	int item; 
};

struct node* newnode(int val)
{
	struct node* Node = (struct node*)malloc(sizeof(node)); 
	Node->left = NULL; 
	Node->right = NULL; 
	Node->item = val; 
	return Node; 
}

int height(struct node* Root)
{
	if (Root == NULL)
	{
		return 0; 
	}
	int h_left = 1 + height(Root->left); 
	int h_right = 1 + height(Root->right); 
	if (h_left > h_right)
	{
		return h_left; 
	}
	return h_right; 
}

void getTheRightView(struct node* point, int h, int* arr)
{
	if (point == NULL)
		return;
	//Un-commenting this and commenting this - both serve the purpose. 
	/*
	if (h == 1 && arr[h] != 1)
	{
		cout << point->item << endl;
		arr[h] = 1; 
		return; 
	}
	*/
	if (arr[h] != 1)
	{
		cout << point->item << " and " << h << endl;
		arr[h] = 1;
	}
	getTheRightView(point->right, h - 1, arr);  
	getTheRightView(point->left, h - 1, arr);
	return; 
}

int main(int argc, char** argv)
{
	struct node* root = newnode(1); 
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(4);
	root->left->right = newnode(5);
	root->left->right->right = newnode(8);
	root->left->right->left = newnode(6);
	root->left->left->left = newnode(0); 
	root->left->left->left->left = newnode(7);
	int h = height(root); 
	global_h = h; 
	cout << "The height is " << h << endl; 
	int* arr = (int*)malloc(sizeof(int)*5); 
	getTheRightView(root, h, arr); 
	return 0; 
}
