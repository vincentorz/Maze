

#include <iostream>
#include<stdlib.h>
#include<time.h>
#include<stack>
#include <windows.h>
#include<vector>
#include <utility>
#include "functions.h"

using namespace std;
 //yx


vector<pair<int,int>> frontier; //y,x
vector<pair<int,int>> choose;
int newx;
int newy;
int r;


getpos maze::prim(){
    getpos p;
    visited[y][x] = 2;
    for(int i=0;i<4;i++){
        newx = x+direction[i][1];
        newy = y+direction[i][0];
        if(newx<l&&newx>0&&newy<l&&newy>0){
            if(visited[newy][newx]==0){

                frontier.push_back({newy,newx});

                visited[newy][newx] = 1; //become frontier
            }
        }

    }
    if(frontier.empty()){
         p.x=-1;
         p.y = -1;
         p.color = -1;
         return p;
    }

    r = rand()%(frontier.size()); //choosing cell
    x = frontier[r].second;
    y = frontier[r].first;
    frontier.erase(frontier.begin()+r);

    for(int i=0;i<4;i++){ // choosing neighbors wall
        newx = x+direction[i][1];
        newy = y+direction[i][0];
        if(newx<l &&newx>0&&newy<l &&newy>0){
            if(visited[newy][newx]==2){
                choose.push_back({newy,newx});
            }
        }
    }
    r = rand()%(choose.size());
    newx = (x+choose[r].second)/2;
    newy = (y+choose[r].first)/2;
    arr[newx][newy] = 1;


    choose.clear();



    p.x=newx;
    p.y = newy;
    p.color = 1;
    return p;


}

