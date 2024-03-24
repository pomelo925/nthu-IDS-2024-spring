//https://acm.cs.nthu.edu.tw/contest/2971/

#include <bits/stdc++.h>
using namespace std;

int N; // 總人數
unordered_map<int,bool> penguin;

void game(const int T, const int A, const int B){
    vector<int> tmp;

    // A 不存在
    if(!penguin[A]) {
        cout << "Penguin07 QQ\n"; 
        return;
    }

    // 殺後面的
    if(T==1){
        for(int i=A+1, count=0; i<=N and count<min(B,N-A); i++){
            // 殺了誰
            if(penguin[i]) {
                penguin[i]=false; count++;
                tmp.push_back(i);
            }

            // 沒殺人
            if(i==N and !count){
                cout << "Penguin07 QQ\n"; 
                return;
            }
        }
        
        // 排大小，列印
        for(int k=0; k<tmp.size(); k++){
            if(!tmp[k]) continue;
            if(k==tmp.size()-1) cout << tmp[k] << "\n";
            else cout << tmp[k] << " ";
        }
    }

    // 殺前面的
    else if(T==2){
        for(int i=A-1, count=0; i>=1 and count<min(B,A-1); i--){
            // 殺了誰
            if(penguin[i]) {
                penguin[i]=false; count++;
                tmp.push_back(i);
            }

            // 沒殺人
            if(i==1 and !count){
                cout << "Penguin07 QQ\n"; 
                return;
            }
        }
        
        // 排大小，列印
        for(int k=tmp.size()-1; k>=0; k--){
            if(!tmp[k]) continue;
            if(k==0) cout << tmp[k] << "\n";
            else cout << tmp[k] << " ";
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int k; cin >> N >> k;
    for(int i=0; i<=N; i++) penguin[i]=true;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int T, A, B; string cmd;
    while(k--){
        getline(cin, cmd); istringstream iss(cmd);
        iss >> T >> A >> B;
        game(T,A,B);
    }
    
    return 0;
}