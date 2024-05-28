#include <iostream>
#include <string>

using namespace std;

// �⺻ ���� Ŭ����
class Animal {
public:
    Animal(string name) : name(name) {}

    void sound() {
        cout << "���� �Ҹ��� ���� �ֽ��ϴ�." << endl;
    }

protected:
    string name;
};

// ����� Ŭ����, ���� Ŭ������ ��ӹ���
class Cat : public Animal {
public:
    Cat(string name) : Animal(name) {}

    void purr() {
        cout << name << "��(��) ���� ���Դϴ�." << endl;
    }
};

// �� Ŭ����, ���� Ŭ������ ��ӹ���
class Dog : public Animal {
public:
    Dog(string name) : Animal(name) {}

    void bark() {
        cout << name << "��(��) ¢�� �ֽ��ϴ�." << endl;
    }
};

int main() {
    // �� Ŭ������ �ν��Ͻ��� �����ϰ� �޼��� ȣ��
    Cat cat("�߿���");
    Dog dog("�۸���");

    cat.sound(); // Animal Ŭ������ �޼��� ȣ��
    cat.purr();  // Cat Ŭ������ �޼��� ȣ��

    dog.sound(); // Animal Ŭ������ �޼��� ȣ��
    dog.bark();  // Dog Ŭ������ �޼��� ȣ��

    return 0;
}
