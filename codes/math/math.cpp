void permutations() {
	std::vector<int> vec = {1, 2, 3, 4, 5};
	int n = vec.size();
	int cont = 0;
	do{
		for (int i = 0; i < n; ++i)
			cout << vec[i] << ' ';
		cout << endl;
		cont++;
	} while (next_permutation(vec.begin(), vec.end()));
	cout << cont << endl;
	return 0;
}