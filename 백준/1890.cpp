#include <iostream>
#include <vector>

using namespace std;
int input[101][101];
int N;
long long int dp[101][101];

void sol() {
	int i, j, d, r;
	dp[0][0] = 1;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (!input[i][j]) break;
			if ((d = (j + input[i][j])) <N)
				dp[i][d] += dp[i][j];
			if ((r = (i + input[i][j])) < N)
				dp[r][j] += dp[i][j];
		}
	}
}

int main() {
	cin >> N;
	int i,j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) cin >> input[i][j];
	}
	sol();

	cout << dp[N - 1][N - 1];
	return 0;
}