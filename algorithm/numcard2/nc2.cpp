#include <iostream>
#include <map>

int N, M;
std::multimap<int, int> m;
std::multimap<int, int>::iterator it;

int main (int argc, const char * argv []) {

    std::scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        int num;
        std::scanf("%d", &num);
        
        it = m.find(num);
        if (it != m.end())
            it->second++;
        else
            m.insert(std::pair<int, int>(num, 1));
    }
    
    
    std::scanf("%d", &M);
    for (int i = 0; i < M; ++i) {
        int num;
        std::scanf("%d", &num);
        
        it = m.find(num);
        if (it != m.end())
            std::printf("%d ", it->second);
        else
            std::printf("0 ");
    }
    
    return 0;
}
