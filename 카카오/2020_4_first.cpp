#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Trie {
    Trie * next[26];
    bool is_finished;
    Trie() {
        fill(next, next+26, nullptr);
        is_finished = false;
    }
 
    int trav(string query, int i) {
        int ret=0;
        if (i == query.size()) {
            if (is_finished)
                return 1;
            else //쿼리는 끝났는데 word는 안끝남
                return 0;
        }
        //쿼리가 끝나지 않았음
        
        int key = query[i]-'a';
        if (key == -34) { //?일 때
            for (int j=0; j<26; j++) {
                if (next[j]) ret+=next[j]->trav(query, i+1);
            }    
        }
        else if (next[key]) //있을 때
            ret += next[key]->trav(query, i+1);
        else //아예 다를 때
             return 0;
        return ret;
        
    }
   
    void insert(string word, int i) {
        if (i == word.size()) {
            is_finished=true;
            //cout << word[i-1] << endl;
            return;
        }
        int key = int(word[i] - 'a');
        if (!next[key]) {
            next[key] = new Trie;
        }
        //cout << key;
        next[key]->insert(word, i+1);
    }
};

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    Trie * root = new Trie;
    for (auto word: words) {
        root->insert(word, 0);        
    }
    
    for (auto query:queries)
        answer.push_back(root->trav(query,0));
    return answer;
}
