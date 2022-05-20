#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab_12_oop_5.1I\MyException.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			MyException e("err");
			Assert::AreEqual("err", e.What());
		}
	};
}
