#include <iostream>
#include <string>

std::string str;

int main (int argc, const char * argv []) {
    
    std::ios::sync_with_stdio(false);
    
    std::cin >> str;
    
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
    while (true) {
        
        if (j == str.size()) {
            sum = (j <= negative) ? sum + std::stoi(s) : sum - std::stoi(s);
            break;
        }
        
        if (str[j] == '-' || str[j] == '+') {
            sum = (j <= negative) ? sum + std::stoi(s) : sum - std::stoi(s);
            s.clear();
        }
        else {
            s += str[j];
        }
        
        ++j;
    }
    
    std::cout << sum;
    
    return 0;
}
