#include <iostream>
#include <string>
#include <queue>

int T, R;
int basis;
std::string str;
std::string QWERTY[26];
std::queue<std::pair<int, int>> q;

void setQWERTY() {
    QWERTY['Q' - 'A'] = "AW";
    QWERTY['W' - 'A'] = "QASE";
    QWERTY['E' - 'A'] = "WSDR";
    QWERTY['R' - 'A'] = "EDFT";
    QWERTY['T' - 'A'] = "RFGY";
    QWERTY['Y' - 'A'] = "TGHU";
    QWERTY['U' - 'A'] = "YHJI";
    QWERTY['I' - 'A'] = "UJKO";
    QWERTY['O' - 'A'] = "IKLP";
    QWERTY['P' - 'A'] = "OL";
    QWERTY['A' - 'A'] = "QWSZ";
    QWERTY['S' - 'A'] = "AWEDXZ";
    QWERTY['D' - 'A'] = "SERFCX";
    QWERTY['F' - 'A'] = "DRTGVC";
    QWERTY['G' - 'A'] = "FTYHBV";
    QWERTY['H' - 'A'] = "GYUJNB";
    QWERTY['J' - 'A'] = "HUIKMN";
    QWERTY['K' - 'A'] = "JIOLM";
    QWERTY['L' - 'A'] = "KOP";
    QWERTY['Z' - 'A'] = "ASX";
    QWERTY['X' - 'A'] = "ZSDC";
    QWERTY['C' - 'A'] = "XDFV";
    QWERTY['V' - 'A'] = "CFGB";
    QWERTY['B' - 'A'] = "VGHN";
    QWERTY['N' - 'A'] = "BHJM";
    QWERTY['M' - 'A'] = "NJK";
}


int find(int c) {
    
    while (!q.empty()) {
        
        int letter = q.front().first;
        int count = q.front().second;
        
        if (c == letter)
            return count * 2;
        
        for (int i = 0; i < QWERTY[letter].length(); ++i)
            q.push({QWERTY[letter][i] - 'A', count + 1});
        
        q.pop();
    }
    
    return 0;
}

        
int main (int argc, const char * argv []) {
    
    std::ios::sync_with_stdio(false);
    
    setQWERTY();
    
    std::cin >> T;
    for (int i = 0; i < T; ++i) {
        R = 0;
        std::cin >> str;
        
        for (int i = 1; i < str.length(); ++i) {
            q.push({str[i - 1] - 'A', 0});
            
            if (str[i - 1] != str[i])
                R += find(str[i] - 'A');
            
            while (!q.empty()) q.pop();
        }
        
        std::cout << R + str.length() << std::endl;
    }
    
    return 0;
}
