#include <iostream>
#include <vector>

bool has_duplicates(const std::vector<int>& v) {
	int n = v.size();
	int x = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			if (v[i] == v[j])
				x++;
		}
	if (x == 0)
		return false;
	else
		return true;
}

int main() {
	std::vector<int> a = { 2, 3, 2, 1, 9, 6 };
	int x = has_duplicates(a);
	std::cout << x;
}

/*
has_duplicates 함수에서 임의의 변수 x를 0으로 초기화하고 
벡터 안의 모든 데이터를 서로 비교하는 반복문을 돌리면서
만약 같은 값이 있으면 x값을 1씩 증가하는 코드를 작성하였다.
반복문 종료하고 x가 0이면 중복값이 없음으로 false, 하나라도 있으면 true를 반환한다.
예를 든 벡터는 중복값이 있으므로 true인 1을 반환 받은 것을 확인하였다.
*/
