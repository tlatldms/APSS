#include <iostream>
#include <queue>

using namespace std;

int dxy[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
int N, M;
char input[11][11];
bool visited[11][11][11][11];
pair<int, int> hole;

vector<int> _move(int dx, int dy, pair<int, int> red, pair<int, int> blue) {
	int red_first; //1이면 red 먼저, 0이면 blue먼저
	int ret;
	if (red.first == blue.first) { //가로선상에 같으면
		if (dx == 0 && dy == 1) { //오른쪽으로 기울임
			red_first = (red.second > blue.second); //red가 더 크면 1, blue가 더 크면 0
		}
		else if (dx == 0 && dy == -1) { //왼쪽으로 기울임
			red_first = (red.second < blue.second);
		}
		else red_first = 1;
	}
	else if (red.second == blue.second) { //세로선상에 같으면
		if (dx == 1 && dy == 0) {// 아래로 기울임
			red_first = (red.first > blue.first);
		}
		else if (dx == -1 && dy == 0) { //위로 기울임
			red_first = (red.first < blue.first);
		}
		else red_first = 1;
	}
	else {
		red_first = 1;
	}
	
	int rx = red.first, ry = red.second, bx = blue.first, by = blue.second, flag=0;
	if (red_first) {
		while (1) {
			rx += dx;
			ry += dy;
			if (hole.first == rx && hole.second == ry) flag = 1;
			if (input[rx][ry] == '#') break;
		}
		rx -= dx;
		ry -= dy;
		while (1) {
			bx += dx;
			by += dy;
			if (hole.first == bx && hole.second == by) {
				flag = 2;
				break;
			}
			if ((bx == rx && by == ry) || input[bx][by] == '#') break;
		}
		bx -= dx;
		by -= dy;
	}
	else {
		while (1) {
			bx += dx;
			by += dy;
			if (hole.first == bx && hole.second == by) {
				flag = 2;
				break;
			}
			if (input[bx][by] == '#') break;
		}
		bx -= dx;
		by -= dy;

		while (flag != 2) {
			rx += dx;
			ry += dy;
			if (hole.first == rx && hole.second == ry && flag != 2) {
				//cout << "골인" << endl;
				flag = 1;
				break;
			}
			if ((bx == rx && by == ry) || input[rx][ry] == '#') break;
		}
		rx -= dx;
		ry -= dy;
	}

	if (flag == 2) ret = 2;
	else if (flag == 1) ret = 1;
	else if (flag == 0) ret = 0;
	return { rx, ry, bx, by, ret}; //5번째가 0이면 그냥 이동, 1이면 red만 골인, 2면 blue가 들어가버림

}

int bfs(pair<int, int> red, pair<int, int> blue) {
	queue<vector<int>> q;
	int rx, ry, bx, by, rnx, rny, bnx, bny, cnt, c, flag, res;
	q.push({ red.first, red.second, blue.first, blue.second, 0 });
	visited[red.first][red.second][blue.first][blue.second] = true;
	while (!q.empty()) {
		vector<int> now = q.front();
		q.pop();

		rx = now[0];
		ry = now[1];
		bx = now[2];
		by = now[3];
		cnt = now[4];
		//cout << "rx: " << rx << ", ry: " << ry << ", bx: " << bx << ", by: " << by << ", cnt:" << cnt << endl;

		if (cnt > 9) return -1;
		

		for (int i = 0; i < 4; i++) {
			//int tmprx = rx + dxy[i][0], tmpry = ry + dxy[i][1];
			//int tmpbx = bx + dxy[i][0], tmpby = by + dxy[i][1];
			//if (input[tmprx][tmpry] == '#' && input[tmpbx][tmpby] == '#') continue;

			//cout << "after visited tmprx:" << tmprx << ", tmpry:" << tmpry << endl;
			vector<int> rb_info = _move(dxy[i][0], dxy[i][1], make_pair(rx, ry), make_pair(bx, by));
			//rnx = rx; rny = ry; c = 0; bnx = bx; bny = by; flag = 0; 
			rnx = rb_info[0], rny = rb_info[1], bnx = rb_info[2], bny = rb_info[3], res = rb_info[4];
			//cout << "rnx: " << rnx << ", rny: " << rny << ", bnx: " << bnx << ", bny: " << bny << ", res:"<<res<<endl;
			


			//if (res == 1) cout << "1리턴" << endl;
			if (res == 1) return cnt + 1;
			else if (res == 2) continue;

			if (visited[rnx][rny][bnx][bny]) {
				//cout << "visited rnx:" << rnx << ", rny:" << rny << "bnx:" << bnx << ", bny:" << bny << endl;
				continue;
			}
			else if (res == 0) {
				//cout << "pushing rnx:" << rnx << ", rny:" << rny << "bnx:" << bnx << ", bny:" << bny << endl;
				q.push({ rnx,rny, bnx, bny, cnt + 1 });
				visited[rnx][rny][bnx][bny] = true;
			}
		}
	}

	return -1;
}

int main() {
	cin >> N >> M;
	pair<int, int> red, blue;
	int i,j;
	char a;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> a;
			if (a == 'O')
			{
				hole = make_pair(i, j);
				input[i][j] = '.';
			}
			else if (a == 'R')
			{
				red = make_pair(i, j);
				input[i][j] = '.';
			}
			else if (a == 'B')
			{
				blue = make_pair(i, j);
				input[i][j] = '.';
			}
			else input[i][j] = a;
		}
	}
	cout << bfs(red, blue);
	return 0;
}