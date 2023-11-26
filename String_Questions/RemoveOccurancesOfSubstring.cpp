// Remove all occurances of substring
#include<iostream>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length()!=0 && s.find(part)<s.length()){
            s.erase(s.find(part), part.length());
        }   
        return s;
    }
};

int main(){
    string s, part;
    cout<<"Enter a string : ";
    cin>>s;
    cout<<"Enter substring : ";
    cin>>part;
    Solution S;
    cout<<"After removing all occurances of substring : "<<S.removeOccurrences(s, part);
    return 0;
}