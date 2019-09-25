#include <queue>
#include <iostream>
int bfs(int flag, char input[][100]);
using namespace std;

int n;
queue<pair<int, int>> q;
int _move[4][2] = { {-1,0},{0,1},{1,0},{0, -1} };


int bfs(int flag, char input[][100]) {
	bool visited[100][100] = { false, };
	int ret = 0;
	int now_x = 0, now_y = 0, next_x, next_y;
	char now_char;
	int i, j, k;
	visited[0][0] = true;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (visited[i][j] == true) {
				continue;
			}
			ret++;
			if (q.empty()) q.push(make_pair(i,j));
			while (!q.empty()) {
				
				now_x = q.front().first;
				now_y = q.front().second;
				now_char = input[now_x][now_y];

				q.pop();
				
				for (k = 0; k < 4; k++) {
					next_x = now_x + _move[k][0];
					next_y = now_y + _move[k][1];
				
				
						if (((flag == 1 && ((input[next_x][next_y] == 'R' && now_char == 'G') || (input[next_x][next_y] == 'G' && now_char == 'R'))) || input[next_x][next_y] == now_char)
							&& next_x >= 0 && next_x < n && next_y >= 0 && next_y < n && visited[next_x][next_y] == false) {

							visited[next_x][next_y] = true;
							q.push(make_pair(next_x, next_y));
						}

				}
				
			}
		}
	}
	return ret;
}

int main() {
	int i, j;
	cin >> n;
	char input[100][100];

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> input[i][j];
		}
	}

	q.push(make_pair(0, 0));
	cout << bfs(0, input) << " " << bfs(1, input);
	return 0;
}