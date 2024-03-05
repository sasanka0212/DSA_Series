#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    deque<long long int> dq;
    vector<long long> ans;
    
    //for first negetive in k sized window
    for(int i = 0; i<K; i++) {
        if(A[i] < 0)
            dq.push_back(i);
    }
    
    //process first negetive from k sized window
    if(!dq.empty())
        ans.push_back(A[dq.front()]);
    else
        ans.push_back(0);
        
    //process further k sized window from array
    for(int i = K; i<N; i++) {
        // element not in k sized window
        if(!dq.empty() && i - dq.front() >= K)
            dq.pop_front();
        //store index of negetive element
        if(A[i] < 0)
            dq.push_back(i);
        //store first negetive elemenet from every k sized window
        if(!dq.empty())
            ans.push_back(A[dq.front()]);
        else
            ans.push_back(0);
    }
    return ans;
 }

int main() {
    long long int A[] = {2, -1, 11, 10, -22, 9, 6, -5, -19, 10, 19, 15, -18};
    vector<long long> ans;
    ans = printFirstNegativeInteger(A, 13, 3);
    for(long long i : ans) 
        cout << i << " ";
}