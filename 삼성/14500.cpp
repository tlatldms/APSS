#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stdio.h>

using namespace std;
int N, M, max_sum = -1, next_x, next_y;
int input[501][501];
bool visited[501][501];
int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };

int block[4][4][2] = { {{0,0}, {0,1}, {0,2},{1,1}},
{{0,1}, {1,0},{1,1}, {1,2}},
{{0,0},{1,0}, {1,1},{2,0}},
{{0,0}, {1,0}, {1,-1}, {2,0}} };


void dfs(int now_x, int now_y, int cnt, int sum) {
	
	if (cnt == 3) {
		//cout << "now_x: " << now_x << ", now_y: " << now_y << ", sum: " << sum << endl;
		max_sum = max(max_sum, sum);
		return;
	}
	visited[now_x][now_y] = true;
	for (int i = 0; i < 4; i++) {
		next_x = now_x + dir[i][0];
		next_y = now_y + dir[i][1];
		
		if (next_x >= 0 && next_x < N &&
			next_y >= 0 && next_y < M &&
			!visited[next_x][next_y])
			dfs(next_x, next_y, cnt+1, sum+ input[next_x][next_y]);
		
	}
	visited[now_x][now_y] = false;
}

void one() {
	int i, j, a,b, tmp_sum;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			

			for (a = 0; a < 4; a++) {
				tmp_sum = 0;
				for (b = 0; b < 4; b++) {
					next_x = i + block[a][b][0];
					next_y = j + block[a][b][1];

					if (next_x >= 0 && next_x < N &&
						next_y >= 0 && next_y < M)
						tmp_sum += input[next_x][next_y];
				}
				//cout << "tmp_sum: " << tmp_sum;
				max_sum = max(max_sum, tmp_sum);
			}
			
		}
	}
}

int main() {
	int i, j;
	cin >> N >> M;

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) cin >> input[i][j];
	}
	
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			dfs(i, j, 0, input[i][j]);
			
		}
	}
	
	//dfs(0, 4, 0, input[0][4]);
	one();
	cout << max_sum;

	return 0;
}