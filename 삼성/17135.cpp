#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string.h>

using namespace std;

int N, M, D;
int board[16][16];
vector<pair<int, int>> enemy_pos;
int dxy[3][2] = { {0,-1}, {-1,0}, {0,1} };
int answer;

void defense(vector<int> gungsu) {
	int nn = N;
	int tmp = 0;
	int new_board[16][16];
	memcpy(new_board, board, sizeof(board));
	while (nn--) {
		vector<queue<vector<int>>> qs (3);
		set<pair<int, int>> se;
		for (int i = 0; i < 3; i++) {
			qs[i].push({ nn, gungsu[i], 0 });
			int visit[16][16] = { 0, };
			while (!qs[i].empty()) {
				int x = qs[i].front()[0];
				int y = qs[i].front()[1];
				int cnt = qs[i].front()[2];
				qs[i].pop();
				if (cnt == D) break;
				if (new_board[x][y] == 1) {// 적군 만남
					se.insert({ x,y });
					break;
				}
				for (int k = 0; k < 3; k++) {
					int nx = x + dxy[k][0];
					int ny = y + dxy[k][1];
					if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
					if (visit[nx][ny]) continue;
					visit[nx][ny] = 1;
					qs[i].push({ nx,ny,cnt + 1 });
				}
			}
		}
		set<pair<int, int>>::iterator it;
		for (it = se.begin(); it != se.end(); ++it) {
			new_board[it->first][it->second] = 0;
			tmp++;
		}
	}
	answer = max(answer, tmp);
}

int main() {
	cin >> N >> M >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if ( board[i][j] == 1) {
				enemy_pos.push_back({ i,j });
			}
		}
	}
	vector<int> tmp;
	for (int i = 0; i < M - 3; i++) {
		tmp.push_back(0);
	}
	for (int i = 0; i < 3; i++) {
		tmp.push_back(1);
	}

	do {
		vector<int> gungsu;
		for (int i = 0; i < M; i++) {
			if (tmp[i] == 1) {
				gungsu.push_back(i);
			}
		}
		defense(gungsu);

	} while (next_permutation(tmp.begin(), tmp.end()));
	cout << answer;
	return 0;
}