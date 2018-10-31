// Backjun.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>

int n; // 입력되는 정점의 최댓값
int m; // 입력되는 간선의 수
int rear, front; // 전단과 후단을 나타내는 변수
int map[30][30], queue[30], visit[30]; // 인접 행렬과 큐와 방문 배열


void BFS(int v)
{
	int i;

	visit[v] = 1; // 정점 v를 방문했다고 표시
	printf("%d ", v);
	queue[rear++] = v; // 큐에 v를 삽입하고 후단을 1 증가시킴
	while (front < rear) // 후단이 전단과 같거나 작으면 루프 탈출
	{
		// 큐의 첫번째에 있는 데이터를 제외하고 제외된 값을 가져오며, 전단 1 증가
		v = queue[front++];
		for (i = 1; i <= n; i++)
		{
			// 정점 v와 정점 i가 만나고, 정점 i를 방문하지 않은 상태일 경우
			if (map[v][i] == 1 && !visit[i])
			{
				visit[i] = 1; // 정점 i를 방문했다고 표시
				printf("%d ", i);
				queue[rear++] = i; // 큐에 i를 삽입하고 후단을 1 증가시킴
			}
		}
	}
}

int main()
{
	int start; // 시작 정점을 나타내는 변수
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
	BFS(start); // BFS 시작!

	return 0;
}

