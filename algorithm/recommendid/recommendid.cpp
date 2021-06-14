#include <string>
#include <ctype.h>
#include <vector>

using namespace std;

void step1_2(string& str) {
    int i = 0;
    while (str[i]) {
        str[i] = tolower(str[i]);
        
        int c = (int)str[i];
        if ((str[i] != '-') &&
            (str[i] != '_') &&
            (str[i] != '.') &&
            (97 > c || c > 122) &&
            (48 > c || c > 57))
        {
            str.erase(i, 1);
            continue;
        }
        
        ++i;
    }
}


void step3_4_5(string& str) {
    
    int i = 0;
    while (str[i]) {
        if (str[i] == '.') {
            if (i != str.size() - 1 && str[i + 1] == '.') {
                str.erase(i, 1);
                continue;
            }
        }
        ++i;
    }
    
    if (str.empty())
        str = 'a';
    
    if (str[0] == '.') {
        str.erase(0, 1);
        if (str.empty())
            str = 'a';
    }
    
    if (str[str.size() - 1] == '.') {
        str.erase(str.size() - 1, 1);
        if (str.empty())
            str = 'a';
    }
}

void step6_7(string& str) {
    
    if (str.size() >= 16) {
        str.erase(str.begin() + 15, str.end());
        
        if (str[str.size() - 1] == '.')
            str.erase(str.size() - 1, 1);
    }
    
    
    if (str.size() <= 2) {
        while (str.size() < 3) {
            str += str[str.size() - 1];
        }
    }
}


string solution(string new_id) {
    string answer = "";

    step1_2(new_id);
    step3_4_5(new_id);
    step6_7(new_id);
    
    answer = new_id;
    
    return answer;
}
