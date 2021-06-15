#include <string>
#include <vector>

using namespace std;

bool map1[16][16];
bool map2[16][16];

void init() {
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            map1[i][j] = map2[i][j] = 0;
        }
    }
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    init();
    
    for (int i = 0; i < n; ++i) {
        int j = n - 1;
        while (arr1[i] > 0) {
            map1[i][j--] = arr1[i] % 2;
            arr1[i] /= 2;
        }
        
        int k = n - 1;
        while (arr2[i] > 0) {
            map2[i][k--] = arr2[i] % 2;
            arr2[i] /= 2;
        }
    }
    
    string str;
    for (int i = 0; i < n; ++i) {
        str = "";
        for (int j = 0; j < n; ++j) {
            if (!map1[i][j] && !map2[i][j])
                str += " ";
            else
                str += '#';
        }
        answer.push_back(str);
    }
    
    return answer;
}
