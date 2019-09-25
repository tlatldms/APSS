#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "common.h"
#include "stack.h"

void printPicked(int n);
void pick(int n,int m, int toPick);

int main() {
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);

	pick(n, m, m);
	return 0;
}

void pick(int n, int m, int toPick) {
	if (toPick == 0) {
		printPicked(m);
		return;
	}
	int smallest = s_is_empty() ? 0 : stack[top-1]+1;
	for (int next = smallest; next < n; next++) {
		s_push(next);
		pick(n, m, toPick - 1);
		s_pop();
	}
}

void printPicked(int m) {
	for (int i = 0; i < m; i++) 
		printf("%d ", stack[i]);
	printf("\n");
}