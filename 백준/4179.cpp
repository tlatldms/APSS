#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int R, C;

pair<int, int> start;
vector<pair<int, int>> fires;
queue<vector<int>> fireQ;
queue<vector<int>> q;

//vector<vector<bool>> visited;
//vector<vector<bool>> fire;
//vector<vector<char>> input;

bool visited[1003][1003];
bool fire[1003][1003];
char input[1003][1003];

 //x,y,time

int dxy[4][2] = { {-1,0}, {1,0}, {0,-1},{0,1} };

int sol() {

	q.push({ start.first, start.second, 0 });
	visited[start.first][start.second] = true;
	int now_x, now_y, next_x, next_y, time, i, f_x, f_y, nf_x, nf_y, nowfire_time, checking=0;
	
	for (i = 0; i < fires.size(); i++) {
		fireQ.push({ fires[i].first, fires[i].second, 0 });
		fire[fires[i].first][fires[i].second] = true;
	}

	while (!q.empty()) {
		//불 먼저
		//cout << "checking: " << checking << endl;
		while (!fireQ.empty()) {
			f_x = fireQ.front()[0];
			f_y = fireQ.front()[1];
			nowfire_time = fireQ.front()[2];
			//cout << "f_x: " << f_x << ", f_y: " << f_y << endl;
			if (nowfire_time != checking) break;
			fireQ.pop();

			for (i = 0; i < 4; i++) {

				nf_x = f_x + dxy[i][0];
				nf_y = f_y + dxy[i][1];

				if (nf_x < 0 || nf_x >= R || nf_y < 0 || nf_y >= C) continue;
				if (input[nf_x][nf_y] != '#' && !fire[nf_x][nf_y]) {
					fireQ.push({ nf_x,nf_y, nowfire_time + 1 });
					fire[nf_x][nf_y] = true;
				}
			}
		}

		//그다음 사람이동
		while (!q.empty()) {
			now_x = q.front()[0];
			now_y = q.front()[1];
			time = q.front()[2];
			//cout << "now_x: " << now_x << ", now_y: " << now_y << ", now_time: " << time << endl;

			if (time != checking) break;
			q.pop();

			
			if (now_x == 0 || now_x == R - 1 || now_y == 0 || now_y == C - 1) {
				return time + 1;
			}

			for (i = 0; i < 4; i++) {
				next_x = now_x + dxy[i][0];
				next_y = now_y + dxy[i][1];
				if (next_x < 0 || next_x >= R || next_y < 0 || next_y >= C) continue;
				if (input[next_x][next_y] != '#' && !visited[next_x][next_y] &&
					!fire[next_x][next_y]) {
					q.push({ next_x, next_y, time + 1 });
					visited[next_x][next_y] = true;
				}
			}
		}
		checking++;
	}
	return -9;
}

int main() {
	cin >> R >> C;
	int i, j;

	vector<char> tmp(C);
	for (i = 0; i < R; i++) {
		cin >> input[i];
		for (j = 0; j < C; j++) {
			if (input[i][j] == 'J') {
				start = make_pair(i, j);
			}
			else if (input[i][j] == 'F') {
				fires.push_back(make_pair(i, j));
			}
		}
	}

	int answer = sol();
	if (answer == -9) cout << "IMPOSSIBLE";
	else cout << answer;

	return 0;
}