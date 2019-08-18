#include <stdio.h>
#include <stdlib.h>

int g_matrixSize[10] = {15, 24, 3, 8, 9, 13, 6, 9, 18, 9};
int g_minCalcNum[10][10];
int g_partPointIndex[10][10];

int CalcMatrixMinNum(int startIndex, int endIndex)
{
    int calcNum;
    int tmpCalcNum;
    int i;

    if (g_minCalcNum[startIndex][endIndex] >= 0) {
        return g_minCalcNum[startIndex][endIndex];
    }
    if (startIndex + 1 == endIndex) {
        calcNum = g_matrixSize[startIndex - 1] * g_matrixSize[startIndex] * g_matrixSize[endIndex];
        return calcNum;
    }
    if (startIndex == endIndex) {
        return 0;
    }

    for (i = startIndex; i < endIndex; i++) {
        tmpCalcNum = CalcMatrixMinNum(startIndex, i) + CalcMatrixMinNum(i + 1, endIndex) + g_matrixSize[startIndex - 1] * g_matrixSize[i] * g_matrixSize[endIndex];
        if (i == startIndex) {
            calcNum = tmpCalcNum;
            g_partPointIndex[startIndex][endIndex] = i;
        } else if (tmpCalcNum < calcNum) {
            calcNum = tmpCalcNum;
            g_partPointIndex[startIndex][endIndex] = i;
        }
    }

    g_minCalcNum[startIndex][endIndex] = calcNum;

    return calcNum;
}

int main()
{
    int result;
    memset((void*)g_minCalcNum, -1, sizeof(int) * 100);
    memset((void*)g_partPointIndex, 0, sizeof(int) * 100);
    result = CalcMatrixMinNum(2, 7);

    printf("%d\n", result);
    return 0;
}