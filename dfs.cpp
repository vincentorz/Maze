

#include <iostream>
#include <vector>
#include<stdlib.h>
#include<time.h>
#include<stack>
#include <utility>
#include "functions.h"

using namespace std;


int breakx,breaky;

stack<pair<int,int>> path;


getpos maze::dfs(){
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
    getpos posdfs;
    if(a>0){ // a = which direction can go

        dir = pick[rand()%a];
        breakx = x+(direction[dir][1]/2);
        breaky = y+(direction[dir][0]/2);
        arr[breaky][breakx] = 1;

        x+=direction[dir][1];
        y+=direction[dir][0];
        path.push({y,x});
        posdfs.x = breakx;
        posdfs.y = breaky;
        posdfs.color = 1;
        return posdfs;
    }
    else{ //dead end
        path.pop();
        if(!path.empty()){

            x = path.top().second;
            y = path.top().first;

            posdfs.x = x;
            posdfs.y = y;
            posdfs.color = 1;

            return posdfs;
        }
        else{
            posdfs.x = -1;
            posdfs.y = -1;
            posdfs.color = 1;
            return posdfs;

        }
    }



}











