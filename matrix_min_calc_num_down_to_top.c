#include <stdio.h>
#include <stdlib.h>

int g_matrixSize[10] = {15, 24, 3, 8, 9, 13, 6, 9, 18, 9};
int g_minCalcNum[10][10];
int g_partPointIndex[10][10];

int CalcMatrixMinNum(int startIndex, int endIndex)
{
    int tmpCalcNum;
    int allLen = endIndex - startIndex + 1;
    int len;
    int tmpStartIndex, tmpEndIndex, partPointIndex;

    for (len = 2; len <= allLen; len++) {
        for (tmpStartIndex = startIndex; tmpStartIndex <= allLen - len + startIndex; tmpStartIndex++) {
            tmpEndIndex = tmpStartIndex + len - 1;
            if (g_minCalcNum[tmpStartIndex][tmpEndIndex] >= 0) {
                continue;
            }
            for (partPointIndex = tmpStartIndex; partPointIndex < tmpEndIndex; partPointIndex++) {
                tmpCalcNum = g_minCalcNum[tmpStartIndex][partPointIndex] + g_minCalcNum[partPointIndex + 1][tmpEndIndex] + g_matrixSize[tmpStartIndex - 1] * g_matrixSize[partPointIndex] * g_matrixSize[tmpEndIndex];
                if (partPointIndex == tmpStartIndex) {
                    g_minCalcNum[tmpStartIndex][tmpEndIndex] = tmpCalcNum;
                    g_partPointIndex[tmpStartIndex][tmpEndIndex] = partPointIndex;
                } else if (tmpCalcNum < g_minCalcNum[tmpStartIndex][tmpEndIndex]) {
                    g_minCalcNum[tmpStartIndex][tmpEndIndex] = tmpCalcNum;
                    g_partPointIndex[tmpStartIndex][tmpEndIndex] = partPointIndex;
                }
            }
        }
    }

    return g_minCalcNum[startIndex][endIndex];
}

int main()
{
    int result;
    int i;
    memset((void*)g_minCalcNum, -1, sizeof(int) * 100);
    memset((void*)g_partPointIndex, 0, sizeof(int) * 100);
    for (i = 0; i < 10; i++) {
        g_minCalcNum[i][i] = 0;
    }
    result = CalcMatrixMinNum(2, 7);

    printf("%d\n", result);
    return 0;
}