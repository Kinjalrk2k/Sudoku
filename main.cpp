#include "solver.h"
#include "grid.h"

int main(int argc, char const *argv[])
{
    int px = 0, py = 0;
    double time;
    clock_t tStart, tStop;

    int prob[N][N] = {{0, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 0, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 0, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    int soln[N][N];

    cout<<"Test: Pregenerated Solvable Puzzle\n";
    tie(px, py) = wherexy_tuple();

    printGrid_prob(prob);

    copyGrid(prob, soln);

    tStart = clock();
    SolveSudoku(soln);
    tStop = clock();    

    printGrid_all(prob, soln, px+38, py);
    time = ((tStop - tStart)/(double)CLOCKS_PER_SEC)*1000;
    cout<<"Time Elapsed: "<<time<<"ms";

    /**/

    cout<<"\n\nTest: Empty Puzzle\n";
    tie(px, py) = wherexy_tuple();

    int prob2[N][N] = {0};
    printGrid_prob(prob2);

    copyGrid(prob2, soln);
    
    tStart = clock();
    SolveSudoku(soln);
    tStop = clock();    

    printGrid_all(prob, soln, px+38, py);
    time = ((tStop - tStart)/(double)CLOCKS_PER_SEC)*1000;
    cout<<"Time Elapsed: "<<time<<"ms";

    /**/

    cout<<endl;
    return 0;
}
