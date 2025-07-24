#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    string word1,word2;
	    cin >> word1 >> word2;
    	vector<int> freq1(26,0);
    	vector<int> freq2(26,0);
    	priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>> pq;
	    for(char ch : word1) freq1[ch - 'a']++;
	    for(char ch : word2) freq2[ch - 'a']++;
	    for(int i =0;i<word1.size();i++) pq.push({i+1,word1[i]});
	    int j = 0;
	    int count = 0;
	    long long cost = 0;
	    bool flag = false;
	    for(char ch : word2){
	        if(freq1[ch - 'a'] < freq2[ch -'a']){
    	        cost = -1;
                flag = true;
    	        break;
	        }
	    }
        while(j < word2.size() && !flag){
            int currCost = pq.top().first;
            char currChar = pq.top().second;
            pq.pop();
            if(word2[j] == currChar){
                if(freq1[currChar - 'a'] >freq2[currChar - 'a'] ){
                    cost+= currCost - count;
                    count++;
                    freq1[currChar - 'a']--;
                }else{
                    freq1[currChar - 'a']--;
                    freq2[currChar - 'a']--;
                    j++;
                }
            }else{
               cost+= currCost - count;
               count++;
            }
        }
        while(!pq.empty() && !flag){
            int currCost = pq.top().first;
            pq.pop();
            cost+= currCost - count;
            count++;
        }
        cout << cost << endl;   
	}
    return 0;
}