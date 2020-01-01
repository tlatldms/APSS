#include <string>
#include <vector>

using namespace std;


vector<int> solution(vector<int> heights) {
    vector<int> answer;
    
    for (int i=0; i<heights.size(); i++ ) {
        int flag=0;
        for (int j = i-1; j>=0; j--) {
            if (heights[j] > heights[i] ) {
                flag=1;
                answer.push_back(j+1);
                break;
            }
        }
        if (!flag)
            answer.push_back(0);
    }
    return answer;
}