#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int j;
    for (int i=0; i<prices.size(); i++) {
        for (j=i+1; j<prices.size(); j++) 
            if (prices[i] > prices[j]) break;
        if (j == prices.size()) answer.push_back(j-i-1);
        else answer.push_back(j-i);
    }
    
    return answer;
}