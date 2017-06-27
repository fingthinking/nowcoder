#include <iostream>

using namespace std;
/**
 * 16进制转换就是从第一位数一直加到最后一位数
 * @return
 */
int main(){
    string str;
    while(getline(cin,str)){
        int num=0;
        int m;
        for(int i=0; i<str.length(); i++){
            char c = str[i];
            if(c>='0' && c<='9'){
                m = c-'0';
            } else if(c >='A' && c<='F'){
                m = c-'A'+10;
            }
            num = (num<<4) + m;
        }
        cout<<num<<endl;
    }
}