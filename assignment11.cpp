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

	static int rol;

	void setData()
	{
		rollno = rol;
		cout <<"Enter your name div address with space: ";
		cin >> name;
		cin >> div;
		cin >> add;
		rol++;
		cout << endl << "students assigned Roll no : " << rollno << endl;

	}

};

void create()
{
	fstream myfile;
	myfile.open("Student_record.txt" , ios::app);

	record r;
	r.setData();
	myfile.write(  (char*)&r, sizeof(r)  );
	myfile.close();
}

void display()
{
	fstream myfile;
	myfile.open("Student_record.txt" , ios::in);
	record r;
//	myfile.read((char*)&r, sizeof(r));
	 while(!myfile.eof())
	  {
		myfile.read((char*)&r, sizeof(r));
		cout << "Roll no : " << r.rollno << endl;
		cout << "Name : " <<  r.name << endl;
		cout << "Div : " << r.div << endl;
		cout << "Address : " << r.add << endl;
		cout << endl;
	  }
	 myfile.close();
}
int record :: rol = 1;

int main()
{
	// fstream myfile;
	// 	myfile.open("Student_record.txt" , ios::in);
	// 	record r;
	// //	myfile.read((char*)&r, sizeof(r));
	// 	 while(!myfile.eof())
	// 	  {
	// 		myfile.read((char*)&r, sizeof(r));
	// 		cout << "Roll no : " << r.rollno << endl;
	// 		cout << "Name : " <<  r.name << endl;
	// 		cout << "Div : " << r.div << endl;
	// 		cout << "Address : " << r.add << endl;
	// 		cout << endl;
	// 	  }
	// 	 myfile.close();
	create();
	create();
	create();
	create();

	display();
	return 0;
}
