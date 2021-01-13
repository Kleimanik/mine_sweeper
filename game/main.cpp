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
    
    sf::Sprite frame0, frame1, frame2, frame3, frame4, frame5, frame6, frame7, frame8;
    sf::Sprite cowerd_frame, flag_frame, expl_mine, no_mine, mine, cow_qm, uncow_qm;
    frame0.setTexture(texture);
    frame0.setTextureRect(sf::IntRect(0*BLOCK, 0*BLOCK, 1*BLOCK, 1*BLOCK));
    frame1.setTexture(texture);
    frame1.setTextureRect(sf::IntRect(1*BLOCK, 0*BLOCK, 1*BLOCK, 1*BLOCK));
    frame2.setTexture(texture);
    frame2.setTextureRect(sf::IntRect(2*BLOCK, 0*BLOCK, 1*BLOCK, 1*BLOCK));
    frame3.setTexture(texture);
    frame3.setTextureRect(sf::IntRect(3*BLOCK, 0*BLOCK, 1*BLOCK, 1*BLOCK));
    frame4.setTexture(texture);
    frame4.setTextureRect(sf::IntRect(4*BLOCK, 0*BLOCK, 1*BLOCK, 1*BLOCK));
    frame5.setTexture(texture);
    frame5.setTextureRect(sf::IntRect(5*BLOCK, 0*BLOCK, 1*BLOCK, 1*BLOCK));
    frame6.setTexture(texture);
    frame6.setTextureRect(sf::IntRect(6*BLOCK, 0*BLOCK, 1*BLOCK, 1*BLOCK));
    frame7.setTexture(texture);
    frame7.setTextureRect(sf::IntRect(7*BLOCK, 0*BLOCK, 1*BLOCK, 1*BLOCK));
    frame8.setTexture(texture);
    frame8.setTextureRect(sf::IntRect(8*BLOCK, 0*BLOCK, 1*BLOCK, 1*BLOCK));
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

    while (true)
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
        string file = "mine.txt";
        srand((int)time(0));
        ofstream outfile;
        outfile.open(file);
        if (!outfile.is_open())
        {
            cout << "Error 404.";
            return 0;
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
        for (int i=0; i<dfct; i++)
        {
            x = rand() % (rows-2);
            x++;
            outfile << x;
            outfile << " ";
            y = rand() % (cols-2);
            y++;
            outfile << y;
            outfile << endl;
        }
        outfile.close();
        if (outfile.is_open())
        {
            cout << "Error 404.";
            return 0;
        }

        int net [rows][cols]={};   //declarate main array named net and reset every atribute to 0

        ifstream infile(file);              //ifstream declarate infile to work with file that we choose
        if (infile.is_open()==false)               //if file is open then fun the program but if not, just say Error 404.(r32)
        {
            cout << "Error 404.";
            return 0;
        }
        string fline, frstint, scndint;
        while (getline(infile,fline))       //getline is to read from file, the secon atribute is variable where getline write from file till he hits endline
        {
            stringstream ss(fline);         //converting string to stream so we can read it with getline
            getline(ss,frstint,' ');        //reading stream `ss` until hits ` ` (the 3rd atribute in bar)
            getline(ss,scndint,' ');    
            x = stoi(frstint);          //stoi is coverting string variable to integer
            y = stoi(scndint);          //stoi is converting only to string!!!
            net [x][y] = 9;
        }


        bool winnet[rows][cols];
        for (x=0;x<rows;x++)
        {
            for (y=0;y<cols;y++)        //this cycle is to set up winnet where mines are false and other is true
            {
                if (net[x][y]==9)
                {
                    winnet[x][y] = false;
                }
                else
                {
                    winnet[x][y] = true;
                }                
            }
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
        for (x=1;x<rows-1;x++)
        {
            for (y=1;y<cols-1;y++)        //this cycle is to reset all variable in array visnet to false
            {
                visnet[x][y] = false; 
            }
        }

        game_window.setSize(sf::Vector2u(rows*BLOCK, cols*BLOCK));      // Ask Chiko !!!
        sf::FloatRect visibleArea(0, 0, rows*BLOCK, cols*BLOCK);
        game_window.setView(sf::View(visibleArea));                     // Ask Chiko !!!

        bool run=true;
        int explx=0, exply=0;
        bool expl_reset=true;

        while (run)
        {
            int vx=0,vy=0;
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
                        visnet [vx] [vy] = true;
                    }
                }
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
                    if (net[x-1][y-1]==0 && !visnet[x-1][y-1])
                    {
                        p.x = x-1;
                        p.y = y-1;
                        waweq.push(p);
                    }
                    visnet[x-1][y-1] = true;

                    if (net[x][y-1]==0 && !visnet[x][y-1])
                    {
                        p.x = x;
                        p.y = y-1;
                        waweq.push(p);
                    }
                    visnet[x][y-1] = true;

                    if (net[x+1][y-1]==0 && !visnet[x+1][y-1])
                    {
                        p.x = x+1;
                        p.y = y-1;
                        waweq.push(p);
                    }
                    visnet[x+1][y-1] = true;

                    if (net[x-1][y]==0 && !visnet[x-1][y])
                    {
                        p.x = x-1;
                        p.y = y;
                        waweq.push(p);
                    }
                    visnet[x-1][y] = true;

                    if (net[x+1][y]==0 && !visnet[x+1][y])
                    {
                        p.x = x+1;
                        p.y = y;
                        waweq.push(p);
                    }
                    visnet[x+1][y] = true;

                    if (net[x-1][y+1]==0 && !visnet[x-1][y+1])
                    {
                        p.x = x-1;
                        p.y = y+1;
                        waweq.push(p);
                    }
                    visnet[x-1][y+1] = true;

                    if (net[x][y+1]==0 && !visnet[x][y+1])
                    {
                        p.x = x;
                        p.y = y+1;
                        waweq.push(p);
                    }
                    visnet[x][y+1] = true;

                    if (net[x+1][y+1]==0 && !visnet[x+1][y+1])
                    {
                        p.x = x+1;
                        p.y = y+1;
                        waweq.push(p);
                    }
                    visnet[x+1][y+1] = true;
                }
            }


            for (x=1;x<rows-1;x++)
            {
                for (y=1;y<cols-1;y++)        //this cycle is to write out net and on places of mine it says O on other place it will be X
                {
                    if (visnet[x][y]==false)
                    {
                        cowerd_frame.setPosition(sf::Vector2f(x*BLOCK, y*BLOCK));
                        game_window.draw(cowerd_frame);
                    }
                    else
                    {
                        if (net[x][y]==0)
                        {
                            frame0.setPosition(sf::Vector2f(x*BLOCK, y*BLOCK));
                            game_window.draw(frame0);
                        }
                        else
                        {
                            if (net[x][y]==1)
                            {
                                frame1.setPosition(sf::Vector2f(x*BLOCK, y*BLOCK));
                                game_window.draw(frame1);
                            }
                            else
                            {
                                if (net[x][y]==2)
                                {
                                    frame2.setPosition(sf::Vector2f(x*BLOCK, y*BLOCK));
                                    game_window.draw(frame2);
                                }
                                else
                                {
                                    if (net[x][y]==3)
                                    {
                                        frame3.setPosition(sf::Vector2f(x*BLOCK, y*BLOCK));
                                        game_window.draw(frame3);
                                    }
                                    else
                                    {
                                        if (net[x][y]==4)
                                        {
                                            frame4.setPosition(sf::Vector2f(x*BLOCK, y*BLOCK));
                                            game_window.draw(frame4);
                                        }
                                        else
                                        {
                                            if (net[x][y]==5)
                                            {
                                                frame5.setPosition(sf::Vector2f(x*BLOCK, y*BLOCK));
                                                game_window.draw(frame5);
                                            }
                                            else
                                            {
                                                if (net[x][y]==6)
                                                {
                                                    frame6.setPosition(sf::Vector2f(x*BLOCK, y*BLOCK));
                                                    game_window.draw(frame6);
                                                }
                                                else
                                                {
                                                    if (net[x][y]==7)
                                                    {
                                                        frame7.setPosition(sf::Vector2f(x*BLOCK, y*BLOCK));
                                                        game_window.draw(frame7);
                                                    }
                                                    else
                                                    {
                                                        if (net[x][y]==8)
                                                        {
                                                            frame8.setPosition(sf::Vector2f(x*BLOCK, y*BLOCK));
                                                            game_window.draw(frame8);
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
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

            game_window.display();
        }

            bool win=true;
            for (x=1;x<rows-1;x++)
            {
                for (y=1;y<cols-1;y++)        //this cycle is to write out net and on places of mine it says O on other place it will be X
                {
                    if (visnet[x][y]!=winnet[x][y])
                    {
                        win=false;
                    }
                }
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
                        cowerd_frame.setPosition(sf::Vector2f(x*BLOCK, y*BLOCK));
                        game_window.draw(cowerd_frame);
                    }
                    else
                    {
                        if (net[x][y]==0)
                        {
                            frame0.setPosition(sf::Vector2f(x*BLOCK, y*BLOCK));
                            game_window.draw(frame0);
                        }
                        else
                        {
                            if (net[x][y]==1)
                            {
                                frame1.setPosition(sf::Vector2f(x*BLOCK, y*BLOCK));
                                game_window.draw(frame1);
                            }
                            else
                            {
                                if (net[x][y]==2)
                                {
                                    frame2.setPosition(sf::Vector2f(x*BLOCK, y*BLOCK));
                                    game_window.draw(frame2);
                                }
                                else
                                {
                                    if (net[x][y]==3)
                                    {
                                        frame3.setPosition(sf::Vector2f(x*BLOCK, y*BLOCK));
                                        game_window.draw(frame3);
                                    }
                                    else
                                    {
                                        if (net[x][y]==4)
                                        {
                                            frame4.setPosition(sf::Vector2f(x*BLOCK, y*BLOCK));
                                            game_window.draw(frame4);
                                        }
                                        else
                                        {
                                            if (net[x][y]==5)
                                            {
                                                frame5.setPosition(sf::Vector2f(x*BLOCK, y*BLOCK));
                                                game_window.draw(frame5);
                                            }
                                            else
                                            {
                                                if (net[x][y]==6)
                                                {
                                                    frame6.setPosition(sf::Vector2f(x*BLOCK, y*BLOCK));
                                                    game_window.draw(frame6);
                                                }
                                                else
                                                {
                                                    if (net[x][y]==7)
                                                    {
                                                        frame7.setPosition(sf::Vector2f(x*BLOCK, y*BLOCK));
                                                        game_window.draw(frame7);
                                                    }
                                                    else
                                                    {
                                                        if (net[x][y]==8)
                                                        {
                                                            frame8.setPosition(sf::Vector2f(x*BLOCK, y*BLOCK));
                                                            game_window.draw(frame8);
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
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        
            game_window.display();
        }
    }
    return 0;       //return to int main number 0
}