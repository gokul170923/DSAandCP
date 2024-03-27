class Solution {

    //      https://leetcode.com/problems/sum-of-subarray-minimums/

public:
    int sumSubarrayMins(vector<int>& arr) {
    int n =arr.size();
    //NUMBER OF SUBSET = N*(N+1)/2;
    vector<int>left(n,-1),right(n,n);
    stack<int>st;

    //FIND THE LARGEST SUBARRAY WITH THE CURRENT ELEMENT AS SMALLEST

    //NSL
    for(int i=0;i<n;i++){
        while(st.empty()==false && arr[st.top()]>arr[i]){
            st.pop();
        }
        if(st.empty()==false) left[i]= st.top();
        st.push(i);
    }
    
    //NSR
    st = stack<int>();

    for(int i =n-1;i>=0;i--){
        //FOR DUPLICACY USE (< AND <=)
        while(st.empty()==false && arr[st.top()]>=arr[i]){
            st.pop();
        }
        if(st.empty()==false) right[i]= st.top();
        st.push(i);    
    }

    long long ans=0,m = 1e9+7;
   
    // SUBARRAY FOR _X_ = LEFT*RIGHT permutation

    for(int i=0;i<n;i++){
        long long l = i-left[i];
        long long r = right[i]-i;
        long long temp =(l*r)%m;
        ans += (arr[i]*temp)%m;
        ans%=m;
    }
    return ans%m;
    }
    
};