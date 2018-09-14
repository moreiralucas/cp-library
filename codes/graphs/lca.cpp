#define MAXN 1001 // N
#define MAXL 10 // (N / 0.3) -> log_2(N)

int ancestral[MAXN][MAXL];
void monta_tabela() {
    // Inicializa todos com -1
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXL; j++)
            ancestral[i][j] = -1;

    for (int i = 1; i <= N; i++)
        ancestral[i][0] = 0;
    
    // Montamos o restante da tabela com programacao dinamica
    for (int j = 1; j < MAXL; j++)
        for (int i = 1; i <= N; i++)
            if (ancestral[i][j - 1] != -1) {
                int k = ancestral[i][j - 1];
                ancestral[i][j] = ancestral[k][j - 1];
            }
}

int lca(int u, int v) {
    if (nivel[u] < nivel[v]) swap(u, v);
    // Agora vamos fazer o nivel[u] ser igual ao nivel[v], subindo pelos ancestrais de u
    for (int i = MAXL - 1; i >= 0; i--)
        if (nivel[u] - (1<<i) >= nivel[v]) u = ancestral[u][i];
        // Agora eles estao no mesmo nível
    if(u == v) return u;

    for (int i = MAXL - 1; i >= 0; i--) {
        if (ancestral[u][i] != -1 && ancestral[u][i] != ancestral[v][i]) {
            u = ancestral[u][i];
            v = ancestral[v][i];
        }
    }
    // Como subimos o maximo possivel sabemos que u != v e
    // que pai[u] == pai[v], logo LCA(u, v) == pai[u] == pai[v]
    return ancestral[u][0];
}