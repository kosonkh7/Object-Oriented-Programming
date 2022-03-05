#include <iostream>
#include <vector>

class Widget {
public:
	virtual int f() { return 1; }
};
class Gadget : public Widget {
public:
	virtual int f() { return 2; }
};
class Gizmo : public Widget {
public:
	virtual int f() { return 3; }
};
void do_it(Widget* w) {
	std::cout << w->f() << " ";
}
int main() {
	std::vector<Widget*> widgets;
	Widget wid;
	Gadget gad;
	Gizmo giz;
	widgets.push_back(&wid);
	widgets.push_back(&gad);
	widgets.push_back(&giz);
	for (size_t i = 0; i < widgets.size(); i++)
		do_it(widgets[i]);
}


/*
(a) What does the program print?
반복문과 do_it함수에 의해 widgets벡터에 저장된 값이 하나씩 출력되는데
Gadget와 Gizmo는 Widget클래스에 상속 받고
f()함수는 virtual에 의해 정상적으로 오버라이딩 된다.
각 객체는 1 2 3을 반환하기 때문에 1 2 3이 출력된다

(b) Would the program still compile and run if the f method within the Widget class were a pure virtual function?
pure virtual function으로 바꿔주면 추상 클래스를 인스턴스화 할 수 없다는 에러 메시지와 함께 정상적으로 실행되지 않는다. 순수 가상 함수가 있는 클래스가 추상 클래스인데 나머지 상속 클래스들의 인터페이스 같은 느낌이라 인스턴스화하는 것이 불가능하다.

(c) How would the program run differently if the virtual keyword were removed from all the code?
virtual이 다 지워지면 파생 클래스의 f()가 기반 클래스의 f()를 오버라이딩 하지 못하여 모두 widget의 f()를 이용하게 되고 따라서 1 1 1이 출력된다.

(d) Would the program behave the same if the virtual keyword were removed from all the classes except for Widget?
Gadget와 Gizmo는 Widget클래스에 상속 받기 때문에
widget클래스내의 f함수만 virtual하면 앞서 코드와 동일하게 실행되는 것을 확인할 수 있다.

*/
