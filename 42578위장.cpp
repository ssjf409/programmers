#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    bool flag = false;
    vector<pair<string, int>> cate_clothes;

    for(int i = 0; i < clothes.size(); i++) {
        for(int j = 0; j < cate_clothes.size(); j++) {
            if(cate_clothes[j].first == clothes[i][1]) {
                cate_clothes[j].second++;
                flag = true;
                break;
            } 
        }
        if(!flag) {
            cate_clothes.push_back(make_pair(clothes[i][1], 1));
            
        }
        flag = false;
        // cate_clothes.push_back(make_pair(clothes[i][1], 1));
    }
    
    for(int i = 0; i < cate_clothes.size(); i++) {
        answer *= (cate_clothes[i].second+1);    
    }
    answer--;
    return answer;
}

int main() {

    
    vector<vector<string>> v = {{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}};

    cout <<solution(v);
    return 0;
}