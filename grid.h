#include "headers.h"

void copyGrid(int grid1[N][N], int grid2[N][N])
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
            grid2[i][j]=grid1[i][j];
    }
}

void printGrid_prob(int grid[N][N], int x=-1, int y=-1)
{
    if(x==-1 && y==-1)
        tie(x, y) = wherexy_tuple();

    fstream f;  //  a filestream object to read the grid.txt file
    int g[19][37];
    int x1=x, y1=y;

    //  grid.txt file contains the ascii table borders of the grid
    f.open("grid.txt", ios::in);

    gotoxy(x1, y1);

    /*  reading the file and storing as ascii int in g[][]  */
    for(int i=0; i<19; i++)
    {
        for(int j=0; j<37; j++)
            f>>g[i][j];
    }

    /*  printing table borders  */
    for(int i=0; i<19; i++)
    {
        for(int j=0; j<37; j++)
            cout<<(char)g[i][j];    //  printing ascii text

        gotoxy(x1, ++y1);
    }

    /*  printing the numbers in the table   */
    x1=x+2;
    y1=y+1;

    for(int i=0; i< N; i++)
    {
        gotoxy(x1, y1);

        for(int j=0; j<N; j++)
        {
            if(grid[i][j]!=UNASSIGNED)  //  if a number is found
            {
                //  print as RED
                SetConsoleTextAttribute(hConsole,FOREGROUND_RED | FOREGROUND_INTENSITY);
                cout<<grid[i][j];
            }
            else
                cout<<" ";  //  print blank

            x1+=4;
            gotoxy(x1, y1);
        }
        y1+=2;
        x1=x+2;
    }

    x1=0;
    gotoxy(x1,y1);

    //  normalize console font colour
    SetConsoleTextAttribute(hConsole,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void printGrid_all(int grid_prob[N][N], int grid_soln[N][N], int x=-1, int y=-1)
{
    if(x==-1 && y==-1)
        tie(x, y) = wherexy_tuple();

    fstream f;
    int g[19][37];
    int x1=x, y1=y;

    //  grid.txt file contains the ascii table borders of the grid
    f.open("grid.txt", ios::in);

    gotoxy(x1, y1);

    /*  reading the file and storing as ascii int in g[][]  */
    for(int i=0; i<19; i++)
    {
        for(int j=0; j<37; j++)
            f>>g[i][j];
    }

    /*  printing the table border   */
    for(int i=0; i<19; i++)
    {
        for(int j=0; j<37; j++)
            cout<<(char)g[i][j];    //  printing ascii text

        gotoxy(x1, ++y1);
    }

    x1=x+2;
    y1=y+1;

    /*  printing the numbers in the table   */
    for(int i=0; i< N; i++)
    {
        gotoxy(x1, y1);

        for(int j=0; j<N; j++)
        {
            if(grid_prob[i][j]==UNASSIGNED) //  if the current position of the problem grid is empty
            {
                //  print the number in solution as GREEN
                SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                if(grid_soln[i][j]!=0)
                    cout<<grid_soln[i][j];
            }

            else
            {
                //  print the number in poblem as RED
                SetConsoleTextAttribute(hConsole,FOREGROUND_RED | FOREGROUND_INTENSITY);
                cout<<grid_prob[i][j];
            }

            x1+=4;
            gotoxy(x1, y1);
        }
        y1+=2;
        x1=x+2;
    }

    x1=0;
    gotoxy(x1,y1);

    SetConsoleTextAttribute(hConsole,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}