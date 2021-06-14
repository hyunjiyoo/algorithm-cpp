#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    set<int> s;
    for (int i = 0; i < lottos.size(); ++i) {
        if (lottos[i] != 0)
            s.insert(lottos[i]);
    }
    
    int zero_count = (int)lottos.size() - (int)s.size();
    
    int correct = 0;
    for (int i = 0; i < win_nums.size(); ++i) {
        auto search = s.find(win_nums[i]);
        if (search != s.end())
            ++correct;
    }
    
    int min_rank = (correct <= 1) ? 6 : 7 - correct;
    int max_rank = (min_rank - zero_count < 1) ? 1 : min_rank - zero_count;
    
    answer.push_back(max_rank);
    answer.push_back(min_rank);
    
    return answer;
}
