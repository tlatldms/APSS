#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M, PR, PC;
char input[502][502];
bool visited[502][502][4];
char li[4] = { 'U','R','D', 'L' };

int voyager(char dir) {
	int now_x=PR-1, now_y=PC-1, cnt=0, i;
	char now_dir = dir;

	while (1) {
		if (now_x < 0 || now_x >= N || now_y < 0 || now_y >= M ||
			(input[now_x][now_y] == 'C')) {
			return cnt;
		}

		for (i = 0; i < 4; i++) {
			if (now_dir == li[i]) {
				if (visited[now_x][now_y][i] == true) return -1;
				else visited[now_x][now_y][i] = true;
				break;
			}
		}

		if (input[now_x][now_y] == '.') {
			if (now_dir == 'U') {
				now_x -= 1;
			}
			else if (now_dir == 'D') {
				now_x += 1;
			}
			else if (now_dir == 'R') {
				now_y += 1;
			}
			else if (now_dir == 'L') {
				now_y -= 1;
			}
		}


		else if (input[now_x][now_y] == '/') {
			if (now_dir == 'U') {
				now_y += 1;
				now_dir = 'R';
			}
			else if (now_dir == 'R') {
				now_x -= 1;
				now_dir = 'U';
			}
			else if (now_dir == 'D') {
				now_y -= 1;
				now_dir = 'L';
			}
			else if (now_dir == 'L') {
				now_x += 1;
				now_dir = 'D';
			}
		}

		else if (input[now_x][now_y] == '\\' ) {
			if (now_dir == 'U') {
				now_y -= 1;
					now_dir = 'L';
			}
			else if (now_dir == 'R') {
				now_x += 1;
					now_dir = 'D';
			}
			else if (now_dir == 'D') {
				now_y += 1;
					now_dir = 'R';
			}
			else if (now_dir == 'L') {
				now_x -= 1;
				now_dir = 'U';
			}
		}
		cnt++;
	}

	return -99;
}
int main() {
	cin >> N >> M;
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) cin >> input[i][j];
	}
	cin >> PR >> PC;
	int ma = -3, nw, flag=0;
	
	int li_num[4];
	for (i = 0; i < 4; i++) {
		if ((nw=voyager(li[i])) == -1) {
			cout << li[i] << endl;
			cout << "Voyager";
			flag = 1;
			break;
		}
		li_num[i] = nw;
		ma = max(ma, nw);
	}
	if (!flag) {
		for (i = 0; i < 4; i++) {
			if (ma == li_num[i]) {
				cout << li[i] << endl;
				cout << ma;
				break;
			}
		}
	}
	return 0;
}