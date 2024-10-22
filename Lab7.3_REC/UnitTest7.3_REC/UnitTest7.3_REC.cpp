#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab7.3_REC/Lab7.3_REC.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest73REC
{
	TEST_CLASS(UnitTest73REC)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int rowCount = 3;
			const int colCount = 4;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];

			a[0][0] = 1; a[0][1] = 1; a[0][2] = 1; a[0][3] = 2;
			a[1][0] = 3; a[1][1] = 3; a[1][2] = 4; a[1][3] = 4;
			a[2][0] = 5; a[2][1] = 5; a[2][2] = 5; a[2][3] = 5;

			int rowWithLongestSeries = -1;

			Part2_SaddlePoint(a, rowCount, colCount, rowWithLongestSeries);

			Assert::AreEqual(2, rowWithLongestSeries);

			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}
