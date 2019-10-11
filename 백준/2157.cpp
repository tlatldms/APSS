#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N, M, K;
int input[301][301];
int dp[301][301];

int sol() {
	int i, j, l, m = -1;
	for (i = 1; i <= N-1; i++) {
		for (j = 1; j <= M-1; j++) {
			
			//현재 번호에서 갈수있는 경로들에대해
			//현재 보고있는 횟수 + 1에다가 업데이트
			for (l = i + 1; l <= N; l++) {
				if (dp[i][j] && input[i][l]) {
					cout << "dp[i][j]: " << dp[i][j] << endl;
					dp[l][j + 1] = max(dp[l][j+1], dp[i][j] + input[i][l]);
					cout << "i: " << i << ", j: " << j << ", l: " << l << ", dp[l][j + 1]: " << dp[l][j + 1] << endl;
				}
			}
		}
	}

	for (i = 1; i <= M-1; i++) {
		m = max(m, dp[N][i]);
		cout << "max! i: " << i << ", m : " << m << endl;
	}
	return m; 
}

int main() {
	cin >> N >> M >> K;
	int i, a, b, c;
	for (i = 0; i < K; i++) {
		cin >> a >> b >> c;
		if (a < b) {
			input[a][b] = max(input[a][b], c);
			if (a == 1) dp[b][1] = max(dp[b][1], c);
		}
	}

	cout << sol();
	return 0;
}