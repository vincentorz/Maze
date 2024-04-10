
#include <iostream>
#include <vector>
#include<stdlib.h>
#include<time.h>
#include<stack>
#include <utility>
#include "functions.h"

using namespace std;

int x=1,y=1;
int breakx,breaky;
int direction[4][2] = {{2,0},{0,2},{-2,0},{0,-2}}; //yx
int pick[4];
int l;
int arr[100][100];
int visited[100][100];
stack<pair<int,int>> path;
void initial_dfs(int leng){
    srand(time(NULL));
    l = leng;
    for(int i=0;i<l;i++){
        for(int j=0;j<l;j++){
            if(i%2&&j%2){
                arr[i][j] = 1;
            }
            else{
                arr[i][j]=0;
            }
            visited[i][j] = 0;
        }
    }
}
pair<int,int> onestep_dfs()
{
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


    if(a>0){ // a = which direction can go
        dir = pick[rand()%a];
        breakx = x+(direction[dir][1]/2);
        breaky = y+(direction[dir][0]/2);
        arr[breaky][breakx] = 1;

        x+=direction[dir][1];
        y+=direction[dir][0];
        path.push({y,x});
        return {breaky,breakx};
    }
    else{ //dead end
        path.pop();
        if(!path.empty()){

            x = path.top().second;
            y = path.top().first;
            return {x,y};
        }
        else{
            cout<<"empty";
            return{-1,-1};
        }


    }
}












