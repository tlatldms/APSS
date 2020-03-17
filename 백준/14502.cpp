#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int m=-1;
int N, M;
int board[9][9];


vector<pair<int, int>> pairs, twos;

int dxy[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };

void bfs(vector<pair<int, int>> walls) {
	queue<vector<int>> q;
	int copied_board[9][9] = { 0, };
	copy(&board[0][0], &board[0][0] + 9*9, &copied_board[0][0]);
	for (auto w : walls) {
		copied_board[w.first][w.second] = 1;
	}
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << copied_board[i][j];
		}
		cout << endl;
	}

	bool visit[9][9] = { 0, };
	int infected = 0;
	for (auto p : twos) q.push({ p.first, p.second });
	while (!q.empty()) {
		int x = q.front()[0], y = q.front()[1];
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dxy[i][0], ny = y + dxy[i][1];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (visit[nx][ny] || copied_board[nx][ny]==1) continue;
			if (copied_board[nx][ny] == 0) {
				visit[nx][ny] = 1;
				copied_board[nx][ny] = 2;
				q.push({ nx,ny });
				infected++;
			}
			
		}
	}
	m = max(m, (int)pairs.size() - infected);
}

void perm() {
	vector<int> tmp;
	
	for (int i = 0; i < pairs.size()-3; i++) {
		tmp.push_back(0);
	}
	for (int i = 0; i < 3; i++) {
		tmp.push_back(1);
	}

	do {
		vector<pair<int, int>> walls;
		for (int i = 0; i < tmp.size(); i++) {
			if (tmp[i]) {
				walls.push_back(pairs[i]);
			}
		}
		bfs(walls);

	} while (next_permutation(tmp.begin(), tmp.end()));

}

int main() {
	cin >> N >> M;
	int a;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> a;
			board[i][j] = a;
			if (a == 0) pairs.push_back({ i,j });
			else if (a == 2) twos.push_back({ i,j });
		}
	}
	perm();
	cout << m;
	return 0;
}