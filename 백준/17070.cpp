#include <iostream>
#include <vector>

using namespace std;

int N, cnt;
int board[18][18];
void dfs(int now_dir, int nr, int nc) {
	if (now_dir == 1 && nr == N && nc + 1 == N) {
		cnt++;
		return;
	}
	else if (now_dir == 2 && nr + 1 == N && nc == N) {
		cnt++;
		return;
	}
	else if (now_dir == 3 && nr + 1 == N && nc + 1 == N) {
		cnt++;
		return;
	}

	if (now_dir == 1 && nc+2 <= N && !board[nr][nc + 2]) {
		dfs(1, nr, nc + 1);
		if (nr + 1 <= N && !board[nr+1][nc+1] && !board[nr+1][nc+2]) dfs(3, nr, nc + 1);
	}
	else if (now_dir == 2 && nr+2 <= N && !board[nr+2][nc]) {
		dfs(2, nr + 1, nc);
		if (nc + 1 <= N && !board[nr + 1][nc + 1] && !board[nr + 2][nc + 1]) dfs(3, nr + 1, nc);
	}
	else if (now_dir == 3) {
		bool a = false, b = false;
		if (nr + 1 <= N && nc + 2 <= N && !board[nr + 1][nc + 2]) {
			dfs(1, nr + 1, nc + 1);
			a = true;
		}
		if (nr + 2 <= N && nc + 1 <= N && !board[nr + 2][nc + 1]) {
			dfs(2, nr + 1, nc + 1);
			b = true;
		}
		if ((a && b) && !board[nr + 2][nc + 2]) dfs(3, nr + 1, nc + 1);
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
		}
	}
	dfs(1, 1, 1);
	cout << cnt;
	return 0;
}