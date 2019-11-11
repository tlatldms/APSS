#include <iostream>

using namespace std;

int N, M, r, c ,d, cnt=0;

int dxy[4][2] = {{0,-1}, {-1,0}, {0,1}, {1,0}};
int input[51][51];
bool visited[51][51];

void dfs(int now_x, int now_y, int dir, int will_clear) {
	//cout << "now x:" << now_x << ", now_y: " << now_y << ",dir: "<<dir << endl;
	if (will_clear && !visited[now_x][now_y] && !input[now_x][now_y]) {
		visited[now_x][now_y] = 1;
		cnt++;
	}
	int next_x = now_x + dxy[dir][0];
	int next_y = now_y + dxy[dir][1];
	int next_dir = ((4 + dir) - 1) % 4;
	//cout << "next x: " << next_x << ", next y:" << next_y << ", next dir:" << next_dir << endl;
	int flag = 0;
	for (int i = 0; i < 4; i++) {
		int tmp_x = now_x + dxy[i][0];
		int tmp_y = now_y + dxy[i][1];
		if (!visited[tmp_x][tmp_y] && !input[tmp_x][tmp_y]) {//가능한거 남은경우
			//cout << "flag = 1" << endl;
			flag = 1; break;
		}
	}

	if (flag == 0) { //4방향 모두 갈 수 없을 때
		//cout << "flag == 0" << endl;
		int back_x = now_x + dxy[(dir + 3) % 4][0];
		int back_y = now_y + dxy[(dir + 3) % 4][1];
		if (input[back_x][back_y]) //뒤가 벽이면
			return;
		else dfs(back_x, back_y, dir, 0);
	}
	else {
		if (visited[next_x][next_y] || input[next_x][next_y]) { // b
			dfs(now_x, now_y, next_dir, 0);
		}
		else { // a
			dfs(next_x, next_y, next_dir, 1);
		}
	}

	
}

int main() {
	cin >> N >> M >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> input[i][j];
	}
	dfs(r, c, d, 1);
	cout << cnt;
	return 0;
}