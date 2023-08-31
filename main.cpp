#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int MAXN=1000;
int a[1000][MAXN];
int used[1000], b[MAXN], num[1000];
int cnt, p, out[MAXN];
char d[MAXN];

void test(){
    for(int i = 0; i < cnt; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

void print(){//输出（大数在前）
    out[0]=a[p][0];
    for (int i = 0; i < 3; ++i) {
        if(d[i+1]=='+'){
            out[i+1]=out[i]+a[p][i+1];
            if(a[p][i+1]>out[i]){
                cout<<a[p][i+1]<<d[i+1]<<out[i]<<"="<<out[i+1];
            }else{
                cout<<out[i]<<d[i+1]<<a[p][i+1]<<"="<<out[i+1];
            }
        }else if(d[i+1]=='-'){
            out[i+1]=out[i]-a[p][i+1];
            cout<<out[i]<<d[i+1]<<a[p][i+1]<<"="<<out[i+1];
        }else if(d[i+1]=='*'){
            out[i+1]=out[i]*a[p][i+1];
            if(a[p][i+1]>out[i]){
                cout<<a[p][i+1]<<d[i+1]<<out[i]<<"="<<out[i+1];
            }else{
                cout<<out[i]<<d[i+1]<<a[p][i+1]<<"="<<out[i+1];
            }
        }else{
            out[i+1]=out[i]/a[p][i+1];
            if(a[p][i+1]>out[i]){
                cout<<a[p][i+1]<<d[i+1]<<out[i]<<"="<<out[i+1];
            }else{
                cout<<out[i]<<d[i+1]<<a[p][i+1]<<"="<<out[i+1];
            }
        }
        cout<<endl;
    }
}

void dfs1(int r){//全排列
    if(r>=4){
        for (int i = 0; i < 4; ++i) {
            a[cnt][i]=b[i];
        }
        cnt++;
        return;
    }else{
        for (int i = 0; i < 4; ++i) {
            int x=a[0][i];
            if(used[x]<num[x]){
                b[r]=x;
                used[x]++;
                dfs1(r+1);
                used[x]--;
            }
        }
    }
}

void dfs2(int step, int ans){//查找答案
    if(step>=4){
        if(ans==24){
            print();
            exit(0);
        }
    }else{
        for (int i = 0; i < 4; ++i) {
            if(i==0){
                ans+=a[p][step];
                d[step]='+';
            }else if(i==1){
                ans-=a[p][step];
                d[step]='-';
            }else if(i==2){
                ans*=a[p][step];
                d[step]='*';
            }else if(ans%a[p][step]==0){
                ans/=a[p][step];
                d[step]='/';
            }else{
                return;
            }
            dfs2(step+1, ans);
            if(i==0){
                ans-=a[p][step];
            }else if(i==1){
                ans+=a[p][step];
            }else if(i==2){
                ans/=a[p][step];
            }else{
                ans*=a[p][step];
            }
        }
    }
}

void print2(){
    out[0]=a[p][0];
    if(d[1]=='+'){
        out[1]=out[0]+a[p][1];
        if(a[p][1]>out[0]){
            cout<<a[p][1]<<d[1]<<out[0]<<"="<<out[1];
        }else{
            cout<<out[0]<<d[1]<<a[p][1]<<"="<<out[1];
        }
    }else if(d[1]=='-'){
        out[1]=out[0]-a[p][1];
        cout<<out[0]<<d[1]<<a[p][1]<<"="<<out[1];
    }else if(d[1]=='*'){
        out[1]=out[0]*a[p][1];
        if(a[p][1]>out[0]){
            cout<<a[p][1]<<d[1]<<out[0]<<"="<<out[1];
        }else{
            cout<<out[0]<<d[1]<<a[p][1]<<"="<<out[1];
        }
    }else{
        out[1]=out[0]/a[p][1];
        if(a[p][1]>out[0]){
            cout<<a[p][1]<<d[1]<<out[0]<<"="<<out[1];
        }else{
            cout<<out[0]<<d[1]<<a[p][1]<<"="<<out[1];
        }
    }
    cout<<endl;
    out[2]=a[p][2];
    if(d[3]=='+'){
        out[3]=out[2]+a[p][3];
        if(a[p][3]>out[2]){
            cout<<a[p][3]<<d[3]<<out[2]<<"="<<out[3];
        }else{
            cout<<out[2]<<d[3]<<a[p][3]<<"="<<out[3];
        }
    }else if(d[3]=='-'){
        out[3]=out[2]-a[p][3];
        cout<<out[2]<<d[3]<<a[p][3]<<"="<<out[3];
    }else if(d[3]=='*'){
        out[3]=out[2]*a[p][3];
        if(a[p][3]>out[2]){
            cout<<a[p][3]<<d[3]<<out[2]<<"="<<out[3];
        }else{
            cout<<out[2]<<d[3]<<a[p][3]<<"="<<out[3];
        }
    }else{
        out[3]=out[2]/a[p][3];
        if(a[p][3]>out[2]){
            cout<<a[p][3]<<d[3]<<out[2]<<"="<<out[3];
        }else{
            cout<<out[2]<<d[3]<<a[p][3]<<"="<<out[3];
        }
    }
    cout<<endl;
    cout<<out[1]<<d[2]<<out[3]<<"=24"<<endl;
}

void dfs3(int step, int ans, int ans2){//两两配对的答案
    if(step>=2){
        int r[4];
        r[0]=ans+ans2;
        r[1]=ans-ans2;
        r[2]=ans*ans2;
        if(ans2>0 && ans%ans2==0){
            r[3]=ans/ans2;
        };
        for (int i = 0; i < 4; ++i) {
            if(r[i]==24){
                if(i==0){
                    d[step]='+';
                }else if(i==1){
                    d[step]='-';
                }else if(i==2){
                    d[step]='*';
                }else{
                    d[step]='/';
                }
                print2();
                exit(0);
            }
        }
        return;
    }else{
        for (int i = 0; i < 4; ++i) {
            if(i==0){
                ans+=a[p][step];
                d[step]='+';
            }else if(i==1){
                ans-=a[p][step];
                d[step]='-';
            }else if(i==2){
                ans*=a[p][step];
                d[step]='*';
            }else if(ans%a[p][step]==0){
                ans/=a[p][step];
                d[step]='/';
            }else{
                return;
            }
            for (int j = 0; j < 4; ++j) {
                if(j==0){
                    ans2+=a[p][step+2];
                    d[step+2]='+';
                }else if(j==1){
                    ans2-=a[p][step+2];
                    d[step+2]='-';
                }else if(j==2){
                    ans2*=a[p][step+2];
                    d[step+2]='*';
                }else if(ans%a[p][step+2]==0){
                    ans2/=a[p][step+2];
                    d[step+2]='/';
                }else{
                    return;
                }
                dfs3(step+1, ans, ans2);
                if(j==0){
                    ans2-=a[p][step+2];
                }else if(j==1){
                    ans2+=a[p][step+2];
                }else if(j==2){
                    ans2/=a[p][step+2];
                }else{
                    ans2*=a[p][step+2];
                }
            }
            if(i==0){
                ans-=a[p][step];
            }else if(i==1){
                ans+=a[p][step];
            }else if(i==2){
                ans/=a[p][step];
            }else{
                ans*=a[p][step];
            }
        }
    }
}


int main(){
    for (int i = 0; i < 4; ++i) {
        scanf("%d", &a[0][i]);
        num[a[0][i]]++;
    }
    dfs1(0);
    for(int i = 0; i < cnt; ++i) {
        p=i;
        dfs2(1, a[p][0]);
    }
    p=1;
    dfs3(1, a[p][0], a[p][2]);
    for(int i = 0; i < cnt; ++i) {
        p=i;
        dfs3(1, a[p][0], a[p][2]);
    }
    cout<<"No answer!"<<endl;
    return 0;
}