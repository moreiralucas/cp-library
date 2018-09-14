// Exponenciacao

int exp(int value1, int value2){
	if (value2 == 0) return 1;
	if (value2 == 1) return value1;
	int result = exp(value1, value2 / 2);
	result = result * result;
	if (value2 % 2 == 1) result = result * value1;
	return result;
}