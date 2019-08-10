#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, m, i, a, b;
	int taken[10] = { 0, };
	int areFriends[10][10] = { {0,} };
	scanf("%d", &n);
	scanf("%d", &m);

	for (i = 0; i < m; i++) {
		scanf("%d", &a);
		scanf("%d", &b);
		areFriends[a][b] = 1;
		areFriends[b][a] = 1;
	}
	printf("%d", countPairings(n, taken, areFriends));

	return 0;
}

int countPairings(int n, int taken[], int areFriends[][10]) {
	int firstFree = -1,i;
	for (i = 0; i < n; i++) {
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}

	if (firstFree == -1) return 1;
	int ret = 0;
	for (int pairWith = firstFree + 1; pairWith < n; ++pairWith) {
		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = 1;
			ret += countPairings(n, taken, areFriends);
			taken[firstFree] = taken[pairWith] = 0;
		}
	}

	return ret;
}

