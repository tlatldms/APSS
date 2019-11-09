#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
int N;

int dp[1000002];

void dp_fun() {

	for (int i = N; i > 0; i--) {
		if (i % 3 == 0) {
			dp[i / 3] = min(dp[i / 3], dp[i] + 1);
		}
		else if (i % 2 == 0) {
			dp[i / 2] = min(dp[i / 2], dp[i] + 1);
		}
		dp[i - 1] = min(dp[i-1], dp[i] + 1);

	}

}

int main() {
	cin >> N;
	memset(dp, 9999999, sizeof(dp));
	dp[N] = 0;
	dp_fun();
	cout << dp[1];
	return 0;
}