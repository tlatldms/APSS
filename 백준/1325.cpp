#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
vector<bool> visited;
vector<int> c;
vector<vector<int>> rel;


void sol(int start) {
	int now;
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while (!q.empty()) {
		
		now = q.front();
		//cout << "now: " << now << endl;
		q.pop();
		c[start]++;
		for (auto a : rel[now]) {
			if (!visited[a]) {
				//cout << "pushing " << a << endl;
				q.push(a);
				visited[a] = true;
			}
		}
	}
}

int main() {
	int i, a, b;
	cin >> N >> M;
	c.resize(N+2);
	rel.resize(N+2);

	//신뢰하는 컴 다 넣기
	for (i = 0; i < M; i++) {
		cin >> a >> b;
		rel[b].push_back(a);
	}

	for (i = 1; i <= N; i++) {
		visited = vector<bool> (N + 2);
		sol(i);
	}

	int st = *max_element(c.begin(), c.end());

	for (i = 1; i <= N; i++) {
		if (st == c[i]) cout << i << " ";
	}


	return 0;
}
