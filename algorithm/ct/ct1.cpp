#include <iostream>
#include <string>
int N;
std::string start[20];
std::string end[20];
int istart[20];
int iend[20];
std::string result;

void solve() {
    int smax = 0;
    int emin = 2400;
    int smax_idx=0;
    int emin_idx=0;
    
    for (int i = 0; i < N; ++i) {
        if (smax < istart[i]) {
            smax_idx=i;
            smax = istart[i];
        }
        if (emin > iend[i]) {
            emin_idx=i;
            emin = iend[i];
        }
    }
    
    if (emin - smax <= 0) {
        result = "-1";
        
    } else {
        start[smax_idx].insert(2, 1, ':');
        end[emin_idx].insert(2, 1, ':');
        result = start[smax_idx] + " ~ " + end[emin_idx];
    }
}


int main() {
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        std::string wave;
        std::cin >> start[i] >> wave >> end[i];
        
        start[i].erase(2, 1);
        istart[i] = std::stoi(start[i]);
        end[i].erase(2, 1);
        iend[i] = std::stoi(end[i]);
    }
    
    solve();
    
    std::cout << result << std::endl;
    
    return 0;
}
