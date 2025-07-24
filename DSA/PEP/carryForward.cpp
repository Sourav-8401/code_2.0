int carryforward(vector<int> arr){
    int n = arr.size();
    int cnt=0;
    int acnt =0;
    for(int i=0; i<n;i++){
        if(arr[i]=='a'){
            acnt++;
        }
        if(arr[i] == 'g'){
            cnt += acnt;
        }
    }
    return cnt;
}

// some value is carried forward like 

