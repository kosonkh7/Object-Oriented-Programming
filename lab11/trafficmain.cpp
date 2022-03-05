#include <iostream>
#include "trafficlight.h"
void print(Trafficlight lt) {
	SignalColor color = lt.get_color();
	std::cout << "+-----+\n";
	std::cout << "| |\n";
	if (color == SignalColor::Red)
		std::cout << "| (R) |\n";
	else
		std::cout << "| ( ) |\n";
	std::cout << "| |\n";
	if (color == SignalColor::Yellow)
		std::cout << "| (Y) |\n";
	else
		std::cout << "| ( ) |\n";
	std::cout << "| |\n";
	if (color == SignalColor::Green)
		std::cout << "| (G) |\n";
	else
		std::cout << "| ( ) |\n";
	std::cout << "| |\n";
	std::cout << "+-----+\n";
}
//print()함수는 신호등 모양을 색에 따라 다르게 출력해주는 조건문
int main() {
	Trafficlight light(SignalColor::Green);
	while (true) {
		print(light);
		light.change();
		std::cin.get();
	}
}

//main함수의 while문이 계속 반복되기 때문에 엔터를 누르면 계속하여 색 순서에 따라 바뀐 신호등이 출력됨.
