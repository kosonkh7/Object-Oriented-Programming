#include <iostream>
#include <vector>
/*
* Comparer objects manage the comparisons and element
* interchanges on the selection sort function below.
*/
class Comparer {
	// Keeps track of the number of comparisons
	// performed
	int compare_count;
	// Keeps track of the number of swaps performed
	int swap_count;
	// Function pointer directed to the function to
	// perform the comparison
	bool (*comp)(int, int);
public:
	// The client must initialize a Comparer object with a
	// suitable comparison function.
	Comparer(bool (*f)(int, int)) :
		compare_count(0), swap_count(0), comp(f) {}
	// Resets the counters to make ready for a new sort
	void reset() {
		compare_count = swap_count = 0;
	}
	// Method that performs the comparison. It delegates
	// the actual work to the function pointed to by comp.
	// This method logs each invocation.
	bool compare(int m, int n) {
		compare_count++;
		return comp(m, n);
	}
	// Method that performs the swap.
	// Interchange the values of
	// its parameters a and b which are
	// passed by reference.
	// This method logs each invocation.
	void swap(int& m, int& n) {
		swap_count++;
		int temp = m;
		m = n;
		n = temp;
	}
	// Returns the number of comparisons this object has
	// performed since it was created.
	int comparisons() const {
		return compare_count;
	}
	// Returns the number of swaps this object has
	// performed since it was created.
	int swaps() const {
		return swap_count;
	}
};
//private 멤버 변수 compare_count swap_count 가지고
// bool타입 포인터 함수 bool (*comp)(int, int);도 있음
//클래스 생성자는 함수 포인터 전달받고, compare_count swap_count 0으로 초기화
//멤버 함수 reset()은 compare_count swap_count 다시 0으로 초기화하는 기능
//멤버 함수 compare()는 정수 2개 전달 받으면 compare_count 1 증가시키는 기능
//멤버 함수 swap은 두 정수를 참조에 의한 호출로 받아 순서 바꿔주는 기능
//멤버 함수 comparisons는 const로 바뀌지 않으며 compare_count를 그냥 보여주는 역할
//멤버 함수 swaps도 마찬가지로 swap_count 보여주는 역할
/*
* selection_sort(a, compare)
* Arranges the elements of vector a in an order determined
* by the compare object.
* a is a vector of ints.
* compare is a function that compares the ordering of
* two integers.
* The contents of a are physically rearranged.
*/
void selection_sort(std::vector<int>& a, Comparer& compare) {
	int n = a.size();
	for (int i = 0; i < n - 1; i++) {
		// Note: i,small, and j represent positions within a
		// a[i], a[small], and a[j] represents the elements at
		// those positions.
		// small is the position of the smallest value we've seen
		// so far; we use it to find the smallest value less
		// than a[i]
		int small = i;
		// See if a smaller value can be found later in the array
		for (int j = i + 1; j < n; j++)
			if (compare.compare(a[j], a[small]))
				small = j; // Found a smaller value
				// Swap a[i] and a[small], if a smaller value was found
		if (i != small)
			compare.swap(a[i], a[small]);
	}
}
//하나의 벡터와 Comparer 클래스 전달 받아 값 바꿔주는 함수
//벡터 내의 값들을 조건문과 반복문을 통해 정렬해주는 기능
/*
* print
* Prints the contents of an integer vector
* a is the vector to print.
* a is not modified.
*/
void print(const std::vector<int>& a) {
	int n = a.size();
	std::cout << '{';
	if (n > 0) {
		std::cout << a[0]; // Print the first element
		for (int i = 1; i < n; i++)
			std::cout << ',' << a[i]; // Print the rest
	}
	std::cout << '}';
}
// 벡터 내의 값을 조건문을 통해 출력해주는 함수
/*
* less_than(a, b)
* Returns true if a < b; otherwise, returns
* false.
*/
bool less_than(int a, int b) {
	return a < b;
}
//a<b이면 true를 반환하는 함수
/*
* greater_than(a, b)
* Returns true if a > b; otherwise, returns
* false.
*/
bool greater_than(int a, int b) {
	return a > b;
}
//a>b이면 true를 반환하는 함수

int main() {
	// Make a vector of integers from an array
	std::vector<int> original{ 23, -3, 4, 215, 0, -3, 2, 23, 100, 88, -10 };
	// Make a working copy of the original vector
	std::vector<int> working = original;
	std::cout << "Before: ";
	print(working);
	std::cout << '\n';
	Comparer lt(less_than), gt(greater_than);
	selection_sort(working, lt);
	std::cout << "Ascending: ";
	print(working);
	std::cout << " (" << lt.comparisons() << " comparisons, "
		<< lt.swaps() << " swaps)\n";
	std::cout << "----------------------------\n";
	// Make another copy of the original vector
	working = original;
	std::cout << "Before: ";
	print(working);
	std::cout << '\n';
	selection_sort(working, gt);
	std::cout << "Descending: ";
	print(working);
	std::cout << " (" << gt.comparisons() << " comparisons, "
		<< gt.swaps() << " swaps)\n";
	std::cout << "----------------------------\n";
	// Sort a sorted vector
	std::cout << "Before: ";
	print(working);
	std::cout << '\n';
	// Reset the greater than comparer so we start counting at
	// zero
	gt.reset();
	selection_sort(working, gt);
	std::cout << "Descending: ";
	print(working);
	std::cout << " (" << gt.comparisons() << " comparisons, "
		<< gt.swaps() << " swaps)\n";
}
