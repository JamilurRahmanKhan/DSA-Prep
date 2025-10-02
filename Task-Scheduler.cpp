// max-heap
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26,0);

        for(char &ch : tasks){
            mp[ch-'A']++;
        }

        priority_queue<int> pq; // max-heap
        int time = 0;

        for(int i=0; i<26; i++){
            if(mp[i] > 0){
                pq.push(mp[i]);
            }
        }

        while(!pq.empty()){
            vector<int> temp;
            for(int i=1; i<= n+1; i++){
                if(!pq.empty()){
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }

            for(int &f : temp){
                if(f > 0){
                    pq.push(f);
                }
            }

            if(pq.empty()){
                time += temp.size();
            }else{
                time += n+1;
            }
        }
        return time;
    }
};

int main() {
    Solution sol;

    // Example test case
    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;

    int result = sol.leastInterval(tasks, n);

    cout << "Least interval time: " << result << endl;  
    // Expected output: 8 (A B idle A B idle A B)

    return 0;
}