#include <bits/stdc++.h>
using namespace std;
                    
class sqrtDecom{
public:
        int n , sqrtn , m;
        vector<int>arr , decomposed;
        sqrtDecom(vector<int>&a,int m){
                                                // init
                n = m;
                arr = a;
                                                // decompose
                sqrtn = sqrt(n);
                m = (n+sqrtn-1)/sqrtn;
                decomposed.resize(m);
                for(int i=0;i<n;i++){
                        decomposed[i/sqrtn] += arr[i];
                }

        }

        void display(){
                cout<<"length : "<<n<<" "<<" sqrt : "<<sqrtn<<'\n';
                cout<<" -> array : ";
                for(int i:arr) cout<<i<<" ";
                cout<<"\n";
                cout<<" -> decomposed : ";
                for(int i:decomposed) cout<<i<<" ";
                cout<<"\n";
        }
};
                        
                        
int main(){
       int n;cin>>n;
       vector<int>arr(n);
       for(int &i:arr) cin>>i;

       sqrtDecom *s1 = new sqrtDecom(arr,n);
       s1->display();

}