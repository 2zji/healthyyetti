#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
	void PrintMethod() {
		cout << "�θ�����" << endl;
	}
};

class Cat : public Animal {
public:
	void PrintMethod() {
		Animal::PrintMethod();
		cout << "�ڻ� �����" << endl;
	}
};

//'main' �Լ� ����
int main() {
	Cat cat;
	cat.PrintMethod();
	return 0;
}
