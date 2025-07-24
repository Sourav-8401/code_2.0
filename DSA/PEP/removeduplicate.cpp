vector<int> removeDuplicate(vector<int>& arr){
    int n= arr.size();
    set<int> st;
    for(int i=0; i<n; i++){
        st.insert(arr[i]);
    }
    for(auto i: st){
        filter_arr.push_back(i);
    }
    return filter_arr;
}
