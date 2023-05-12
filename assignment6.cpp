//============================================================================
// Name        : assignment6.cpp
// Author      : Ajinkya Mogal
// Version     : 11 april
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class  node
{
public:
    int data;
    node* next;
     node(int d)
     {
        data = d;
        next = NULL;
     }
};



class graph
{
    int max;
    node* array[];
    public:
    graph()
    {
        max = 0;
    }
    graph(int size)
    {
        max = size;
    }

    void create()
    {
        for(int i = 0 ; i < max ; i++)
        {
            cout << "Enter number of neighbour of " << i+1 << "(enter -1 if no neighbour) :";
            int neighbour ; cin >> neighbour;
            if(neighbour == -1)
            {
                array[i] = NULL;
            }
            else
            {   
                int a ; cin >> a;
                array[i] = new node(a);
                for(int j = 0 ; j < neighbour-1; j++)
                {
                    cin >> a;
                    node * new_node = new node(a);
                    node * temp = array[i];

                    while(temp->next)
                        temp = temp->next;

                    temp->next = new_node;
                }
                
            }
        }
    }

    void display()
    {
        for(int i = 0 ; i < max ; i++)
        {
            cout << i + 1 << " -> ";
            node * temp = array[i];

            while(temp)
            {
                cout << temp-> data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }


    void BFS(int s)
    {
        bool visited[max] = {0};

        queue<int> q;
        q.push(s);
        visited[s-1] = 1;  
        
        while(!q.empty())
        {
            int a = q.front();
            q.pop();
            cout << a << " " ;
            node * temp = array[a - 1];
            while(temp)
            {
                int i = temp->data;
                if(!visited[ i -1])
                {
                    q.push(i);
                    visited[i - 1] = 1;
                }
                temp = temp->next;
            }
        }
    }

    void DFS(int s)
    {
        bool visited[max] = {0};

        stack<int> st;
        st.push(s);
        visited[s-1] = 1;  
        
        while(!st.empty())
        {
            int a = st.top();
            st.pop();
            cout << a << " " ;
            node * temp = array[a - 1];
            while(temp)
            {
                int i = temp->data;
                if(!visited[ i -1])
                {
                    st.push(i);
                    visited[i - 1] = 1;
                }
                temp = temp->next;
            }
        }
    }
};

int main()
{
    

    graph g;
    // g.display();
    // g.DFS(1);


    while(1)
    {
        cout<< "*******MENU********\n"
        << "1.Create Graph \n"
        << "2.BFS \n"
        << "3.DFS \n\n"
        << "Enter your choice : ";
        int a; cin >> a;

        switch(a)
        {
            case 1:
            {
                cout << "How many vertex in graph :" << endl;
                int n ; cin >> n;
                g = n;;
                g.create(); 
                cout << "sucessfully created !!" << endl;
                g.display();
                cout << endl;
            }
                break;
            case 2:
            {
                cout << "BFS :  ";
                g.BFS(1);

            }
                break;
            case 3:
            {
                cout << "BFS :  ";
                g.DFS(1);
            }
                break;
            
            default:
                cout << "Enter valid input ";
        }
        cout << endl << "Do you want to continue(1/0) :";
        bool k; cin >> k;

        if(!k)
            break;

    }
}