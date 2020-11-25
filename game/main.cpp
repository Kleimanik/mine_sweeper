#include<iostream>  //iostream is library for command cout and cin
#include<string>    // -//- for type of variable string
#include<fstream>   // -//- for commands ifstream(r14.)/ofstream and for work with stream
#include<sstream>   // -//- for command stringstream r20.
#include<queue>
using namespace std;    //std is for commands cin/cout here i declaret to use it every time or if I do`t, I can use it separate in program

struct Point
{
    int x,y;
};


/*
int** set_up_net ( int **net, int r , int c)
{
for (int x=0;x<r;x++)
{
    for (int y=0;y<c;y++)        //this cycle is for seting up playing net, 9=mine, other numbers is number of mines near him
    {
        if (net[x][y]>=9)
        {
            if (x>0 && x<r-1)
            {
                if (y>0 && y<c-1)
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
                    if (y>0 && y<c-1)
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
                    if (y>0 && y<c-1)
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
return net;
}*/

int main()
{
    int rows = 9, cols = 9;     //declarate size of array `net`
    // enum quad 
    int net [rows][cols]={};   //declarate main array named net and reset every atribute to 0
    string file;
    cout << "Zadaj nazov suboru: " ;
    cin >> file;                        //space where user set the name of text file with mines place
    cout << file << endl;               //just for check
    ifstream infile(file);              //ifstream declarate infile to work with file that we choose
    if (infile.is_open()==false)               //if file is open then fun the program but if not, just say Error 404.(r32)
    {
        cout << "Error 404.";
        return 0;
    }
    string fline, frstint, scndint;
    int x, y;
    while (getline(infile,fline))       //getline is to read from file, the secon atribute is variable where getline write from file till he hits endline
    {
        stringstream ss(fline);         //converting string to stream so we can read it with getline
        getline(ss,frstint,' ');        //reading stream `ss` until hits ` ` (the 3rd atribute in bar)
        getline(ss,scndint,' ');    
        x = stoi(frstint);          //stoi is coverting string variable to integer
        y = stoi(scndint);          //stoi is converting only to string!!!
        net [x][y] = 9;
    }


    for (x=0;x<rows;x++)
    {
        for (y=0;y<cols;y++)        //this cycle is to write out net and on places of mine it says O on other place it will be X
        {
            if (net[x][y]==9)
            {
                cout << "O";
            }
            else
            {
                cout << "X";
            }                
        }
        cout << endl;
    }

/*    int** newnet;
    newnet = set_up_net((int**)&net[0][0] , rows , cols );
    for (x=0;x<rows;x++)
    {
        for (y=0;y<cols;y++)
        {
            net[x][y] = newnet[x][y];
        }
    }*/

    for (x=0;x<rows;x++)
    {
        for (y=0;y<cols;y++)        //this cycle is for seting up playing net, 9=mine, other numbers is number of mines near him
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

    bool visnet[rows][cols];
    for (x=0;x<rows;x++)
    {
        for (y=0;y<cols;y++)        //this cycle is to reset all variable in array visnet to false
        {
            visnet[x][y] = false; 
        }
    }

    for (x=0;x<rows;x++)
    {
        for (y=0;y<cols;y++)        //
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
            bool beach;
            while(beach)
            {
                p = waweq.front();
                waweq.pop();
                p.x = x;
                p.y = y;

                if (x>0 && x<rows-1)
                {
                    if (y>0 && y<cols-1)
                    {
                        if (net[x-1][y-1]==0)
                        {
                            p.x = x-1;
                            p.y = y-1;
                            waweq.push(p);
                        }
                        visnet[x-1][y-1] = true;

                        if (net[x][y-1]==0)
                        {
                            p.x = x;
                            p.y = y-1;
                            waweq.push(p);
                        }
                        visnet[x][y-1] = true;

                        if (net[x+1][y-1]==0)
                        {
                            p.x = x+1;
                            p.y = y-1;
                            waweq.push(p);
                        }
                        visnet[x+1][y-1] = true;

                        if (net[x-1][y]==0)
                        {
                            p.x = x-1;
                            p.y = y;
                            waweq.push(p);
                        }
                        visnet[x-1][y] = true;

                        if (net[x+1][y]==0)
                        {
                            p.x = x+1;
                            p.y = y;
                            waweq.push(p);
                        }
                        visnet[x+1][y] = true;

                        if (net[x-1][y+1]==0)
                        {
                            p.x = x-1;
                            p.y = y+1;
                            waweq.push(p);
                        }
                        visnet[x-1][y+1] = true;

                        if (net[x][y+1]==0)
                        {
                            p.x = x;
                            p.y = y+1;
                            waweq.push(p);
                        }
                        visnet[x][y+1] = true;

                        if (net[x+1][y+1]==0)
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
                          if (net[x-1][y]==0)
                            {
                                p.x = x-1;
                                p.y = y;
                                waweq.push(p);
                            }
                            visnet[x-1][y] = true;

                            if (net[x+1][y]==0)
                            {
                                p.x = x+1;
                                p.y = y;
                                waweq.push(p);
                            }
                            visnet[x+1][y] = true;

                            if (net[x-1][y+1]==0)
                            {
                                p.x = x-1;
                                p.y = y+1;
                                waweq.push(p);
                            }
                            visnet[x-1][y+1] = true;

                            if (net[x][y+1]==0)
                            {
                                p.x = x;
                                p.y = y+1;
                                waweq.push(p);
                            }
                            visnet[x][y+1] = true;

                            if (net[x+1][y+1]==0)
                            {
                                p.x = x+1;
                                p.y = y+1;
                                waweq.push(p);
                            }
                            visnet[x+1][y+1] = true;
                        }
                        else
                        {
                            if (net[x-1][y-1]==0)
                            {
                                p.x = x-1;
                                p.y = y-1;
                                waweq.push(p);
                            }
                            visnet[x-1][y-1] = true;

                            if (net[x][y-1]==0)
                            {
                                p.x = x;
                                p.y = y-1;
                                waweq.push(p);
                            }
                            visnet[x][y-1] = true;

                            if (net[x+1][y-1]==0)
                            {
                                p.x = x+1;
                                p.y = y-1;
                                waweq.push(p);
                            }
                            visnet[x+1][y-1] = true;

                            if (net[x-1][y]==0)
                            {
                                p.x = x-1;
                                p.y = y;
                                waweq.push(p);
                            }
                            visnet[x-1][y] = true;

                            if (net[x+1][y]==0)
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

                            if (net[x][y-1]==0)
                            {
                                p.x = x;
                                p.y = y-1;
                                waweq.push(p);
                            }
                            visnet[x][y-1] = true;

                            if (net[x+1][y-1]==0)
                            {
                                p.x = x+1;
                                p.y = y-1;
                                waweq.push(p);
                            }
                            visnet[x+1][y-1] = true;

                            if (net[x+1][y]==0)
                            {
                                p.x = x+1;
                                p.y = y;
                                waweq.push(p);
                            }
                            visnet[x+1][y] = true;

                            if (net[x][y+1]==0)
                            {
                                p.x = x;
                                p.y = y+1;
                                waweq.push(p);
                            }
                            visnet[x][y+1] = true;

                            if (net[x+1][y+1]==0)
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

                                if (net[x+1][y]==0)
                                {
                                    p.x = x+1;
                                    p.y = y;
                                    waweq.push(p);
                                }
                                visnet[x+1][y] = true;

                                if (net[x][y+1]==0)
                                {
                                    p.x = x;
                                    p.y = y+1;
                                    waweq.push(p);
                                }
                                visnet[x][y+1] = true;

                                if (net[x+1][y+1]==0)
                                {
                                    p.x = x+1;
                                    p.y = y+1;
                                    waweq.push(p);
                                }
                                visnet[x+1][y+1] = true;
                            }
                            else
                            {

                                if (net[x][y-1]==0)
                                {
                                    p.x = x;
                                    p.y = y-1;
                                    waweq.push(p);
                                }
                                visnet[x][y-1] = true;

                                if (net[x+1][y-1]==0)
                                {
                                    p.x = x+1;
                                    p.y = y-1;
                                    waweq.push(p);
                                }
                                visnet[x+1][y-1] = true;

                                if (net[x+1][y]==0)
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
                			if (net[x-1][y-1]==0)
                            {
                                p.x = x-1;
                                p.y = y-1;
                                waweq.push(p);
                            }
                            visnet[x-1][y-1] = true;

                            if (net[x][y-1]==0)
                            {
                                p.x = x;
                                p.y = y-1;
                                waweq.push(p);
                            }
                            visnet[x][y-1] = true;

                            if (net[x-1][y]==0)
                            {
                                p.x = x-1;
                                p.y = y;
                                waweq.push(p);
                            }
                            visnet[x-1][y] = true;

                            if (net[x-1][y+1]==0)
                            {
                                p.x = x-1;
                                p.y = y+1;
                                waweq.push(p);
                            }
                            visnet[x-1][y+1] = true;

                            if (net[x][y+1]==0)
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

                                if (net[x-1][y]==0)
                                {
                                    p.x = x-1;
                                    p.y = y;
                                    waweq.push(p);
                                }
                                visnet[x-1][y] = true;

                                if (net[x-1][y+1]==0)
                                {
                                    p.x = x-1;
                                    p.y = y+1;
                                    waweq.push(p);
                                }
                                visnet[x-1][y+1] = true;

                                if (net[x][y+1]==0)
                                {
                                    p.x = x;
                                    p.y = y+1;
                                    waweq.push(p);
                                }
                                visnet[x][y+1] = true;
                            }
                            else
                            {
                    			if (net[x-1][y-1]==0)
                                {
                                    p.x = x-1;
                                    p.y = y-1;
                                    waweq.push(p);
                                }
                                visnet[x-1][y-1] = true;

                                if (net[x][y-1]==0)
                                {
                                    p.x = x;
                                    p.y = y-1;
                                    waweq.push(p);
                                }
                                visnet[x][y-1] = true;

                                if (net[x-1][y]==0)
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

                if(!waweq.empty())
                {
                    beach=false;
                }
            }
        }

        for (x=0;x<rows;x++)        // ine premenne
        {
            for (y=0;y<cols;y++)        //this cycle is to write out net and on places of mine it says O on other place it will be X
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


    }
    cout << "Vybuchol si, skus svoje stastie nabuduce." << endl;

    for (x=0;x<rows;x++)
    {
        for (y=0;y<cols;y++)        //this cycle is to write out net and on places of mine it says O on other place it will be X
        {
            cout << net[x][y] << " "; 
        }
        cout << endl;
    }
    return 0;       //return to int main number 0
}




