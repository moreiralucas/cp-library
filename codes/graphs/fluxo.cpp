int res[MAX][MAX], mf, f, s, t; // Nao esqueca de zerar a matriz
vi p; // p stores the BFS spanning tree from s

void augment(int v, int minEdge) { // Transverse BFS spanning from s->t
    if (v == s) {
        f = minEdge; // Record a minEdge in a global var f
        return;
    }
    else if(p[v] != -1) {
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f;
        res[v][p[v]] += f;
    }
}

void flow() {
    mf = 0;
    while(1){
        f = 0;
        vi dist(mn, INF); dist[s] = 0;
        std::vector<bool> vis(mn, false);
        queue<int> q; q.push(s);
        p.assign(mn, -1);  // Record the BFS spanning tree, from s to t
        while(!q.empty()){
            int u = q.front(); q.pop();
            if (u == t) break; // Immediatly stop BFS if we already reach sink t
            // for(int v = 0; v < mn; v++) {
            if(vis[u]) continue;
            vis[u] = true;
             for(int i = 0; i < (int)adj[u].size(); i++) {
                int v = adj[u][i];
                if(vis[v] || !res[u][v]) continue;
                
                if (res[u][v] > 0 && dist[v] == INF) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                    p[v] = u;
                }
            }
        }
        augment(t, INF); // Find the min edge weight 'f in this path, if any
        if (f == 0) break; // We cannot send any more flow ('f' == 0), terminate
        mf += f; // We can still send a flow, increase teh max flow
    }
}
