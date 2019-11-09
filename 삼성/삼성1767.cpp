#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;
int input[13][13];
vector<vector<int>> g_d;
bool visited[13][13];
enum DIR {U, R, D, L};
vector<pair<int, int>> cores, ret;
int N, m;
void get_available_cores() {
	cores.clear();
	ret.clear();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			/*
			bool up = false, right = false, left = false,  down = false;
			if (input[i][j]) {
				for (int k = 0; k < i; k++) if (input[k][j]) up = true;
				for (int k = i + 1; k < N; k++) if (input[k][j]) down = true;
				for (int k = 0; k < i; k++) if (input[i][k]) left = true;
				for (int k = j + 1; k < N; k++) if (input[i][k]) right = true;

				if (!(up && down && left && right)) { //네방향 모두에 이미 core 있지는 않을 때
					cores.push_back(make_pair(i, j));
				}
			}
			*/
			if (input[i][j]) cores.push_back(make_pair(i, j));
		}
	}
	for (pair<int,int> a : cores) {
		visited[a.first][a.second] = 1;
	}
}

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}

void dfs(int depth, int sum, int core_count) {
	if (depth == cores.size()) {
		ret.push_back(make_pair(core_count, sum));
		return;
	}

	int nx = cores[depth].first;
	int ny = cores[depth].second;
	bool tf = false;
	vector<bool> flag = { 1,1,1,1 };
	for (int i = 0; i < nx; i++) {
		if (visited[i][ny]) flag[0] = 0;
	}
	for (int i = nx + 1; i < N; i++) {
		if (visited[i][ny]) flag[2] = 0;
	}
	for (int j = 0; j < ny; j++) {
		if (visited[nx][j]) flag[3] = 0;
	}
	for (int j = ny+1; j < N; j++) {
		if (visited[nx][j]) flag[1] = 0;
	}
	if (!(flag[0] || flag[1] || flag[2] || flag[3])) tf = true;
	vector<int> dist = {nx, N-ny-1, N-nx-1, ny};
	for (int i = 0; i < 4; i++) {
		if (flag[i]) {
			if (i == 0) for (int k = 0; k < nx; k++) visited[k][ny] = 1;
			else if (i == 1) for (int j = ny + 1; j < N; j++) visited[nx][j] = 1;
			else if (i == 2) for (int k = nx + 1; k < N; k++) visited[k][ny] = 1;
			else if (i == 3) for (int j = 0; j < ny; j++) visited[nx][j] = 1;
			/*
			vector<vector<int>> s = dirs;
			s.push_back({ depth,i });
			dfs(depth + 1, sum + dist[i], s);
			*/
			dfs(depth + 1, sum + dist[i], core_count+1);
			if (i == 0) for (int k = 0; k < nx; k++) visited[k][ny] = 0;
			else if (i == 1) for (int j = ny + 1; j < N; j++) visited[nx][j] = 0;
			else if (i == 2) for (int k = nx + 1; k < N; k++) visited[k][ny] = 0;
			else if (i == 3) for (int j = 0; j < ny; j++) visited[nx][j] = 0;
		}
	}
	if (tf) {
		//cout << " tf true in : " << nx << " " << ny << endl;
		//cout << flag[0] << flag[1] << flag[2] << flag[3] << endl;
		dfs(depth + 1, sum, core_count);
	}
}


int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N;
		m = 9999999;
		memset(input, 0, sizeof(input));
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) cin >> input[i][j];
		}


		get_available_cores();
		dfs(0, 0,0);
		sort(ret.begin(), ret.end(), comp);
		//for (auto a : ret) cout << a.first << " " << a.second << "\n\n";
		cout << "#"<<i<< " "<< ret[0].second << endl;
		//for (auto a : g_d) cout << a[0] << ":" << a[1] << " ";
		//cout << "\n\n";
	}
	return 0;
}