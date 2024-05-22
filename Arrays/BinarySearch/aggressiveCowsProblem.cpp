#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &stalls, int k, int mid) {
    int cowCount = 1;
    int lastPos = stalls[0];
    for(int i = 0; i<stalls.size(); i++) {
        if(stalls[i] - lastPos >= mid) {
            cowCount++;
            if(cowCount == k)
                return true;
            lastPos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end());
    int s = 0;
    int e = stalls[stalls.size()-1];
    int ans = -1;
    int mid = s + (e - s) / 2;
    while(s <= e) {
        if(isPossible(stalls, k, mid)) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main(){
    vector<int> stalls = {4, 2, 3, 6, 1};
    int cowsCount = 3;

    cout << endl << "Maximum possible distance is :" << aggressiveCows(stalls, cowsCount);
}