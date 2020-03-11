#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

int N;
long long m=INT_MIN;
string str;

long long cal(char op, long long val1, long long val2) {
	if (op == '+') return val1 + val2;
	else if (op == '-') return val1 - val2;
	else if (op == '*') return val1 * val2;
}

void dfs(int idx, long long value, int depth) {
	//cout << "idx: " << idx << ", value: " << value << ", depth: " << depth << endl;
	if (idx == N-1) {
		m = max(m, cal(str[idx], value, str[idx + 1] - '0'));
		return;
	}
	else if (idx == N + 1) {
		m = max(m, value);
		return;
	}

	//°ýÈ£ O
	long long tmp = cal(str[idx + 2], str[idx + 1]-'0', str[idx + 3]-'0');
	if (idx+4 <= N+1) dfs(idx+4, cal(str[idx], value, tmp), depth+1);

	//°ýÈ£ X
	dfs(idx + 2, cal(str[idx], value, str[idx + 1] - '0'), depth+1);
}

int main() {
	cin >> N;
	cin >> str;
	str = "+" + str;
	
	dfs(0,0,0);
	if (N == 1) cout << str[1] - '0';
	else cout << m;
	
	return 0;
}