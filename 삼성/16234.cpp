#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

bool visit[51][51];
int board[51][51];
int dxy[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
int N, L, R, coun;
int v[51][51];

void printt() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << v[i][j];
		}
		cout << "\n";
	}
}
void bfs() {
	int flag=0;
	do {
		flag = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visit[i][j]) continue;
				queue<vector<int>> q;
				q.push({ i,j });
				visit[i][j] = true;
				vector<pair<int, int>> t;
				int sum = 0;
				while (!q.empty()) {
					int x = q.front()[0];
					int y = q.front()[1];
					q.pop();
					//cout << v[x][y] << endl;
					sum += v[x][y];
					t.push_back({ x,y });
					for (int k = 0; k < 4; k++) {
						int next_x = x + dxy[k][0];
						int next_y = y + dxy[k][1];

						if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= N) continue;
						if (visit[next_x][next_y]) continue;
						int cha = abs(v[x][y] - v[next_x][next_y]);

						if (cha >= L && cha <= R) {
							visit[next_x][next_y] = true;
							q.push({ next_x, next_y });
						}

					}
				}
				if (t.size() >= 2) flag = 1;
				for (auto a : t) {
					v[a.first][a.second] = sum / t.size();
				}
				
			}
			
		}
		if (flag == 1) coun++;
		//printt();
		memset(visit, 0, sizeof(visit));
	} while (flag == 1);

}

int main() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) cin >> v[i][j];
	
	bfs();
	
	cout <<coun;
	return 0;
}