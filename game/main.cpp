#include <iostream>  //iostream is library for command cout and cin
#include <string>    // -//- for type of variable string
#include <fstream>   // -//- for commands ifstream(r14.)/ofstream and for work with stream
#include <sstream>   // -//- for command stringstream r20.
#include <queue>
#include <cstdlib>
#include <time.h>
#include <SFML/Graphics.hpp>    // library for graphic from sfml

using namespace std;    //std is for commands cin/cout here i declaret to use it every time or if I do`t, I can use it separate in program

struct Point
{
    int x,y;
};

int BLOCK = 16;


int main()
{
    sf::Texture texture;
    if (!texture.loadFromFile("minesweeper_texture.png"))
    {
        std::cout << "Error texture load." << std::endl;
    }
    sf::Texture home_screen_texture;
    if (!home_screen_texture.loadFromFile("minesweeper_title_screen.png"))
    {
        std::cout << "Error texture load2." << std::endl;
    }
    sf::Texture t_easy;
    if (!t_easy.loadFromFile("minesweeper_easy.png"))
    {
        std::cout << "Error texture load3." << std::endl;
    }
    sf::Texture t_easy_press;
    if (!t_easy_press.loadFromFile("minesweeper_easy_press.png"))
    {
        std::cout << "Error texture load4." << std::endl;
    }
    sf::Texture t_medium;
    if (!t_medium.loadFromFile("minesweeper_medium.png"))
    {
        std::cout << "Error texture load5." << std::endl;
    }
    sf::Texture t_medium_press;
    if (!t_medium_press.loadFromFile("minesweeper_medium_press.png"))
    {
        std::cout << "Error texture load6." << std::endl;
    }
    sf::Texture t_hard;
    if (!t_hard.loadFromFile("minesweeper_hard.png"))
    {
        std::cout << "Error texture load7." << std::endl;
    }
    sf::Texture t_hard_press;
    if (!t_hard_press.loadFromFile("minesweeper_hard_press.png"))
    {
        std::cout << "Error texture load8." << std::endl;
    }
    sf::Sprite home_screen, easy, easy_press, medium, medium_press, hard, hard_press;
    home_screen.setTexture(home_screen_texture);
    home_screen.setTextureRect(sf::IntRect(0*BLOCK, 0*BLOCK, 20*BLOCK, 20*BLOCK));
    easy.setTexture(t_easy);
    easy.setTextureRect(sf::IntRect(0*BLOCK, 0*BLOCK, 20*BLOCK, 20*BLOCK));
    easy_press.setTexture(t_easy_press);
    easy_press.setTextureRect(sf::IntRect(0*BLOCK, 0*BLOCK, 20*BLOCK, 20*BLOCK));
    medium.setTexture(t_medium);
    medium.setTextureRect(sf::IntRect(0*BLOCK, 0*BLOCK, 20*BLOCK, 20*BLOCK));
    medium_press.setTexture(t_medium_press);
    medium_press.setTextureRect(sf::IntRect(0*BLOCK, 0*BLOCK, 20*BLOCK, 20*BLOCK));
    hard.setTexture(t_hard);
    hard.setTextureRect(sf::IntRect(0*BLOCK, 0*BLOCK, 20*BLOCK, 20*BLOCK));
    hard_press.setTexture(t_hard_press);
    hard_press.setTextureRect(sf::IntRect(0*BLOCK, 0*BLOCK, 20*BLOCK, 20*BLOCK));
    
    sf::Sprite frame[9];
    for (int i=0; i<9; i++)
    {
        frame[i].setTexture(texture);
        frame[i].setTextureRect(sf::IntRect(i*BLOCK, 0*BLOCK, 1*BLOCK, 1*BLOCK));
    }
    sf::Sprite cowerd_frame, flag_frame, expl_mine, no_mine, mine, cow_qm, uncow_qm;
    cowerd_frame.setTexture(texture);
    cowerd_frame.setTextureRect(sf::IntRect(0*BLOCK, 1*BLOCK, 1*BLOCK, 1*BLOCK));
    flag_frame.setTexture(texture);
    flag_frame.setTextureRect(sf::IntRect(1*BLOCK, 1*BLOCK, 1*BLOCK, 1*BLOCK));
    expl_mine.setTexture(texture);
    expl_mine.setTextureRect(sf::IntRect(2*BLOCK, 1*BLOCK, 1*BLOCK, 1*BLOCK));
    no_mine.setTexture(texture);
    no_mine.setTextureRect(sf::IntRect(3*BLOCK, 1*BLOCK, 1*BLOCK, 1*BLOCK));
    mine.setTexture(texture);
    mine.setTextureRect(sf::IntRect(4*BLOCK, 1*BLOCK, 1*BLOCK, 1*BLOCK));
    cow_qm.setTexture(texture);
    cow_qm.setTextureRect(sf::IntRect(5*BLOCK, 1*BLOCK, 1*BLOCK, 1*BLOCK));
    uncow_qm.setTexture(texture);
    uncow_qm.setTextureRect(sf::IntRect(6*BLOCK, 1*BLOCK, 1*BLOCK, 1*BLOCK));

    bool game=true;
    while (game)
    {

        sf::RenderWindow game_window(sf::VideoMode(20*BLOCK, 20*BLOCK), "Minesweeper");     //here I start graphics by rendering window

        int dfct = 5, rows = 9, cols = 9;     //declarate size of array `net`
        bool play=false;
        while (!play)
        {
            home_screen.setPosition(sf::Vector2f(0*BLOCK, 0*BLOCK));
            game_window.draw(home_screen);
            
            sf::Event event;
            int x,y;
            bool click=false;
            while(game_window.pollEvent(event))
            {
                
                sf::Vector2i mpos = sf::Mouse::getPosition(game_window);
                x = mpos.x/BLOCK;
                y = mpos.y/BLOCK;

                if (event.type == sf::Event::Closed)
                {
                    game_window.close();
                    return 0;
                }
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        click = true;
                    }
                }
            }

            if((x>12) and (x<18) and (11>=y) and (y>8))
            {
                dfct=1;
                easy_press.setPosition(sf::Vector2f(0*BLOCK, 0*BLOCK));
                game_window.draw(easy_press);
                if (click)
                    play=true;
            }
            else
            {
                easy.setPosition(sf::Vector2f(0*BLOCK, 0*BLOCK));
                game_window.draw(easy);
            }
            if((x>9) and (x<18) and (14>=y) and (y>11))
            {
                dfct=2;
                medium_press.setPosition(sf::Vector2f(0*BLOCK, 0*BLOCK));
                game_window.draw(medium_press);
                if (click)
                    play=true;
            }
            else
            {
                medium.setPosition(sf::Vector2f(0*BLOCK, 0*BLOCK));
                game_window.draw(medium);
            }
            if((x>11) and (x<18) and (17>y) and (y>14))
            {
                dfct=3;
                hard_press.setPosition(sf::Vector2f(0*BLOCK, 0*BLOCK));
                game_window.draw(hard_press);
                if (click)
                    play=true;
            }
            else
            {
                hard.setPosition(sf::Vector2f(0*BLOCK, 0*BLOCK));
                game_window.draw(hard);
            }
            

            game_window.display();
            game_window.clear();

        }
        
        int x, y;
        if (dfct==1)
        {
            dfct = 10;
            rows = 11;
            cols = 11;
        }
        else
        {
            if(dfct==2)
            {
                dfct = 40;
                rows = 18;
                cols = 18;
            }
            else
            {
                dfct = 99;
                rows = 24;
                cols = 24;
            }
        }

        bool winnet[rows][cols]={true};
        for (x=0;x<rows;x++)
        {
            for (y=0;y<cols;y++)
            {
                winnet[x][y]=true;
            }
        }
        
        int net [rows][cols]={};   //declarate main array named net and reset every atribute to 0
        srand((int)time(0));
        for (int i=0; i<dfct; i++)
        {
            x = rand() % (rows-2);
            x++;
            y = rand() % (cols-2);
            y++;
            winnet[x][y]=false;
            net [x][y] = 9;
        }

        for (x=0;x<rows;x++)        //this cycle is for seting up playing net, 9=mine, other numbers is number of mines near him
        {
            for (y=0;y<cols;y++)
            {
                if (!winnet[x][y])
                {
                    if (winnet[x+1][y]){net[x+1][y]++;}
                    if (winnet[x+1][y+1]){net[x+1][y+1]++;}
                    if (winnet[x+1][y-1]){net[x+1][y-1]++;}
                    if (winnet[x-1][y]){net[x-1][y]++;}
                    if (winnet[x-1][y+1]){net[x-1][y+1]++;}
                    if (winnet[x-1][y-1]){net[x-1][y-1]++;}
                    if (winnet[x][y+1]){net[x][y+1]++;}
                    if (winnet[x][y-1]){net[x][y-1]++;}
                }
            }
        }

        for (x=0;x<rows;x++)
        {
            net[x][0]=1;
            net[x][cols-1]=1;
        }
    
        for (y=0;y<cols;y++)
        {
            net[0][y]=1;
            net[rows-1][y]=1;
        }

        bool visnet[rows][cols];
        for (x=0;x<rows;x++)
        {
            for (y=0;y<cols;y++)
            {
                visnet[x][y] = true; 
            }
        }
        for (x=1;x<rows-1;x++)
        {
            for (y=1;y<cols-1;y++)        //this cycle is to reset all variable in array visnet to false
            {
                visnet[x][y] = false; 
            }
        }

        int not_click_net[rows][cols];      //array for flags and questionmarks
        for (x=1;x<rows-1;x++)
        {
            for (y=1;y<cols-1;y++)
            {
                not_click_net[x][y] = 0; 
            }
        }

        bool flag_net[rows][cols];
        for (x=0;x<rows;x++)
        {
            for (y=0;y<cols;y++)
            {
                flag_net[x][y] = true;
            }
        }


        game_window.setSize(sf::Vector2u(rows*BLOCK, cols*BLOCK));      // Ask Chiko !!!
        sf::FloatRect visibleArea(0, 0, rows*BLOCK, cols*BLOCK);
        game_window.setView(sf::View(visibleArea));                     // Ask Chiko !!!

        bool run=true;
        int explx=0, exply=0;
        bool expl_reset=true;
        bool win=true;

        while (run)
        {
            int vx=0,vy=0;
            bool flag=false, r_click=false, l_click=false;

            sf::Event e;
            while(game_window.pollEvent(e))
            {
                sf::Vector2i mpos = sf::Mouse::getPosition(game_window);
                vx = mpos.x/BLOCK;
                vy = mpos.y/BLOCK;

                if (e.type == sf::Event::Closed)
                {
                    game_window.close();
                    return 0;
                }
                if (e.type == sf::Event::MouseButtonPressed)
                {
                    if (e.mouseButton.button == sf::Mouse::Left)
                    {
                        l_click = true;
                    }
                }
                if (e.type == sf::Event::MouseButtonPressed)
                {
                    if (e.mouseButton.button == sf::Mouse::Right)
                    {
                        r_click = true;
                    }
                }
            }

            
            if((r_click) and (visnet[vx][vy]==false))
            {
                if(not_click_net[vx][vy]==0)
                {
                    not_click_net[vx][vy]++;
                }
                else                    
                {
                    if(not_click_net[vx][vy]==1)
                    {
                        not_click_net[vx][vy]++;
                    }
                    else
                    {
                        not_click_net[vx][vy]=0;
                    }
                }
            }

            if((l_click) and (not_click_net[vx][vy]==0))
            {
                visnet [vx] [vy] = true;
            }
        
            if ((net[vx][vy]==0) and (visnet[vx][vy]))
            {
                queue<Point>waweq;
                struct Point p;
                p.x = vx;
                p.y = vy;
                waweq.push(p);
                while(!waweq.empty())
                {
                    p = waweq.front();
                    waweq.pop();
                    x = p.x;
                    y = p.y;

                    for (int i=-1; i<2; i++)
                    {
                        for (int j=-1; j<2 ; j++)
                        {
                            if ((i==0) and (j==0))
                                continue;

                            if (net[x+i][y+j]==0 && !visnet[x+i][y+j])
                            {
                                p.x = x+i;
                                p.y = y+j;
                                waweq.push(p);
                            }
                            visnet[x+i][y+j] = true;
                        }
                    }
                }
            }


            for (x=1;x<rows-1;x++)
            {
                for (y=1;y<cols-1;y++)        //this cycle is to write out net and on places of mine it says O on other place it will be X
                {
                    if (visnet[x][y]==false)
                    {
                        if(not_click_net[x][y]==0)
                        {
                            cowerd_frame.setPosition(sf::Vector2f(x*BLOCK, y*BLOCK));
                            game_window.draw(cowerd_frame);
                        }
                        else
                        {
                            if(not_click_net[x][y]==1)
                            {
                                flag_frame.setPosition(sf::Vector2f(x*BLOCK, y*BLOCK));
                                game_window.draw(flag_frame);
                                flag_net[x][y]=false;
                            }
                            else
                            {
                                cow_qm.setPosition(sf::Vector2f(x*BLOCK, y*BLOCK));
                                game_window.draw(cow_qm);
                            }
                        }
                    }
                    else
                    {
                        if(net[x][y]!=9)
                        {
                            int j;
                            j = net[x][y];
                            frame[j].setPosition(sf::Vector2f(x*BLOCK, y*BLOCK));
                            game_window.draw(frame[j]);
                        }
                        else
                        {
                            run=false;
                            if (expl_reset)
                            {
                                explx=x;
                                exply=y;
                                expl_reset=false;
                            }
                        }
                    }
                }
            }

            win=true;
            for (x=1;x<rows-1;x++)
            {
                for (y=1;y<cols-1;y++)        //this cycle is to write out net and on places of mine it says O on other place it will be X
                {
                    if (flag_net[x][y]!=winnet[x][y])
                    {
                        win=false;
                    }
                }
            }

            for (x=1;x<rows-1;x++)
            {
                for (y=1;y<cols-1;y++)        //this cycle is to write out net and on places of mine it says O on other place it will be X
                {
                    if (visnet[x][y]!=flag_net[x][y])
                    {
                        win=false;
                    }
                }
            }

            if(win)
            {
                run=false;
            }

            game_window.display();
        }

        bool end_game=true;
        while (end_game)
        {
            sf::Event e;
            while(game_window.pollEvent(e))
            {
                sf::Vector2i mpos = sf::Mouse::getPosition(game_window);
                if (e.type == sf::Event::Closed)
                {
                    game_window.close();
                    return 0;
                }

            }
            for (x=1;x<rows-1;x++)
            {
                for (y=1;y<cols-1;y++)        //this cycle is to write out net and on places of mine it says O on other place it will be X
                {
                    if (visnet[x][y]==false)
                    {
                        if(not_click_net[x][y]==0)
                        {
                            cowerd_frame.setPosition(sf::Vector2f(x*BLOCK, y*BLOCK));
                            game_window.draw(cowerd_frame);
                        }
                        else
                        {
                            if(not_click_net[x][y]==1)
                            {
                                if(winnet[x][y])
                                {
                                    no_mine.setPosition(sf::Vector2f(x*BLOCK, y*BLOCK));
                                    game_window.draw(no_mine);
                                }
                                else
                                {
                                    flag_frame.setPosition(sf::Vector2f(x*BLOCK, y*BLOCK));
                                    game_window.draw(flag_frame);
                                }
                            }
                            else
                            {
                                cow_qm.setPosition(sf::Vector2f(x*BLOCK, y*BLOCK));
                                game_window.draw(cow_qm);
                            }
                        }
                    }
                    else
                    {
                        if(net[x][y]!=9)
                        {
                            int j;
                            j = net[x][y];
                            frame[j].setPosition(sf::Vector2f(x*BLOCK, y*BLOCK));
                            game_window.draw(frame[j]);
                        }
                        else
                        {
                            for (int i=1;i<rows-1;i++)
                            {
                                for (int j=1;j<cols-1;j++)
                                {
                                    if (net[i][j]==9)
                                    {
                                        if ((i==explx) and (j==exply))
                                        {
                                            expl_mine.setPosition(sf::Vector2f(explx*BLOCK, exply*BLOCK));
                                            game_window.draw(expl_mine);
                                        }
                                        else
                                        {
                                            visnet[i][j]=true;
                                            mine.setPosition(sf::Vector2f(i*BLOCK, j*BLOCK));
                                            game_window.draw(mine);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            game_window.display();
            game_window.clear();
        }
    }

    return 0;       //return to int main number 0
}