// 백준 5545 최고의 피자 C++
#pragma warning(disable: 4996)
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N, A, B, C, SUM, PRICE;

    scanf("%d", &N);
    scanf("%d %d", &A, &B);
    scanf("%d", &C);
    SUM = C;
    PRICE = A;
    
    int* arr = new int [N];
    for (int i = 0; i< N; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + N);
    for (int i = N - 1; i >= 0; i--)
    {
        if (arr[i] / B > SUM / PRICE)
        {
            SUM += arr[i];
            PRICE += B;
        }
    }
    printf("%d", SUM / PRICE);
    delete [] arr;
    return 0;
}