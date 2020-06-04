#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, board[103][103];


int reversed[5][4] = { {-1,-1,-1,-1}, {-1,-1,1,0}, {1,-1,-1,2}, {3, 2,-1, -1}, {-1,0,3,-1} };

int dxy[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
void printfun() {
	for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= N + 1; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
int main() {
	
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> T;
	int cnt = 1;
	while (cnt <= T) {
		//TODO: 전역 배열들 초기화
		int m = 0;
		vector<vector<pair<int, int>>> wormholes(11);
		cin >> N;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> board[i][j];
				if (board[i][j] >= 6 && board[i][j] <= 10) {
					wormholes[board[i][j]].push_back({ i,j });
				}
			}
		}
		
		int x, y, dir, start_x, start_y;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (int l = 0; l < 4; l++) {
					int score = 0;
					if (board[i][j] == 0) {
						start_x = i, start_y = j;
						x = start_x, y = start_y; dir = l;
						bool flag=false, after_wormhole = false;
						while (1) {
							//cout << x << " " << y <<" " << dir<< endl;
							int nx=x, ny=y, nd=dir;
							int now_num = board[x][y];
							//빈 칸일때
							if (x == start_x && y == start_y) {
								if (flag) {
									m = max(m, score);
									//cout << "reached start point" << endl;
									break;
								}
								else flag = true;
							}
							//벽 만났을때
							if (x ==0 ||x == N+1 || y == 0 || y == N+1) {
								//cout << "met wall" << endl;
								nd = (dir + 2) % 4;
								nx = x + dxy[nd][0];
								ny = y + dxy[nd][1];
								score++;
							}
							else if (now_num == 0) {
								nx = x + dxy[dir][0];
								ny = y + dxy[dir][1];
								nd = dir;
							}
							//블랙홀
							else if (now_num == -1 ) {
								m = max(m, score);
								break;
							}
							//웜홀
							else if (now_num >= 6 && now_num <= 10) {
								if (after_wormhole == true) {
									nx = x + dxy[dir][0];
									ny = y + dxy[dir][1];
									after_wormhole = false;
								}
								else {
									if (wormholes[now_num][0] == make_pair(x, y)) {
										nx = wormholes[now_num][1].first;
										ny = wormholes[now_num][1].second;
									}
									else if (wormholes[now_num][1] == make_pair(x, y)) {
										nx = wormholes[now_num][0].first;
										ny = wormholes[now_num][0].second;
									}
									after_wormhole = true;
								}
								nd = dir;
								
								
							}
							//삼각형 블록
							else if (now_num >= 1 && now_num <= 4) {
								if (reversed[now_num][dir] == -1) {
									nd = (dir + 2) % 4;
								}
								//방향이 바꿔야하는 경우에 해당되면
								else nd = reversed[now_num][dir];
								nx = x + dxy[nd][0];
								ny = y + dxy[nd][1];
								score++;
							}
							//그냥 블록이면
							else if (now_num == 5 ) {
								//cout << "met block" << endl;
								nd = (dir + 2) % 4;
								nx = x + dxy[nd][0];
								ny = y + dxy[nd][1];
								score++;
							}
							x = nx, y = ny, dir = nd;
						}

					}
				
				}
			}
		}
		cout << "#" << cnt << " " << m << endl;
		cnt++;
	}
	
	return 0;
}