vector<int> min_window_sort(vector<int> arr){
    int n= arr.size();
    int start = -1, end = -1;
    for(int i=0; i<n-1; i++){
        if(arr[i] > arr[i+1]){
            start = i++;
            while(i+1<n && arr[i] < arr[i+1]){
                i++;
            }
            end = i+1;
        }
    }
    return {start, end};
}