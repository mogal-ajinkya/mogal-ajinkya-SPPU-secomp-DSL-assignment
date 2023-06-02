//============================================================================
// Name        : Assignment-1.cpp
// Author      : Ajinkya Mogal
// Date        : 17 feb / 21 feb / 24 feb
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//Beginning with an empty binary search tree. Construct the binary search tree
//by inserting the values in given order. After constructing binary search tree
//perform following operations 1) Insert a new node 2) Find numbers of node in
//longest path 3) Minimum and maximum data value found in tree 4) Change
//a tree so that the roles of the left and right pointers are swapped at every node
//5)Search an element

#include <bits/stdc++.h>
using namespace std;



class node
{
private:
public:
	int data;
	node*left;
	node*right;
	node(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
};



void insert(node *&root , int data)
{
	node * temp = new node(data);
	node*temp1 = root;
	node *prev = NULL;
	if(root == NULL)
	{
		root = temp;
	}
	else
	{
		while(temp1 != NULL)
		{
			if(data < temp1->data)
			{
				prev = temp1;
				temp1 = temp1->left;
			}
			else
			{
				prev = temp1;
				temp1 = temp1->right;
			}
		}
		if(data < prev->data)
		{
			prev->left = temp;
		}
		else
		{
			prev->right = temp;
		}
	}
}


void display(node*root)
{
	if(root == NULL)
	{
		return;
 	}

	display(root->left);
	cout << root->data << " ";
	display(root->right);
}


int longest(node* &root)
{
	if(root == NULL)
	{
		return 0;
	}

	int a = longest(root->left);
	int b = longest(root->right);
	return max(a,b)+1;
}


//search function for deletion
node* search(node*&root ,node*&prev, int data)
{
	node*temp = root;
	if(root == NULL)
		return NULL;
	else
	{
		while(temp != NULL)
		{
			if(temp->data > data)
			{
				prev = temp;
				temp = temp->left;
			}
			else if(temp->data == data)
			{
				return temp;
			}
			else
			{
				prev = temp;
				temp = temp->right;
			}
		}
		return NULL;
	}
}



node*max(node*&root)
{
	if(root == NULL)
		return NULL;
	node*temp = root;
	node*prev = NULL;
	while(temp != NULL)
	{
		prev = temp;
		temp = temp->right;
	}
	return prev;
}



node*min(node*&root)
{
	if(root == NULL)
		return NULL;
	node*temp = root;
	node*prev = NULL;
	while(temp != NULL)
	{
		prev = temp;
		temp = temp->left;
	}
	return prev;
}



void deletenode(node * &root , int data)
{
	node * todelete = NULL;
	node * prev = NULL;

	todelete = search(root ,prev ,  data);


	if(todelete != NULL)
	{
		if(todelete->right == NULL && todelete->left == NULL)
		{
			if(todelete != root)
			{
				if(prev->left == todelete )
					prev->left = NULL;
				else
					prev->right = NULL;
			}
			else
			{
				root =  NULL;
			}
			
			delete todelete;
		}
		else if(todelete->right && todelete->left )
		{
			node * maxinlsubtree = max(todelete->left);

			todelete->data = maxinlsubtree->data;
			deletenode(todelete->left, maxinlsubtree->data);
		}
		else
		{
			node * toinsert = NULL;
			if(todelete->left)
				toinsert = todelete->left;
			else
				toinsert = todelete->right;

			if(todelete != root)
			{
				if(prev->left == todelete )
					prev->left = toinsert;
				else
					prev->right = toinsert;
			}
			else
			{
				root = toinsert;
			}
			delete todelete;
		}
	}

}

void mirroring(node* &root)
{
	if(root == NULL)
		return ;

	mirroring(root->left);
	mirroring(root->right);

	node*temp = root->left;
	root->left = root->right;
	root->right = temp;
}


void levelT(node * &root)
{
	if(root == NULL)
		return;

	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		node* temp = q.front();
		q.pop();
		if(temp == NULL&& !q.empty())
		{
			cout << endl;
			q.push(NULL);
		}
		else if(temp == NULL)
			continue;
		else
		{
			cout << temp->data << " ";
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);

		}

	}
}
int main() {
	node * root = NULL;
	insert(root , 51);
	insert(root , 85);
	insert(root , 62);
	insert(root , 23);
	insert(root , 10);
	insert(root , 2);
	insert(root , 35);
	levelT(root);
	display(root);


//	cout << "\n###########menu###############\n1)Insert a new node \n2)Numbers of node in longest path\n3)Minimum and maximum value \n4)Mirroring \n5)Search an element\n6)Delete node \n7)display\n\n";
	while(true)
	{
		cout <<endl << "Enter operation you want to perform : " ;
		int a ; cin >> a ;

		switch(a)
		{
			case 1:
			{
				cout << "Enter element you want to insert : \n";
				int z;cin >> z;
				insert(root , z);
				cout << "sucessfully inserted "<< z << endl;
				break;
			}

			case 2:
				cout << "Longest path is : " << longest(root) << endl;
				break;
			case 3:
			{
				cout << "Minimum element is : " << min(root)->data << endl;
				cout << "Maximum element is : " << max(root)->data << endl;
			}

				break;
			case 4:
				cout << "\nBefore : ";display(root);
				mirroring(root);
				cout << "\nAfter : " ;display(root);
				cout << "Resetting to intial:";
				mirroring(root);
				cout <<"\n";
				break;
			case 5:
			{
				cout <<"Enter element you want to search" << endl;
				int y; cin >> y;
				node* notrequire = NULL;
				node* searched = search(root ,notrequire , y);
				if(searched!= NULL)
					cout<< searched->data << " is present !!!" << endl;
				else
					cout << "Absent!!!!!!" << endl;
			}

				break;
			case 6:
			{
				cout <<"Enter node you want to delete:" << endl;
				int x;cin >> x;
				deletenode(root , x);
				cout << "Deleted sucessfully!!!!!"<<endl;
				display(root);
			}
			break;
			case 7:
			{
				cout <<"TREE inorder : " << endl;
				display(root);
				cout << endl;
			}
			break;
			default:
				cout << "Enter valid input ?\n";
				break;
		}

		cout << "Do you want to exit ? (1/0) : ";
		bool b; cin >> b;

		if(b)
			break;
	}

	return 0;
}