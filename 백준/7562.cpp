#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int _move[8][2] = { {-2,-1},{-2,1}, {-1,-2}, {-1,2},{1,2}, {1, -2}, {2,1}, {2,-1} };
bool visited[301][301] = { false, };
queue < pair<pair<int, int>, int>> q;


long long int BFS(int l, int now_x, int now_y, int to_x, int to_y) {

	int i, j, nx, ny, next_x, next_y;
	long long int cnt = -1;
	q.push(make_pair(make_pair(now_x, now_y), cnt));
	while (!q.empty()) {
		nx = q.front().first.first;
		ny = q.front().first.second;
		cnt = q.front().second + 1;

	
		q.pop();

		if (nx == to_x && ny == to_y) {
			break;
		}
		for (i = 0; i < 8; i++) {
			next_x = nx + _move[i][0];
			next_y = ny + _move[i][1];
			
			if (next_x >= 0 && next_y >= 0 &&
				next_x < l && next_y < l && !visited[next_x][next_y]) {
				q.push(make_pair(make_pair(next_x, next_y), cnt));
				visited[next_x][next_y] = true;
			}
		}
		
	}
	return cnt;

}

int main() {
	int i, n, l, now_x, now_y, to_x, to_y;
	cin >> n;
	vector<long long int> answer(n);
	for (i = 0; i < n; i++) {
		cin >> l >> now_x >> now_y >> to_x >> to_y;
		answer[i] = BFS(l, now_x, now_y, to_x, to_y);
	}

	for (i = 0; i < n; i++) {
		cout << answer[i] << endl;
	}
	return 0;

}