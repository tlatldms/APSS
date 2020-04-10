#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>

using namespace std;

int N, M, answer=-1;
int input[1002][1002];
bool visit[1002][1002][2];
int dxy[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };

struct Node {
	int x, y, cnt;
	bool broken = false;
};
void bfs() {
	queue<Node> q;
	Node first = { 1,1,1,false };
	visit[1][1][0] = true;
	q.push(first);
	while (!q.empty()) {
		Node now = q.front();
		//cout << "cnt: " << now.cnt <<", x: " << now.x << ", y: " << now.y << endl;
		q.pop();
		if (now.x == N && now.y == M) {
			answer = now.cnt;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nx = now.x + dxy[i][0];
			int ny = now.y + dxy[i][1];
			if (nx <= 0 || nx > N || ny <= 0 || ny > M) continue;
			
			if (!input[nx][ny]) {
				//visit[][][0]은 벽 안뚫었을 때. 
				if (!now.broken) {
					//벽 안뚫은거 겹침
					if (visit[nx][ny][0]) continue;
					visit[nx][ny][0] = true;
					
				}
				else { //벽 뚫었을 때
					if (visit[nx][ny][1]) continue;
					visit[nx][ny][1] = true;
				}
				q.push({ nx,ny,now.cnt + 1,now.broken });
				//벽 뚫은거 겹침
			}
			else { //벽이 있을 때
				if (now.broken) { //이미 부술 기회 씀
					continue;
				}
				else { //아직 부술 기회 있음
					visit[nx][ny][1] = true;
					q.push({ nx,ny, now.cnt+1, true });
				}
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) { 
			scanf("%1d", &input[i][j]);
		}
	}
	bfs();
	cout << answer;
	return 0;
}