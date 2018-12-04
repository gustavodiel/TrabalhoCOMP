int fat(int n)
{
	if(n == 0){
		return 1;
	}

	return n*fat(n-1);

}

{
	int n, x;

	print("Valor:");
	read(n);
	x = fat(n);
	print(x);
}
