#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>

using namespace std;

int map[2000][2000][4];

//vector<vector<vector<int>>> map(2000, vector<vector<int>>(2000, {0,0,0,0}));

int dxy[4][2] = { {0,1}, {0,-1}, {-1, 0}, {1,0} };
int N;
vector<vector<int>> info (1000, vector<int> (5));

void move() {
	for (auto v : info) {
		map[v[0]][v[1]][v[2]] = 0;
		v[4] = 0;
	}
	for (auto v : info) {
		int x = v[0], y = v[1], dir = v[2], power = v[3];

		int nx = x + dxy[dir][0];
		int ny = y + dxy[dir][1];
		v[4] = 1;
		map[nx][ny][dir] = 1;
	}
}

void fun() {
	if (map)
}

int main(int argc, char** argv)
{
	int test_case;
	int T, x,y;
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		info.clear();
		for (int i = 0; i < N; i++) {
			scanf("%d %d %d %d", &x, &y, &info[i][2], &info[i][3]);
			info[i][0] = x + 1000;
			info[i][1] = y + 1000;
		}


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}