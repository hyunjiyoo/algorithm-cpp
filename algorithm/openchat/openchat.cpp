#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    vector<string> behavior(record.size(), "");
    vector<string> id(record.size(),"");
    vector<string> name(record.size(), "");
    
    for (int i = 0; i < record.size(); ++i) {
        istringstream ss(record[i]);
        string token;
        
        while (getline(ss, token, ' ')) {
            if (token == "Enter" || token == "Leave" || token == "Change")
                behavior[i] = token;
            else if (token.find("uid") != string::npos)
                id[i] = token;
            else
                name[i] = token;
        }
    }
    
    
    for (int i = 0; i < record.size(); ++i) {
        cout << behavior[i] << ' ' << id[i] << ' ' << name[i] << endl;
    }
    
    
    for (int i = 0; i < record.size(); ++i) {
        for (int j = (int)record.size() - 1; j >= 0; --j) {
            if (id[j] == id[i]) {
                name[i] = name[j];
                break;
            }
        }
    }
    
    
    cout << endl;
    for (int i = 0; i < record.size(); ++i) {
        cout << behavior[i] << ' ' << id[i] << ' ' << name[i] << endl;
    }
    
    
    for (int i = 0; i < record.size(); ++i) {
        string str = "";
        
        if (behavior[i] == "Enter") {
            str += name[i];
            str += "님이 들어왔습니다.";
            answer.push_back(str);
        }
        else if (behavior[i] == "Leave") {
            str += name[i];
            str += "님이 나갔습니다.";
            answer.push_back(str);
        }
    }
    
    return answer;
}

int main() {
    
    vector<string> v = {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"};
    vector<string> ans;
    ans = solution(v);
    
    for (auto it = ans.begin(); it != ans.end(); ++it) {
        cout << *it << endl;
    }
    
    return 0;
}
