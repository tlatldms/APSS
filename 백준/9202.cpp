#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool find_flag;

int w, b;
int dxy[8][2] = {
	{-1,-1}, {-1,0}, {-1,1},
	{0,-1}, {0,1},
	{1,-1}, {1,0}, {1,1}
};

char board[31][4][4];

bool make_visit[4][4];

vector<string> words;

struct trie {
	trie* next[27];
};

//trie* roots[4][4];

void find_word(trie* t, const char* str, int bn) {
	if (find_flag) return;
	if (*str == '\0') {
		find_flag = 1;
		//cout << "found " << str << endl;
		return;
	}

	//cout << "now char : " << str[idx] << endl;
	int alpha_num = (*str) - 'A';
	if (t->next[alpha_num] == NULL) return;
	else {
		find_word(t->next[alpha_num], str + 1, bn);
	}

}

void delete_trie(trie* t) {
	for (int k = 0; k < 26; k++) {
		if (t->next[k] != NULL)
			delete_trie(t->next[k]);
	}
	delete t;
}


void make_trie(trie* t, int x, int y, int bn, int depth) {
	if (depth == 9) return;
	make_visit[x][y] = true;
	for (int k = 0; k < 8; k++) {
		int nx = x + dxy[k][0];
		int ny = y + dxy[k][1];
		if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
		if (make_visit[nx][ny]) continue;
		int nc = board[bn][nx][ny] - 'A';
		if (t->next[nc] == NULL) {
			t->next[nc] = new trie();
		}
		make_trie(t->next[nc], nx, ny, bn, depth + 1);
	}
	make_visit[x][y] = false;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> w;
	string s;
	for (int i = 0; i < w; i++) {
		cin >> s;
		words.push_back(s);
	}
	cin >> b;
	string b_s;

	for (int bc = 0; bc < b; bc++) {

		for (int i = 0; i < 4; i++) {
			cin >> b_s;
			for (int j = 0; j < 4; j++) {
				board[bc][i][j] = b_s[j];
			}
		}
	}

	for (int bc = 0; bc < b; bc++) {
		//cout << "bc: " << bc << endl;
		string longest = "";
		int longest_len = -3;
		int score = 0;
		int found = 0;
		trie* root = new trie();
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				make_trie(root, i, j, bc, 0);
			}
		}

		for (auto ss : words) {
			find_flag = 0;
			find_word(root, ss.c_str(), 0);
			if (find_flag) {
				found++;
				int now_score = 0; int now_s = ss.size();
				if (now_s == 1 || now_s == 2) now_score = 0;
				else if (now_s == 3 || now_s == 4) now_score = 1;
				else if (now_s == 5) now_score = 2;
				else if (now_s == 6) now_score = 3;
				else if (now_s == 7) now_score = 5;
				else if (now_s == 8) now_score = 11;
				score += now_score;
				if (longest_len == (int)ss.size()) {
					if (ss.compare(longest) < 0) {
						longest = ss;
					}
				}
				else {
					if (longest_len < (int)ss.size()) {
						longest_len = (int)ss.size();
						longest = ss;
					}
				}

			}
		}

		cout << score << " " << longest << " " << found << endl;
		delete_trie(root);
	}
	return 0;
}