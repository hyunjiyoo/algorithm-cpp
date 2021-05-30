#include <iostream>

using namespace std;

void computeLPSArray(char* pat, int64_t M, int* lps);

void KMPSearch(char* pat, char* txt)
{
    int64_t M = strlen(pat);
    int64_t N = strlen(txt);

    int lps[M];

    computeLPSArray(pat, M, lps);

    int i = 0;
    int j = 0;
    while (i < N) {
        if (txt[i] == pat[j]) {
            i += 1;
            j += 1;
        }
   
        if (j == M) {
            printf("Found pattern at index %d \n", i - j);
        }
        
        else if (i < N && txt[i] != pat[j]) {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i += 1;
            }
        }
        
    }
}


void computeLPSArray(char* pat, int64_t M, int* lps)
{
    int len = 0;
    lps[0] = 0;
    
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len += 1;
            lps[i] = len;
            i += 1;
            
        }
        else {
            
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i += 1;
            }
        }
    }
}


int main() {
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";
    KMPSearch(pat, txt);
    return 0;
}

