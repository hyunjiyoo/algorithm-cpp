#include <iostream>
#include <string>

int cvti(char c) {
    return c - '0';
}
char cvtc(int i) {
    return i + '0';
}

std::string div2(std::string s) {
    std::string ret;
    
    int acc = 0;
    
    {
        int i = cvti(s[0]);
        const int d = i / 2;
        ret.reserve(s.size() - (d == 0));
        
        if (d)
            ret.push_back(cvtc(d));
        
        acc = (i & 0x1)? 5 : 0;
    }
    
    auto it = s.begin() + 1;
    auto end = s.end();
    
    for (; it != end; ++it) {
        const char c = *it;
        const int i = cvti(c);
        
        ret.push_back(cvtc((i / 2) + acc));
        
        acc = (i & 0x1)? 5 : 0;
    }
    return ret;
}

std::string mod2(std::string s) {
    const int i = cvti(s.back());
    return std::to_string(i & 0x1);
}

void to_binary(std::string s) {
    if (s.empty())
        return;
    
    to_binary(div2(s));
    std::cout << mod2(s);
}

int main(int argc, const char* argv[]) {
    std::string s;
    std::cin >> s;
    to_binary(s);

    return 0;
};
