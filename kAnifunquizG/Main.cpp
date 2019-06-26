
# include <Siv3D.hpp> // OpenSiv3D v0.3.2
#include<string>
#include<Windows.h>
#include<time.h>
#include "TextButton.h"
#include<vector>
using namespace std;
void Main()
{
	//System::SetExitEvent(WindowEvent::Manual);
	//Window::SetStyle(WindowStyle::NonFrame);
	Window::Resize(875, 635);//ウィンドウサイズ
	TextReader reader(U"quiz.txt");

	Window::SetTitle(U"kani.fun");//ウィンドウタイトル
	Graphics::SetBackground(Palette::White);//背景

	const Font font(30);
	const Font font2(15);




	while (System::Update()) {
		font(U"Press start").draw(Arg::center = Window::Center(), Color(0, 0, 0));
		if (MouseL.down()) break;

	}

	System::Update();

	font(U"Wait").draw(Arg::center = Window::Center(), Color(0, 0, 0));


	System::Update();

	//ここからクイズフォーマット１
	TextButton B0(Window::Width() / 4, Window::Height() * 13 / 20, Window::Width() * 19 / 40, Window::Height() * 12 / 60);
	TextButton B1(Window::Width() / 4, Window::Height() * 26 / 30, Window::Width() * 19 / 40, Window::Height() * 12 / 60);
	TextButton B2(Window::Width() / 4 * 3, Window::Height() * 13 / 20, Window::Width() * 19 / 40, Window::Height() * 12 / 60);
	TextButton B3(Window::Width() / 4 * 3, Window::Height() * 26 / 30, Window::Width() * 19 / 40, Window::Height() * 12 / 60);
	//ここまで
	int qm = 0;
	int qn = 0;
	int clock1 = 0;
	int point = 0;
	String question[1000] = {};
	String S0[1000] = {}, S1[1000] = {}, S2[1000] = {}, S3[1000] = {};
	String answer[1000] = {};
	String drawquestion = U"";
	String maked[1000] = {};
	String genre[1000] = {};
	String check;
	String line;

	Sleep(500);




	//clock1=clock();
	for (int i = 0; reader.readLine(question[i]); i++) {
		reader.readLine(S0[i]);
		reader.readLine(S1[i]);
		reader.readLine(S2[i]);
		reader.readLine(S3[i]);
		reader.readLine(answer[i]);
		reader.readLine(maked[i]);
		reader.readLine(genre[i]);

		qm = i;
	}
	for (int i = 0; i < 10; i++) {

		srand(time(NULL));
		if (qm == 0) { break; }
		qn = rand() % (qm + 1);


		drawquestion = question[qn];
		clock1 = clock();
		while (System::Update())
		{

			//if (100 < clock() - clock1) {}
			font2(U"残り時間：" + ToString(20000 - clock() + clock1)).draw(200, 50, Color(0, 0, 0));
			font2(U"制作者：" + maked[qn]).draw(Arg::center = Point(700, 250), Color(0, 0, 0));
			font2(drawquestion).draw(Arg::center = Point(437, 100), Color(0, 0, 0));
			if (clock() - clock1 > 20000) {

				check = U"4";

				break;
			}
			if (KeyEscape.down()/* || WindowEvent::CloseButton*/) { system("taskkill /IM kani.funquiz.exe /F"); }

			if (B0.draw(S0[qn])) {
				check = U"0";
				break;
			}
			if (B1.draw(S1[qn])) {
				check = U"1";
				break;
			}
			if (B2.draw(S2[qn])) {
				check = U"2";
				break;
			}
			if (B3.draw(S3[qn])) {
				check = U"3";
				break;
			}

		}





		if (answer[qn] == check) {
			point += 20000 + clock1 - clock();
			//正解
			System::Update();
			font(U"正解").draw(Arg::center = Window::Center(), Color(0, 0, 0));




			System::Update();



			Sleep(2500);

		}

		else if (check == U"4") {
			//時間切れ

			System::Update();

			font(U"時間切れ").draw(Arg::center = Window::Center(), Color(0, 0, 0));


			System::Update();

			Sleep(2500);



		}
		else {

			//不正解
			System::Update();

			font(U"不正解").draw(Arg::center = Window::Center(), Color(0, 0, 0));


			System::Update();


			Sleep(2500);

		}
	}
	int end = 0;
	while (System::Update()) {

		font(point).draw(Arg::center = Window::Center(), Color(0, 0, 0));

		if (MouseL.down())end++;
		if (end > 2)break;
	}

}
