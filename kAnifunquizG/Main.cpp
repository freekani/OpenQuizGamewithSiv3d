
# include <Siv3D.hpp> // OpenSiv3D v0.3.2
#include<string>
#include<Windows.h>
#include<time.h>
#include "TextButton.h"
#include<vector>
#include "Quiz4.h"
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
	int clock1 = 0;
	int point = 0;
	vector<Quiz4> quizList;
	String addQuestion;
	String addS0, addS1, addS2, addS3;
	String addAnswer;
	String drawquestion = U"";
	String addPresenter;
	String addGenre;
	String check;
	String line;

	Sleep(500);


	//clock1=clock();
	while (reader.readLine(addQuestion)) {
		reader.readLine(addS0);
		reader.readLine(addS1);
		reader.readLine(addS2);
		reader.readLine(addS3);
		reader.readLine(addAnswer);
		reader.readLine(addPresenter);
		reader.readLine(addGenre);
		quizList.push_back(Quiz4(addQuestion, addS0, addS1, addS2, addS3, addAnswer, addPresenter, addGenre));
	}
	for (int i = 0; i < 10; i++) {
		srand(time(NULL));
		if (quizList.size() == 0) { break; }
		 int qn = rand() % (quizList.size());

		clock1 = clock();
		while (System::Update())
		{
			//if (100 < clock() - clock1) {}
			font2(U"残り時間：" + ToString(20000 - clock() + clock1)).draw(200, 50, Color(0, 0, 0));
			font2(U"制作者：" + quizList[qn].getPresenter()).draw(Arg::center = Point(700, 250), Color(0, 0, 0));
			font2(quizList[qn].getQuestion()).draw(Arg::center = Point(437, 100), Color(0, 0, 0));
			if (clock() - clock1 > 20000) {

				check = U"4";

				break;
			}
			if (KeyEscape.down()/* || WindowEvent::CloseButton*/) { system("taskkill /IM kani.funquiz.exe /F"); }

			if (B0.draw(quizList[qn].getS0())) {
				check = U"0";
				break;
			}
			if (B1.draw(quizList[qn].getS1())) {
				check = U"1";
				break;
			}
			if (B2.draw(quizList[qn].getS2())) {
				check = U"2";
				break;
			}
			if (B3.draw(quizList[qn].getS3())) {
				check = U"3";
				break;
			}

		}

		if (quizList[qn].getAnswer() == check) {
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
		quizList.erase(quizList.begin() + qn);
	}
	int end = 0;
	while (System::Update()) {

		font(point).draw(Arg::center = Window::Center(), Color(0, 0, 0));

		if (MouseL.down())end++;
		if (end > 2)break;
	}

}
