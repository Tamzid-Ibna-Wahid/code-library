#include <bits/stdc++.h>
using namespace std;

typedef long long item;
// struct item{
//     int m, c;
// };

struct segtree{
    int size;
    vector<item> values;
    vector<item> lazy;
    item NEUTRAL_ELEMENT = INT_MIN; // for max queries

    item merge(item a, item b) { return max(a,b); }
    item single(int v) { return v; }

    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        values.assign(2*size, NEUTRAL_ELEMENT);
        lazy.assign(2*size, 0);
    }

    void push(int x, int lx, int rx){
        if(lazy[x] != 0){
            values[x] += lazy[x];  // add lazy value
            if(rx - lx > 1){       // not a leaf
                lazy[2*x+1] += lazy[x];
                lazy[2*x+2] += lazy[x];
            }
            lazy[x] = 0;
        }
    }

    void build(vector<long long> &a, int x, int lx, int rx){
        if(rx - lx == 1){
            if(lx < a.size()) values[x] = single(a[lx]);
            return;
        }
        int m = (lx + rx)/2;
        build(a, 2*x+1, lx, m);
        build(a, 2*x+2, m, rx);
        values[x] = merge(values[2*x+1], values[2*x+2]);
    }

    void build(vector<long long> &a){ build(a, 0, 0, size); }

    void range_add(int l, int r, long long v, int x, int lx, int rx){
        push(x, lx, rx);
        if(rx <= l || lx >= r) return; // no overlap
        if(lx >= l && rx <= r){        // complete overlap
            lazy[x] += v;
            push(x, lx, rx);
            return;
        }
        int m = (lx + rx)/2;
        range_add(l, r, v, 2*x+1, lx, m);
        range_add(l, r, v, 2*x+2, m, rx);
        values[x] = merge(values[2*x+1], values[2*x+2]);
    }
    void range_add(int l, int r, long long v){ range_add(l, r, v, 0, 0, size); }

    item calc(int l, int r, int x, int lx, int rx){
        push(x, lx, rx);
        if(rx <= l || lx >= r) return NEUTRAL_ELEMENT;
        if(lx >= l && rx <= r) return values[x];
        int m = (lx + rx)/2;
        item s1 = calc(l, r, 2*x+1, lx, m);
        item s2 = calc(l, r, 2*x+2, m, rx);
        return merge(s1, s2);
    }
    item calc(int l, int r){ return calc(l, r, 0, 0, size); }
};

int main(){
    vector<long long> a = {2, 5, 1, 4, 9, 3};
    int n = a.size();

    segtree t;
    t.init(n);
    t.build(a);

    cout << "Initial max [0,6): " << t.calc(0,6) << "\n"; // 9
    t.range_add(1,4,5); // add 5 to a[1..3]
    cout << "After adding 5 to [1,4): " << t.calc(0,6) << "\n"; // max becomes 10
    cout << "Max in [1,4): " << t.calc(1,4) << "\n"; // max in updated subarray
}