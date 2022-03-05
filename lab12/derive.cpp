#include <iostream>

class Base {
	int x;
public:
	Base(int x) : x(x) {}
	virtual void print() const { std::cout << "Base: " << x << std::endl; }
	virtual ~Base() {}
};

class Derived : public Base {
	int x, y;
public:
	Derived(int x, int y) : Base(x), x(x), y(y) {}
	void print() const { std::cout << "Derived: " << x << ", " << y << std::endl; }
	bool operator<(const Derived& d1) {
		if ((this->x + this->y) < (d1.x + d1.y))
			return true;
		else
			return false;
	}
	~Derived() {}
};



int main() {
	// All data members of Base and Derived classes must be declared 
	// as private access types
	Base* p1 = new Derived(10, 20);		// (x, y)
	Base* p2 = new Base(5);			// (x) 
	p1->print();			// prints 10, 20
	p1->Base::print();		// prints 10
	p2->print(); 			// prints 5
	Derived* p3 = dynamic_cast<Derived*>(p1);
	if (p3 != nullptr) p3->print();			// prints 10, 20

	const Base b1 = *p2;
	b1.print();				// prints 5

	Derived d1(1, 3), d2(2, 4);
	Derived d3 = (d1 < d2) ? d1 : d2;	// operator <: (d1.x+d1.y) < (d2.x+d2.y)
	d3.print();				// prints 1, 3
}

/*
클래스 Base와 이를 상속 받는 클래스 Derived를 만들어 주었다.
Base클래스는 멤버 변수 하나와 이를 출력해주는 멤버 함수 print()를 가짐
읽기 전용이므로 const 붙여줌
오버라이딩 위해 virtual 붙여줌
소멸자도 만들어주었다.
Derived 클래스에는 연산자 오버로딩을 정의해주었다.
this포인터를 적절히 사용하여 조건이 맞으면 true, 아니면 false가 반환하는 bool타입 연산자다
*/
