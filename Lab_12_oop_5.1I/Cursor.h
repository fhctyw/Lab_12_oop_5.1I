// Cursor.h
#pragma once
#include "LongLong.h"
#include <iostream>
#include "CursorException.h"
#include "MyException.h"
using namespace std;

class Cursor : public LongLong
{
	char size;
	bool view;
public:
	Cursor(LongLong pos = LongLong(0,0), char size = 1, bool  view = false) throw(MyException);
	Cursor(const Cursor& c);
	Cursor& operator=(const Cursor& c);
	
	operator string() const;
	friend ostream& operator<<(ostream& out, const Cursor& c);
	friend istream& operator>>(istream& in, Cursor& c) throw(CursorException);

	bool setPosition(LongLong ll);
	char getSize() { return size; }
	bool setSize(char s);
	bool getView() { return view; }
	bool setView(bool v) { view = v; return true; }

	void move(long x, long y);
	void changeView();
	void SizeUp() throw(exception);
	void SizeDown();

	void Show();
	void Hide();
};

