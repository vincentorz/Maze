#include <iostream>
#include<stdlib.h>
#include<time.h>
#include<stack>
#include <windows.h>
int x=1,y=1;
using namespace std;
int direction[4][2] = {{2,0},{0,2},{-2,0},{0,-2}}; //yx
int pick[4];

int main()
{
    //HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    //SetConsoleTextAttribute(h,13);
    srand(time(NULL));
    int l;
    cin>>l;
    l = l*2+1;
    int arr[l][l];
    int visited[l][l];
    stack<pair<int,int>> path;
    for(int i=0;i<l;i++){
        for(int j=0;j<l;j++){
            if(i%2&&j%2)
                arr[i][j] = 1;
            else
                arr[i][j]=0;
            visited[i][j] = 0;
        }
    }

    while(true){
        visited[y][x] = 1;

        int a = 0,dir; //for picking direction
        for(int i=0;i<4;i++){
            int newy = y+direction[i][0];
            int newx = x+direction[i][1];
            if(newx<l&&newx>=0&&newy<l&&newy>=0){
                if (visited[newy][newx]==0){
                    pick[a] = i;
                    a++;
                }
            }
        }
        if(a>0){
            dir = pick[rand()%a];
            arr[y+(direction[dir][0]/2)][x+(direction[dir][1]/2)] = 1;
            x+=direction[dir][1];
            y+=direction[dir][0];
            path.push({y,x});



        }
        else{ //dead end
            path.pop();
            if(path.empty()){
                break;
            }
            //cout<<path.top().first<<" "<<path.top().second;
            x = path.top().second;
            y = path.top().first;

        }

    }
    for(int i=0;i<l;i++){
        for(int j=0;j<l;j++){
            if (!arr[i][j]){
                cout<<0<<" ";
            }
            else{
                cout<<"1 ";
            }

        }
        cout<<endl;
    }

    return 0;
}
