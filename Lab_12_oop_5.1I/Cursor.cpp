// Cursor.cpp
#include "Cursor.h"
#include <sstream>
#include <iostream>

using namespace std;

Cursor::Cursor(LongLong pos, char s, bool v) throw(MyException)
{
    if (!(setPosition(pos) && setSize(s) && setView(v)))
        throw new MyException("bad params");
}

Cursor::Cursor(const Cursor& c)
{
    *this = c;
}

Cursor& Cursor::operator=(const Cursor& c)
{
    size = c.size;
    view = c.view;
    *this = LongLong::operator=(c);
    return *this;
}

istream& operator>>(istream& in, Cursor& c) throw(CursorException)
{
    long x, y;
    int s;
    bool v;
    cout << "¬вед≥ть позиц≥ю x: "; in >> x;
    cout << "¬вед≥ть позиц≥ю y: "; in >> y;
    cout << "¬вед≥ть розм≥р: "; in >> s;
    cout << "¬ед≥ть вид курсору(1 - horizontal, 0 - vertical): "; in >> v;
    if (!(c.setPosition(LongLong(x, y)) && c.setSize(s) && c.setView(v)))
        throw CursorException("bad params");
    return in;
}

Cursor::operator string() const
{
    stringstream ss;
    ss << '(' << getHigh() << ", " << getLow() << ") size: " << (int)size << (view ? " horizontal" : " vertical");
    return ss.str();
}

ostream& operator<<(ostream& out, const Cursor& c)
{
    out << string(c);
    return out;
}

bool Cursor::setPosition(LongLong ll)
{
    if (ll.getHigh() >= 0)
    {
        LongLong::operator=(ll);
        return true;
    }
    else
        return false;
}

bool Cursor::setSize(char s)
{
    if (s > 0 && s < 16)
    {
        size = s;
        return true;
    }
    else
        return false;
}

void Cursor::move(long x, long y)
{
    Hide();

    LongLong ll(y, x);
    LongLong::operator=(*this + ll);

    Show();
}

void Cursor::changeView()
{
    view = !view;
}

void Cursor::SizeUp() throw(exception)
{
    if (!setSize(size + 1))
        throw exception("s > 0 && s < 16");
}

void Cursor::SizeDown()
{
    setSize(size - 1);
}

void Cursor::Show()
{
    cout << "Cursor shows" << endl;
}

void Cursor::Hide()
{
    cout << "Cursor hides" << endl;
}
