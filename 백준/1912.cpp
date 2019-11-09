#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> input;
vector<int> dp;
int sol() {
	int i, m = input[0];
	for (i = 1; i < n; i++) {
		if (dp[i - 1] <= 0) dp[i] = input[i];
		else dp[i] = dp[i - 1] + input[i];
		m = max(m, dp[i]);
	}
	
	return m;
}

int main() {
	cin >> n;
	input.resize(n);
	dp.resize(n);
	int i;
	for (i = 0; i < n; i++) {
		scanf("%d", &input[i]);
	}

	dp[0] = input[0];

	cout << sol();
	return 0;
}