#include <bits/stdc++.h>
#define left LAJK
using namespace std;
typedef int64_t ll;

const int N = 2e6;
ll P;
struct mod{
    int x;
    mod() : x(0) {}
    mod(int _x): x(_x) {}
    mod operator+(mod b){ return (ll(x)+ll(b.x)+P)%P;}
    mod operator*(mod b){ return (ll(x)*ll(b.x)+P)%P;}
};
bool comp[N];
int primes[N], ps;

int n, k;
int a[N], left, done;
bool f[N];

int main(){
    srand(time(NULL));
    for(ll i=2;i<N;i++)
        if(!comp[i]){
            if(i > 1e4) primes[ps++] = i;
            for(ll j=i*i;j<N;j+=i) comp[j] = 1;
        }
    random_shuffle(primes, primes+ps);
    ps = min(ps,25);

    scanf(" %d%d", &n, &k);
    for(int i=0;i<1+n;i++){
        char in[20];
        scanf(" %s", in);
        f[i] = (sscanf(in, " %d", a+i) > 0);
        left += !f[i];
        done += f[i];
    }

    if(k == 0){
        if(f[0]){
            if(a[0]) printf("No\n");
            else     printf("Yes\n");
        } else {
            if(done&1) printf("Yes\n");
            else       printf("No\n");
        }
        return 0;
    }

    int zero = 1;
    for(int i=0;zero && i<ps;i++){
        P = primes[i];
        mod val = 0;
        for(int i=n;i+1;--i) {
            val = val*mod(k);
            if(f[i]) val = val + mod(a[i]);
        }
        zero &= (val.x == 0 || val.x == P);
    }

    if(done&1) { // ultimo a jogar foi computador
        if(left) zero = 1, left--;
    } else { // ultimo a jogar foi humano
        if(left) zero = 0, left--;
    }
    while(left--) zero ^=1;
    if(zero) printf("Yes\n");
    else     printf("No\n");

}
