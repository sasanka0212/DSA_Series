#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int lengthCount = 0;
        int size = chars.size();
        while(i<size){
            int j = i + 1;
            while(j<size && chars[i]==chars[j]){
                j++;
            }
            int count = j - i;
            chars[lengthCount++] = chars[i];
            if(count>1){
                string c = to_string(count);
                for(char ch : c){
                    chars[lengthCount++] = ch;
                }
            }
            i = j;
        }
        return lengthCount;
    }
};

int main(){
    vector<char> chars = {'a', 'a', 'a', 'b', 'c', 'c', 'd', 'd', 'd'};
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