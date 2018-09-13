const int N = 2005;
int p[N], v[N];
int memo[N][N]; //memset(memo, -1, sizeof memo);
int mochila(int i, int j) {
	if(i == 0) return 0;
	if(memo[i][j] != -1) return memo[i][j];

	// não colocar o item => mochila(i-1. j)
	// colocar o item => mochila(i-1, j - p[i]) + v[i]
	int res = mochila(i-1, j);
	if(p[i] <= j) {
		res = max(res, mochila(i-1, j - p[i]) + v[i]);
	}

	return memo[i][j] = res;
}