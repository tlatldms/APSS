#include <string>
#include <vector>
#include <queue>

using namespace std;

queue<pair<int,int>> q;
int solution(int bridge_length, int weight, vector<int> truck_weights) {

    int time_cnt = 0, idx = 0, now_w=0;
    while ((idx < truck_weights.size()) || !q.empty()) {
        time_cnt++;
        if (!q.empty()) {
            if (time_cnt - (q.front().first) == bridge_length) { //시간 다 되면
                now_w -= q.front().second;
                q.pop();
            }
        }
        if (idx < truck_weights.size() && now_w + truck_weights[idx] <= weight) { // 새로운 무게 실을수있으면
            now_w += truck_weights[idx];
            q.push(make_pair(time_cnt, truck_weights[idx++]));
        }
    }
    return time_cnt;
}