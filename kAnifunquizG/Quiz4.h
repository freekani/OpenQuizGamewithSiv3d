#pragma once
#include<Siv3D.hpp>
using namespace std;
class Quiz4
{
private:
	String question;
	String a0;
	String a1;
	String a2;
	String a3;
	String answer;
	String presenter;
	String genre;
public:

	Quiz4(String question, String a0, String a1, String a2, String a3, String answer, String genre, String presenter) {
		this->question = question;
		this->a0 = a0;
		this->a1 = a1;
		this->a2 = a2;
		this->a3 = a3;
		this->answer = answer;
		this->genre = genre;
		this->presenter = presenter;

	}
	/*
	Quiz4(JSONValue j)
		: question(j[U"question"].get<String>())
		, a0(j[U"a0"].get<String>())
		, a1(j[U"a1"].get<String>())
		, a2(j[U"a2"].get<String>())
		, a3(j[U"a3"].get<String>())
		, answer(j[U"answer"].get<String>())
		,genre(j[U"genre"].get<String>())
		, presenter(j[U"presenter"].get<String>()) 
	{}
	*/
	String getQuestion() {
		return this->question;
	}
	String getA0() {
		return this->a0;
	}
	String getA1() {
		return this->a1;
	}
	String getA2() {
		return this->a2;
	}
	String getA3() {
		return this->a3;
	}
	String getAnswer() {
		return this->answer;
	}
	String getGenre() {
		return this->genre;
	}
	String getPresenter() {
		return this->presenter;
	}
};

