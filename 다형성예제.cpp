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
		cout << "±¹¹Î ¼ö : " << civil_ << endl;
		cout << "±º·Â : " << force_ << endl;
		cout << "ÀÌ¸§ : " << name_ << endl;
		cout << "¸éÀû : " << territory_ << endl;
	}

private:
	int civil_;		//±¹¹Î ¼ö
	int force_;		//±¹·Â
	string name_;	//ÀÌ¸§
	int territory_;	//¶¥(¸éÀû)
};

class Kimchi : public Food {
public:
	Kimchi(int civil, int force, string name, int territory, int garlic, int pepper) 
		: Food(civil, force, name, territory), garlic_(garlic), pepper_(pepper)
	{}
	void show() {
		Food::show();
		cout << "¸¶´Ã : " << garlic_ << endl;
		cout << "°íÃß : " << pepper_ << endl;
	}
private:
	int garlic_;
	int pepper_;	//ÇÑ±ÛÀÇ Èû
};

class Jelly : public Food {
public:
	Jelly(int civil, int force, string name, int territory, int jelatin, int suger) 
		: Food(civil, force, name, territory), jelatin_(jelatin), suger_(suger)
	{}
	void show() {
		Food::show();
		cout << "Á©¶óÆ¾ : " << jelatin_ << endl;
		cout << "¼³ÅÁ : " << suger_ << endl;
	}
private:
	int jelatin_;
	int suger_;	//¼³ÅÁÀÇ Èû
};

class Cheese : public Food {
public:
	Cheese(int civil, int force, string name, int territory, int milk, int Rennet)
		: Food(civil, force, name, territory), milk_(milk), Rennet_(Rennet)
	{}
	void show() {
		Food::show();
		cout << "¿ìÀ¯ : " << milk_ << endl;
		cout << "ÀÀ°íÁ¦ : " << Rennet_ << endl;
	}
private:
	int milk_;
	int Rennet_;	//ÀÀ°íÁ¦
};

void main(void) {
	Food* player = new Kimchi(15, 95, "°«±èÄ¡", 86, 100, 100);
	Food* friends = new Cheese(100, 20, "Â¥°èÄ¡", 100, 20, 100);

	player->show();
	friends->show();

	delete friends;
	delete player;
}