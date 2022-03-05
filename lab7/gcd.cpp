int gcd(int num1, int num2) {
	int min = (num1 < num2) ? num1 : num2;
	int largestFactor = 1;
	for (int i = 2; i <= min; i++)
		if (num1 % i == 0 && num2 % i == 0)
			largestFactor = i;
	return largestFactor;
}

/*
재귀함수가 아닌 반복문을 사용하여 최대공약수를 구하는 함수를 만들었다.
정수 2개를 전달 받아 조건문을 통해 둘 다 나누어 떨어지는 최대의 정수를 반환하는 코드이다.
*/
