//============================================================================
// Name        : assignment9.cpp
// Author      : Ajinkya Mogal
// Version     :  12 may
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//A Dictionary stores keywords & its meanings. Provide facility for
//adding new keywords, deleting keywords, updating values of any
//entry. Provide facility to display whole data sorted in ascending/
//Descending order. Also find how many maximum comparisons may
//require for finding any keyword. Use Height balance tree and find the
//complexity for finding a keyword.


#include <iostream>
using namespace std;



class node
{
    public:
	int data;
	node*left , * right;
	int height;
	int balancefact ;
	node(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
		height = 1;
		balancefact = 0;
	}
};
class AVLTree
{

    public:
	int getHeight(node * root)
	{
		if(root == NULL)
			return 0;
		int a = getHeight(root->left);
		int b = getHeight(root->right);

		return max(a , b) + 1;
	}

	int getBalancefact(node * root)
	{
		if(root == NULL)
			return 0;

		int a = getHeight(root->left);
		int b = getHeight(root->right);

		return a - b;
	}

	node * leftrotate(node*root)
	{
		node*temp = root->right;
		root->right = temp->left;
		temp->left = root;

		temp->height = getHeight(temp);
		temp->balancefact = getBalancefact(temp);

		root->height = getHeight(root);
		root->balancefact = getBalancefact(root);
		return temp;
	}

	node * rightrotate(node*root)
	{
		node*temp = root->left;
		root->left = temp->right;
		temp->right = root;

		temp->height = getHeight(temp);
		temp->balancefact = getBalancefact(temp);

		root->height = getHeight(root);
		root->balancefact = getBalancefact(root);
		return temp;
	}
	node * insert(node* &root , int a)
	{
		if(root == NULL)
			return new node(a);
		else if(a < root->data)
		{
			root->left = insert(root->left , a);
		}
		else if(a > root->data)
		{
			root->right = insert(root->right , a);
		}
		else
			cout << "Cant insert duplicate value";


		root->height = getHeight(root);

		root->balancefact = getBalancefact(root);


//		right right
		if(root->balancefact < -1 && a > root->right->data)
		{
			return leftrotate(root);
		}
//		right left
		else if(root->balancefact < -1 && a < root->right->data)
		{
			root->right = rightrotate(root->right);
			return leftrotate(root);
		}
//		left left
		else if(root->balancefact > 1 && a < root->left->data)
		{
			return rightrotate(root);
		}
//		left right
		else if(root->balancefact > 1 && a > root->left->data)
		{
			root->left = leftrotate(root->left);
			return rightrotate(root);
		}
		else
		{

		}

		return root;

	}
	void display(node * root)
	{
		if(root == NULL)
			return ;
		display(root->left);
		cout << root->data <<  " ";
		display(root->right);
	}
};

int main()
{
	AVLTree t;
	node * root = NULL;

    cout << "Enter how many node you want to insert : " << endl;
    int a ; cin >> a;
    cout << "Enter n element with space : "<<endl;
    for(int i = 0 ; i < a ; i++)
    {
        int b ;cin>> b;
	root = t.insert(root , b);
	t.display(root);
    cout << endl;

    }
    // 9
// 11 14 17 7 8 4 13 10 12
	// root = t.insert(root , 11);
	// root = t.insert(root , 14);
	// root = t.insert(root , 17);
	// root = t.insert(root , 7);
	// root = t.insert(root , 8);
	// root = t.insert(root , 4);
	// root = t.insert(root , 13);
	// root = t.insert(root , 10);
	// root = t.insert(root , 12);
	return 0;
}
