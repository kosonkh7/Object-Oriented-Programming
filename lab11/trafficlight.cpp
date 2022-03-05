#include "trafficlight.h"
// Ensures a traffic light object is in the state of
// red, green, or yellow. A rogue value makes the
// traffic light red
Trafficlight::Trafficlight(SignalColor initial_color) {
	switch (initial_color) {
	case SignalColor::Red:
	case SignalColor::Green:
	case SignalColor::Yellow:
		color = initial_color;
		break;
	default:
		color = SignalColor::Red; // Red by default, just in case
	}
}
//SignalColor 클래스의 생성자 내용을 의미함
//스위치문으로 통해 전달 받은 값이 빨 초 노 중에 하나면
//color에 그걸 저장하고
//다른 거면 디폴트 값으로 빨강을 저장한다.
// Ensures the traffic light's signal sequence
void Trafficlight::change() {
	// Red --> green, green --> yellow, yellow --> red
	if (color == SignalColor::Red)
		color = SignalColor::Green;
	else if (color == SignalColor::Green)
		color = SignalColor::Yellow;
	else if (color == SignalColor::Yellow)
		color = SignalColor::Red;
}
// Returns the light's current color so a client can
// act accordingly
//SignalColor 클래스의 change 함수의 내용을 의미함
//color의 값이 빨강이면 초록, 초록이면 노랑, 노랑이면 빨강으로 색을 바꿔주는 기능이다.


SignalColor Trafficlight::get_color() const {
	return color;
}
// SignalColor 클래스의 get_color 함수의 내용을 의미함
//chage함수로 인해 변경된 color값을 가져옴
//Trafficlight.h 헤더를 포함함
