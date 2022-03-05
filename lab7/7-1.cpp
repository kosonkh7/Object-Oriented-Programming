#include <iostream>
// Draws a bar n segments long
// using iteration.
void segments1(int n) {
	while (n > 0) {
		std::cout << "*";
		n--;
	}
	std::cout << '\n';
}
// Draws a bar n segments long
// using recursion.
void segments2(int n) {
	if (n > 0) {
		std::cout << "*";
		segments2(n - 1);
	}
	else
		std::cout << '\n';
}
int main() {
	segments1(3);
	segments1(10);
	segments1(0);
	segments1(5);
	std::cout << "-------------\n";
	segments2(3);
	segments2(10);
	segments2(0);
	segments2(5);
} 

/*
segment1함수와 segment2함수를 실행하는 코드이다.
두 함수 모두 main함수에서 전달 받은 양의 정수값만큼 *을 출력하는 함수인데
segment1함수는 while 반복문을 통해,
segment2함수는 조건문과 재귀함수를 통하여 표현한 것이 차이점이다.
*/
