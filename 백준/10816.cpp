#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int N, M, cnt = 0;
vector<int> cards;


int sol(int target) {
	int low = lower_bound(cards.begin(), cards.end(), target) - cards.begin();
	if (cards[low] != target) {
		return 0;
	}

	int up = upper_bound(cards.begin(), cards.end(), target) - cards.begin();
	return up - low;
}

int main() {
	int i, a;
	cin >> N;
	cards.resize(N);
	for (i = 0; i < N; i++) {
		//cin >> cards[i];
		scanf("%d", &cards[i]);
	}
	sort(cards.begin(), cards.end());
	cin >> M;
	for (i = 0; i < M; i++) {
		//cin >> a;
		//입력이 많으면 무조건....
		scanf("%d", &a);
		cout << sol(a) << " ";
	}

	return 0;
}
