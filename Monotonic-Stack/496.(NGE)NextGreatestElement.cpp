//     https://leetcode.com/problems/next-greater-element-i/description/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        vector<int>ans(nums1.size(),-1);
        stack<int>st;

        //RIGHT GREATEST USING STACK
        for(int i=nums2.size()-1;i>=0;i--){
            
            // pop the stack until a greater elemnt is found since it 
            // will be the right greatest.
            while(st.empty()==false && st.top()<=nums2[i]){
                st.pop();
            }
            // here your right greatest is at top;
            if(st.empty()==false) mp[nums2[i]] = st.top();
            else mp[nums2[i]] =-1;

            st.push(nums2[i]);
        }
        
        //  NEED TO BE DONE using map BECAUSE OF TwO ARRAY.
        for(int i=0;i<nums1.size();i++){
            ans[i] = mp[nums1[i]];
        }
        return ans;
        
    }
};
