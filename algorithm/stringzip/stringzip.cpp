#include <string>
#include <vector>
#include <limits>
#include <iostream>

using namespace std;

int solution(string s) {
    
    int min = numeric_limits<int>::max();
    
    vector<string> str;
    int unit = 1;
    while (unit <= s.size()) {
        str.clear();
        
        for (int i = 0; i < s.size(); i += unit) {
            int j = 0;
            string ss = "";
            while (i + j < s.size() && j < unit) {
                ss += s[i + j];
                ++j;
            }
            str.push_back(ss);
        }
        
        int i, same, count;
        i = count = 0;
        while (i < str.size() - 1) {
            same = 1;
            while (str[i] == str[i + same]) ++same;
                       
            count += (same == 1) ? (int)str[i].size() :
                                (int)str[i].size() + to_string(same).size();
            
            i += same;
            if (str.size() - 1 == i)
                count += str[i].size();
        }
        
        if (count == 0)
            count = (int)str[0].size();
        
        min = (min > count) ? count : min;
        ++unit;
    }
    
    return min;
}

int main() {
    string s = "aabbaccc";
    
    cout << solution(s) << endl;
    
    return 0;
}
