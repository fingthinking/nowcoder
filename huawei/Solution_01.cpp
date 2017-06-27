#include <iostream>

using namespace std;

int main(){
    string str;
    getline(cin,str); // 为了输入到string中包含空格,必须使用getline方法
    long len = str.length();
    long pos = str.rfind(' ');
    if(pos > len){
        cout<<len;
    }else{
        cout<<len-pos-1;
    }
}