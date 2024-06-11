#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int ansIndex = 0;
        int n = chars.size();

        while(i<n) {
            int j = i + 1;
            while(j<n && chars[i] == chars[j]) 
                j++;

            //store character first
            chars[ansIndex++] = chars[i];

            //calculate count and store
            int count = j - i;
            if(count > 1) {
                string cnt = to_string(count);
                for(char ch : cnt)
                    chars[ansIndex++] = ch;
            }
            //index of new character
            i = j;
        }
        return ansIndex;
    }
};

int main(){
    vector<char> chars = {'a', 'a', 'a', 'b', 'c', 'c', 'd', 'd'};
    Solution s;
    cout<<"Actual char array : "<<endl;
    for(char ch : chars){
        cout<<ch<<" ";
    }cout<<endl;

    cout<<"Length of compressed string : "<<s.compress(chars);
    cout<<"After compression : "<<endl;
    for(char ch : chars){
        cout<<ch<<" ";
    }cout<<endl;

    return 0;
}