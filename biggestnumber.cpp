//프로그래머스 큰 수 만들기 https://programmers.co.kr/learn/courses/30/lessons/42883

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

char* solution(const char* number, int k) {
	int len = strlen(number) - k;
	char* answer = (char*)malloc(sizeof(char) * (len + 1));
	answer[len] = '\0';
	int answeridx = 0;
	int idx = 0;
	int max = 0;
	int maxidx = 0;
	while (answeridx < len)
	{
		max = 0;
		for (int i = idx; i < idx + k + 1; i++)
		{
			if (max < number[i])
			{
				max = number[i];
				maxidx = i;
			}
		}
		answer[answeridx] = number[maxidx];
		k -= maxidx - idx;
		idx = maxidx + 1;
		answeridx += 1;
	}
	return (answer);
}

int main(void)
{
	const char number[] = "4177252841";
	int k = 4;
	printf("%s", solution(number, k));
}