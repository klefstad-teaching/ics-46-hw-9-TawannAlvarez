#include <gtest/gtest.h>

#include "dijkstras.h"
#include "ladder.h"

TEST(Ladder, Main) {
  set<string> word_list;
  load_words(word_list, "src/words.txt");
  EXPECT_TRUE(generate_word_ladder("cat", "dog", word_list).size() == 4);
  EXPECT_TRUE(generate_word_ladder("marty", "curls", word_list).size() == 6);
  EXPECT_TRUE(generate_word_ladder("code", "data", word_list).size() == 6);
  EXPECT_TRUE(generate_word_ladder("work", "play", word_list).size() == 6);
  EXPECT_TRUE(generate_word_ladder("sleep", "awake", word_list).size() == 8);
  EXPECT_TRUE(generate_word_ladder("car", "cheat", word_list).size() == 4);
}
TEST(d, main){
  Graph g;
    string file_name = "src/small.txt";
    file_to_graph(file_name,g);
    int source = 0;
    int destination = 3;
    vector<int> previous(g.numVertices, -1);
    vector<int> distances = dijkstra_shortest_path(g,source,previous);
    vector<int> shortest = extract_shortest_path(distances, previous, destination);
    int total_cost = distances[destination];
    vector<int> ex = {0,3};
    int cost = 1;
    EXPECT_EQ(ex, shortest);
    EXPECT_EQ(cost, total_cost);
}
