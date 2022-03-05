// Computes the midpoint of the points (x1, y1) and (x2, y2).
// The point (mx, my) represents the midoint.
void midpoint(double x1, double y1, double x2, double y2,
	double& mx, double& my) {
	// Add your code . . .
}
-
void midpoint(double x1, double y1, double x2, double y2,
	double& mx, double& my) {
	
	mx = (x1 + x2) / 2;
	my = (y1 + y2) / 2;

	std::cout << "(" << mx << "," << my << ")";

}


int main() {
	double x1 = 10, y1 = 5, x2 = 10, y2 = 7, mx, my;

	midpoint(x1, y1, x2, y2, mx, my);
}

//함수에서 mx에 x1과 x2의 평균, my에 y1과 y2의 평균을 저장하여 출력하게 해주었다.
