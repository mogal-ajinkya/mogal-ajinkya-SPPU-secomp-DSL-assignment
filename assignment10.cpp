//============================================================================
// Name        : assignment10.cpp
// Author      : Ajinkya Mogal
// Version     : r 16 may
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
// Implement the Heap sort algorithm using heap data structure with 
// modularity of programming language.


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class hp
{

    int *a;
    int size;

public:
    void heapify(int i)
    {

        // while (i < size)
        // {
        //     int k = i;
        //     int left = 2 * i + 1;
        //     int right = 2 * i + 2;

        //     if (left < size && a[i] < a[left])
        //     {
        //         if (right < size && a[left] > a[right])
        //         {
        //             swap(a[i], a[left]);
        //             i = left;
        //         }
        //         else if (right < size && a[left] < a[right])
        //         {
        //             swap(a[i], a[right]);
        //             i = right;
        //         }
        //         else
        //         {
        //             swap(a[i], a[left]);
        //             i = left;
        //         }
        //     }

        //     else if (right < size && a[i] < a[right])
        //     {

        //         if (left < size && a[left] > a[right])
        //         {
        //             swap(a[i], a[left]);
        //             i = left;
        //         }
        //         else if (left < size && a[left] < a[right])
        //         {
        //             swap(a[i], a[right]);
        //             i = right;
        //         }
        //         else
        //         {
        //             swap(a[i], a[left]);
        //             i = right;
        //         }
        //     }

        //     else
        //     {
        //         return;
        //     }
        // }

        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if(left < size && a[left] > a[largest])
        {
            largest = left;
        }
        if(right < size && a[right] > a[largest])
        {
            largest = right;
        }

        if(i != largest)
        {
            swap(a[i] , a[largest]);
            heapify(largest);
        }
    
    }

    void sort()
    {

        cout << "enter the no of element ::";
        int n;
        cin >> n;
        a = new int[n];
        size = n;

            cout << "enter the element ::";
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = size - 1; i >= 0; i--)
        {

            heapify(i);
        }

        for (int i = 0; i < n; i++)
        {

            cout << a[i] << " ";
        }

        cout << endl;

        while (size > 1)
        {
            swap(a[0], a[size - 1]);
            size--;
            heapify(0);
        }

        for (int i = 0; i < n; i++)
        {

            cout << a[i] << " ";
        }
    }
};

int main()
{
    cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
    hp h;
    h.sort();
    return 0;
}