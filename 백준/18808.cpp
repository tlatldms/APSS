#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int N, M, K;
int cnt;
int board[41][41];
int sticker[101][11][11];
vector<pair<int, int>> nms;
void print_sticker(int num) {
	for (int i = 0; i < nms[num].first; i++) {
		for (int j = 0; j < nms[num].second; j++) {
			cout << sticker[num][i][j] << " ";

		}
		cout << endl;
	}
}

void print_board() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}
void rotate(int stick_num) {
	int stick_r = nms[stick_num].first;
	int stick_c = nms[stick_num].second;

	int tmp[11][11] = { 0, };
	for (int i = 0; i < stick_r; i++) {
		for (int j = 0; j < stick_c; j++) {
			tmp[j][stick_r -1 - i] = sticker[stick_num][i][j];
		}
	}



	memset(sticker[stick_num], 0, sizeof(sticker[stick_num]));
	for (int i = 0; i < stick_c; i++) {
		for (int j = 0; j < stick_r; j++) {
			sticker[stick_num][i][j] = tmp[i][j];
		}
	}
	nms[stick_num].first = stick_c;
	nms[stick_num].second = stick_r;
	//cout << " print now sticker  " << endl;
	//print_sticker(stick_num);
}

bool stick(int stick_num) {
	
	int stick_r = nms[stick_num].first;
	int stick_c = nms[stick_num].second;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int end_r = i + stick_r;
			int end_c = j + stick_c;
			if ((end_r > N) || (end_c > M)) continue;
			bool can_stick = 1;
			for (int q = 0; q < stick_r; q++) {
				for (int w = 0; w < stick_c; w++) {
					//보드에 이미 붙어있음
					if (board[i + q][j + w] && sticker[stick_num][q][w]) {
						can_stick = 0;
						break;
					}
				}
				if (!can_stick) break;
			}
			if (can_stick) { // 스티커 붙이기

				//cout << " possible in i, j: " << i << " " << j << endl;
				for (int q = 0; q < stick_r; q++) {
					for (int w = 0; w < stick_c; w++) {
						if (sticker[stick_num][q][w]) {
							board[i + q][j + w] = 1;
							cnt++;
						}
					}
				}
				return 1;
			}
			else continue;
		}
	}
	return 0;
}

int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int r, c;
		cin >> r >> c;
		nms.push_back(make_pair(r, c));
		for (int q = 0; q < r; q++) {
			for (int w = 0; w < c; w++) {
				cin >> sticker[i][q][w];
			}
		}
	}

	for (int i = 0; i < K; i++) {
		//스티커 붙이기 실패
		bool success = false;
		for (int j = 0; j < 4; j++) {
			//cout << "now sticker: " << endl;
			//print_sticker(i);

			if (stick(i)) {
			//cout << "suces sticker i: " << i << " rotate: " << j << endl;
				success = true;
				break;
			}
			else {
				rotate(i);
			}
		}
		//print_board();
		//cout << endl;
	}
	
	cout << cnt;

	return 0;
}