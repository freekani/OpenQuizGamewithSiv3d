#pragma once
#include<Siv3D.hpp>
using namespace std;
class Quiz4
{
private:
	String question;
	String S0;
	String S1;
	String S2;
	String S3;
	String answer;
	String presenter;
	String genre;
public:
	Quiz4(String question, String S0, String S1, String S2, String S3, String answer, String presenter, String genre) {
		this->question = question;
		this->S0 = S0;
		this->S1 = S1;
		this->S2 = S2;
		this->S3 = S3;
		this->answer = answer;
		this->presenter = presenter;
		this->genre = genre;
	}
	String getQuestion() {
		return this->question;
	}
	String getS0() {
		return this->S0;
	}
	String getS1() {
		return this->S1;
	}
	String getS2() {
		return this->S2;
	}
	String getS3() {
		return this->S3;
	}
	String getAnswer() {
		return this->answer;
	}
	String getPresenter() {
		return this->presenter;
	}
	String getGenre() {
		return this->genre;
	}
};

