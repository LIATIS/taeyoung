// 백준 수 찾기 1920 https://www.acmicpc.net/problem/1920

#pragma warning(disable: 4996)
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int binarysearch(int* arr, int max, int searchint)
{
	int min = 0;
	while (min <= max)
	{
		if (arr[(min + max) / 2] == searchint)
		{
			return 1;
		}
		else if (arr[(min + max) / 2] > searchint)
		{
			max = (min + max) / 2 - 1;
		}
		else
		{
			min = (min + max) / 2 + 1;
		}
	}
	return 0;
}
int main()
{
	int N, M, Buffer;
	scanf("%d", &N);
	int *arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &Buffer);
		arr[i] = Buffer;
	}
	sort(arr, arr + N);
	scanf("%d", &M);
	int* problem = new int[M];
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &Buffer);
		problem[i] = Buffer;
	}
	for (int i = 0; i < M; i++)
	{
		printf("%d\n", binarysearch(arr, N - 1, problem[i]));
	}
	delete [] arr;
	delete [] problem;
	return 0;
}
