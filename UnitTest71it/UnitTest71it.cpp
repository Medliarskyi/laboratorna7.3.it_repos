#include "pch.h"
#include "CppUnitTest.h"
#include "../lab73it/lab73it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest71it
{
	TEST_CLASS(UnitTest71it)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            int k = 3, n = 3;
            int** matrix = new int* [k];
            for (int i = 0; i < k; ++i) {
                matrix[i] = new int[n];
            }

            matrix[0][0] = -5; matrix[0][1] = 4; matrix[0][2] = -7;
            matrix[1][0] = 3;  matrix[1][1] = -1; matrix[1][2] = -3;
            matrix[2][0] = 2;  matrix[2][1] = 0;  matrix[2][2] = 1;

            sortColumnsByCharacteristics(matrix, k, n);

            
            for (int i = 0; i < k; ++i) {
                delete[] matrix[i];
            }
            delete[] matrix;
		}
	};
}
