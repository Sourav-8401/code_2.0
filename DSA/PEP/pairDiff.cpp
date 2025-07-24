vector<int> pairDiff(vector<int>& arr, int k){
        unordered_map<int, int> mp;
        int n=arr.size();
        int cnt=0;
        for(auto x : arr){
            if(mp.find(x-k) != mp.end()){
                cnt += mp[x-k];
            }
            if(mp.find(k+x) != mp.end()){
                cnt += mp[x+k];
            }
            mp[x]++;
        }
        return cnt;
}
