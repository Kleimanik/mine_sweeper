#include<iostream>  //iostream is library for command cout and cin
#include<string>    // -//- for type of variable string
#include<fstream>   // -//- for commands ifstream(r14.)/ofstream and for work with stream
#include<sstream>   // -//- for command stringstream r20.
using namespace std;    //std is for commands cin/cout here i declaret to use it every time or if I do`t, I can use it separate in program

int main()
{
        int rows = 9, cols = 9;     //declarate size of array `net`
        // enum quad 
        bool net [rows][cols]={};   //declarate main array named net and reset every atribute to 0
        string file;
        cout << "Zadaj nazov suboru: " ;
        cin >> file;                        //space where user set the name of text file with mines place
        cout << file << endl;               //just for check
        ifstream infile(file);              //ifstream declarate infile to work with file that we choose
        if (infile.is_open())               //if file is open then fun the program but if not, just say Error 404.(r32)
        {
            string fline, frstint, scndint;
            int x, y;
            while (getline(infile,fline))       //getline is to read from file, the secon atribute is variable where getline write from file till he hits endline
            {
                stringstream ss(fline);         //converting string to stream so we can read it with getline
                getline(ss,frstint,' ');        //reading stream `ss` until hits ` ` (the 3rd atribute in bar)
                getline(ss,frstint,' ');    
                x = stoi(frstint);          //stoi is coverting string variable to integer
                y = stoi(scndint);          //stoi is converting onli to string!!!
                net [x][y] = true;
            }
        }
        else
        {
            cout << "Error 404.";
        }
        return 0;       //return to int main number 0
}