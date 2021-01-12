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

/*void set_up_net ( int net[][], int rows , int cols)
{
for (int x=0;x<rows;x++)
{
    for (int y=0;y<cols;y++)        //this cycle is for seting up playing net, 9=mine, other numbers is number of mines near him
    {
        if (net[x][y]>=9)
        {
            if (x>0 && x<rows-1)
            {
                if (y>0 && y<cols-1)
                {
                    net[x+1][y]++;
                    net[x+1][y+1]++;
                    net[x+1][y-1]++;
                    net[x-1][y]++;
                    net[x-1][y+1]++;
                    net[x-1][y-1]++;
                    net[x][y+1]++;
                    net[x][y-1]++;
                }
                else
                {
                    if (y==0)
                    {
                        net[x+1][y]++;
                        net[x+1][y+1]++;
                        net[x-1][y]++;
                        net[x-1][y+1]++;
                        net[x][y+1]++;
                    }
                    else
                    {
                        net[x+1][y]++;
                        net[x+1][y-1]++;
                        net[x-1][y]++;
                        net[x-1][y-1]++;
                        net[x][y-1]++;
                    }    
                }    
            }
            else
            {
                if (x==0)
                {
                    if (y>0 && y<cols-1)
                    {
                        net[x][y+1]++;
                        net[x][y-1]++;
                        net[x+1][y+1]++;
                        net[x+1][y-1]++;
                        net[x+1][y]++;
                    }
                    else
                    {
                        if (y==0)
                        {
                            net[x+1][y]++;
                            net[x+1][y+1]++;
                            net[x][y+1]++;
                        }
                        else
                        {
                            net[x+1][y]++;
                            net[x+1][y-1]++;
                            net[x][y-1]++;                                        
                        }
                    }
                }
                else
                {
                    if (y>0 && y<cols-1)
                    {
                        net[x][y+1]++;
                        net[x][y-1]++;
                        net[x-1][y+1]++;
                        net[x-1][y-1]++;
                        net[x-1][y]++;
                    }
                    else
                    {
                        if (y==0)
                        {
                            net[x-1][y]++;
                            net[x-1][y+1]++;
                            net[x][y+1]++;
                        }
                        else
                        {
                            net[x-1][y]++;
                            net[x-1][y-1]++;
                            net[x][y-1]++;                                        
                        }
                    }
                }
            }
        }
    }
}
cout << "hatata patata";
}*/

int main()
{
    int dfct = 5, rows = 9, cols = 9;     //declarate size of array `net`
    while ((dfct>3) or (dfct<1))
    {
        cout << "Zadaj vysku obtiaznosti od 1 do 3: ";
        cin >> dfct;
        if ((dfct>3) or (dfct<1))
        {
            cout << "Skus to znova." << endl;
        }
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
        cout << endl;
    }

/*    //int **newnet = &net;
    set_up_net( net , rows , cols );
    for (x=0;x<rows;x++)
    {
        for (y=0;y<cols;y++)
        {
            net[x][y] = newnet[x][y];
        }
    }*/

/*    for (x=0;x<rows;x++)
    {
        for (y=0;y<cols;y++)        //this cycle is for seting up playing net, 9=mine, other numbers is number of mines near him
        {
            if (!winnet[x][y])
            {
                if (x>0 && x<rows-1)
                {
                    if (y>0 && y<cols-1)
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
                    else
                    {
                        if (y==0)
                        {
                            net[x+1][y]++;
                            net[x+1][y+1]++;
                            net[x-1][y]++;
                            net[x-1][y+1]++;
                            net[x][y+1]++;
                        }
                        else
                        {
                            net[x+1][y]++;
                            net[x+1][y-1]++;
                            net[x-1][y]++;
                            net[x-1][y-1]++;
                            net[x][y-1]++;
                        }
                    }    
                }
                else
                {
                    if (x==0)
                    {
                        if (y>0 && y<cols-1)
                        {
                            net[x][y+1]++;
                            net[x][y-1]++;
                            net[x+1][y+1]++;
                            net[x+1][y-1]++;
                            net[x+1][y]++;
                        }
                        else
                        {
                            if (y==0)
                            {
                                net[x+1][y]++;
                                net[x+1][y+1]++;
                                net[x][y+1]++;
                            }
                            else
                            {
                                net[x+1][y]++;
                                net[x+1][y-1]++;
                                net[x][y-1]++;
                            }
                        }
                    }
                    else
                    {
                        if (y>0 && y<cols-1)
                        {
                            net[x][y+1]++;
                            net[x][y-1]++;
                            net[x-1][y+1]++;
                            net[x-1][y-1]++;
                            net[x-1][y]++;
                        }
                        else
                        {
                            if (y==0)
                            {
                                net[x-1][y]++;
                                net[x-1][y+1]++;
                                net[x][y+1]++;
                            }
                            else
                            {
                                net[x-1][y]++;
                                net[x-1][y-1]++;
                                net[x][y-1]++;
                            }
                        }    
                    }
                }
            }                
        }
    }*/



    for (x=0;x<rows;x++)
    {
        for (y=0;y<cols;y++)        //this cycle is for seting up playing net, 9=mine, other numbers is number of mines near him
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
        net[x][cols-1];
    }
    
    for (y=0;y<cols;y++)
    {
        net[0][y]=1;
        net[rows-1][y];
    }

/*    for (x=0;x<rows;x++)
    {
        for (y=0;y<cols;y++)
        {
            if(net[x][y]>8)
            {
                net[x][y]=9;
            } 
        }
    }*/

    bool visnet[rows][cols];
    for (x=1;x<rows-1;x++)
    {
        for (y=1;y<cols-1;y++)        //this cycle is to reset all variable in array visnet to false
        {
            visnet[x][y] = false; 
        }
    }

    for (x=1;x<rows-1;x++)
    {
        for (y=1;y<cols-1;y++)
        {
            if (visnet[x][y]==false)
            {
                cout << "X ";
            }
            else
            {
                cout << "O ";
            }
        }
        cout << endl;
    }

    bool expl=true;
    while (expl)
    {
        cout << "Zadaj suradnice pola ktore chces vybrat: ";
        int vx,vy;
        cin >> vx >> vy;
        visnet [vx] [vy] = true;

        if (net[vx][vy]==0)
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

            /*    if (x>0 && x<rows-1)
                {
                    if (y>0 && y<cols-1)
                    {
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
                    else
                    {
                        if (y==0)
                        {
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
                        else
                        {
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
                        }
                    }    
                }
                else
                {
                    if (x==0)
                    {
                        if (y>0 && y<cols-1)
                        {

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

                            if (net[x+1][y]==0 && !visnet[x+1][y])
                            {
                                p.x = x+1;
                                p.y = y;
                                waweq.push(p);
                            }
                            visnet[x+1][y] = true;

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
                        else
                        {
                            if (y==0)
                            {

                                if (net[x+1][y]==0 && !visnet[x+1][y])
                                {
                                    p.x = x+1;
                                    p.y = y;
                                    waweq.push(p);
                                }
                                visnet[x+1][y] = true;

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
                            else
                            {

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

                                if (net[x+1][y]==0 && !visnet[x+1][y])
                                {
                                    p.x = x+1;
                                    p.y = y;
                                    waweq.push(p);
                                }
                                visnet[x+1][y] = true;

                            }
                        }
                    }
                    else
                    {
                        if (y>0 && y<cols-1)
                        {
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

                            if (net[x-1][y]==0 && !visnet[x-1][y])
                            {
                                p.x = x-1;
                                p.y = y;
                                waweq.push(p);
                            }
                            visnet[x-1][y] = true;

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

                        }
                        else
                        {
                            if (y==0)
                            {

                                if (net[x-1][y]==0 && !visnet[x-1][y])
                                {
                                    p.x = x-1;
                                    p.y = y;
                                    waweq.push(p);
                                }
                                visnet[x-1][y] = true;

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
                            }
                            else
                            {
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

                                if (net[x-1][y]==0 && !visnet[x-1][y])
                                {
                                    p.x = x-1;
                                    p.y = y;
                                    waweq.push(p);
                                }
                                visnet[x-1][y] = true;
                            }
                        }    
                    }
                }
            }*/
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

        for (x=1;x<rows-1;x++)        // ine premenne
        {
            for (y=1;y<cols-1;y++)        //this cycle is to write out net and on places of mine it says O on other place it will be X
            {
                if (visnet[x][y]==false)
                {
                    cout << "X ";
                }
                else
                {
                    cout << net[x][y] << " ";
                    if (net[x][y]>=9)
                    {
                        expl=false;
                    }
                }
            }
            cout << endl;
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
        if (win)
        {
            cout << "Gratulujem, vyhral si.";
            return 0;
        }


    }
    cout << "Vybuchol si, skus svoje stastie nabuduce." << endl;

    for (x=1;x<rows-1;x++)
    {
        for (y=1;y<cols-1;y++)        //this cycle is to write out net and on places of mine it says O on other place it will be X
        {
            cout << net[x][y] << " "; 
        }
        cout << endl;
    }
    return 0;       //return to int main number 0
}