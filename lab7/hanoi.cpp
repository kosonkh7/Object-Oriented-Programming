#include <iostream>
void Hanoi(int m, char start, char middle, char end){
	if(m == 1){
		std::cout << "Move disc " << m << " from " << start << " to " << end 
<< std::endl;
	}
	else{
		Hanoi(m-1, start, end, middle);
		std::cout << "Move disc " << m << " from " << start << " to " << end 
<< std::endl;
		Hanoi(m-1, middle, start, end);
	}
}
int main(){
	int discs = 3;
	Hanoi(discs, 'A', 'B', 'C');
}


/*
disc 1, 2, 3이 있는데 start인 A구역에서 end인 C구역으로 같은 순서대로 쌓아 옮기는 함수인데
작은 숫자가 큰 숫자 밑으로 갈 수 없는 규칙이 있다
그러므로 세 개의 기둥이 있다는 가정 하에 가장 큰 원판을 end로 보내기 위해선 나머지 원판들이 middle에 전부 쌓여있어야 한다. 
if else 조건문을 통해 위 조건들을 만족하게끔 코드가 작성되어있다.
첫번째 디스크를 세번째로 옮기고, 두번째 디스크를 중간으로 옮긴 다음에 다시 첫번째 디스크를 중간으로 옮긴다. 가장 큰 디스크를 마지막으로 옮긴 다음에 다시 가장 작은 디스크를 처음으로 옮기고 두번째 디스크를 마지막으로 옮긴 다음에 첫번째 디스크를 마지막으로 옮기는 것으로 마무리한다.
*/
