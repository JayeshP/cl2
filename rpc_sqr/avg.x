const MAXSIZE=50;
struct numlist{
	int num[MAXSIZE];
	int len;
};
typedef struct numlist numlist;
program SQRPROGRAM{
	version SQRVER{
		double sqr(numlist) = 12;
	}=1;
}=123;
