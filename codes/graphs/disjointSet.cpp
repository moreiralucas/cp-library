class DisjointSet{
    public: vector<int> parent, component_size;
    DisjointSet(int n): parent(n) {
        for(int i=0; i<n; i++) {
            parent[i] = i;
            component_size.pb(1);
        }
    }
    void join(int a, int b) {
        if(!check(a,b)) {
            int s = component_size[find(b)];
            parent[find(b)] = find(a);
            component_size[find(a)] += s;
        }
    }
    int find(int a){
        return a == parent[a] ? a : parent[a] = find(parent[a]);
    }
    bool check(int a, int b) {
        return find(a) == find(b);
    }
    int getsize(int a) {
        return component_size[find(a)];
    }
};
