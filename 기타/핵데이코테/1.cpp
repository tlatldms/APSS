#include <string>
#include <vector>
#include <iostream>

using namespace std;

int decrease(vector<int> grade) {
	int sum = 0;
	for (int i = 0; i < grade.size() - 1; i++) {
		if (grade[i] > grade[i + 1]) {
			int now_target = grade[i + 1];
			for (int j = 0; j <= i; j++) {
				if (grade[j] <= now_target) continue;
				//cout << "i j: "<<i<<" "<<j<< " grade[j] - now_target: "<<grade[j] - now_target << endl;
				sum += (grade[j] - now_target);
				grade[j] = now_target;
			}
		}
	}

	return sum;
}

int solution(vector<int> grade) {
	int answer = -1;
	answer = decrease(grade);
	return answer;
}