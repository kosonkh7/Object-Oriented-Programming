#include <iostream>
#include <math.h>

const double PI = 3.14;

class IntPoint {
public:
	int x;
	int y;
	IntPoint(int x, int y) : x(x), y(y) {}
};
class Circle {
	IntPoint center; 
	double radius; 
	
public:
	Circle(IntPoint pt, double r) :
		center((pt.x < -100) ? -100 : (pt.x > 100 ? 100 : pt.x),
			(pt.y < -100) ? -100 : (pt.y > 100 ? 100 : pt.y)),
			radius((r < 0) ? 0 : r) {}

	double get_perimeter() {
		return 2 * radius * PI;
	}
	double get_area() {
		return radius * radius * PI;
	}


};

int main() {
	Circle c1(IntPoint(4, 3), 5);
	std::cout << c1.get_perimeter() << " " << c1.get_area();
}


/*
위 Rectangle 클래스를 변형하여 Circle 클래스를 만들었다.
우선 원주율 PI를 전역 변수 const double 타입으로 만들어 계산에 사용할 수 있게 해주었다.
원의 중심을 표현하기 위해 클래스 Intpoint는 그대로 사용하였고,
Circle 클래스에서 너비와 높이 대신 반지름을 나타내는 radius로 바꿔주었다.
중심과 반지름의 범위는 이전 클래스 그대로 활용하였고,
멤버함수인 get_perimeter와 get_area는 각각 원의 둘레와 반지름에 맞게 공식을 변형해주었다.
또한 원주율을 3.14로 설정하였기 때문에 이에 맞게 결과값도 소수점을 출력해주는게 좋을 거라 생각하여 double 형태로 반환하게 바꿔주었다.
main함수 안에서 제대로 작동하는지 확인해보았다.
*/
