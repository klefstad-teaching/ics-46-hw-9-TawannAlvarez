#include "ladder.h"
// g++ -o  lad ladder_main.cpp ladder.cpp
// ./lad
int main(){
    /*set<string> word_list;
    load_words(word_list, "words.txt");
    cout << generate_word_ladder("cat", "dog", word_list).size() << endl;*/
    verify_word_ladder();
    return 0;
}