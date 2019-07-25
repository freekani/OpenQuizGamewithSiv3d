#pragma once
# include <Siv3D.hpp>
using namespace std;
class TextButton
{
private:
	int x, y, width, height;
	String text;
public:
	Rect button;
	Font drawText;
	
	TextButton(int x, int y, int width, int hight) {
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = hight;
		button = Rect(Arg::center = Point(x, y), width, hight);
		drawText = Font(24);
	}
	bool draw() {
		if (this->button.leftPressed()) {
			this->button.draw(Color(150, 150, 150));

		}
		else if (this->button.leftReleased()) {
			return true;
		}
		else {
			this->button.draw(Color(180, 180, 180));
		}
		this->drawText(this->text).draw(Arg::center = Point(x, y));
		return false;
	}

	void setText(String text) {
		this->text = text;
		//drawText = Font(Window::Size().x / text.size() / 4);
	}
};