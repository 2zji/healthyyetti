#include <iostream>
#include <string>

using namespace std;

// 기본 동물 클래스
class Animal {
public:
    Animal(string name) : name(name) {}

    void sound() {
        cout << "동물 소리를 내고 있습니다." << endl;
    }

protected:
    string name;
};

// 고양이 클래스, 동물 클래스를 상속받음
class Cat : public Animal {
public:
    Cat(string name) : Animal(name) {}

    void purr() {
        cout << name << "이(가) 착륙 중입니다." << endl;
    }
};

// 개 클래스, 동물 클래스를 상속받음
class Dog : public Animal {
public:
    Dog(string name) : Animal(name) {}

    void bark() {
        cout << name << "이(가) 짖고 있습니다." << endl;
    }
};

int main() {
    // 각 클래스의 인스턴스를 생성하고 메서드 호출
    Cat cat("야옹이");
    Dog dog("멍멍이");

    cat.sound(); // Animal 클래스의 메서드 호출
    cat.purr();  // Cat 클래스의 메서드 호출

    dog.sound(); // Animal 클래스의 메서드 호출
    dog.bark();  // Dog 클래스의 메서드 호출

    return 0;
}
