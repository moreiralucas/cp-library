void moedas(int argc, char const *argv[]){
	int m, n;
	cin >> m >> n;
	while(m){
		vector<int> array(m+1, 50001);
		array[0] = 0;
		for (int i = 0; i < n; ++i){
			int valor;
			cin >> valor;
			for (int j = 0; j < m; ++j){
				if(array[j] != 50001 && j + valor <= m)
					if(array[j+valor] > array[j] + 1)
						array[j+valor] = array[j]+1;
			}
		}
		if(array[m] < 50001){
			cout << array[m] << endl;
		}
		else
			cout << "Impossivel" << endl;
		cin >> m >> n;
	}
}
