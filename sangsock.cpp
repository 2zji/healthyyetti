#include <iostream>
#include <string>

using namespace std;

class Person {
public:
	string name;
	int hakbun;
	Person(string, int);
	void PrintShow() {
		cout << name << "�� �й��� " << hakbun << "�Դϴ�." << endl;
	}
};

class Student : public Person {
public:
	string university;
	Student(string, int, string);
	void PrintShow() {
		cout << university;
		Person::PrintShow();
	}
};

int main(void) {
	Student* stu = new Student("������", 2207, "�ǽĴ�");
	stu->PrintShow();
	delete stu;
	return 0;
};