const int MAX_N = 10000;
int v[MAX_N + 1];
int tree[MAX_N * 4];

void build(int no, int esq, int dir) {
    if (esq == dir) {
        tree[no] = v[esq];
    } else {
        int meio = (esq + dir) / 2;
        // intervalo esquerda: [esq, meio]
        // intervalo direita: [meio+1, dir]
        build(2 * no + 1, esq, meio);
        build(2 * no + 2, meio + 1, dir);
        tree[no] = tree[2 * no + 1] + tree[2 * no + 2];
    }
}

void update(int no, int esq, int dir, int i) {
    if (esq == dir) {
        tree[no] = v[i];
    } else {
        int meio = (esq + dir) / 2;
        if (i <= meio)
            update(2 * no + 1, esq, meio, i);
        else
            update(2 * no + 2, meio + 1, dir, i);
        tree[no] = tree[2 * no + 1] + tree[2 * no + 2];
    }
}

int query(int no, int esq, int dir, int i, int j) {
    if (esq == i && dir == j) {
        return tree[no];
    } else {
        int meio = (esq + dir) / 2;
        if (j <= meio)
            return query(2 * no + 1, esq, meio, i, j);
        else if (i > meio)
            return query(2 * no + 2, meio + 1, dir, i, j);
        else
            return min(query(2 * no + 1, esq, meio, i, meio),
            	query(2 * no + 2, meio + 1, dir, meio + 1, j));
    }
}

int main() {
    int n, m;
    cin>>n>>m;
    for (int i = 1; i <= n; ++i)
        cin>>v[i];
    build(0, 1, n);
    for (int consulta = 1; consulta <= m; ++consulta) {
        int tipo;
        cin>>tipo;
        if (tipo == 1) {
            int i, x;
            cin>>i>>x;
            v[i] += x;
            update(0, 1, n, i);
        } else {
            int l, r;
            cin>>l>>r;
            cout<<query(0, 1, n, l, r)<<endl;
        }
    }
}
