#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void InputRec(int** a, const int rowCount, const int colCount, int i = 0, int j = 0);
void PrintRec(int** a, const int rowCount, const int colCount, int i = 0, int j = 0);
int Part1_CountRec(int** a, const int rowCount, const int colCount, int& count, int i = 0, int j = 0);
void Part2_SaddlePoint(int** a, const int rowCount, const int colCount, int& rowWithLongestSeries, int i = 0, int j = 1, int currentSeriesLength = 1, int longestInRow = 1, int maxSeriesLength = 0);

int main()
{
    srand((unsigned)time(NULL));
    int rowCount, colCount;
    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    InputRec(a, rowCount, colCount);
    PrintRec(a, rowCount, colCount);

    int count = 0;
    if (Part1_CountRec(a, rowCount, colCount, count))
        cout << "count = " << count << endl;
    else
        cout << "there are no zero elements" << endl;

    int rowWithLongestSeries = -1;
    Part2_SaddlePoint(a, rowCount, colCount, rowWithLongestSeries);
    if (rowWithLongestSeries != -1)
        cout << "Row with the longest series of identical elements: " << rowWithLongestSeries << endl;
    else
        cout << "No series of identical elements found." << endl;

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void InputRec(int** a, const int rowCount, const int colCount, int i, int j)
{
    if (i == rowCount) return;
    if (j == colCount) {
        cout << endl;
        InputRec(a, rowCount, colCount, i + 1, 0);
    }
    else {
        cout << "a[" << i << "][" << j << "] = ";
        cin >> a[i][j];
        InputRec(a, rowCount, colCount, i, j + 1);
    }
}

void PrintRec(int** a, const int rowCount, const int colCount, int i, int j)
{
    if (i == rowCount) return;
    if (j == colCount) {
        cout << endl;
        PrintRec(a, rowCount, colCount, i + 1, 0);
    }
    else {
        cout << setw(4) << a[i][j];
        PrintRec(a, rowCount, colCount, i, j + 1);
    }
}

int Part1_CountRec(int** a, const int rowCount, const int colCount, int& count, int i, int j)
{
    if (j == colCount) return count > 0;
    if (i == rowCount) return Part1_CountRec(a, rowCount, colCount, count, 0, j + 1);
    if (a[i][j] == 0) {
        count++;
        return Part1_CountRec(a, rowCount, colCount, count, 0, j + 1);
    }
    return Part1_CountRec(a, rowCount, colCount, count, i + 1, j);
}

void Part2_SaddlePoint(int** a, const int rowCount, const int colCount, int& rowWithLongestSeries, int i, int j, int currentSeriesLength, int longestInRow, int maxSeriesLength)
{
    if (i == rowCount) return;

    if (j == colCount) {
        if (currentSeriesLength > longestInRow)
            longestInRow = currentSeriesLength;
        if (longestInRow > maxSeriesLength) {
            maxSeriesLength = longestInRow;
            rowWithLongestSeries = i;
        }
        Part2_SaddlePoint(a, rowCount, colCount, rowWithLongestSeries, i + 1, 1, 1, 1, maxSeriesLength);
    }
    else {
        if (a[i][j] == a[i][j - 1])
            currentSeriesLength++;
        else {
            if (currentSeriesLength > longestInRow)
                longestInRow = currentSeriesLength;
            currentSeriesLength = 1;
        }
        Part2_SaddlePoint(a, rowCount, colCount, rowWithLongestSeries, i, j + 1, currentSeriesLength, longestInRow, maxSeriesLength);
    }
}