#include "dijkstras.h"
constexpr int UNDEFINED = -1;
vector<int> dijkstra_shortest_path(const Graph & g, int source, vector<int>& previous){
    int numVertices = g.numVertices;
    vector<int> distances(numVertices,INF);
    vector<bool> visited(numVertices, false);
    distances[source] = 0;
    previous[source] = UNDEFINED;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
    minHeap.push({source,0});
    while(!minHeap.empty()){
        int u = minHeap.top().first;
        minHeap.pop();
        if(visited[u]) continue;

        visited[u] = true;
        for(Edge edge:g[u]){
            int v = edge.dest;
            int weight = edge.weight;
            if(!visited[v] && distances[u] + weight < distances[v]){
                distances[v] = distances[u] + weight;
                previous[v] = u;
                minHeap.push({v,distances[v]});
            }
        }
    }
    return distances;
}
vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination){
    vector<int> shortest_path;
    for(int i = destination; i != -1; i = previous[i]){
        shortest_path.insert(shortest_path.begin(), i);
    }
}
void print_path(const vector<int>& v, int total){
    cout << "Totoal cost:" << total < endl;
    for(int i = 0; i < v.size(); i ++){
        cout << v[i];
    }
    cout << endl;

}