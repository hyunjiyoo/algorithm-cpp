#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    
    vector<int> answer;
    map<string, set<string>> m;
    map<string, int> idx_m;
    
    istringstream ss;
    for (string s : report) {
        
        ss.str(s);
        
        string first, second;
        ss >> first >> second;
        
        m[second].insert(first);
        ss.clear();
    }
    
    
    for (int i = 0; i < (int)id_list.size(); ++i)
        idx_m[id_list[i]] = i;
    
    
    answer.resize((int)id_list.size());
    
    for (int i = 0; i < (int)id_list.size(); ++i) {
        
        string user = id_list[i];
        if (m[user].size() >= k) {
            for (auto it : m[user]) {
                int idx = idx_m[it];
                ++answer[idx];
            }
        }
    }
    
    return answer;
}
