#include <iostream>
#include <string>

std::string str;

int main (int argc, const char * argv []) {
    
    std::ios::sync_with_stdio(false);
    
    std::cin >> str;
    str += "+";
    
    int i = 0;
    bool flag = true;
    int negative = (int)str.size();
    
    while (i < str.size()) {
        if (str[i] == '-') {
            flag = false;
            negative = i;
            break;
        }
        ++i;
    }
    
    
    std::string s;
    int sum = 0;
    int j = (str[0] == '-') ? 1 : 0;
    
    for (; j < str.size(); ++j) {
        if (std::isalnum(str[j])) {
            s += str[j];
            continue;
        }
        
        int num = std::stoi(s);
        
        if (j <= negative)
            sum += num;
        else
            sum -= num;
        
        s.clear();
    }
    
    std::cout << sum;
    
    return 0;
}
