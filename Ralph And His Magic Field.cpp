#include <cstdio>
const int mod=1e9+7;
int k;
long long n, m;
inline int power(int a, int b) {
	int re=1;
	for(; b; b>>=1, a=(long long)a*a%mod)
		if(b&1) re=(long long)re*a%mod;
	return re;
}
int main() {
	scanf("%I64d%I64d%d", &n, &m, &k);
	if(((n+m)&1)&&(k==-1)) printf("0");
	else printf("%d", power(2, (int)((n-1)%(mod-1)*((m-1)%(mod-1))%(mod-1))));
}
