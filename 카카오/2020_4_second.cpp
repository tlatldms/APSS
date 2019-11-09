#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Trie {
    Trie * next[27];
    int count;
    Trie() {
        fill(next, next+27, nullptr);
        count=0;
    }
};


void insert(string word, Trie* now_node) {
    for (int i=0; i<word.size(); i++) {
        int key = int(word[i] - 'a');
        if (!now_node->next[key]) {
            now_node->next[key] = new Trie;
        }
        now_node = now_node->next[key];
        now_node->count++;
    }

}

int trav(string query, Trie* now_node) {
    for (int i=0; i<query.size(); i++) {
        int key = int(query[i] - 'a');
        if (key == -34) {
            return now_node->count;   
        }
        else if (now_node->next[key]) { //키가 있으면
            now_node = now_node->next[key];
        } else {
            return 0;
        }
    }
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    Trie * root_arr[10002][2] ={0,}; // 0: 똑바로 , 1: 리버스
    for (auto word: words) {
        if (!root_arr[word.size()][0])
        {
            root_arr[word.size()][0] = new Trie;
        }
        if (!root_arr[word.size()][1])
        {
            root_arr[word.size()][1] = new Trie;
        }
        insert(word, root_arr[word.size()][0]);
        
        string reversed_word = word;
        reverse(reversed_word.begin(), reversed_word.end());

        insert(reversed_word, root_arr[reversed_word.size()][1]);
    }
    //vector<string> t = {"?????", "????t", "????t", "?????"};
    for (auto query:queries) {
        if (query[0] == '?' && query[query.size()-1] == '?') {
            int cnt=0;
            for (int k=0; k<26; k++) {
                if (root_arr[query.size()][0]->next[k]) {
                    cnt+=root_arr[query.size()][0]->next[k]->count;
                    //cout << "k: " << k<<", count: " << root_arr[query.size()][0]->next[k]->count << endl;
                }
            }
            answer.push_back(cnt);
        }
        else if (query[0] == '?') {
            string reversed_query = query;
            reverse(reversed_query.begin(), reversed_query.end());
            if (root_arr[query.size()][1])
                answer.push_back(trav(reversed_query, root_arr[query.size()][1]));
            else answer.push_back(0);
        } else {
            if (root_arr[query.size()][0])
                answer.push_back(trav(query, root_arr[query.size()][0]));
            else answer.push_back(0);
        }
       
    }
        return answer;
}
