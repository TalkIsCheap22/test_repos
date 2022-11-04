#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int a[1000],b[1000],jiaoji[1000],bingji[2000],yuji[1000];
int n,m,num_jiaoji,num_bingji,num_yuji=0;

void cal_jiaoji(){
    int index=0;
    for(int i=0;i<n;i++){
        if(a[i]>b[m-1])break;
        while(a[i]>b[index])index++;
        if(a[i]==b[index]){
            jiaoji[num_jiaoji]=a[i];
            num_jiaoji++;
            index++;
        }
    }
}

void cal_bingji(){
    int index=0;
    int mark=0;
    for(int i=0;i<n;i++){
        if(a[i]>b[m-1])break;
        mark=i;
        while(a[i]>b[index]){
            bingji[num_bingji]=b[index];
            num_bingji++;
            index++;
        }
        bingji[num_bingji]=a[i];
        num_bingji++;
        if(a[i]==b[index])index++;
    }
    for(int i=index;i<m;i++){
        bingji[num_bingji]=b[i];
        num_bingji++;
    }
    for(int i=mark+1;i<n;i++){
        bingji[num_bingji]=a[i];
        num_bingji++;
    }
}

void cal_yuji(){
    int index=0;
    int mark=0;
    for(int i=0;i<n;i++){
        if(a[i]<=b[m-1]){
            mark=i;
            while(a[i]>b[index])index++;
            if(a[i]<b[index]){
                yuji[num_yuji]=a[i];
                num_yuji++;
            }
        }
        else break;
    }
    for(int i=mark+1;i<n;i++){
        yuji[num_yuji]=a[i];
        num_yuji++;
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    cin>>m;
    for(int i=0;i<m;i++)cin>>b[i];
    cal_jiaoji();
    cal_bingji();
    cal_yuji();
    if(num_jiaoji!=0){
        for(int i=0;i<num_jiaoji;i++)cout<<jiaoji[i]<<" ";
        cout<<"\n";
    }
    for(int i=0;i<num_bingji;i++)cout<<bingji[i]<<" ";
    cout<<"\n";
    if(num_yuji!=0){
        for(int i=0;i<num_yuji;i++)cout<<yuji[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
