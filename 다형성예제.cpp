#include<iostream>
#include<string>

using namespace std;

class Food {
public:
	Food(int civil, int force, string name, int territory) 
		: civil_(civil), force_(force), name_(name), territory_(territory)
	{}

	virtual void show() {
		Food::show();
		cout << "���� �� : " << civil_ << endl;
		cout << "���� : " << force_ << endl;
		cout << "�̸� : " << name_ << endl;
		cout << "���� : " << territory_ << endl;
	}

private:
	int civil_;		//���� ��
	int force_;		//����
	string name_;	//�̸�
	int territory_;	//��(����)
};

class Kimchi : public Food {
public:
	Kimchi(int civil, int force, string name, int territory, int garlic, int pepper) 
		: Food(civil, force, name, territory), garlic_(garlic), pepper_(pepper)
	{}
	void show() {
		Food::show();
		cout << "���� : " << garlic_ << endl;
		cout << "���� : " << pepper_ << endl;
	}
private:
	int garlic_;
	int pepper_;	//�ѱ��� ��
};

class Jelly : public Food {
public:
	Jelly(int civil, int force, string name, int territory, int jelatin, int suger) 
		: Food(civil, force, name, territory), jelatin_(jelatin), suger_(suger)
	{}
	void show() {
		Food::show();
		cout << "����ƾ : " << jelatin_ << endl;
		cout << "���� : " << suger_ << endl;
	}
private:
	int jelatin_;
	int suger_;	//������ ��
};

class Cheese : public Food {
public:
	Cheese(int civil, int force, string name, int territory, int milk, int Rennet)
		: Food(civil, force, name, territory), milk_(milk), Rennet_(Rennet)
	{}
	void show() {
		Food::show();
		cout << "���� : " << milk_ << endl;
		cout << "������ : " << Rennet_ << endl;
	}
private:
	int milk_;
	int Rennet_;	//������
};

void main(void) {
	Food* player = new Kimchi(15, 95, "����ġ", 86, 100, 100);
	Food* friends = new Cheese(100, 20, "¥��ġ", 100, 20, 100);

	player->show();
	friends->show();

	delete friends;
	delete player;
}