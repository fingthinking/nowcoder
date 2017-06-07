#include <iostream>
#include <cstring>
using namespace std;
class Solution {
public:
    void replaceSpace(char *str, int length) {
        // 创建一个新的数组,然后赋值,最后再赋值回去
        int index = 0;
        char tmp[3 * length];
        for (int i=0; i < length; i++) {
            if (str[i] == ' ') {
                tmp[index++] = '%';
                tmp[index++] = '2';
                tmp[index++] = '0';
            } else {
                tmp[index++] = str[i];
            }
        }
        tmp[index] = '\0';
        strcpy(str,tmp);
    }
};

//int main(){
//    char m_str[] = "We Are Happy.";
//    Solution s;
//    cout<< strlen(m_str)<<endl;
//    s.replaceSpace(m_str,strlen(m_str));
//    cout<<m_str<<endl;
//}