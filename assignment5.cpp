//============================================================================
// Name        : assignment5.cpp
// Author      : Ajinkya Mogal
// Version     : 28 march
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//Implement all the functions of a dictionary (ADT) using open
//hashing technique: separate chaining using linked list Data: Set of
//(key, value) pairs, Keys are mapped to values, Keys must be
//comparable, and Keys must be unique. Standard Operations: Insert
//(key, value), Find(key), Delete(key)
#include <iostream>
using namespace std;
class node
{
public:
	string key;
	string value;
	node * next;

	node(string _key , string _value)
	{
		key = _key;
		value = _value;
		next = NULL;
	}
};

class hashing
{
	node *hashed_array[10] = {NULL};
public :
	int hash_func(string key)
	{
		return key[0]%10;
	}

	void insert(string key , string value )
	{
		int hash_index = hash_func(key);
		node * prev = NULL;
		node * curr = hashed_array[hash_index];

		while(curr != NULL)
		{
			prev = curr;
			curr = curr->next;
		}

		if(curr == NULL && prev == NULL)
		{
			node * temp = new node(key, value);
			hashed_array[hash_index] = temp;
		}
		else
		{
			node * temp = new node(key , value);
			prev->next = temp;
		}

	}

	void display()
	{
		for(int i = 0 ; i < 10 ; i++)
		{
			if(hashed_array[i] == NULL)
			cout << i <<" NULL" << endl;
			if(hashed_array[i] != NULL)
			{
				cout << i << "->>"<< endl;
//				node * prev = NULL;
				node * curr = hashed_array[i];
				while(curr != NULL)
				{
					string temp = curr->key;
					char c = temp[0];
					cout <<"  " << "KEY=> " << curr->key << "   VALUE=> " << curr->value << " ascii- " << int(c) << endl;
					curr = curr->next;
				}
			}
		}
	}

	void deleteelement(string key)
	{
		int hash_index = hash_func(key);
		node * prev = NULL;
		node * curr = hashed_array[hash_index];

		if(curr == NULL)
		{
			cout << "NOt present";
		}

		while(curr != NULL)
		{
			if(prev == NULL && curr->key == key)
			{

				hashed_array[hash_index] = curr->next;
				return;
			}
			if(curr->key == key)
			{
//				delete code
				prev = curr->next;
				delete curr;
				// cout << "DEleted";
				return;
			}
			prev = curr;
			if(curr != NULL)
			curr = curr->next;
		}
		cout << "NOT PRESENT" ;
	}

	void search(string key)
	{
		int hash_index = hash_func(key);
		node * curr = hashed_array[hash_index];

		if(curr == NULL)
		{
			cout << "NOT PRESENT" << endl;
		}
		else
		{
			bool ispresent = 0;
			while(curr != NULL)
			{
				if(curr->key == key)
				{
					cout << "PRESENT at " << hash_index << endl;
					ispresent = 1;
				}
				curr = curr->next;
			}
			if(ispresent == 0)
			{
				cout << "absent" << endl;
			}
		}
	}
};
int main() {
	hashing h1;
	h1.insert("ajinkya" , "abc");
	h1.insert("rushi" , "abc");
	h1.insert("lodha" , "abc");
	h1.insert("niks" , "abc");
	h1.insert("camel" , "abc");
	h1.insert("malusare" , "abc");
	h1.insert("bedarkar" , "abc");
	h1.insert("virat" , "abc");
	h1.insert("peeyush" , "abc");
	h1.insert("king" , "abc");
	h1.insert("zebra" , "abc");
	h1.display();

	h1.deleteelement("ajinkya");
	h1.display();
	h1.deleteelement("malusare");
		h1.display();
//		h1.deleteelement("rushi");
//			h1.display();h1.deleteelement("bedarkar");
//			h1.display();

	while(0)
	{
		cout << endl << "Enter element you want to search : ";
		string key;cin >> key;
		h1.search(key);
		cout << "ascii" << int(key[0]) << endl;
 		cout << "Do you want to exit :";
		int a; cin >>a;
		if(a == 1)
			break;

	}


}