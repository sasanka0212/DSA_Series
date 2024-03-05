#include<iostream>
using namespace std;

class petrolPump {
    public:
    int petrol;
    int distance;
};

int tour(petrolPump p[],int n)
    {
        int depicit = 0;
        int balance = 0;
        int start = 0;
        
        for(int i = 0; i<n; i++) {
            balance = balance + p[i].petrol - p[i].distance;
            if(balance < 0) {
                start = i + 1;
                depicit = depicit + balance;
                balance = 0;
            } 
        }
        if(balance + depicit >= 0) {
            return start;
        }
        return -1;
    }

int main() {
    petrolPump p[] = {{4,6}, {6,5}, {7,3}, {4,5}};
    int ans = tour(p, 4);
    cout << "Source is " << ans;
}