#include <iostream>
#include <string>

int opt[10] = { 0, 9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999 };

int main (int argc, const char * argv []) {
    
    std::ios::sync_with_stdio(false);
    
    std::string str;
    std::cin >> str;

    int N = std::stoi(str);
    
    int sum = 0;
    for (int i = 0; i < str.size(); ++i)
        sum += (N - (opt[i]));
    
    std::cout << sum;
    
    return 0;
}
