#include "dijkstras.h"
#include <iostream>
#include <vector>
#include <climits>
#include <fstream>
// g++ -o dis dijkstras_main.cpp dijkstras.cpp
// ./dis
int main(){
    Graph g;
    string file_name = "small.txt";
    file_to_graph(file_name,g);
    int source = 0;
    int destination = 3;
    vector<int> previous(g.numVertices, UNDEFINED);
    vector<int> distances = dijkstra_shortest_path(g,source,previous);
    vector<int> shortest = extract_shortest_path(distances, previous, destination);
    int total_cost = distances[destination];
    print_path(shortest, total_cost);
    return 0;
}