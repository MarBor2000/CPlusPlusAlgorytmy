#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 2147483647
bool Edges = false;
bool negativeCycles = false;

void checkEdges(int n,vector<vector<pair<int,int>>>& graph) {
    for(int i = 0; i < n;++i) {
        for(int j = 0; j < graph[i].size();++j) {
            if(graph[i][j].second < 0) {
                Edges=true;
                return;
            }
        }
    }
}

void checkCycles(vector<vector<pair<int,int>>>& graph, vector<int>& distance) {
    int i = 0;
    while(i < graph.size()) {
        for(int j = 0; j < graph[i].size(); ++j) {

            int destination = graph[i][j].first;
            int weight = graph[i][j].second;

            if(distance[i] != INF && distance[i] + weight < distance[destination]) {
                negativeCycles = true;
                return;
            }
        }
        ++i;
    }
}

void bellmanFord(vector<vector<pair<int,int>>>& graph, int first, vector<int>& distance) {
    distance[first] = 0;
    int i = 0;
    while(i < graph.size()-1) {

        bool anyChange = false;
        for(int j = 0; j < graph.size(); ++j) {
            for(int k = 0; k < graph[j].size(); ++k) {

                int destination = graph[j][k].first;
                int weight = graph[j][k].second;

                if(distance[j] != INF && distance[j] + weight < distance[destination]) {
                    distance[destination] = distance[j] + weight;
                    anyChange = true;
                }
            }
        }

        if(!anyChange) {
            break;
        }

        ++i;
    }

    checkCycles(graph,distance);
}

void dijkstry(vector<vector<pair<int,int>>>& graph, int first, vector<int>&distance) {

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> priorityQueue;
    priorityQueue.push({0,first});

    distance[first] = 0;

    do{

        int vertex = priorityQueue.top().second;
        int dist = priorityQueue.top().first;
        priorityQueue.pop();

        if(dist > distance[vertex]) {
            continue;
        }

        int i = 0;

        while(i<graph[vertex].size()) {

            int destination = graph[vertex][i].first;
            int weight = graph[vertex][i].second;

            if(distance[vertex] + weight < distance[destination]) {

                distance[destination] = distance[vertex] + weight;
                priorityQueue.push({distance[destination],destination});

            }

            ++i;

        }

    }while(!priorityQueue.empty());
}


void showResult(vector<int>& distance, int n){
    for(int i = 0; i < n; ++i){
        if(distance[i]==INF){
            cout <<i<<": "<<INF<<"\n";
        }else{
            cout<<i<<": "<<distance[i]<<"\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,int>>> graph(n);
    vector<int> distance(n,INF);

    for(int i = 0;i < m;++i) {
        int p,k,w;
        cin>>p>>k>>w;
        graph[p].push_back({k,w});
    }

    int first;
    cin>>first;

    checkEdges(n,graph);

   if(Edges) {
        bellmanFord(graph,first,distance);
    }else {
        dijkstry(graph,first,distance);
   }


    if(negativeCycles) {
        cout<<"Graf zawiera ujemny cykl!";
    }else {
        showResult(distance,n);
    }


    return 0;
}