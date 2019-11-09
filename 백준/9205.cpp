#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

bool visited[101]; 
vector<pair<int, int>> market(102);
pair<int, int> fest;
queue<int> q;
int t, n, flag=0;

void bfs() {
	q.push(0);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (abs(market[now].first - fest.first) + abs(market[now].second - fest.second) <= 1000) {
			flag = 1;
			return;
		}

		for (int i = 1; i <= n; i++) {
			if (visited[i]) continue;
			if (abs(market[now].first - market[i].first) + abs(market[now].second - market[i].second) <= 1000) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

void dfs(int now_market) {
	visited[now_market] = true;
	//cout << "now_market: " << now_market << endl;
	if (abs(market[now_market].first - fest.first) +
		abs(market[now_market].second - fest.second) <= 1000) {
		flag = 1;
		return;
	}
	for (int i = 0; i <= n; i++) {
		if (!visited[i] &&
			(abs(market[now_market].first - market[i].first) +
				abs(market[now_market].second - market[i].second) <= 1000))
		{
			
			dfs(i);
		
		}
	}
	
}

int main() {
	cin >> t;
	int i,j;
	for (j = 0; j < t; j++) {
		cin >> n;
		cin >> market[0].first >> market[0].second;

		for (i = 1; i <= n; i++) {
			cin >> market[i].first >> market[i].second;
		}
		cin >> fest.first >> fest.second;


		dfs(0);
		//bfs();
		if (!flag) cout << "sad" << endl;
		else cout << "happy"<<endl;

		flag = 0;
		memset(visited, 0, sizeof(visited));
		market = vector < pair<int, int>>(102);
		while (!q.empty()) q.pop();
	}


	return 0;
}