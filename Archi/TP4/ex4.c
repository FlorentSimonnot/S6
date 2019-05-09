int fib(int n){ 
	return (n<=2) ? 1 : fib(n-1) + fib(n-2); 
}

int fib2_rec(int n, int acc1, int acc2){
	return (n<=2) ? acc2 : fib2_rec(n-1, acc2, acc1 + acc2);
}

int fib2(int n){ 
	return fib2_rec(n,1,1); 
}