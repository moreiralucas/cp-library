void factorize(unsigned long long n){
	int raiz=sqrt(n);
	for(int i =2; i<=n && i<=raiz; i++){
		if(n%i==0){
			while(n%i == 0)
				n/=i;
			cout << i << endl;
		}
	}
	if(n>1)
		cout << n << endl;
}
