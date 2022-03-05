#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
/*
* binary_search(a, seek)
* Returns the index of element seek in vector a;
* returns -1 if seek is not an element of a
* a is the vector to search; a's contents must be
* sorted in ascending order.
* seek is the element to find.
*/
int binary_search(const std::vector<int>& a, int seek) {
	int n = a.size();
	int first = 0, // Initially the first element in vector
		last = n - 1, // Initially the last element in vector
		mid; // The middle of the vector
	while (first <= last) {
		mid = first + (last - first + 1) / 2;
		if (a[mid] == seek)
			return mid; // Found it
		else if (a[mid] > seek)
			last = mid - 1; // continue with 1st half
		else // a[mid] < seek
			first = mid + 1; // continue with 2nd half
	}
	return -1; // Not there
}
/*
* linear_search(a, seek)
* Returns the index of element seek in vector a.
* Returns -1 if seek is not an element of a.
* a is the vector to search.
* seek is the element to find.
* This version requires vector a to be sorted in
* ascending order.
*/
int linear_search(const std::vector<int>& a, int seek) {
	int n = a.size();
	for (int i = 0; i < n && a[i] <= seek; i++)
		if (a[i] == seek)
			return i; // Return position immediately
	return -1; // Element not found
}
/*
* Tests the execution speed of a given search function on a
* vector.
* search - the search function to test
* v - the vector to search
* trials - the number of trial runs to average
* Returns the elapsed time in seconds
* The C++ chrono library defines the types
* system_clock::time_point and microseconds.
*/
double time_execution(int (*search)(const std::vector<int>&, int),
	std::vector<int>& v, int trials) {
	int n = v.size();
	// Average the time over a specified number of trials
	double elapsed = 0.0;
	for (int iters = 0; iters < trials; iters++) {
		clock_t start_time = clock(); // Start the timer
		for (int i = 0; i < n; i++) // Search for all elements
			search(v, i);
		clock_t end_time = clock(); // Stop the timer
		elapsed += static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
	}
	return elapsed / trials; // Mean elapsed time per run
}
int main() {
	std::cout << "---------------------------------------\n";
	std::cout << " Vector Linear Binary\n";
	std::cout << " Size Search Search\n";
	std::cout << "---------------------------------------\n";
	// Test the sorts on vectors with 1,000 elements up to
	// 10,000 elements.
	for (int size = 0; size <= 50000; size += 5000) {
		std::vector<int> list(size); // Make a vector of the appropiate size
		// Ensure the elements are ordered low to high
		for (int i = 0; i < size; i++)
			list[i] = i;
		std::cout << std::setw(7) << size;
		// Search for all the elements in list using linear search
		// Compute running time averaged over five runs
		std::cout << std::fixed << std::setprecision(3) << std::setw(12)
			<< time_execution(linear_search, list, 5)
			<< " sec";
		// Search for all the elements in list binary search
		// Compute running time averaged over 25 runs
		std::cout << std::fixed << std::setprecision(3) << std::setw(12)
			<< time_execution(binary_search, list, 25)
			<< " sec\n";
	}
}


/*
이진검색과 선형검색의 처리 시간 차이를 보여주는 코드이다.
벡터 길이를 0부터 50000까지 5000씩 증가시켜 시간 차이를 보여주고 있다.
결과부터 보면 이진검색은 길이 50000인 벡터에서도 1초 미만의 검색 시간을 보여주는 반면
선형검색은 2분 가까이 시간이 걸렸다. 
처리 시간이 선형검색은 n, 이진검색은 logn으로 비례하기 때문에 이런 차이를 보이는 것이다.
이진검색과 선형검색을 해주는 알고리즘을 각각 함수로 선언하였고
time_execution 함수에서 함수 포인터를 통해 위 함수를 불러와 시간을 계산할 수 있게 해준다.
또한 time_execution함수는 메인 함수로부터 함수 크기를 전달받아 for문을 통해 모두 검색하는 기능을 수행한다.
*/
