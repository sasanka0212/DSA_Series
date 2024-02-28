// sum of minimum and maximum element of every subarray of size k
#include<iostream>
#include<queue>
using namespace std;

int solve(int *arr, int N, int K) {
    deque<int> maxi(K);
    deque<int> mini(K);
    for(int i = 0; i<K; i++) {
        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();
        while(!mini.empty() && arr[mini.back()] >= arr[i]) 
            mini.pop_back();
        maxi.push_back(i);
        mini.push_back(i);
    }
    int sum = 0;
    sum += arr[maxi.front()] + arr[mini.front()];

    //for remaining k size subarrays
    for(int i = K; i<N; i++) {
        while(!maxi.empty() && i - maxi.front() >= K) 
            maxi.pop_front();
        while(!mini.empty() && i - mini.front() >= K)
            mini.pop_front();
        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();
        while(!mini.empty() && arr[mini.back()] >= arr[i]) 
            mini.pop_back();
        maxi.push_back(i);
        mini.push_back(i);
        sum += arr[maxi.front()] + arr[mini.front()];
    }
    return sum;
}

int main() {
    int arr[] = {2, 5, -7, 1, 0, 11, -5, 6};
    int ans = solve(arr, 8, 5);
    cout << ans << endl;
}