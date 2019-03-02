#include "solver.h"
#include "grid.h"

int main(int argc, char const *argv[])
{
    int px = 0, py = 0;

    int prob[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    int soln[N][N];

    cout<<"Test: Pregenerated Solvable Puzzle\n";
    tie(px, py) = wherexy_tuple();

    printGrid_prob(prob);

    copyGrid(prob, soln);
    SolveSudoku(soln);

    printGrid_all(prob, soln, px+38, py);

    /**/

    cout<<"\n\nTest: Empty Puzzle\n";
    tie(px, py) = wherexy_tuple();

    int prob2[N][N] = {0};
    printGrid_prob(prob2);

    copyGrid(prob2, soln);
    SolveSudoku(soln);

    printGrid_all(prob2, soln, px+38, py);

    /**/

    return 0;
}
