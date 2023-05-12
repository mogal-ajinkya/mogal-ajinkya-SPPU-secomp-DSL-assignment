//============================================================================
// Name        : assignment8.cpp
// Author      : Ajinkya Mogal
// Version     : 9 may
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node* left;
	node* right;
	node(int a)
	{
		data = a;
		left = NULL;
		right = NULL;
	}
};


node* insert(int i , int j , pair<int , int > matrix[][5] , int freq[] , int &count )
{
	if(i == j && count < 5)
    {
        return NULL;
    }

    int a = matrix[i][j].second;
    int data = freq[a];
    node * temp = new node(data);
    cout << "data :- " << data  << " " << a <<  " " << i << " " << j << " " <<  count++ <<  endl;
    temp->left = insert(i , a - 1 , matrix , freq , count );
    cout << "done " << endl ;
    temp->right = insert(a  , j , matrix , freq , count );

    return temp;
}

int weight(int freq[],int freq1[] , int start , int end)
{
	int sum = 0;
	for(int i = start + 1 ; i <= end ; i++)
	{
		sum = sum + freq[i];
		// sum = sum + freq1[i];
	}
	return sum;

}
void createMatrix(int key[] , int freq[] ,int freq1[] , pair<int , int > matrix[][5])
{
	for(int i = 0 ; i < 5 ; i++)
	{
		for(int j = 0 ; j < 5 ; j++)
		{
			matrix[i][j] = pair<int , int> {0 , 0};
		}
	}

	int j = 1;
	for(int n = 4 ; n > 0 ; n-- )
	{
		for(int i = 0;i < n ; i++ )
		{
			cout << i << i + j << " ";

			int k = 0;
			int minimu = 100000;      // 0 , 1
			for(int z = i + 1 ; z <= i + j ; z++)
			{
				//  k = z = 1
				int a = matrix[i][z-1].first + matrix[z][i + j].first + weight(freq ,freq1 , i ,i +  j);
//				cout << a << " ";
				if(minimu > a)
				{
					minimu = a;
					k = z;
				}

			}
			matrix[i][i+j] = pair<int , int > {minimu , k };










		}
		cout << endl;
		j++;
	}

}
void displayMatrix(pair<int,int> matrix[][5])
{
	cout << "displaying mat" << endl;

	for(int i = 0 ; i < 5 ; i++)
	{
		for(int j = 0 ; j < 5 ; j++)
		{
			cout << "{" << matrix[i][j].first << " , " << matrix[i][j].second << "}         ";
		}
	cout << endl;
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


int main() {
	cout << "!!!Hello World!!!" << endl;

	pair<int , int > matrix[5][5];
	int key[5] = {0 , 10 , 20 , 30 , 40};
	int freq[5] = { 0 , 4 , 2 , 6 , 3 };
	int freq1[5] = {  3 , 3 , 1 , 1 };
	// int freq[6] = { 0 ,  2 , 3 , 1 , 1 , 1 };

	createMatrix(key , freq , freq1 , matrix);
	displayMatrix(matrix);
    int a = 0;
    node * root = insert(0 , 4 , matrix , freq , a);
    cout << " done ";
    display(root);
	return 0;
}