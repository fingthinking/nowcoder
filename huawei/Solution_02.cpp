#include <iostream>

using namespace std;
int main(){
    static const int CHAR_STEP = 'A'-'a';
    string str;
    char c;
    while(getline(cin,str)){
        cin>>c;
        int len=0;
        for(int index=0; index<str.length(); index++){
            char s = str[index];
            if((s>='a' && s<='z') || (s>='A' && s<='Z')){
                if(s == c || s == c+CHAR_STEP || s==c-CHAR_STEP){
                    len++;
                }
            }
        }
        cout<<len;
        cin.ignore();
    }
}