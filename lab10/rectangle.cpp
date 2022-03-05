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
