int upper(vector<int>&arr,int l,int r,int k){
        int ans = -1;
        while(l<=r){
                int mid = l + (r-l)/2;
                if(arr[mid]>=k){
                        ans = mid;
                        r = mid-1;
                }
                else l = mid+1;
        }
        return ans;
}

int lower(vector<int>&arr,int l,int r,int k){
        int ans = -1;
        while(l<=r){
                int mid = l + (r-l)/2;
                if(arr[mid]<=k){
                        ans = mid;
                        l = mid+1;
                }
                else r = mid-1;
        }
        return ans;
}
