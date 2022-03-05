#include <iostream>
#include <vector>


void reverse(std::vector<int>& v) {
	int n = v.size();
	std::vector<int> vv(n, 0);
	for (int i = 0; i < n; i++) {
		vv[i] = v[n - 1 - i];
	}
	v = vv;
	
}

int main() {
	std::vector<int> a = { 4, 5, 3, 4, 2, 1, 3, 0 };
	reverse(a);
	for (int i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
}


/*
reverse 함수에서 함수의 레퍼런스를 호출 받아
기존 함수와 크기가 같은 vv벡터를 만들고
for문을 통해 v벡터의 역순으로 저장한 뒤에
다시 v벡터에 vv벡터를 저장하였고
이를 main함수에서 출력하게끔 코드를 작성하였다.
*/
