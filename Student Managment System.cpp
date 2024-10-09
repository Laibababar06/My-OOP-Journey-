#include<iostream>
using namespace std;
class students {
	string name;
	const string cnic;
	char const gender;
	float cgpa;
public:
	void setName(string n) {
		name = n;
	}
	string getName() {
		return name;
	}
	void setcgpa(float c) {
		cgpa = c;
	}
	float getcgpa() {
		return cgpa;
	}
	students(string name,string cnic,char gender,float cgpa):cnic(cnic ),gender(gender) {
		this->name = name;
		this->cgpa = cgpa; 
	} 
	void print() {
		cout << "NAME: " << name << endl;
		cout << "Cgpa: " << cgpa << endl; 
		cout << "Gender: " << gender << endl;
		cout << "Cnic: " << cnic << endl;
	}
};
class section {
	students* arr[40];
	string sec;
	string teacher;
	int counter = 0;
public:
	section(string sec, string tec)
	{
		this->sec = sec;
		teacher = tec;
	}
	~section()
	{
		for (int i = 0; i < 40; i++)
		{
			delete arr[i];
			arr[i] = nullptr;
		 }
	
	}
	void updateSection()
	{
		int choice; 
		cout << "ENTER 1 TO UPDATE TEACHER NAME and 2 TO UPDATE SECTION NAME : " << endl;
		cin >> choice; 
		string t;
		switch (choice)
		{
		case 1:   
			
			cout << "enter name of teacher: " << endl;
			cin >> t;
			teacher = t;
			break;
		case 2:
			cout << "enter name of section: " << endl;
			cin >> t;
			sec = t;
			break;
		}
	}
	void input()
	{
		string name;
		string cnic;
		float gpa;
		char gender;
		cout << "Enter name ";
		cin >> name;   
		cout << "Enter cnic : ";
		cin >> cnic; 
		cout << "Enter gpa : ";
		cin >> gpa;
		cout << "Enter gender male female : ";
		cin >> gender;
		arr[counter++] = new students(name, cnic, gender, gpa); 
	} 
	void print()
	{
		for (int i = 0; i < counter; i++) {
			cout << "STUDENT " << i + 1 << endl; 
			arr[i]->print(); 
			cout << endl;
		}
	}
	void update()
	{
		int index; 
		cout << "Enter student " << 1 << " - " << counter+1 ;
		cin >> index; 
		index--; //this is because we took input from 1- number not 0  
		int choice;
		cout << "ENTER 1 TO UPDATE NAME and 2 TO UPDATE CGPA: " << endl;
		cin >> choice;
		string name;
		switch (choice) {
		case 1:
			
			cout << "enter name" << endl;
			cin >> name;
			arr[index]->setName(name);
			break;  
		case 2: 
			float n;
			cout << "enter gpa" << endl;
			cin >> n;
			arr[index]->setcgpa(n);
			break;
		}
	}
};
int main() {
	
	int choice; 
	section obj("SE-3B","DR.Usama ");
	while (1)
	{
		cout << "1.ADD STUDENT\n2.PRINT \n3.UPDATE STUDENT\n4.UPDATE SECTION\n5.EXIT\n"; 
		cin >> choice; 
		switch (choice)
		{
		case 1: 
			obj.input();  
			break;  
		case 2:  
			obj.print(); 
			break;
		case 3: 
			obj.update();
			break; 
		case 4:
			obj.updateSection();
			break; 
		case 5: 
			exit(0); 

		}
	}
	system("pause");
}