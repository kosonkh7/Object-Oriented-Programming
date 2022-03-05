#include <iostream>
#include <vector>

bool is_ascending(std::vector<int>& v) {
	int n = v.size();
	int x = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			if (v[i] > v[j])
				x++;
		}
	if (x == 0)
		return true;
	else
		return false;
}

int main() {
	std::vector<int> a = { 1, 2, 3 };
	int x = is_ascending(a);
	std::cout << x;
}


/*
is_ascending 함수에서 임의의 변수 x를 초기화 한 뒤
반복문과 조건문을 통해 벡터 내 데이터를 일일이 비교해가며 앞의 값이 뒤의 값보다 큰 경우가 있으면 x++하게 코드를 작성하였다.
순서대로 정렬되어있다면 x는 0이므로 이때 true 반환, 그렇지 않으면 false 반환하게 코드를 작성하였다.
예를 들어 정렬된 벡터는 true를 반환하는 것을 확인하였다.
*/
