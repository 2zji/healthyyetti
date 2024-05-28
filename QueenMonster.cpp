#include <iostream>
#include <string>

using namespace std;

// �⺻ Ŭ����
class Monster {
protected:
    string name;
    int health;

public:
    // ������
    Monster(const string& name, int health) : name(name), health(health) {}

    // ���� �Ҹ���
    virtual ~Monster() {}

    // ���� �޼���
    virtual void attack() const {
        cout << "����! " << name << "�� ����!" << endl;
    }

    // ���ظ� �Դ� �޼���
    void takeDamage(int damage) {
        health -= damage;
        cout << name << "��(��) " << damage << "�� ���ظ� �Ծ����ϴ�. ���� ü��: " << health << endl;
    }
};

// �Ļ� Ŭ����
class Goblin : public Monster {
public:
    // ������
    Goblin(const string& name, int health) : Monster(name, health) {}

    // ���� �޼��� �������̵�
    void attack() const override {
        cout << "Į���� �ֵѷ� ����! " << name << "�� ����!" << endl;
    }
};

int main() {
    // Goblin ��ü ����
    Goblin goblin("���", 20);

    // ������ ���� �޼��� ȣ��
    goblin.attack();

    // ������ ���ظ� �Դ� �޼��� ȣ��
    goblin.takeDamage(10);

    return 0;
}