#include <iostream>
using namespace std;

int Fibonacci(int);

int Fibonacci(int n) {
    int a=0, b=1, sum=0;

    if (n == 1) sum = 0;
    else if (n == 2) sum = 1;
    else {
        for (int i = 3; i <= n; ++i) {
            sum = a + b;
            a = b;
            b = sum;
        }
    }
    return sum;
}


int main() {
	int size;
	cout << "몇 번째까지 출력? : ";
	cin >> size;
    cout<< Fibonacci(size);
}

/*
메인함수에서 size를 정수로 입력 받아 몇 번째 피보나치 수를 출력할지 정한다
사용자 정의 함수 Fibonacci 는 size 번째 피보나치 수를 sum변수에 저장해 반환한다.
편의상 if 조건문으로 첫 번째는 0, 두 번째는 1로 반환하도록 고정하였고
나머진 for반복문을 통해 차곡차곡 더해 피보나치 수를 반환할 수 있도록 코드를 작성하였다.
만약 수열을 출력하고 싶으면 함수 반환값을 void로 하여 cout을 통해 size번째까지 수열을 출력하게끔 해줄 수 있을 것이다. 
*/
