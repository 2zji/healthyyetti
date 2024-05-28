//frend 선언

#include <iostream>
#include <string>

using namespace std;

// 선행 선언
class Credits; // 'Student' 클래스에서 'Credits'를 참조하므로 선행 선언이 필요합니다

class Student {
private:  // 멤버 변수는 기본적으로 비공개
    string name;
    string major;
    string hakbun;

public:
    Student(string name, string major, string hakbun) {
        this->name = name;
        this->major = major;
        this->hakbun = hakbun;
    }

    friend void printGrade(Student, Credits); // 'printGrade' 함수에 접근 권한 부여
};

class Credits {
private: // 멤버 변수는 기본적으로 비공개
    double grade;

public:
    Credits(double grade) {
        this->grade = grade;
    }

    friend void printGrade(Student, Credits); // 'printGrade' 함수에 접근 권한 부여
};

void printGrade(Student a, Credits b) {
    cout << "이름 : " << a.name << endl; // 비공개 멤버에 접근
    cout << "학과 : " << a.major << endl;
    cout << "학번 : " << a.hakbun << endl;
    cout << "학점 : " << b.grade << endl; // 비공개 멤버에 접근
}

int main() {
    Student c("박미림", "웹솔루션학과", "20240505"); // Student 객체 생성
    Credits d(4.4); // Credits 객체 생성
    printGrade(c, d); // Student와 Credits 객체 정보 출력
    return 0;
}
