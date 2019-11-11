#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int n, m, house = 0, chicken = 0, mi = 99999999;
int input[51][51];

vector<pair<int, int>> chicken_pos;


int dxy[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
void bfs(vector<int> now_c) {
	bool visit[51][51] = { 0, };
	queue<vector<int>> q;
	int tmp[51][51];
	int t_house = house;
	int ret = 0;
	std::copy(&input[0][0], &input[0][0] + 51*51, &tmp[0][0]);

	for (int i = 0; i < now_c.size(); i++) {
		q.push({ chicken_pos[now_c[i]].first, chicken_pos[now_c[i]].second, 0 });
		visit[chicken_pos[now_c[i]].first][chicken_pos[now_c[i]].second] = true;
	} //처음에 다 넣고

	while (!q.empty()) {
		int now_x = q.front()[0], now_y = q.front()[1], now_cnt = q.front()[2];
		q.pop();
		//cout << "now_x: " << now_x << "now_y: " << now_y << "now_cnt: " << now_cnt << endl;
		if (tmp[now_x][now_y] == 1) {
			t_house--;
			//cout << " here x y: " << now_x << ", " << now_y << endl;
			ret += now_cnt;
		}
		if (!t_house) break;
		for (int i = 0; i < 4; i++) {
			int next_x = now_x + dxy[i][0];
			int next_y = now_y + dxy[i][1];
			if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n ) continue;
			if (visit[next_x][next_y]) continue;
			visit[next_x][next_y] = true;
			q.push({ next_x, next_y, now_cnt + 1 });
		}
	}
	mi = min(mi, ret);
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> input[i][j];
			if (input[i][j] == 1) house++;
			else if (input[i][j] == 2) chicken_pos.push_back({ i,j });
		}
	}


	vector<int> t;
	for (int k = 0; k < chicken_pos.size() - m; k++) {
		t.push_back(0);
	}
	for (int k = 0; k < m; k++) {
		t.push_back(1);
	}

	do {
		vector<int> now_c;
		for (int k = 0; k < chicken_pos.size(); k++) {
			if (t[k]) now_c.push_back(k);
		}
		bfs(now_c);
	} while (next_permutation(t.begin(), t.end()));

	cout << mi;
	return 0;
}