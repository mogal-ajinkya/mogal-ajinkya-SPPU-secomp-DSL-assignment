//============================================================================
// Name        : assignment3.cpp
// Author      : Ajinkya Mogal
// Version     :  10 march / 14 march
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//Create an inordered threaded binary search tree. Perform inorder,
//preorder traversals without recursion and deletion of a node. Analyze
//time and space complexity of the algorithm


#include <iostream>
using namespace std;

class node
{
public :
	int data;
	node * left;
	node * right;
	bool lthread;
	bool rthread;

	node ( int val)
	{
		data = val;
		left = NULL;
		right = NULL;
		lthread = 1;
		rthread = 1;
	}
};

void insert(node * & root , int key)
{

	node * ptr = root;

	while(ptr != NULL)
	{
		if(ptr->data == key)
		{
			cout << "Can`t insert duplicate values!!!!" << endl;
			return;
		}
		if(ptr->data > key)
		{
			if(ptr->lthread == false)
				ptr = ptr->left;
			else
				break;
		}
		else
		{
			if(ptr->rthread == false)
				ptr = ptr->right;
			else
				break;
		}
	}

	node * temp = new node(key);
	if(ptr == NULL)
	{
		root = temp;
	}
	else if(ptr->data > key)
	{
		temp->left = ptr->left;
		temp->right = ptr;
		ptr->lthread = false;
		ptr->left = temp;
	}
	else if (ptr->data < key)
	{
		temp->right = ptr->right;
		temp->left = ptr;
		ptr->rthread = false;
		ptr->right = temp;
	}
}

node * inorder_sucessor(node * ptr)
{
	if(ptr->rthread == true )
		return ptr->right;
	else
	{
		ptr = ptr->right;
		while(ptr->lthread == false)
			ptr = ptr->left;
		return ptr;
	}
}

node * inorder_predecessor(node *ptr)
{
	if(ptr->lthread == true)
		return ptr->left;
	else
	{
		ptr = ptr->left;
		while(ptr->rthread == false)
			ptr = ptr->right;
		return ptr;
	}
}

void traversal_inorder(node *&root )
{
	if(root == NULL)
		return;

	node *temp = root;

	while(temp->lthread == false)
		temp = temp->left;


	while(temp != NULL)
	{
		cout << temp->data << " ";
		temp = inorder_sucessor(temp);
	}

}

void traversal_preorder(node * & root)
{
	if(root == NULL)
		return;
	node * ptr = root;
	while(ptr != NULL)
	{
		cout << ptr->data << " ";
		if(ptr->lthread == false)
			ptr = ptr->left;
		else if(ptr->rthread == false)
			ptr = ptr->right;
		else
		{
			while(ptr != NULL && ptr->rthread == true)
				ptr = ptr->right;
			if(ptr != NULL)
				ptr = ptr->right;
		}
	}
}


node* deletenode(node*&root , node *&par , node *&ptr)
{
//	both child
	if(ptr->lthread == false && ptr->rthread == false)
	{
		cout << "this is exefcuted" << ptr->data;
        // node * s = inorder_sucessor(ptr); to get parent of sucessor we write our own sucessor func
		node * s = ptr->right;
		node * parofsuc = ptr;
		while(s->left != NULL && s->lthread == false)
		{
			parofsuc=s;
			s = s->left;
		}
        ptr->data = s->data;

		cout << "copied and called";
        ptr = deletenode(ptr->right , parofsuc,  s);
	}
//	one  child presentif(ptr->lthread == false && ptr->rthread == true || ptr->lthread == true && ptr->rthread == false)
	else if(ptr->lthread == true && ptr->rthread == true)
	{
		cout << "deleting ptr";
		if(par == NULL)
			root = NULL;
		else if(par->left == ptr)
		{
			par->left = ptr->left;
			par->lthread = true;
		}
		else
		{
			par->right = ptr->right;
			par->rthread = true;
		}

		delete ptr;
		return root;
	}
	else 
	{
		node * child = NULL;
		// check for whether lwft is present or right 
		if(ptr->lthread == true)
			child = ptr->right;
		else
			child = ptr->left;

		// check for right to delete or left of parent  and assign
		if(par == NULL)
			root = NULL;
		else if(par->left == ptr)
			par->left = child;
		else
			par->right = child;

		node * s = inorder_sucessor(ptr);
        node * p = inorder_predecessor(ptr);


		if (ptr->lthread == false)
			p->right = s;
    // If ptr has right subtree.
		else {
        // if (ptr->rthread == false)
            s->left = p;
			}
			
		
		delete ptr;
		return root;
	}

}


node * todelete(node *&root , int key )
{
	if(root == NULL)
	{
		cout << "Tree is empty!!!!!" << endl;
	}
	bool found = 0;
	node * ptr = root;
	node * par = NULL;
	while(ptr != NULL)
	{
		if(ptr->data == key)
		{
			found = 1;
			break;
		}
		par = ptr;
		if(ptr->data > key)
		{
			if(ptr->lthread == false)
				ptr = ptr->left;
			else
				break;
		}
		else
		{
			if(ptr->rthread == false)
				ptr = ptr->right;
			else
				break;
		}
	}
	if(found == 0)
	{
		cout << "Key is not present!!!!!!!";
		return NULL;
	}
	else
	{
		return deletenode(root , par , ptr);
	}
}

int main() {
	node * root = NULL;
	insert(root , 20);
	insert(root , 30);
	insert(root , 10);
	insert(root , 5);
	insert(root , 16);
	insert(root , 14);
	insert(root , 17);
	insert(root , 13);
	insert(root , 15);
	traversal_inorder(root);
	cout << endl;
	traversal_preorder(root);
	cout << endl;
	cout << endl;
	todelete(root , 13);
	traversal_inorder(root);
	cout << endl;
	traversal_preorder(root);
	cout << endl;
	cout << endl;
	cout << endl;
	todelete(root , 14);
	traversal_inorder(root);
	cout << endl;
	traversal_preorder(root);
	cout << endl;
	return 0;
}