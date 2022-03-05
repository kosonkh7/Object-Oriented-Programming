enum class SignalColor { Red, Green, Yellow };
class Trafficlight {
private:
	SignalColor color; // The light's current color: Red, Green, or Yellow
public:
	Trafficlight(SignalColor initial_color);
	void change();
	SignalColor get_color() const;
};

//신호등의 빛 색을 나타내는 클래스 trafficlight
//파라미터로 열거형 클래스 SignalColor 에서 하나 가져옴
