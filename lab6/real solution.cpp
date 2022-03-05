#include <iostream>
#include <cmath>
using namespace std;


int main() {
	double a, b, c;
	cout << "이차항 계수, 일차항 계수, 상수를 차례대로 입력하시오 : ";
	cin >> a >> b >> c;

	if (a == 0 && b == 0)
		cout << "유효하지 않은 식이다";
	else if (a == 0 && b != 0)
		cout << "근은 " << -c / b;
	else if (b * b - 4.0 * a * c < 0)
		cout << "실근을 갖지 않는다";
	else if (b * b - 4.0 * a * c >= 0)
		cout << "근은 " << (-b + sqrt(b * b - 4 * a * c)) / 2.0 / a << ", " << (-b - sqrt(b * b - 4.0 * a * c)) / 2.0 / a;
}

/*
cin을 통해 이차항, 일차항 계수와 상수를 차례로 입력받고
if 조건문을 통해 a=0, b=0인 경우 안된다는 구문 출력
a=0, b!=0인 경우 일차식의 근을 출력
b^2-4ac <0인 경우 실근이 없다는 구문 출력
b^2-4ac >=인 경우 근의 공식을 통해 두 근을 출력하는 코드를 작성하였다.
*/
