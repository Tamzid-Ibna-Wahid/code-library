#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R> using ordered_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
  
     ordered_set <int> a;
    
    // inserting element
    a.insert(1);
    a.insert(40);
    a.insert(4);
    a.insert(7);
    a.insert(4);  // order set only contain unique value
    
    // a contains
    for(auto &i :a){
        cout<<i<<" ";
    }
    cout<<endl;
    
    
    // finding kth element. It return iterator
    cout<<*a.find_by_order(0)<<endl;
    cout<<*a.find_by_order(1)<<endl;
    cout<<*a.find_by_order(2)<<endl;
    cout<<*a.find_by_order(3)<<endl;
    
    cout<<endl;
    
    // finding the number of element smaller then x
    cout<<a.order_of_key(6)<<endl;
    cout<<a.order_of_key(100)<<endl;
    cout<<a.order_of_key(0)<<endl;
    
    
    // lower bound of x 
    cout<<*a.lower_bound(6)<<endl;
    
    
    // upper bound of x
     // if no upper bound return 0
    cout<<"upper_bound : "<<*a.upper_bound(2)<<endl;
    
    
    // remove element
    a.erase(6);
    a.erase(23); // element that is not present will not affected
    
    
    // another way
    // a.erase(iterator);  
    
    
    // another way
    /*
        int ind = a.order_of_key(x);        // find the index
        auto it = a.find_by_order(ind);     // get the iterator
        a.erase(it);                      // remove by iterator
    */  

    
    
    
    
  ordered_map<int, int>mp;
  mp.insert({1, 10});
  mp.insert({2, 20});
  cout << mp.find_by_order(0)->second << endl; ///k th element
  cout << mp.order_of_key(2) << endl; ///number of first elements less than k
    
    
  
  return 0;
}