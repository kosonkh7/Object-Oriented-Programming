#include <iostream>
#include <vector>

void ascending(std::vector<int>& v) {
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i+1; j < v.size(); j++) {
			if (v[i] > v[j])
				std::swap(v[i], v[j]);
		}

	}
}


void special_sort(std::vector<int>& v) {
	int n = v.size();
	std::vector <int> even = {};
	std::vector <int> odd = {};
	for (int i = 0; i < n; i++) {
		if (v[i] % 2 == 0)
			even.push_back(v[i]);
		else
			odd.push_back(v[i]);
	}
	ascending(even);
	ascending(odd);
	v.clear();
	for (int i = 0; i < even.size(); i++)
		v.push_back(even[i]);
	for (int i = 0; i < odd.size(); i++)
		v.push_back(odd[i]);
}


int main() {
	std::vector<int> a = { 2, 1, 10, 4, 3, 6, 7, 9, 8, 5 };
	special_sort(a);
	for (int i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
}


/*
special_sort함수에서 우선 짝수와 홀수를 따로 따로 저장할 수 있는 even, odd 벡터를 만들고
for문과 if조건문을 통해 기존 벡터의 짝수값과 홀수값을 분류해서 저장해준다
추가로 만든 ascending함수는 벡터 안의 숫자를 오름차순으로 정렬해주게 코드를 작성하였다.
even함수와 odd함수를 오름차순으로 정렬해주고
기존 v함수를 clear()로 데이터를 모두 지운 후
even함수와 odd함수를 차례로 v에 push_back하여 저장해주면 보이는대로 짝수와 홀수를 구분하여 오름차순으로 정렬까지 된 결과를 확인할 수 있다.
*/
