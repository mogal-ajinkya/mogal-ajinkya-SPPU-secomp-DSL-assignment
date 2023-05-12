//============================================================================
// Name        : assignment7.cpp
// Author      : Ajinkya Mogal
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Graph
{
public:
	int max;
	vector<vector<int> > adj;


	Graph(int size)
	{
		max = size;
        cout << "enter all" ;
		for(int i = 0 ; i  < max ; i++)
		{
			vector<int> temp;
			for(int j = 0 ; j < max ; j++)
			{
                int a;cin >> a;
				// temp.push_back(0);
				temp.push_back(a);
			}
			adj.push_back(temp);
		}



	}

	void create()
	{
		cout << "How many edges are their :";
		int a; cin >> a;

		for(int i = 0 ; i < a ; i++)
		{
			cout << "Enter vertex(i,j):";
			int b , c; cin >> b >> c;

			cout << "Enter weight" << b << " " << c << ":" ;
			int d ; cin >> d;

			adj[b-1][c-1] = d;
			adj[c-1][b-1] = d;
		}
	}

    

	void display()
	{
		cout << endl << endl;
		for(int i = 0 ; i  < max ; i++)
		{
			for(int j = 0 ; j < max ; j++)
				cout << adj[i][j] << " ";
			cout << endl;
		}
	}

    void prims()
    {
        int min_cost = INT_MAX;
        int visited[max] = {0};
        int p , q ;
        int total = 0;
        visited[0] = 1;

        int count = 0;
        for(int i = 0 ; i < max ; i++)
        {
            if(visited[i] && count < max - 1)
            {
                for(int j = 0 ; j < max ; j++)
                {
                    if(!visited[j] &&  adj[i][j] !=0  && adj[i][j] < min_cost)
                    {
                            min_cost = adj[i][j];
                            p = i ; q = j;
                    }
                }
                cout << min_cost << " ";
                visited[p] = 1;
                visited[q] = 1;
                count++;
                total = total + min_cost;
                min_cost = INT_MAX;
                i = 0;
            }
            
        }

        cout << "Cost : " << total ;
        
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
                if(adj[u - 1 ][k] < key[k+1] && visited[k+1] == 0 && adj[u - 1 ][k] != 0 )
                {
                    key[k+1] = adj[u-1][k];
                    parent[k+1] = u ;
                }
            }

            for(int i = 1 ; i < max + 1 ; i++) cout << key[i] ;
            cout << endl;
        }


        int total = 0;
        for(int i = 1 ; i < max + 1 ; i++)
        {
            cout << key[i] << " ";
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
int main() {
	cout << "How many vertices are their : ";
	int a ; cin >> a;

	Graph g(a);
	// g.create();
	g.display();
    g.prims();
    g.primsbabber();
	return 0;
}
