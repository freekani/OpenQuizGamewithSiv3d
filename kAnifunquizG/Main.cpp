
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
	const Font quizInfomationFont(17);
	const Font quizScriptsFont(16);


	while (System::Update()) {
		font(U"Press start").draw(Arg::center = Window::Center(), Color(0, 0, 0));
		if (MouseL.up()) break;

	}

	System::Update();

	font(U"Wait").draw(Arg::center = Window::Center(), Color(0, 0, 0));


	System::Update();

	//ここからクイズフォーマット１
	TextButton Button0(Window::Width() / 2, Window::Height() * 12 / 30, Window::Width() * 39 / 40, Window::Height() * 1 / 7);
	TextButton Button1(Window::Width() / 2, Window::Height() * 17 / 30, Window::Width() * 39 / 40, Window::Height() * 1 / 7);
	TextButton Button2(Window::Width() / 2, Window::Height() * 22 / 30, Window::Width() * 39 / 40, Window::Height() * 1 / 7);
	TextButton Button3(Window::Width() / 2, Window::Height() * 27 / 30, Window::Width() * 39 / 40, Window::Height() * 1 / 7);
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

		if (quizList.size() == 0) { break; }
		int qn = Random(0, int(quizList.size() - 1));
		Quiz4 now_playing = quizList[qn];
		quizList.erase(quizList.begin() + qn);
		clock1 = clock();
		Button0.setText(now_playing.getS0());
		Button1.setText(now_playing.getS1());
		Button2.setText(now_playing.getS2());
		Button3.setText(now_playing.getS3());
		while (System::Update())
		{
			//if (100 < clock() - clock1) {}
			quizInfomationFont(U"残り時間：" + ToString(20000 - clock() + clock1)).draw(Arg::center = Point(Window::Width() / 20 * 3, Window::Height() / 13), Color(0, 0, 0));
			quizInfomationFont(U"制作者：" + now_playing.getPresenter()).draw(Arg::center = Point(Window::Width() / 20 * 17, Window::Height() / 13), Color(0, 0, 0));


			quizScriptsFont(now_playing.getQuestion()).draw(Arg::center = Point(437, 100), Color(0, 0, 0));
			if (clock() - clock1 > 20000) {

				check = U"4";

				break;
			}
			if (KeyEscape.down()/* || WindowEvent::CloseButton*/) {
				system("taskkill /IM kAnifunquizG.exe /F");
			}

			if (Button0.draw()) {
				check = U"0";
				break;
			}
			if (Button1.draw()) {
				check = U"1";
				break;
			}
			if (Button2.draw()) {
				check = U"2";
				break;
			}
			if (Button3.draw()) {
				check = U"3";
				break;
			}

		}

		if (now_playing.getAnswer() == check) {
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

		if (quizList.size() == 0) {
			break;
		}

	}
	int end = 0;
	while (System::Update()) {

		font(point).draw(Arg::center = Window::Center(), Color(0, 0, 0));

		if (MouseL.down())end++;
		if (end > 2)break;
	}

}
