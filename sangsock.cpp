#include <iostream>
#include <string>

using namespace std;

class Person {
public:
	string name;
	int hakbun;
	Person(string, int);
	void PrintShow() {
		cout << name << "의 학번은 " << hakbun << "입니다." << endl;
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
	Student* stu = new Student("빵도둑", 2207, "피식대");
	stu->PrintShow();
	delete stu;
	return 0;
};