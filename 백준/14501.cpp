#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int,int>> arr;
vector<int> dp (17);

int N;
int main() {
	cin >> N;
	int a, b;
	arr.push_back({ 0,0 });
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		arr.push_back({ a,b });
	}


	for (int i = 1; i <= N; i++) {
		if (i + arr[i].first - 1 <= N) {
			dp[i + arr[i].first - 1] = max(dp[i-1] + arr[i].second, dp[i + arr[i].first - 1]);
			for (int j = i + arr[i].first; j <= N; j++) {
				dp[j] = max(dp[j], dp[i + arr[i].first - 1]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << "i: " << i << ", dp: " << dp[i] << endl;
	}
	
	cout << dp[N];
	return 0;
}