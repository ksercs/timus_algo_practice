#include <cstdio>
#include <map>

std:: map <int, int> a;

int n, m, q, i, x, ans;

void solution(){
    scanf("%d", &n);
    for(i = 0 ; i < n ; i ++) scanf("%d", &x), a[x] ++;
    scanf("%d", &m);
    for(i = 0 ; i < m ; i ++){
        scanf("%d", &q);
        if(a[q]) ans ++;
    }
    printf("%d", ans);
}

int main(){
    solution();
    return 0;
}
