#include <iostream>

using namespace std;

void init_arr(int arr[], int len, int init_num=0){
    for(int i=0; i<len; i++){
        arr[i] = init_num;
    }
}

int main(){
    int len;
    int arr[1000];

    while(cin>>len){
        // 初始化数组
        init_arr(arr,1000);
        if(len <= 0){
            exit(0);
        }
        // 写入数值
        for(int i=0; i<len; i++){
            int num;
            cin>>num;
            if(arr[num] == 0){
                arr[num]++;
            }
        }

        for(int i=0; i<1000; i++){
            if(arr[i] != 0){
                cout<<i<<endl;
            }
        }
    }
}

