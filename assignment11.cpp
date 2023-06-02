//============================================================================
// Name        : assignment11.cpp
// Author      : Ajinkya Mogal
// Version     : 23 may
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

class record
{
public :
	int rollno;
	char name[20];
	char div[5];
	char add[20];


	void setData()
	{
		cout << "Enter Roll Number: ";
		cin >> rollno;
		cout << "Enter Name: ";
		cin >> name;
		cout << "Enter Division: ";
		cin >> div;
		cout << "Enter Address: ";
		cin >> add;
	}

};

void create()
{
	fstream myfile;
	myfile.open("Student_record.txt" , ios::app);


	if(myfile)
	{
		char choice;
		do
		{
			record r;
			r.setData();
			myfile.write(  (char*)&r, sizeof(r)  );
			cout << "Do you want to add another record? (y/n): ";
            cin >> choice;
		} while (choice == 'y' || choice == 'Y');
		
		
	}
	else 
	{
		cout << "Error in opening file !!!" << endl;
	}
	myfile.close();
}

void display()
{
	fstream myfile;
	myfile.open("Student_record.txt" , ios::in);

	if(myfile)
	{
		record r;
			myfile.read((char*)&r, sizeof(r));
		while(!myfile.eof())
		{
			cout << "Roll no : " << r.rollno << endl;
			cout << "Name : " <<  r.name << endl;
			cout << "Div : " << r.div << endl;
			cout << "Address : " << r.add << endl;
			cout << endl;
			myfile.read((char*)&r, sizeof(r));
		}
		myfile.close();
	}
	else 
	{
		cout << "Error in opening file !!!" << endl;
	}
	
}

void display(int rolno)
{
	fstream myfile;
	myfile.open("Student_record.txt" , ios::in);

	if(myfile)
	{
		record r;
		int isfound = 0;
		myfile.read((char*)&r, sizeof(r));
		while (!myfile.eof())
		{
			if(r.rollno == rolno)
			{
				isfound = 1;
				cout << "Recored found !!!" << endl;
				cout << "Roll no : " << r.rollno << endl;
				cout << "Name : " <<  r.name << endl;
				cout << "Div : " << r.div << endl;
				cout << "Address : " << r.add << endl;
				cout << endl;
			}
			myfile.read((char*)&r, sizeof(r));
		}
		if(!isfound)
			cout << "Not present !!!" << endl;
		myfile.close();
		
	}
	else 
	{
		cout << "Error in opening file !!!" << endl;
	}
}

void deletion(int roll)
{
	fstream myfile;
	fstream mytemp;
	myfile.open("Student_record.txt" , ios::in);
	mytemp.open("temp.txt" , ios::out);

	if(myfile && mytemp)
	{
		record r;
		int isfound = 0;
		myfile.read((char*)&r, sizeof(r));
		while (!myfile.eof())
		{
			if(r.rollno == roll)
			{
				isfound = 1;
				cout << "Deleted Sucessfully !!!" << endl;
			}
			else
			{
				mytemp.write(  (char*)&r, sizeof(r)  );
			}
			myfile.read((char*)&r, sizeof(r));
		}
		if(!isfound)
			cout << "Not present !!!" << endl;
		myfile.close();
		mytemp.close();

		remove("Student_record.txt");
		rename("temp.txt" , "Student_record.txt");
	}
	else 
	{
		cout << "Error in opening file !!!" << endl;
	}
}
int main()
{
	remove("Student_record.txt");
	int choice ;
	do 
	{
		cout << "------ Menu ------" << endl;
        cout << "1. Create File and Add Records" << endl;
        cout << "2. Display All Records" << endl;
        cout << "3. Display Record by Roll Number" << endl;
        cout << "4. Delete Record by Roll Number" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

		switch (choice)
		{
		case 1:
			create();
			break;
		case 2:
			display();
			break;
		case 3:
			cout << "Enter roll no:" << endl;
			int a ; cin >> a;
			display(a);
			break;
		case 4:
			cout << "Enter roll no:" << endl;
			int b ; cin >>b;
			deletion(a);
			break;
		case 5:
			cout << "exiting ..." << endl;
			break;
		default:
			cout << "Enter valid input!!!" << endl;
			break;
		}

	}while ( choice != 5);
	return 0;
}
