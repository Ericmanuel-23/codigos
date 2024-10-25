#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
#define PB push_back
#define F first
#define S second
#define PF push_back

using namespace std;
const int MAXN = 2e5+1;
const int SIZE = 1e5+1;

vector<int> SZ(SIZE), P(SIZE);
map<int,int>F;
//vector<set<int>>adj(SIZE);
int n;
stack<int>Pila;
bool cmp = 0;
void build(){
    for(int i = 1; i <= n ; i++){
        SZ[i] = 1;
        P[i] = i;
        F[i] ++;
    }
}

int find(int x){
    if(P[x] != x)
        P[x] = find(P[x]);
    return P[x];
}

void merge(int a, int b){ // 3 2
    a = find(a); 
    b = find(b);
    //cout << a << " " << b <<'\n';
    if(a == b){
        return;
    }
    //cout<< a << " " <<SZ[a] << " " << b << " " <<SZ[b]<<'\n';
    if(SZ[a] < SZ[b]){//SZ[1] == 3  ---  SZ[2] == 1 
        swap(a, b);
    }
    SZ[a]+=SZ[b];//SZ[1] = 4 
     //SZ[2] = 1
    P[b] = a; //P[2] = 1
    F[b] = 0;
    F[a]+= SZ[b];
    SZ[b] = 0;
    //cout << SZ[a] << " "<< P[b]<<"\n";
}

void query(int a, int b){// 1 2
    int cnt = 0;
    int x = 0; 
    for(auto c : F){
        cerr << c.F << " " << c.S <<'\n';
        if(c.S){
            //cnt += (c.S - 1);
            x++;
        }
        else{
            F.erase(c.F);
        }
    }
    if(x == 1)cnt = 0;
    else cnt += x * (x-1) / 2;
    Pila.push(cnt);
}

signed main(){
    ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);

    int m;
    cin >> n >> m;
    build();
    vector<pair<int,int>>V(m + 5);
    stack<pair<int,int>> q;
    
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        q.push({a,b});
    }
    //q.push({0,0});

    while(!q.empty()){

        int a = q.top().F;
        int b = q.top().S;
        q.pop();

        //adj[a].insert(b);
        //adj[b].insert(a);
        if(cmp)
            query(a,b);
        else{
            if(!Pila.empty())
                Pila.push(Pila.top());
            else
                query(a,b);
        }

        cmp = 0;
       if(!q.empty() && P[a] != P[b]){
            cmp = 1;
            merge(a,b);
       }
    }

    while(!Pila.empty()){
        cout<<Pila.top() << '\n';
        Pila.pop();
    }                                                           
    return 0;
}