#include <iostream>
using namespace std;

// 클래스 정의
class Animal {

public:
    int a, b, c, d;

    // 기본 생성자
    Animal() {}

    // 생성자 1개 매개변수
    Animal(int a) {
        cout << "a" << endl;
        this->a = a;  // 멤버 변수에 매개변수 값 할당
    }

    // 생성자 2개 매개변수
    Animal(int a, int b) : Animal(a) {
        cout << "b" << endl;
        this->b = b;
    }

    // 생성자 3개 매개변수
    Animal(int a, int b, int c) : Animal(a, b) {
        cout << "c" << endl;
        this->c = c;
    }

    // 생성자 4개 매개변수
    Animal(int a, int b, int c, int d) : Animal(a, b, c) {
        cout << "d" << endl;
        this->d = d;
    }
};

int main() {
    Animal e(1, 2, 3, 4);  // 객체 생성
    return 0;
}
