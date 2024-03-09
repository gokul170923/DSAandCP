#include <bits/stdc++.h>
using namespace std;

/*
    TRICKS 

    1. check set bit 
        (n>>bit) & 1 == 1 (set) or 0(reset)
    
    2. set a bit
        n | (1<<bit)

    3. reset a bit
        n & ~(1<<bit)
    
    4. toggle a bit  
        n ^ (1<<bit)
        
        

*/

void binaryTodecimal(vector<int>&binary){
    int n = binary.size();
    int ans =0;
    for(int i=n-1;i>=0;i--){
        ans  +=  binary[i]*(1<<(n-i-1));
    }
    cout<<ans<<endl;
}
void decimalTobinary(){
    int n;
    cin>>n;
    vector<int>binary;
    while(n){
        binary.push_back(n&1);
        n = n>>1;
    }
    reverse(binary.begin(),binary.end());
    for(int i:binary) cout<<i<<' ';
    cout<<endl;
}



int main(){
    decimalTobinary();
    int n =10;
    cout<< (1&(n>>2)); 
    cout<< (n|(1<<2));
    cout<< (n& ~(1<<3));
    cout<< (n^ (1<<2));

}