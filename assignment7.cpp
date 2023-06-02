//============================================================================
// Name        : assignment7.cpp
// Author      : Ajinkya Mogal
// Version     : 
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
// To write a program for Graph creation and find its minimum cost using
// Prim’s or Kruskal’s algorithm.
// You have a business with several offices; you want to lease phone lines 
// to connect them up with each other; and the phone company charges 
// different amounts of money to connect different pairs of cities. You 
// want a set of lines that connects all your offices with a minimum total 
// cost. Solve the problem by suggesting appropriate data structures.

#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Graph
{
public:
	int max;
    int ** arr;


    Graph(int size)
	{
		max = size;
        arr = new int*[max];

        for(int i = 0 ; i < max ; i++)
        {
            arr[i] = new int[max];
        }

        for(int i = 0 ; i  < max ; i++)
		{
			for(int j = 0 ; j < max ; j++)
                arr[i][j] = 0;
		}

        // for(int i = 0 ; i  < max ; i++)
		// {
		// 	for(int j = 0 ; j < max ; j++)
        //     {
        //         int a; cin >> a;
        //         arr[i][j] = a;
        //     }
		// }
	}

	void create(int a)
	{
		cout << "How many edges are their :";
		int a; cin >> a;

		for(int i = 0 ; i < a ; i++)
		{
			cout << "Enter vertex(i,j):";
			int b , c; cin >> b >> c;

			cout << "Enter weight" << b << " " << c << ":" ;
			int d ; cin >> d;

			arr[b-1][c-1] = d;
			arr[c-1][b-1] = d;
		}
	}

    

	void display()
	{
		cout << endl << endl;
		for(int i = 0 ; i  < max ; i++)
		{
			for(int j = 0 ; j < max ; j++)
				cout << arr[i][j] << " ";
			cout << endl;
		}
	}

    void primsbabber()
    {
        bool visited[max+1];             // if visited
        int key[max+1];              // min of keys 
        int parent[max+1];                // parent track

        for(int i = 1 ;   i < max + 1 ; i++)
        {
            visited[i] = 0;
            key[i] = INT_MAX;
            parent[i] = -1;
        }

        key[1] = 0;
        
        for(int i = 1 ;   i < max + 1 ; i++)
        {
            int u;int min = INT_MAX;
            for(int j = 1 ; j < max + 1; j++)
            {
                if(visited[j] == false && key[j] < min)
                {
                    min = key[j];
                    u = j;
                }
            }

            visited[u] = true;
            for(int k = 0 ; k < max ; k++)
            {
                if(arr[u - 1 ][k] < key[k+1] && visited[k+1] == 0 && arr[u - 1 ][k] != 0 )
                {
                    key[k+1] = arr[u-1][k];
                    parent[k+1] = k+1 ;
                }
            }

            for(int i = 1 ; i < max + 1 ; i++) cout << key[i] ;
            cout << endl;
        }


        int total = 0;
        for(int i = 1 ; i < max + 1 ; i++)
        {
            cout << parent[i] << " ";
            total = total + key[i];
        }

        cout << endl << total ;
    }
};

// 0 28 0 0 0 10 0
// 28 0 16 0 0 0 14
// 0 16 0 12 0 0 0
// 0 0 12 0 22 0 18
// 0 0 0 22 0 25 24
// 10 0 0 0 25 0 0
// 0 14 0 18 24 0 0

// 0 5 6 4
// 5 0 3 2
// 6 3 0 1
// 4 2 1 0

// 0 2 0 6 0 
// 2 0 3 8 5
// 0 3 0 0 7
// 6 8 0 0 0 
// 0 5 7 0 0 
int main()
{
	cout << "How many vertices are their : ";
	int a ; cin >> a;

	Graph g(a);
	g.create(a);
    cout << "Adjacency matrix of the above graph is : " << endl;
	g.display();
    g.primsbabber();
	return 0;
}
