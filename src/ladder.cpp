
#include "ladder.h"
using namespace std;
function generate_word_ladder(begin_word, end_word, word_list){
    queue<vector<string>> ladder_queue;
    set<string> visited;

    ladder_queue.push(begin_word);
    visited.insert(begin_word);

    while(!ladder_queue.empty()){
        vector<string> = ladder = ladder_queue.front();
        ladder_queue.pop();


        string last_word = ladder.back();

        for(const string& word : word_list){

            if(is_adjacent(last_word, word)){

                if(visited.find(word) == visited.end()){

                    visited.insert(word);

                    vector<string> new_ladder = ladder;

                    new_ladder.push_back(word);

                    if(word = end_word){

                        return new_ladder;
                    }

                    ladder_queue.push(new_ladder);
            }
            }
        }
    }

    return vector<string>;

}