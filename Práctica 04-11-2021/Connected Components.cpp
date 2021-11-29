#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
        map<int, short> visited_vertexes;
        map<int, vector<std::map<int, int>>> adjacent_vertexes;
        int total_weight = 0;
        void add_edge(int vertex1, int vertex2, int weight);
        void clear_visited_vertexes();
};



void Graph::add_edge(int vertex1, int vertex2, int weight){
    std::map<int, int> temp;
    temp = {{vertex2, weight}}; 
    this->adjacent_vertexes[vertex1].push_back(temp);
    temp = {{vertex1, weight}};
    this->adjacent_vertexes[vertex2].push_back(temp);
    total_weight += weight;
}


void Graph::clear_visited_vertexes(){
    this->visited_vertexes.clear();
}


void dfs_tag_vertexes(Graph *g, int current_vertex, int parent_vertex);

void _dfs_tag_vertexes(Graph *g, int current_vertex, int parent_vertex, std::vector<int> *arr);


int main(){
    int N, V, E, e1, e2;
    char aux;
    
    cin >> N;

    for(int i = 0; i < N; i++){
        short *array_aux = (short*)calloc(N, sizeof(short));
        Graph *g = new Graph();

        int componentes = 1;

        std::cout << "Case #" << i+1 << ":\n";
        std::cin >> V >> E;

        for(int j = 0; j < E; j++){
            cin >> aux;
            e1 = aux - 'a';
            array_aux[e1] = 1;

            std::cin >> aux;
            e2 = aux - 'a';
            array_aux[e2] = 1;

            g->add_edge(e1, e2, 0);
        }
		for(int i = 0; i < V; i++)
            if(array_aux[i] == 0)
                g->add_edge(i, i, 0);
        

        dfs_tag_vertexes(g, g->adjacent_vertexes.begin()->first, -1);
        std::cout << "\n";

        for(auto k : g->adjacent_vertexes){
            if(g->visited_vertexes[k.first] == 0){
                componentes++;
                dfs_tag_vertexes(g, k.first, -1);
                cout << "\n";
            }     
        }
        
        cout << componentes << " connected components\n\n";

        free(g);
        free(array_aux);
    }

    return 0;
}

void dfs_tag_vertexes(Graph *g, int current_vertex, int parent_vertex){

    std::vector<int> array_aux;

    _dfs_tag_vertexes(g, current_vertex, parent_vertex, &array_aux);

    std::sort(array_aux.begin(), array_aux.end());
    
    for(auto i : array_aux)
        std::cout << (char)(i + 'a') << ",";

}


void _dfs_tag_vertexes(Graph *g, int current_vertex, int parent_vertex, std::vector<int> *arr){
    if(g->visited_vertexes[current_vertex] == 2)
        return;

    g->visited_vertexes[current_vertex] = 1;
    
    arr->push_back(current_vertex);


    for(auto i : g->adjacent_vertexes[current_vertex])
        for(auto j : i)
            if(j.first != parent_vertex && g->visited_vertexes[j.first] != 1)
               _dfs_tag_vertexes(g, j.first, current_vertex, arr);

    g->visited_vertexes[current_vertex] = 2;

    return;
}
