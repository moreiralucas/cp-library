list<int> cyc;
std::vector<pib > adj[MAX];
void euler_tour(list<int>::iterator it, int u) {
    for (int j = 0; j < (int)adj[u].size(); j++) {
        pib v = adj[u][j];
        if (v.not_visited) {
            adj[u][j].not_visited = false;
            for (int k = 0; k < (int)adj[v.ff].size(); k++) {
                pib uu = adj[v.ff][k];
                if (uu.ff == u && uu.not_visited) {
                    adj[v.ff][k].not_visited = false;
                    break;
                }
            }
            euler_tour(cyc.insert(it, u), v.ff);
        }
    }
}
