int power(int a, int x){
	if (x == 0) return 1; 
	if (x == 1) return a; 
	return power(a,x/2)*power(a,x/2)*power(a,x%2);  
}
