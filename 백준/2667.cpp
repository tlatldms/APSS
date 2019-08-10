#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> answer;
int _move[4][2]= { {-1,0}, {1,0}, {0,1}, {0,-1} };


void BFS(int n, vector<vector<int>> input) {
	queue<pair<int, int>> q;
	bool visited[25][25] = { false, };
	int i, j, k, now_x, now_y, next_x, next_y, cnt;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (visited[i][j] || input[i][j] == 0) {
				continue;
			}
			cnt = 0;
			q.push(make_pair(i, j));
			visited[i][j] = 1;
			while (!q.empty()) {
				now_x = q.front().first;
				now_y = q.front().second;
				cnt++;
				//cout << "now_x: " << now_x << "now_y: " << now_y << "cnt :" << cnt;
				q.pop();

				for (k = 0; k < 4; k++) {
					next_x = now_x + _move[k][0];
					next_y = now_y + _move[k][1];
					if (next_x >= 0 && next_y >= 0 && next_x < n && next_y < n && !visited[next_x][next_y]) {
						if (input[next_x][next_y]) q.push(make_pair(next_x, next_y));
						visited[next_x][next_y] = true;
					}
				}
			}

			answer.push_back(cnt);
			//cout << "push";
		}
	}
}

int main() {
	int i, j, n;
	cin >> n;
	char str[25];
	vector <vector<int> > input(n, vector<int>(n));
	for (i = 0; i < n; i++) {
		cin >> str;
		for (j = 0; j < n; j++) {
			if (str[j] == '1') input[i][j] = 1;
			else input[i][j] = 0;
		}
	}
	BFS(n, input);
	cout << answer.size()<<endl;
	sort(answer.begin(), answer.end());
	for (auto item : answer) cout <<item << endl;

	return 0;
}