#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include<stdlib.h>
#include<time.h>
#include<stack>
#include <utility>
#include <windows.h>
#include "functions.h"
#include <string>
using namespace sf;
using namespace std;
int colorx,colory;
pair<int,int> drawing;
bool done_dfs = 0;
bool done_prim = 0;
int dfs_step = 0;
int prim_step = 0;
int gridsize = 20;
int l;
vector<sf::Text> Textvector(10,sf::Text());
void changecolor(int i,int j,int r,int g,int b,vector<vector< sf::VertexArray>> &q);
void initialvector(int l,int startx,int starty,vector<vector< sf::VertexArray>> &q);
void updatetext(Text text);

int main()
{
    Text text;
    Font font;
    font.loadFromFile("Fonts/Party Confetti.ttf");


    cin>>l;
    l = l*2+1;




    vector<vector< sf::VertexArray>> dfsvector(l,vector<sf::VertexArray>(l,sf::VertexArray(sf::Quads, 4)));
    vector<vector< sf::VertexArray>> primvector(l,vector<sf::VertexArray>(l,sf::VertexArray(sf::Quads, 4)));
    maze dfs_class;
    dfs_class.initial_maze(l);

    maze prim_class;
    prim_class.initial_maze(l);

    initialvector(l,0,0,dfsvector);
    initialvector(l,(gridsize+2)*l,0,primvector);


    text.setFont(font);
    text.setCharacterSize(gridsize*l/10);
    text.setString("DFS algorithm");
    text.setPosition(sf::Vector2f(gridsize*l*0.25,gridsize*l+1));
    Textvector[0] =text;
    text.setFont(font);
    text.setCharacterSize(gridsize*l/10);
    text.setString("Prim's algorithm");
    text.setPosition(sf::Vector2f(gridsize*(l)*1.25,gridsize*l+1));
    Textvector[1] = text;


    sf::RenderWindow window(sf::VideoMode(1920, 1080), "20729 »¯¤åÁ¾");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        if(!done_prim){
            getpos drawxy = prim_class.prim();

            colory = drawxy.y;
            colorx = drawxy.x;
            if (colorx>0){
                changecolor(colory,colorx,0,255,0,primvector);
                prim_step++;
            }
            else{
                done_prim = 1;

            }
        }


        for(int i=0;i<l;i++){
            for(int j=0;j<l;j++){
                window.draw(primvector[i][j]);
            }
        }
        if(!done_prim) changecolor(colory,colorx,255,255,255,primvector);

        if(!done_dfs){
            getpos drawxy;
            drawxy = dfs_class.dfs();

            colory = drawxy.y;
            colorx = drawxy.x;
            if (colorx>0){
                changecolor(colory,colorx,0,255,0,dfsvector);
                dfs_step++;
            }
            else{
                done_dfs = 1;


            }
        }


        for(int i=0;i<l;i++){
            for(int j=0;j<l;j++){
                window.draw(dfsvector[i][j]);
            }
        }
        if(!done_dfs) changecolor(colory,colorx,255,255,255,dfsvector);
        updatetext(text);
        for(int i=0;i<5;i++){
            window.draw(Textvector[i]);
        }

        window.display();
        Sleep(1);
    }//end while true

    return 0;
} // end main

void changecolor(int i,int j,int r,int g,int b,vector<vector< sf::VertexArray>> &q){

    for(int v=0;v<4;v++){
        q[i][j][v].color = sf::Color(r,g,b);
    }
}



void initialvector(int l,int startx,int starty,vector<vector< sf::VertexArray>> &q){
    for(int i=0;i<l;i++){
        for(int j=0;j<l;j++){
            q[i][j][0].position = sf::Vector2f(startx+gridsize*i,starty+gridsize*j);
            q[i][j][1].position = sf::Vector2f(startx+gridsize*i+gridsize,starty+gridsize*j);
            q[i][j][2].position = sf::Vector2f(startx+gridsize*i+gridsize,starty+gridsize*j+gridsize);
            q[i][j][3].position = sf::Vector2f(startx+gridsize*i,starty+gridsize*j+gridsize);
                if(!(i%2&&j%2)){
                    changecolor(i,j,0,0,255,q);
                }
                else{
                    changecolor(i,j,255,255,255,q);
                }
            }
    }
}
void updatetext(Text text){

    string s;
    s = "step count " + to_string(dfs_step);
    text.setString(s);
    text.setPosition(sf::Vector2f(gridsize*l*0.25,gridsize*(l)*1.1));
    Textvector[2] = text;
    s = "step count " + to_string(prim_step);
    text.setString(s);
    text.setPosition(sf::Vector2f(gridsize*l*1.25,gridsize*(l)*1.1));
    Textvector[3] = text;

}






