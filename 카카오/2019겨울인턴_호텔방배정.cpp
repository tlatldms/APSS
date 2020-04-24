#include <string>
#include <vector>
#include <map>

using namespace std;

vector<long long> tmp;
vector<long long> solution(long long k, vector<long long> room_number) {

    map<long long, long long> m;
    vector<long long> answer;
    
    for (long long rn: room_number) {
        
        long long now = rn;
        while(1) {
            if (m[now]) {
                tmp.push_back(now);
                now = m[now];
            } else {
                for (auto a: tmp) {
                    m[a] = now+1; 
                }
                m[now] = now+1;
                answer.push_back(now);
                break;
            }   
        }
        tmp.clear();
    }
    return answer;
}