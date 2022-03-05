#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
/*
* print
* Prints the contents of an int vector
* a is the vector to print; a is not modified
* n is the number of elements in the vector
*/
void print(const std::vector<int>& a) {
	int n = a.size();
	std::cout << "{";
	if (n > 0) {
		std::cout << a[0]; // Print the first element
		for (int i = 1; i < n; i++)
			std::cout << ',' << a[i]; // Print the rest
	}
	std::cout << "}";
}
/*
* Returns a pseudorandom number in the range begin...end - 1,
* inclusive. Returns 0 if begin >= end.
*/
int random(int begin, int end) {
	if (begin >= end)
		return 0;
	else {
		int range = end - begin;
		return begin + rand() % range;
	}
}
/*
* Randomly permute a vector of integers.
* a is the vector to permute, and n is its length.
*/
void permute(std::vector<int>& a) {
	int n = a.size();
	for (int i = 0; i < n - 1; i++) {
		// Select a pseudorandom location from the current
		// location to the end of the collectionstd::swap(a[i], a[random(i, n)]);
	}
}
/* Randomly permute a vector? */
void faulty_permute(std::vector<int>& a) {
	int n = a.size();
	for (int i = 0; i < n; i++) {
		// Select a pseudorandom position somewhere in the collection
		std::swap(a[i], a[random(0, n)]);
	}
}
/* Classify a vector as one of the six permutations */
int classify(const std::vector<int>& a) {
	switch (100 * a[0] + 10 * a[1] + a[2]) {
	case 123: return 0;
	case 132: return 1;
	case 213: return 2;
	case 231: return 3;
	case 312: return 4;
	case 321: return 5;
	}
	return -1;
}
/* Report the accumulated statistics */
void report(const std::vector<int>& a) {
	std::cout << "1,2,3: " << a[0] << '\n';
	std::cout << "1,3,2: " << a[1] << '\n';
	std::cout << "2,1,3: " << a[2] << '\n';
	std::cout << "2,3,1: " << a[3] << '\n';
	std::cout << "3,1,2: " << a[4] << '\n';
	std::cout << "3,2,1: " << a[5] << '\n';
}
/*
* Fill the given vector with zeros.
* a is the vector, and n is its length.
*/
void clear(std::vector<int>& a) {
	int n = a.size();
	for (int i = 0; i < n; i++)
		a[i] = 0;
}
int main() {
	// Initialize random generator seed
	srand(static_cast<int>(time(0)));
	// permutation_tally vector keeps track of each permutation pattern
	// permutation_tally[0] counts {1,2,3}
	// permutation_tally[1] counts {1,3,2}
	// permutation_tally[2] counts {2,1,3}
	// permutation_tally[3] counts {2,3,1}
// permutation_tally[4] counts {3,1,2}
// permutation_tally[5] counts {3,2,1}
	std::vector<int> permutation_tally{ 0, 0, 0, 0, 0, 0 };
	// original always holds the vector {1,2,3}
	const std::vector<int> original{ 1, 2, 3 };
	// working holds a copy of original that gets permuted and tallied
	std::vector<int> working;
	// Run each permutation one million times
	const int RUNS = 1000000;
	std::cout << "--- Random permute #1 -----\n";
	clear(permutation_tally);
	for (int i = 0; i < RUNS; i++) { // Run 1,000,000 times
	// Make a copy of the original vector
		working = original;
		// Permute the vector with the first algorithm
		permute(working);
		// Count this permutation
		permutation_tally[classify(working)]++;
	}
	report(permutation_tally); // Report results
	std::cout << "--- Random permute #2 -----\n";
	clear(permutation_tally);
	for (int i = 0; i < RUNS; i++) { // Run 1,000,000 times
	// Make a copy of the original vector
		working = original;
		// Permute the vector with the second algorithm
		faulty_permute(working);
		// Count this permutation
		permutation_tally[classify(working)]++;
	}
	report(permutation_tally); // Report results
}


/*
faulty_permute함수와 permute함수를 반복문을 통해 1000000번 반복한 결과를 비교하는 함수이다.
main함수부터 보면 임시로 만든 working 벡터에 각각 permute와 faulty_permute함수를 적용하여
classify함수를 통해 지정된 순열 케이스를 permutation_tally벡터에 저장한 뒤 그 순열이 몇 번 나왔는지 report함수를 활용해 그 횟수를 출력하는 함수이다.
random 함수는 지정된 범위 안에서 랜덤의 정수를 반환하는 함수이다.
permute함수는 반복문 안에 내용이 없어서 변화가 없고, 따라서 결과 출력시 original 벡터인 1,2,3인 케이스가 1000000번 반복되는 것을 확인할 수 있다.
faulty_permute함수는 random함수에서 반환 받은 순서의 벡터와 swap을 통해 순서를 바꾼 순열을 반환하므로 결과를 보면 6가지 케이스가 얼추 비슷한 비율을 가지는 것을 볼 수 있다.
classify함수는 6가지케이스를 각각 0에서 5까지로 바꾸어 반환해주는 함수이다.
report함수는 결과값을 출력해주는 양식을 제공해주는 함수이다.
clear함수는 permute함수와 faulty_permute함수 실행하는 사이에 임시 벡터인 permutation_tally를 초기화해주기 위한 함수이다.

*/
