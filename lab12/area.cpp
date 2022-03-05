#include <iostream>

class Shape {
public:
	static double PI;
	virtual double area() const = 0;
	virtual void print() const = 0;
};
//Shape 클래스에 순수가상함수 area와 print 선언
//스태틱 더블 타입으로 PI선언

class TwoDemensional : public Shape {
protected:
	double length;
	double width;
public:
	TwoDemensional(double len, double wid);
	double area() const override;
	void print() const override;
};

//길이와 너비 멤버 변수를 가지고 Shape로부터 area와 print함수 상속 받는 클래스

class ThreeDemensional : public Shape {
protected:
	double length;
	double width;
	double height;
public:
	ThreeDemensional(double len, double wid, double hei);
	double area() const override = 0;
	void print() const override;
};

//길이와 너비, 높이 멤버 변수를 가지고 Shape로부터 area와 print함수 상속 받는 클래스
//자식 클래스들의 넓이 공식이 다르기 때문에 area를 순수가상함수로 설정


class Rectangle : public TwoDemensional {
public:
	Rectangle(double len, double wid);
};
// TwoDemensional  로부터 상속 받는 직사각형 클래스
class Triangle : public TwoDemensional {
public:
	Triangle(double len, double wid);
	double area() const override;
};

// TwoDemensional  로부터 상속 받는 삼각형 클래스
// area()함수도 상속 받아 오버라이딩 된다..


class Circle : public TwoDemensional {
public:
	Circle(double r);
	double area() const override;
};

// TwoDemensional  로부터 상속 받는 원 클래스
// area()함수도 상속 받아 오버라이딩 된다..


class Cube : public ThreeDemensional {
public:
	Cube(double len, double wid, double hei);
	double area() const override;
};

// ThreeDemensional 로부터 상속 받는 직육면체 클래스
// area()함수도 상속 받아 오버라이딩 된다..

class Sphere : public ThreeDemensional {
public:	
	Sphere(double r);
	double area() const override;
};

// ThreeDemensional 로부터 상속 받는 구 클래스
// area()함수도 상속 받아 오버라이딩 된다..


double Shape::PI = 3.14;
TwoDemensional::TwoDemensional(double len, double wid): length(len), width(wid) {}
ThreeDemensional::ThreeDemensional(double len, double wid, double hei): length(len), width(wid), height(hei) {}
Rectangle::Rectangle(double len, double wid): TwoDemensional(len, wid) {}
Triangle::Triangle(double len, double wid): TwoDemensional(len, wid){}
Circle::Circle(double r): TwoDemensional(r, r){}
Cube::Cube(double len, double wid, double hei):ThreeDemensional(len, wid, hei) {}
Sphere::Sphere(double r): ThreeDemensional(r, r, r) {}


double TwoDemensional::area() const {
	return width * length;
}

void TwoDemensional::print() const {
	std::cout << "넓이는 " << area() << std::endl;
}

void ThreeDemensional::print() const {
	std::cout << "총 면적은 " << area() << std::endl;
}

double Triangle::area() const {
	return TwoDemensional::area()/2;
}

double Circle::area() const {
	return TwoDemensional::area() * PI;
}

double Cube::area() const {
	return 2 * (width * length + width * height + length * height);
}

double Sphere::area() const {
	return 4 * PI * width * width;
}

int main() {
	Circle cc(3);
	Triangle tt(3, 4);
	Rectangle rr(3, 4);
	cc.print();
	tt.print();
	rr.print();
	std::cout << "---------" << "\n";
	Cube ccc(1, 2, 3);
	Sphere sss(3);
	ccc.print();
	sss.print();
}



/*
생성자 초기화 리스트 작성해주고
원, 삼각형, 직사각형, 직육면체, 구의 넓이를 구하는 공식을 적용해서 멤버 함수 코드 작성해주었다.
출력은 TwoDemensional::print() ThreeDemensional::print()함수를 상속 받아 이용하여 출력하였고
정상적으로 계산된 것을 확인할 수 있었다.


B-1. Write the declarations and definitions for the geometric classes define in Figure B-1. Use the following hints: (include test codes)
a.	Define Shape, TwoDimensional and ThreeDimensional as abstract classes.
b.	Define PI as static class member in the Shape class.
c.	Define area calculation and print functions as pure virtual functions in the Shape class.
d.	Use public inheritance.
e.	Define all data or member functions common to two-dimensional shapes in the TwoDimensional class. Do the same for all common data or member functions for the three-dimension shape.
*/
