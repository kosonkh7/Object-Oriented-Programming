#include <iostream>
#include <vector>

void rotate(std::vector<int>& v) {
	int n = v.size();
	std::vector<int> x(n, 0);
	for (int i = 1; i < n; i++) {
		x[i] = v[i-1];
	}
	x[0] = v[n-1];
	v = x;
}

int main() {
	std::vector<int> a = { 2, 1, 10, 4, 3, 6, 7, 9, 8, 5 };
	rotate(a);
	for (int i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
}

/*
rotate 함수에서 따로 v와 사이즈가 같은 x벡터를 만든 후에
맨 마지막 값을 x[0]에 저장하고 나머지 값들을 for문을 통해 뒤로 저장하는 코드를 작성하였다.
이후 main함수에서 rotate함수가 적용된 a벡터를 출력해주었다.
*/
