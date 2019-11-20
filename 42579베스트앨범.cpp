#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

// bool compare(pair<string, int> a, pair<string, int> b) {
//     return a.second > b.second;
// }
vector<pair<string, int>> v;

class Song {
    private:
    string genres;
    int plays = 0;
    int index;
    
    public:
    Song();
    Song(string genres, int plays, int index);
    ~Song();
    void Get_genres(string genres);
    void Get_plays(int plays);
    void Get_index(int index);
    string Return_genres();
    int Return_plays();
    int Return_index();
};
Song::Song(string genres_, int plays_, int index_) {
    this->genres = genres_;
    this->plays = plays_;
    this->index = index_;
}

Song::~Song() {
    
}

void Song::Get_genres(string genres_) {
    this->genres = genres_;
}
void Song::Get_plays(int plays_) {
    this->plays = plays_;
}
void Song::Get_index(int index_) {
    this->index = index_;
}

string Song::Return_genres() {
    return this->genres;
}

int Song::Return_index() {
    return this->index;
}

int Song::Return_plays() {
    return this->plays;
}

bool Return_v_index(Song a) {
    string str = a.Return_genres();
    for(int i = 0; i < v.size(); i++) {
        if(v[i].first == str) {
            return i;
        }
    }
    // return v.find(a.Return_genres());
}

bool compare(Song a, Song b) {
    if(Return_v_index(a) != Return_v_index(b)) {
        return Return_v_index(a) < Return_v_index(b);
    } else {
        return a.Return_plays() > b.Return_plays();
    }
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    vector<Song> v_song;

    
    bool flag = false;
    
    
    for(int i = 0; i < genres.size(); i++) {
        // v_song[i].Get_genres(geners[i]);
        // v_song[i].Get_plays(plays[i]);
        // v_song[i].Get_index(i);
        
        v_song.push_back(Song(genres[i], plays[i], i));


        for(int j = 0; j < v.size(); j++) {
            if(genres[i] == v[j].first) {
                v[j].second += plays[i];
                flag = true;
                break;
            }
        }
        if(!flag) {
            v.push_back(make_pair(genres[i], 0));
        }
        flag = false;
        
    }

    sort(v_song.begin(), v_song.end(), compare);
    
    for(int i = 0; i < v_song.size(); i++) {
        cout << v_song[i].Return_genres() << '\t' << v_song[i].Return_plays() << '\t' << v_song[i].Return_index() << '\n';
    }
    







    // vector<pair<string, int>> v;
    // bool flag = false;
    
    
    // for(int i = 0; i < genres.size(); i++) {
    //     for(int j = 0; j < v.size(); j++) {
    //         if(genres[i] == v[j].first) {
    //             v[j].second += plays[i];
    //             flag = true;
    //             break;
    //         }
    //     }
    //     if(!flag) {
    //         v.push_back(make_pair(genres[i], 0));
    //     }
    //     flag = false;
    // }

    // sort(v.begin(), v.end(), compare);



    // //
    // for(int i = 0; i < v.size(); i++) {
    //     cout << v[i].first << ' ' << v[i].second << '\n';
    // }


    // vector<pair<int, int>> temp(v.size());
    // vector<pair<int, int>> max(v.size());


    // for(int j = 0; j < v.size(); j++) {
    //     for(int i = 0; i < genres.size(); i++) {
    //         if(genres[i] == v[j].first) {
    //             if(plays[i] > max[j].first){
    //                 max[j].second = max[j].first;
    //                 max[j].first = plays[i];

    //                 temp[j].second = temp[j].first;
    //                 temp[j].first = i;
    //             } else if(plays[i] > max[j].second) {
    //                 max[j].second = plays[i];
    //                 temp[j].second = i;
    //             }
    //         }
    //     }
    //      cout << v[j].first << '\t' << max[j].first << '\t' << max[j].second << '\t' << temp[j].first << '\t' << temp[j].second << '\n';
    // }

    

    // for(int i = 0; i< temp.size(); i++) {
    //     answer.push_back(temp[i].first);
    //     answer.push_back(temp[i].second);
    //     cout << temp[i].first << ' ' << temp[i].second << '\n';//
    // }



    return answer;
}

int main() {

    vector<string> v = {"classic", "pop", "classic", "classic", "pop", "jazz", "jazz", "jazz", "jazz"};
    vector<int> u = {500, 600, 150, 800, 2500, 700, 500, 300, 200};
    
    solution(v, u);
    return 0;
}