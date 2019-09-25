#include <iostream>
#include <queue>
using namespace std;
bool visited[251][251] = {false, };
int R, C;
char input[251][251];
int k_arr[90000] = { 0, };
int v_arr[90000] = { 0, };
int cnt=1;
int ret_k = 0, ret_v = 0;
void bfs() {
	int i, j, k;
	queue<pair<int, int>> q;
	
	char now_char;
	int now_x=0, now_y=0, next_x, next_y;
	int move[4][2] = { {-1,0},{0, 1}, {1,0}, {0,-1} };

	for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) {
			if (visited[i][j] == true || input[i][j] =='#') continue;
			cnt++;
			q.push(make_pair(i, j));
			visited[i][j] = true;
			while (!q.empty()) {
				now_x = q.front().first;
				now_y = q.front().second;
				now_char = input[now_x][now_y];
				q.pop();

				if (now_char == 'k') k_arr[cnt]++;
				else if (now_char == 'v') v_arr[cnt]++;


				for (k = 0; k < 4; k++) {
					next_x = now_x + move[k][0];
					next_y = now_y + move[k][1];
					if (
						next_x >= 0 && next_x < R && next_y>=0 && next_y<C &&
						(input[next_x][next_y] == '.' || input[next_x][next_y] == 'k' || input[next_x][next_y] == 'v')
						&& visited[next_x][next_y]==false
						
						) {
						q.push(make_pair(next_x, next_y));
						visited[next_x][next_y] = true;
					}
				}
			}
		}
	}
}


int main() {
	int i, j;
	cin >> R >> C;

	for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) {
			cin >> input[i][j];
		}
	}

	bfs();
	for (i = 0; i <= cnt+1; i++) {
		if (k_arr[i] > v_arr[i]) ret_k += k_arr[i];
		else ret_v += v_arr[i];
	}

	cout << ret_k << " " << ret_v;
	return 0;
}