class Grafo {
private:
    int n; // Número de vertices
    list<pii > * adj;
public:
    Grafo (int n) {
        this->n = n; // Quantidade de vertices
        adj = new list<pii >[n]; // Cria lista de adjacencia
    }

    // Adiciona aresta ao Grafo
    void addAresta(int v1, int v2, int custo) {
        adj[v1].pb(mp(v2, custo));
    }

    int dijkstra(int orig, int dest) {
        // Vetor de distancias
        int dist[n];
        bool vis[n];
        priority_queue<pii, vector<pii >, greater<pii > > pq;
        // Inicia vetores de distancias e visitados
        for (int i = 0; i < n; i++) {
            dist[i] = INFINITO;
            vis[i] = false;
        }
        dist[orig] = 0;
        pq.push(mp(dist[orig], orig));

        while (!pq.empty()) {
            pii p = pq.top(); pq.pop();
            int u = p.second;
            // verifica se o vertice nao foi expandido
            if (vis[u] == false) {
                // marca visitados
                vis[u] = true;
                // Percorre os vértices "v" adjacentes a "u"
                for (list<pii >::iterator it = adj[u].begin(); it != adj[u].end(); it++) {
                    // Obtém o vértice adjacente e o custo da aresta
                    int v = it->first;
                    int custo_aresta = it->second;
                    // relaxamento(u, v)
                    if (dist[v] > (dist[u] + custo_aresta)) {
                        dist[v] = (dist[u] + custo_aresta); // Atualiza a dist de "v"
                        pq.push(mp(dist[v], v));
                    }
                }
            }
        }
        return dist[dest];
    }
};
