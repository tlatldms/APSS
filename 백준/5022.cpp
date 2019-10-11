#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct St {
	int x, y;
	vector<pair<int, int>> history;
};
bool visited[101][101] = { false, };

int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
int n, m;
int A[2][2], B[2][2];


void bfs() {
	int now_x, now_y, next_x, next_y, i,j,cnt;
	queue<St> q;
	vector<pair<int, int>> hist;
	struct St first;
	first.x = A[0][0]; first.y = A[0][1]; first.history.push_back(make_pair(A[0][0], A[0][1]));
	q.push(first);

	while (!q.empty()) {

		now_x = q.front().x;
		now_y = q.front().y;
		hist = q.front().history;
		q.pop();
		if (now_x == A[1][0] && now_y == A[1][1]) break;
		for (i = 0; i < 4; i++) {
			next_x = now_x + dir[i][0];
			next_y = now_y + dir[i][1];
			
			if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m && !visited[next_x][next_y]) {
				struct St ne;
				vector<pair<int, int>> hists = hist.push_back(make_pair(1, 1));
				ne.x = next_x; ne.y = next_y, ne.history=hists;
				q.push(ne);
				visited[next_x][next_y] = true;
			}
		}
	}
}


int main() {
	int i, j, cnt = 0;
	cin >> n >> m;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) cin >> A[i][j];
	}
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) cin >> B[i][j];
	}


	bfs();
	return 0;
}