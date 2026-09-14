#ifndef SIUUU_H
#define SIUUU_H

// Standard Headers
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// Debug macro
#ifndef ONLINE_JUDGE
#define deb(x) cerr << #x << " = "; _print(x); cerr << endl;
#else
#define deb(x)
#endif

// Debug functions
void _print(long long t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
void _print(float t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(const string& t) { cerr << t; }
void _print(bool t) { cerr << (t ? "true" : "false"); }

template <class T, class V> void _print(const pair<T, V>& p) { cerr << "{"; _print(p.first); cerr << ", "; _print(p.second); cerr << "}"; }
template <class T> void _print(const vector<T>& v) { cerr << "[ "; for (const T& i : v) _print(i), cerr << " "; cerr << "]"; }
template <class T> void _print(const set<T>& v) { cerr << "{ "; for (const T& i : v) _print(i), cerr << " "; cerr << "}"; }
template <class T> void _print(const multiset<T>& v) { cerr << "{ "; for (const T& i : v) _print(i), cerr << " "; cerr << "}"; }
template <class T, class V> void _print(const map<T, V>& v) { cerr << "{ "; for (const auto& i : v) _print(i), cerr << " "; cerr << "}"; }
template <class T> void _print(const unordered_set<T>& v) { cerr << "{ "; for (const T& i : v) _print(i), cerr << " "; cerr << "}"; }
template <class T, class V> void _print(const unordered_map<T, V>& v) { cerr << "{ "; for (const auto& i : v) _print(i), cerr << " "; cerr << "}"; }
template<class T, size_t N> void _print(const array<T, N>& a) { cerr << "[ "; for (auto &x : a) _print(x), cerr << " "; cerr << "]"; }

// PBDS typedefs
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using orderedmulti_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R> using ordered_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Typedefs & Macros
typedef long long ll;
typedef long l;
typedef long double ld;
typedef unsigned long long ull;
typedef long double lld;
#define endl "\n"
#define vint vector<int>
#define vpr vector<pr>
#define vvint vector<vector<int>>
#define pr pair<int, int>
#define REPn(i,n) for(ll i = 0; i < n; i++)
#define REPsn(i,s,n) for(ll i = s; i <= n; i++)
#define print(arr) for(auto &x: arr)cout<<x<<" ";endl;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define int long long
#define em emplace_back
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sum_all(v) accumulate(all(v), 0ll)
#define sz(x) ((ll)(x).size())
#define INF 2000000000000000000

#endif // SIUUU_H

// g++ -std=c++17 -O2 -DLOCAL -c Siuuu.h
// g++ -std=c++17 $file_name -o $file_base_name -DLOCAL && timeout 4s -c Siuuu.h
