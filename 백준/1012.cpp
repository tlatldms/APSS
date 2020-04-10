#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dxy[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };

int T, N, M, K;

int main() {
	cin >> T;
	while (T--) {
		int cnt = 0;
		int board[51][51] = { 0, };
		bool visit[51][51] = { 0, };
		cin >> M >> N >> K;
		int x, y;
		for (int i = 0; i < K; i++) {
			cin >> x >> y;
			board[y][x] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] && !visit[i][j]) {
					queue<pair<int, int>> q;
					q.push({ i,j });
					while (!q.empty()) {
						int x = q.front().first;
						int y = q.front().second;
						q.pop();
						for (int p = 0; p < 4; p++) {
							int nx = x + dxy[p][0];
							int ny = y + dxy[p][1];
							if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
							if (visit[nx][ny]) continue;
							if (board[nx][ny]) {
								visit[nx][ny] = 1;
								q.push({ nx,ny });
							}
						}
					}
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	
	}

	return 0;
}