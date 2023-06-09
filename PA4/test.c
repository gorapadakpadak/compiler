int s[10];
int isPrime(int p);
int main(void){
	int a[10], i, j;
	for(i=0;i<10;i++)	a[i] = i+2;
	for(i=0;i<10;i++){
		if(isPrime(a[i]) == 1){
			j = s[i] = 0;
			while(1){
				s[i] += j++;
				if(j>a[i])	break;
			}
			print(s[i]);
		}
	}
	return 0;
}
int isPrime(int p){
	int i, r;
	i = 2;
	if(p == 2)	return 1;
	do{
		r = p % i++;
	}while(i<p && r > 0);
	if(i == p)      return 1;
	else    return 0;
}
