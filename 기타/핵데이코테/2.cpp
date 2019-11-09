#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

int m = -1; int pairs = 0;
int dxy[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
vector<set<char>> sharing;
set<pair<char, char>> set_of_pairs;
void fun(vector<string> maps) {
	int next_x, next_y;
	char now_char, next_char;
	for (int i = 0; i < maps.size(); i++) {
		for (int j = 0; j < maps[0].size(); j++) {
			now_char = maps[i][j];
			if (now_char == '.') continue;
			for (int k = 0; k < 4; k++) {
				next_x = i + dxy[k][0];
				next_y = j + dxy[k][1];
				if (next_x < 0 || next_x >= maps.size() || next_y < 0 || next_y >= maps[0].size()) continue;
				if (maps[next_x][next_y] != '.' && maps[next_x][next_y] != now_char) { //other city found 
					sharing[now_char].insert(maps[next_x][next_y]);
				}
			}
		}
	}

	for (int i = 0; i < 256; i++) {
		if (sharing[i].size()) {
			m = max(int(sharing[i].size()), m);
			pair<char, char> p;
			for (char c : sharing[i]) {
				if (c < char(i)) { //ABC사전순 정렬 
					p = make_pair(c, char(i));
				}
				else p = make_pair(char(i), c);
				set_of_pairs.insert(p);
			}
		}
	}

}

vector<int> solution(vector<string> maps) {
	vector<int> answer;
	sharing.resize(256); //sharing['A'] ~~
	fun(maps);
	if (m == -1) m = 0;
	answer = { int(set_of_pairs.size()), m };
	return answer;
}