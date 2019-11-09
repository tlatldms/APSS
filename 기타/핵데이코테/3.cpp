#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
string cmd;
vector<string> btns;
vector<int> scrs;

int m = -1;

void dfs(string command, int only_btn_sum) { //�ѹ��� �ѹ�ư�� �Ҹ��ϰ� ���� string���� dfs
	m = max(m, only_btn_sum + int(command.size()));
	ssize_t pos;
	for (int i = 0; i < btns.size(); i++) {
		pos = 0;
		while ((pos = command.find(btns[i], pos)) != string::npos) { //�ϳ��� ��ư�� �� Ŀ�ǵ忡 �������� �־ ���� ó��
			string tmp = command;
			tmp.erase(pos, btns[i].size());
			//cout<< "tmp: " << tmp << endl;
			dfs(tmp, only_btn_sum + scrs[i]);
			pos += btns[i].size();
		}

	}


}

int solution(string command, vector<string> buttons, vector<int> scores) {
	int answer = 0;
	cmd = command, btns = buttons, scrs = scores;

	dfs(command, 0);
	//cout<< "m: " << m;
	answer = m;
	return answer;
}