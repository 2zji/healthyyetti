#include <iostream>
#include <vector>
#include <string>

using namespace std;

class SW2_2 {
public:
	SW2_2(string name) : name_(name) {
		num_++;
	}
	static string get_teacher(void) { return teacher_ };
	static int get_num(void) { return num_; }
	string get_name(void) { return name_; }

private:
	static string teacher_; //담임
	static int num_;
	string name_;
};

string SW2_2::teacher_ = "권지웅";
int SW2_2::num_ = 0;

void main(void){
	SW2_2* sb = new SW2_2("조수빈");
	cout << "인원 수: " << sb->get_num() << endl;
	SW2_2* js = new SW2_2("나지수");
	cout << "인원 수: " << js->get_num() << endl;

	delete js;
	delete sb;
}