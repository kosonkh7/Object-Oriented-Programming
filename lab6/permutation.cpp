#include <iostream>
#include <cmath>
using namespace std;

int permutation(int, int);

int permutation(int n, int r) {
	int per = 1;
	for (int i = 0; i < r; i++) {
		per *= n;
		n--;
	}
	return per;
}


int main() {
	int n, r;
	cout << "n과 r을 차례로 입력하시오: ";
	cin >> n >> r;
	cout << "nPr은 " << permutation(n, r);
}

/*
main함수에서 n과 r을 입력 받아 permutation 함수에 전달하였다
permutation 함수는 nPr = n * n-1 … * n-r+1 공식에 따라서
r만큼 반복하여 n을 1씩 뺀 값을 변수 per에 곱하며 저장하고 per값을 반환하는 함수이다.
*/
