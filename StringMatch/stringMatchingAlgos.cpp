/*

1. BRUTE - O(n*n)

2. RABIN CARP  --> uses rolling hash to reuce number of substring comparison
                a good hash is polynomial rolling hash
                O(n+m) in average
                O(n*m) in worst

3. KMP  --> precomute a pie/lps arry that tell us the longest proper prefix that
            is equal to a suffix in the pattern upto that index
            During comparing if a character is not same the previous was same
            so just check for the longest prefic that was matched in teh pattern
            and go just that much back.


*/


#include<iostream>
#include<string>
#include<vector>
using namespace std;

int brute(string s,string t){
    int n = s.size() , m = t.size();
    for(int i=0;i<=n-m;i++){
        int j=0;
        while(j<m && s[j+i]==t[j]) j++;
        if(j==m) return i;
    }
    return-1;
}
    
int rabin_carp(string s,string t){
    int n = s.size();
    int m = t.size();
    int hashofx = 0 , rollhash=0;
    for(auto i:t) hashofx += i;
    
    int j=0;
    for(int i=0;i<n;i++){
        rollhash+=s[i];
        if(i-j+1>m){
            rollhash-=s[j];
            j++;
        }
        if(i-j+1==m && rollhash ==hashofx){
            int k=0;
            while(k<m && s[k+j]==t[k]){
                k++;
            }
            if(k==m) return j; 
        }
    }
    return -1;

}


int KMP(string s,string t){
    int n = s.size() , m = t.size();

    //precompute lps array
    vector<int>lps(m);
    int i=1,j=0;
    while(i<m){
        if(t[i]==t[j]){
            j++;
            lps[i] = j;
            i++;
        }
        else if(j==0){
            lps[i] =0;
            i++;
        }
        else j = lps[j-1];
    }
    

    //kmp
    i=0,j=0;
    while(i<n){
        if(s[i]==t[j]){
            i++;
            j++;
        }
        else if(j==0) i++;
        else{
            j = lps[j-1];
        }
        if(j==m) return i-m;
    }
    return -1;
}

int main(){
    string text = "ababaaaaaaa" ,pattern = "abaa";

    cout<<brute(text,pattern)<<endl;
    cout<<rabin_carp(text,pattern)<<endl;
    cout<<KMP(text,pattern)<<endl;
}