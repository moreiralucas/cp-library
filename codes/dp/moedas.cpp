#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]){
	int m, n;

	cin >> m >> n;
	
	while(m){
		//cout << "m e n: " << m << ' ' << n << endl;
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
			//cout << "Possivel" << endl;
			cout << array[m] << endl;
		}
		else
			cout << "Impossivel" << endl;

		cin >> m >> n;
		
	}
	return 0;
}

/*
1000 2
35 150
110 3 20 30 60
3 2 2 9
0
*/