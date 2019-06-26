#pragma once
# include <Siv3D.hpp>
using namespace std;
class TextButton
{
private:
	int x, y, width, hight;
public:
	Rect button;
	Font text;

	TextButton(int x, int y, int width, int hight) {
		this->x = x;
		this->y = y;
		this->width = width;
		this->hight = hight;
		button = Rect(Arg::center = Point(x, y), width, hight);
		text = Font(20);
	}

};

