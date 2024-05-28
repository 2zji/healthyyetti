#include <iostream>
#include <string>

using namespace std;

// 기본 클래스
class Monster {
protected:
    string name;
    int health;

public:
    // 생성자
    Monster(const string& name, int health) : name(name), health(health) {}

    // 가상 소멸자
    virtual ~Monster() {}

    // 공격 메서드
    virtual void attack() const {
        cout << "공격! " << name << "의 공격!" << endl;
    }

    // 피해를 입는 메서드
    void takeDamage(int damage) {
        health -= damage;
        cout << name << "이(가) " << damage << "의 피해를 입었습니다. 현재 체력: " << health << endl;
    }
};

// 파생 클래스
class Goblin : public Monster {
public:
    // 생성자
    Goblin(const string& name, int health) : Monster(name, health) {}

    // 공격 메서드 오버라이드
    void attack() const override {
        cout << "칼날을 휘둘러 공격! " << name << "의 공격!" << endl;
    }
};

int main() {
    // Goblin 객체 생성
    Goblin goblin("고블린", 20);

    // 몬스터의 공격 메서드 호출
    goblin.attack();

    // 몬스터의 피해를 입는 메서드 호출
    goblin.takeDamage(10);

    return 0;
}