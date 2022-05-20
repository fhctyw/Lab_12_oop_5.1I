#pragma once

class Object
{
	static unsigned int count;
public:
	Object() { count++; };
	~Object() { count--; };
	static unsigned int Count() { return count; };
};

