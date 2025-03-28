
#include "ladder.h"
using namespace std;
vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
    queue<vector<string>> ladder_queue;
    set<string> visited;

    ladder_queue.push({begin_word});
    visited.insert(begin_word);

    while(!ladder_queue.empty()){
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        


        string last_word = ladder.back();

        for(const string& word : word_list){

            if(is_adjacent(last_word, word)){

                if(visited.find(word) == visited.end()){

                    visited.insert(word);

                    vector<string> new_ladder = ladder;

                    new_ladder.push_back(word);

                    if(word == end_word){
                        return new_ladder;
                    }

                    ladder_queue.push(new_ladder);
            }
            }
        }
    }

    return {};

}
bool is_adjacent(const string& word1, const string& word2){
    //cout << "here"<< endl;
    return edit_distance_within(word1,word2,1);
}
void error(string word1, string word2, string msg){
    cout << word1 << ", " << word2 << " " << msg << endl;
}
bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    if(abs((int)(str1.size() - str2.size())) > d){
        return false;
    }
    int count = 0;
    int j = 0;
    int i = 0;
    for(;i < str1.size() && j < str2.size(); ){
        if (str1[i]!= str2[j]){
            count++;
            if(str1.size() > str2.size()){
                i++;
            }else if(str2.size() > str1.size()){
                j++;
            }else{
                i++;
                j++;
            }
        }else{
            i++;
            j++;
        }
    }
    if(i< str1.size()|| j < str2.size()){
        count ++;
    }
    return count <= d;
}
void load_words(set<string> & word_list, const string& file_name){
    ifstream file(file_name);
    string word;
    while(file >> word){
        word_list.insert(word);
    }

}
void print_word_ladder(const vector<string>& ladder){
    if(ladder.empty()){
        cout << "No word ladder found." << endl;
        return;
    }
    cout << "Word ladder found: ";
    for(const string& word : ladder){
        cout << word << ' ';
    }
    cout << endl;
}
#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}

void verify_word_ladder() {

    set<string> word_list;

    load_words(word_list, "words.txt");

    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);

    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);

    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);

    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);

    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);

    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);

}


