void troco(){
	int v, m;
	cin >> v >> m;
	vector<int> moedas(v+1);
	vector<int> entrada(m);
	moedas[0] = 0;
	for (int i = 1; i <= v; ++i) moedas[i] = -1;
	for (int i = 0; i < m; ++i)
		cin >> entrada[i];
	for (int j = 0; j < m; ++j){
		int a = entrada.back();
		entrada.pop_back();
		for (int i = v; i >= 0; --i){
			if(moedas[i] >= 0 && (i + a) <= v){
				if(moedas[i + a] == -1)
					moedas[i + a] = 1;
				else
					moedas[i + a]++;
			}
		}

	}
	if(moedas[v] > 0)
		cout << "S\n";
	else
		cout << "N\n";
}
