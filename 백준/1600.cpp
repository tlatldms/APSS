#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int hor[8][2] = { {-2,-1}, {-1,-2}, {1,-2}, {2,-1}, {-2,1}, {-1,2},{1,2}, {2,1} };
int mon[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
int K, W, H;
int input[201][201];
bool visited[201][201][32];
queue<vector<int>> q;

int bfs() {
	q.push({ 0,0,K,0 });

	int now_x, now_y, now_k, cnt, i, next_x, next_y;
	for (i = 0; i < 32; i++) visited[0][0][i] = true;
	while (!q.empty()) {
		now_x = q.front()[0];
		now_y = q.front()[1];
		now_k = q.front()[2];
		cnt = q.front()[3];
		q.pop();
		//printf("now_x: %d, now_y: %d, now_k: %d, now cnt: %d\n",
			//now_x, now_y, now_k, cnt);
		if (now_x == H - 1 && now_y == W - 1) {
			return cnt;
		}
		//cout << "SS";
		if (now_k > 0) {
			for (i = 0; i < 8; i++) {
				next_x = now_x + hor[i][0];
				next_y = now_y + hor[i][1];

				if (next_x >= 0 && next_x < H &&
					next_y >= 0 && next_y < W &&
					!visited[next_x][next_y][now_k-1] && input[next_x][next_y] != 1)
				{
					//cout << "horse" << endl;
					q.push({ next_x, next_y, now_k - 1, cnt + 1 });
					visited[next_x][next_y][now_k-1] = true;
				}
			}
		}

		for (i = 0; i < 4; i++) {
			next_x = now_x + mon[i][0];
			next_y = now_y + mon[i][1];

			if (next_x >= 0 && next_x < H &&
				next_y >= 0 && next_y < W && !visited[next_x][next_y][now_k]
				&& input[next_x][next_y] != 1)
			{
				//cout << "monkey" << endl;
				q.push({ next_x, next_y, now_k, cnt + 1 });
				visited[next_x][next_y][now_k] = true;
			}
		}

		
		
	}
	return -1;
}

int main() {
	cin >> K >> W >> H;
	int i, j;
	for (i = 0; i < H; i++) {
		for (j = 0; j < W; j++) {
			cin >> input[i][j];
		}
	}
	cout << bfs();
	return 0;
}