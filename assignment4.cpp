//============================================================================
// Name        : assignment4.cpp
// Author      : Ajinkya Mogal
// Version     : 24 march
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


class node
{
public:
	string name;
	int number;

	node(int telephone , string name)
	{
		this->name = name;
		this->number = telephone;
	}
};

node *hasharra[10] = {NULL};
node *hasharra2[10] = {NULL};


int hashfunc(int telephone)
{
	return telephone%10;
}

void insertWOR(int telephone , string name)
{
	node *temp = new node(telephone , name);

	int hindex = hashfunc(telephone);
	int count = 1;
	while(hasharra[hindex] != NULL  &&  count != 10)
	{
		hindex++;
		count++;

		hindex = hindex%10;
	}
	if(hasharra[hindex] == NULL)
	{
		hasharra[hindex] = temp;
//		cout << hasharra[hindex]->number << " is inserted" << endl;
	}
	else
	{
		cout << endl << "Can't inser array is full" << endl ;
	}
}

void insertWR(int telephone , string name)
{
	node *temp = new node(telephone , name);

	int hindex = hashfunc(telephone);
	int count = 1;

	if(hasharra2[hindex] != NULL && hashfunc(hasharra2[hindex]->number) != hindex)
	{
		node * temp2 = hasharra2[hindex];
		hasharra2[hindex] = temp;
		temp = temp2;
	}

	while(hasharra2[hindex] != NULL  &&  count != 10)
	{
		hindex++;
		count++;

		hindex = hindex%10;
	}
	if(hasharra2[hindex] == NULL)
	{
		hasharra2[hindex] = temp;
//		cout << hasharra2[hindex]->number << " is inserted" << endl;
	}
	else
	{
		cout << "Can't inser array is full" << endl ;
	}
}

node * search(int key)
{
	int hindex = hashfunc(key);

	while(hasharra[hindex] != NULL )
	{
		if(hasharra[hindex]->number == key)
			return hasharra[hindex];

		hindex++;
		hindex = hindex%10;
	}
	return NULL;
}

void deletetele(int key)
{
	int hindex = hashfunc(key);

	while(hasharra[hindex] != NULL )
	{
		if(hasharra[hindex]->number == key)
		{
			cout << "Deleting - " << hasharra[hindex]->number;
			hasharra[hindex] = NULL;
			return;
		}

		hindex++;
		hindex = hindex%10;
	}
	cout << "Not present " ;
}

void display(node *arra[])
{
	for(int i = 0 ; i  < 10 ; i++)
	{
		if( arra[i] == NULL )
		{
			cout  << endl << i << " " << "NULL";
			continue;
		}
		cout << endl << i << " " <<arra[i]->name << " " << arra[i]->number << " ";
	}
}
int main() {

	insertWOR(12,"aad");
	insertWOR(2,"aad");
	insertWOR(22,"aad");
	insertWOR(34,"aad");
	insertWOR(67,"aad");
	insertWOR(1,"aad");
	insertWOR(90,"aad");
	insertWOR(45,"aad");
	insertWOR(37,"aad");
	insertWOR(22,"aad");
	insertWOR(88,"aad");
	display(hasharra);


	insertWR(12,"aad");
	insertWR(2,"aad");
	insertWR(23,"aad");
	insertWR(34,"aad");
	insertWR(67,"aad");
	insertWR(1,"aad");
	insertWR(90,"aad");
	insertWR(45,"aad");
	insertWR(37,"aad");
	insertWR(26,"aad");
	insertWR(81,"aad");
	display(hasharra2);


	return 0;
}
