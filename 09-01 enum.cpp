#include <iostream>

using namespace std;

//열거형 정의
enum FoodStyle {
	KOREAN,		//0(디폴트 값, 값을 주고 싶을 시, KOREAN = 0 으로 한다)
	JAPANESE,	//1
	CHINESE		//2
};

void main(void) {
	//열거형을 사용하면 가독성도 좋아지고, 중간에 값을 유연하게 추가할 수 있다
	int style = FoodStyle::KOREAN;
	
	switch (style) {
	case KOREAN:
		cout << "김치, 쌈, 비빔밥" << endl;
		break;
	case JAPANESE:
		cout << "초밥, 우동, 타코야끼" << endl;
		break;
	case CHINESE:
		cout << "동파육, 마라탕, 탕후루" << endl;
	}
}