#include <iostream>

int main (int argc, const char * argv []) {
    long long n, m;
    std::scanf("%lld %lld", &n, &m);
    std::printf("%lld\n%lld", n/m, n%m);
    
    return 0;
}
