#include <iostream>
#include <string>
int main() {
	// Declare a string object and initialize it
	std::string word = "fred";
	// Prints 4, since word contains four characters
	std::cout << word.length() << '\n';
	// Prints "not empty", since word is not empty
//word에 저장된 단어의 길이를 출력
	if (word.empty())
		std::cout << "empty\n";
	else
		std::cout << "not empty\n";
	// Makes word empty
//empty인지 아닌지 확인하는 조건문
	word.clear();
//word 값 초기화
	// Prints "empty", since word now is empty
	if (word.empty())
		std::cout << "empty\n";
	else
		std::cout << "not empty\n";
//조건문 다시 돌려보니 empty함
	// Assign a string using operator= method
	word = "good";
//word에 good저장
	// Prints "good"
	std::cout << word << '\n';
//출력
	// Append another string using operator+= method
	word += "-bye";
//string은 대입연산자 이용가능
	// Prints "good-bye"
	std::cout << word << '\n';
//출력해보니 대입한 값 뒤에 붙어있음
	// Print first character using operator[] method
	std::cout << word[0] << '\n';
//word의 첫 번째 단어 출력 -> g
	// Print last character
	std::cout << word[word.length() - 1] << '\n';
//word의 마지막 단어 출력 -> e
	// Prints "od-by", the substring starting at index 2 of length 5
	std::cout << word.substr(2, 5);
//word의 세번째 값부터 5개 출력 -> od-by
	std::string first = "ABC", last = "XYZ";
	// Splice two strings with + operator
	std::cout << first + last << '\n';
//first와 last 이어서 출력 -> ABCXYZ
	std::cout << "Compare " << first << " and ABC: ";
	if (first == "ABC")
		std::cout << "equal\n";
	else
		std::cout << "not equal\n";
//조건문 통해 ABC와 같은지 아닌지 비교 -> 같음
	std::cout << "Compare " << first << " and XYZ: "; 
	if (first == "XYZ")
		std::cout << "equal\n";
	else
		std::cout << "not equal\n";
}
//조건문 통해 ABC와 같은지 아닌지 비교 -> 다름
