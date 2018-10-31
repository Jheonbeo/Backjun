// Backjun.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <stdio.h>

int n; // �ԷµǴ� ������ �ִ�
int m; // �ԷµǴ� ������ ��
int rear, front; // ���ܰ� �Ĵ��� ��Ÿ���� ����
int map[30][30], queue[30], visit[30]; // ���� ��İ� ť�� �湮 �迭


void BFS(int v)
{
	int i;

	visit[v] = 1; // ���� v�� �湮�ߴٰ� ǥ��
	printf("%d ", v);
	queue[rear++] = v; // ť�� v�� �����ϰ� �Ĵ��� 1 ������Ŵ
	while (front < rear) // �Ĵ��� ���ܰ� ���ų� ������ ���� Ż��
	{
		// ť�� ù��°�� �ִ� �����͸� �����ϰ� ���ܵ� ���� ��������, ���� 1 ����
		v = queue[front++];
		for (i = 1; i <= n; i++)
		{
			// ���� v�� ���� i�� ������, ���� i�� �湮���� ���� ������ ���
			if (map[v][i] == 1 && !visit[i])
			{
				visit[i] = 1; // ���� i�� �湮�ߴٰ� ǥ��
				printf("%d ", i);
				queue[rear++] = i; // ť�� i�� �����ϰ� �Ĵ��� 1 ������Ŵ
			}
		}
	}
}

int main()
{
	int start; // ���� ������ ��Ÿ���� ����
	int v1, v2;
	do
	{
		scanf_s("%d %d %d", &n, &m, &start);
	} while (1000 < n > 1 && 1000< m > 1);
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d %d", &v1, &v2);
		map[v1][v2] = 1;
	}
	BFS(start); // BFS ����!

	return 0;
}

