#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int cover(int** board, int n, int m);
int set(int** board, int y, int x, int type, int delta, int n, int m);

int coverType[4][3][2] = {
	{ { 0,0 },{ 0,1 },{ 1,0 } },
{ { 0,0 },{ 0,1 },{ 1,1 } },
{ { 0,0 },{ 1,1 },{ 1,0 } },
{ { 0,0 },{ 1,-1 },{ 1,0 } }
};

int main() {
	int n, m, i,j,cnt=0;
	char a = 2;
	scanf("%d", &n);
	scanf("%d", &m);

	int** board = (int**)malloc(sizeof(int*)*n);
	for (i = 0; i < n; i++)
		board[i] = (int *)malloc(sizeof(int)*m);
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%c", &a);
			if (a == 32 || a == 10) scanf("%c", &a);
			if (a == '#') board[i][j] = 1;
			else {
				board[i][j] = 0;
				++cnt;
			}
		}
	}
	if (cnt % 3 != 0) return 0;
	printf("%d",cover(board, n, m));

	for (i = 0; i < n; i++) {
		free(board[i]);
	}
	free(board);
}

int set(int** board, int y, int x, int type, int delta, int n, int m) {
	int ok = 1;
	for (int i = 0; i < 3; i++) {
		int ny = y + coverType[type][i][0];
		int nx = x + coverType[type][i][1];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m)
			ok = 0;
		else if ((board[ny][nx] += delta) > 1)
		ok = 0;
	}
	return ok;
}

int cover(int** board,int n,int m) {
	int y = -1, x = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
			if (y != -1) break;
		}
	}

	if (y == -1) return 1;
	int ret = 0;
	for (int type = 0; type < 4; type++) {
		if (set(board, y, x, type, 1, n, m))
			ret += cover(board, n, m);
		set(board, y, x, type, -1, n, m);
	}
	return ret;
}


