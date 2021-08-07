#include <iostream>
#include <algorithm>

int L, C;
char alphabet[15];
char password[15];

void input() {
    
    std::ios::sync_with_stdio(false);
    std::cin >> L >> C;
    for (int i = 0; i < C; ++i) {
        std::cin >> alphabet[i];
    }
    
    std::sort(alphabet, alphabet + C);
}


void output() {
    int consonant = 0;
    bool vowel = false;
    for (int i = 0; i < L; ++i) {
        if (password[i] == 'a' ||
            password[i] == 'e' ||
            password[i] == 'i' ||
            password[i] == 'o' ||
            password[i] == 'u')
            vowel = true;
        else
            ++consonant;
    }
    
    if (vowel && consonant >= 2) {
        for (int i = 0; i < L; ++i) {
            std::cout << password[i];
        }
        std::cout << std::endl;
    }
}


void solve(int step = 0, int num = 0) {
    
    if (step == L) {
        output();
        return;
    }
    
    for (int i = num; i < C; ++i) {
        password[step] = alphabet[i];
        solve(step + 1, i + 1);
    }
}

int main (int artc, const char * argv []) {
    
    input();
    solve();
    
    return 0;
}
