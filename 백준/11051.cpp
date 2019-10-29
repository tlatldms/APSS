#include <iostream>

using namespace std;

int N, K;

long long dp[1002][1002];

long long fun() {
	int i, j;

	for (i = 1; i <= N; i++) {
		dp[i][1] = 1;
		dp[i][i+1] = 1;
	}

	for (i = 2; i <= N; i++) {
		for (j=2; j <= i; j++)
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
	}


	return dp[N][K+1];
}
int main() {
	cin >> N >> K;
	cout << fun();
	return 0;
}