#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
#include <set>

using namespace std;

int N, M;
int info[11][11];
int islands[11][11];
int dxy[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
int con[7][7];
int root[7];

int num_cnt = 0;
bool visit[11][11];


void dfs(int x, int y, int num) {
	visit[x][y] = true;
	islands[x][y] = num;
	for (int k = 0; k < 4; k++) {
		int nx = x + dxy[k][0];
		int ny = y + dxy[k][1];

		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
		if (info[nx][ny] && !visit[nx][ny])
			dfs(nx, ny, num);

	}
}

void check() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (islands[i][j]) { //숫자인걸 봤을때
				int now_num = islands[i][j];
				for (int k = 0; k < 4; k++) { //k: U R D L
					int nx = i + dxy[k][0];
					int ny = j + dxy[k][1];
					int cnt = 0;
					while (nx >= 0 && nx < N && ny >= 0 && ny < M) {
						if (islands[nx][ny]) {
							if (cnt >= 2 && islands[nx][ny] != now_num) {
								con[now_num][islands[nx][ny]] = min(con[now_num][islands[nx][ny]], cnt);
								//printf("start i,j: %d,%d here nx,ny: %d,%d w:::%d\n", i, j, nx, ny, con[now_num][islands[nx][ny]]);
							}
							break;
						}
						else {
							nx += dxy[k][0], ny += dxy[k][1], cnt++;
						}
					} 
				}
			}
		}
	}
	
}

void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << islands[i][j] << " ";
		}
		cout << endl;
	}
}

void print_con() {
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 6; j++) {
			cout << con[i][j] << " ";
		}
		cout << endl;
	}
}

int find(int x) {
	if (x == root[x]) return x;
	else return find(root[x]);
}

bool comp(vector<int> a, vector<int> b) {
	return a[2] < b[2];
}
int main() {
	cin >>N >> M;
	for (int i = 0; i < 7; i++) {
		root[i] = i;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> info[i][j];
		}
	}
	for (int i = 1; i < 7; i++) {
		for (int j = 1; j < 7; j++) {
			con[i][j] = 9999999;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (info[i][j] && !visit[i][j]) { //1인걸 봤을 때
				dfs(i, j, ++num_cnt);
			}
		}
	}
	
	check();
	//print_con();
	vector<vector<int>> connections;
	for (int i = 1; i < 7; i++) {
		for (int j = 1; j < 7; j++) {
			if (con[i][j] != 9999999) {
				connections.push_back({ i, j, con[i][j] });
			}
		}
	}
	int t=0;
	sort(connections.begin(), connections.end(), comp);
	int ret = 0;
	for (vector<int> c : connections) {
		if (find(c[0]) != find(c[1])) {
			ret += c[2];
			//cout << "c[0]: " << c[0] << ", c[1]: " << c[1] << ", weight: " << c[2] << endl;
			t++;
			root[find(c[1])] = find(c[0]);
		}
	}
	
	if (t == (num_cnt-1)) cout << ret;
	else cout << -1;
	
	return 0;
}