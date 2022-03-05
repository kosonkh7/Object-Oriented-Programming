#include <iostream>
class IntPoint {
public:
	int x;
	int y;
	IntPoint(int x, int y) : x(x), y(y) {}
};
class Rectangle {
	IntPoint corner; // Location of the rectangle's lower-left corner
	int width; // The rectangle's width
	int height; // The rectangle's width
public:
	Rectangle(IntPoint pt, int w, int h) :
		corner((pt.x < -100) ? -100 : (pt.x > 100 ? 100 : pt.x),
			(pt.y < -100) ? -100 : (pt.y > 100 ? 100 : pt.y)),
		width((w < 0) ? 0 : w), height((h < 0) ? 0 : h) {}
	int get_perimeter() {
		return 2 * width + 2 * height;
	}
	int get_area() {
		return width * height;
	}
	int get_width() {
		return width;
	}
	int get_height() {
		return height;
	}
	// Returns true if rectangle r overlaps this
	// rectangle object.
	bool intersect(Rectangle r) {
		// Details omitted
	}
	// Returns the length of a diagonal rounded to the nearest
	// integer.
	int diagonal() {
		// Details omitted
	}
	// Returns the geometric center of the rectangle with
	// the (x,y) coordinates rounded to the nearest integer.
	IntPoint center() {
		// Details omitted
	}
	bool is_inside(IntPoint pt) {
		// Details omitted
	}
	
	int diagonal() {
		return sqrt(pow(width, 2)+ pow(height, 2));
	}
//피타고라스의 공식을 적용하여 반환해주었다.
//맨 위에 <math.h> 전처리기를 추가하여 제곱과 제곱근 기능을 가능하게 해주었다.
	
	IntPoint center() {
		return IntPoint(corner.x + width/2, corner.y + height/2);
	}
//클래스타입이 IntPoint이므로 IntPoint타입을 반환해야한다.
//기존 기준 점인 (corner.x, corner.y)에서 가로로 width/2, 세로로 height/2만큼 이동한 점이 중심이기 때문에 이를 반영한 값을 반환하는 함수이다.
	
	bool intersect(Rectangle r) {
		if (r.corner.x == corner.x)
			if (r.corner.y == corner.y)
				if (r.width == width)
					if (r.height == height)
						return true;
		else return false;

	}
//전달 받은 r과 메소드 안의 값을 각각 다 비교해가며
//모두 일치하면 true, 아니면 false를 반환하게끔 코드를 작성하였다.
	
	bool is_inside(IntPoint pt) {
		if (pt.x >= corner.x && pt.x <= corner.x + width)
			if (pt.y >= corner.y && pt.y <= corner.y + height)
				return true;
			else 
				return false;
		else 
			return false;
	} 
//Intpoint 타입 pt의 x가 corner.x 이상, corner.x + width 이하
//Intpoint 타입 pt의 y가 corner.y 이상, corner.y + width 이하일 때
//true를 반환하고 그렇지 않으면 false를 반환하게 코드를 작성하였다.	
	
};


int main() {
	Rectangle rect1(IntPoint(2, 3), 5, 7),
		rect2(IntPoint(2, 3), 1, 3),
		rect3(IntPoint(2, 3), 15, 3),
		rect4(IntPoint(2, 3), 5, 3);
	std::cout << rect1.get_width() << '\n';
	std::cout << rect1.get_height() << '\n';
	std::cout << rect2.get_width() << '\n';
	std::cout << rect2.get_height() << '\n';
	std::cout << rect3.get_width() << '\n';
	std::cout << rect3.get_height() << '\n';
	std::cout << rect4.get_width() << '\n';
	std::cout << rect4.get_height() << '\n';
	std::cout << rect1.get_perimeter() << '\n';
	std::cout << rect1.get_area() << '\n';
	std::cout << rect2.get_perimeter() << '\n';
	std::cout << rect2.get_area() << '\n';
	std::cout << rect3.get_perimeter() << '\n';
	std::cout << rect3.get_area() << '\n';
	std::cout << rect4.get_perimeter() << '\n';
	std::cout << rect4.get_area() << '\n';
}
