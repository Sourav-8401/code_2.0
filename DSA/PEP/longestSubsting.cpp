vector<int> stringMatch(string s1, string s2){
    int n= s1.size();
    vector<int> mp(26);

    for(int i=0; i<n; i++){
        int pos = s1[i] - 'a';
        mp[pos]++;
    }
    int size =0;
    int s =0;
    for(int i=0; i<s2.size(); i++){
        int curEle = s2[i] - 'a';
        if(mp[curEle] >0 ){
            size++;
            
        }else{
            size = 0;
        }
    }
    if(size == n) 
        return true;
    else 
        return false;
}
