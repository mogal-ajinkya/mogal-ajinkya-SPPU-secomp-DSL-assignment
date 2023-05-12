//============================================================================
// Name        : Assignment2.cpp
// Author      : Ajinkya Mogal
// Version     :3 mar
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//Beginning with an empty binary tree, Construct binary tree by inserting
//the values in the order given. After constructing a binary tree perform
//following operations on it-
//1.Perform in order / pre order and post order traversal
//2.Change a tree so that the roles of the left and right pointers are
//swapped at every node
//3.Find the height of tree
//4.Copy this tree to another [operator=]
//5.Count number of leaves, number of internal nodes.
//6.Erase all nodes in a binary tree.
//(implement both recursive and non-recursive methods)

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
void preorder_iterative(node * &root)
{
    if(root == NULL)
        return;
    stack<node *>s;
    s.push(root);

    while(!s.empty())
    {
        node * temp = s.top();
        cout << temp->data << " ";
        s.pop();

        if(temp->right)
        {
            s.push(temp->right);
        }
        
        if(temp->left)
        {
            s.push(temp->left);
        }

    }
}

void inorder_iterative(node * & root)
{
    stack<node * > s;
    // s.push(root);

    node * curr = root;
    while(true)
    {
        if(curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        else{
            if(s.empty()) break;

            curr = s.top();
            cout << curr->data << " ";
            s.pop();
            curr = curr->right;
        }
    }
}
void postorder_iterative(node * root)
{
    stack<node*>s1;
    stack<node*>s2;
    s1.push(root);

    while(!s1.empty())
    {
        node * temp = s1.top();
        s2.push(temp);
        s1.pop();
        if(temp->left)
        {
            s1.push(temp->left);
        }
        if(temp->right)
        {
            s1.push(temp->right);
        }
    }
    while(!s2.empty())
    {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

node *copy(node * &root )
{
    if(root == NULL)
        return NULL;

    node * temp = new node(root->data);
    temp->left  = copy(root->left );
    temp->right = copy(root->right );
    
    return temp;
}

void insert(node * &root)
{
	if(root == NULL)
	{
		cout << "Enter root node: ";
		int a; cin >> a;
		root = new node(a);
	}

	queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
		node * temp = q.front();
		q.pop();
		if(temp == NULL)
			continue;

		cout << "Enter data left to "<< temp->data << " : ";
		int a; cin >> a;
		node * newnodel ;
		if(a != -1)
			newnodel = new node(a);
		else
			newnodel = NULL;

		if(temp->left != NULL)
		{
			q.push(newnodel);
		}
		else
		{
			q.push(newnodel);
			temp->left = newnodel;
		}


		cout << "Enter data right to "<< temp->data;
		cin >> a;
		node * newnoder ;
		if(a != -1)
			newnoder = new node(a);
		else
			newnoder = NULL;

		if(temp->right != NULL)
			q.push(newnodel);
		else
		{
			q.push(newnoder);
			temp->right = newnoder;
		}
	}
	return;
}


void display(node*&root)
{
	if(root == NULL)
	{
		return;
    }

	display(root->left);
	cout << root->data << " ";
	display(root->right);
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

void leavesandinternalnode(node * &root , int &leaves , int &internal)
{
    if(root == NULL)
        return;

    leavesandinternalnode(root->left , leaves , internal);
    leavesandinternalnode(root->right, leaves , internal);
    if(root->left == NULL && root->right == NULL)
    {
        leaves++;
    }
    else{
        internal++;
    }
}

void erase(node * root)
{
    if(root == NULL)
        return ;

    erase(root->left);
    erase(root->right);
    cout << "deleting " << root->data << endl;
    delete root;
}


int main() {
	node*root = NULL;
	// insert(root);
	// display(root);
    // preorder(root);
    // node* clone = copy(root );
    // display(clone);
    // int leaves = 0;
    // int internal = 0;
    // leavesandinternalnode(root , leaves , internal);
    // cout << endl << "leaves" << leaves  <<endl <<"internal " <<  internal;
	// cout << "!!!Hello World!!!" << endl;
    // erase(root);
    // cout << "display" << endl;
    // display(root);
    
	cout << "\n###########menu###############\n1)Create and Insert \n2)Inorder / pre order and post order traversal\n3)Mirrorin \n4)height \n5)Copy of existing tree \n6)leaves and internal node  \n7)delete tree\n\n";
	while(true)
	{
		cout << "Enter operation you want to perform : " ;
		int a ; cin >> a ;

		switch(a)
		{
			case 1:
			{
				insert(root);
                cout << "Tree is sucessfully created !!" << endl;
                display(root);
				break;
			}

			case 2:
            {
                cout << endl << "Inorder iterative : ";
                inorder_iterative(root);
				cout << endl << "Postorder iterative : ";
                postorder_iterative(root);
				cout << endl << "Preorder iterative : ";
                preorder_iterative(root);
            }
				break;
			case 3:
			{
				cout << "\nBefore : ";display(root);
				mirroring(root);
				cout << "\nAfter : " ;display(root);
				cout << "Resetting to intial:";
				mirroring(root);
				cout <<"\n";
			}

				break;
			case 4:
                cout << "Height of tree is : " << longest(root) << endl;
				break;
			case 5:
			{
				cout << "Copy is sucessfully created !!"<< endl;
                node* clone = copy(root );
                cout << "displaying copy : " << endl ;
                display(clone);
			}

				break;
			case 6:
			{
                int leaves = 0;int internal = 0;
                leavesandinternalnode(root , leaves , internal);
                cout << endl << "No. of leaves in tree :" << leaves  <<endl <<"No. of Internal nodes in tree : " <<  internal;
			}
			break;
			case 7:
			{
				erase(root);
                cout << "tree is sucessfully deleted !!"  << endl;
			}
			break;
			default:
				cout << "Enter valid input ?\n";
				break;
		}

		cout << endl << "Do you want to exit ? (1/0) : ";
		bool b; cin >> b;

		if(b)
			break;
	}

	return 0;
}



