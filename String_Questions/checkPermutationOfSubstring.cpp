#include<iostream>
using namespace std;

class Solution {
    private:
    bool checkEqual(int count1[], int count2[]) {
        for(int i = 0; i<26; i++) {
            if(count1[i] != count2[i])
                return false;
        }
        return true;
    }
    public:
    bool checkPermutation(string s1, string s2) {
        int count1[26] = {0};
        for(int i = 0; i<26; i++) {
            int index = s1[i] - 'a';
            count1[index]++;
        }

        int windowSize = s1.length();
        int i = 0;
        int count2[26] = {0};
        while(i < windowSize && i < s2.length()) {
            int index = s2[i] - 'a';
            count2[index]++;                
            i++;
        }

        if(checkEqual(count1, count2)) 
            return true;

        while(i < s2.length()) {
            char newChar = s2[i];
            int index = newChar - 'a';
            count2[index]++;

            char oldChar = s2[i-windowSize];
            index = oldChar - 'a';
            count2[index]--;

            if(checkEqual(count1, count2)) 
                return true;
            i++;
        }
        return false;
    }
};

int main() {
    Solution s;
    string s1 = "ab";
    string s2 = "dcbaooi";

    cout << s.checkPermutation(s1, s2) << endl;
}