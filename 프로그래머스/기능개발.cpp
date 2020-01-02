#include <string>
#include <vector>
#include <queue>

using namespace std;

queue<pair<int, int>> q;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int day_cnt=0, idx=0;
    
    while (idx < progresses.size()) {
        day_cnt++;
        int baepo=0;
        while (idx < progresses.size() && progresses[idx] + day_cnt*speeds[idx] >= 100) {
            baepo++; idx++;
        }
        if (baepo) answer.push_back(baepo);
    }
    return answer;
}