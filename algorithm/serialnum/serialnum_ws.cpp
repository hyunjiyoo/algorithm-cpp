#include <iostream>
#include <algorithm>
#include <array>
#include <string>
#include <cctype>

int N;
std::array<std::string, 1'001> str;
std::array<int, 1'001> len, sum, idx;
     
void input() {
    std::cin >> N;
    std::fill(sum.begin(), sum.end(), 0);
    
    for (int i = 0; i < N; ++i) {
        std::cin >> str[i];
        len[i] = (int)str[i].length();
        idx[i] = i;
        
        for (auto ch : str[i])
            if (isdigit(ch))
                sum[i] += (ch - '0');
    }
}

void solve() {
    std::sort(idx.data(), idx.data() + N, [](int l, int r) {
        if ((len[l] < len[r]) ||
            (sum[l] < sum[r] && len[l] == len[r]) ||
            (str[l] < str[r] && len[l] == len[r] && sum[l] == sum[r])) {
            return true;
        }
        return false;
    });
}

void output() {
    for (int i = 0; i < N; ++i)
        std::cout << str[idx[i]] << "\n";
}

void solve2() {
    auto sum = [](const std::string& s) {
        int result = 0;
        for (auto ch : s)
            if (isdigit(ch))
                result += (ch - '0');
        return result;
    };
    
    std::sort(str.data(), str.data() + N, [](std::string& l, std::string& r) {
        if ((l.length() < r.length()) ||
            (sum(l) < sum(r) && l.lenght() == r.length()) ||
            (l < r && l.length() == r.length() && sum(l) == sum(r))) {
            return true;
        }
        return false;
    });
}

void output2() {
    for (int i = 0; i < N; ++i)
        std::cout << str[i] << "\n";
}

int main (int argc, const char * argv []) {
    input();
    solve();
    output();
    return 0;
}
