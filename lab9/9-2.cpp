#include <iostream>
#include <vector>

bool balanced(const std::vector<int>& v) {
	int even = 0, odd = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] % 2 == 0)
			even++;
		else
			odd++;
	}
	if (even == odd)
		return true;
	else
		return false;
}

int main() {
	std::vector<int> a = { 2, 1, 10, 4, 3, 6, 7, 9, 8, 5 };
	
	std::cout << balanced(a);
}

/*
for문을 통해 벡터의 크기만큼 반복하면서 짝수이면 변수 even에 1증가, 홀수이면 odd에 1증가하게 코드를 작성하였고, even과 odd가 같으면 true, 아니면 false가 반환되도록 하였다
main함수에 벡터는 짝수와 홀수가 값이 같고, true값인 1을 반환하여 출력하는 것을 확인할 수 있다.
*/
