void maxSubarray(vector<int> arr){
    int n= arr.size();
    int mxsum = 0;
    int sum = 0;
    for(int i=0; i<n; i++){
        if(sum + arr[i]>0){
            sum = sum + arr[i];
        }else{
            sum = 0;
        }
        mxsum = max(mxsum, sum);
    }
    return mxsum;
}