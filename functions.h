

#include <iostream>
#include <utility>
#include<vector>
#include <SFML/Graphics.hpp>
#include<time.h>
#include<iostream>
using namespace std;
struct getpos{
    int x,y,color;
};

class maze{
    int l;
    int y=1,x=1;
    int arr[201][201];
    int visited[201][201];
    int pick[4];
    int direction[4][2] = {{2,0},{0,2},{-2,0},{0,-2}};

    //vector<vector< sf::VertexArray>> dfsvector(l,vector<sf::VertexArray>(l,sf::VertexArray(sf::Quads, 4)));
public:
    void initial_maze(int leng){
        l = leng;
        srand(time(NULL));
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
    getpos dfs();
    getpos prim();

};














