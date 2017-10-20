#include <stdio.h>
#include <mem.h>

int main(){
    int n;
    int k;
    scanf("%d %d",&n,&k);
    int rQueen;
    int cQueen;
    int grid[n+1][n+1];
    memset(grid, 0, sizeof(grid[0][0]) * (n+1) * (n+1));
    scanf("%d %d",&rQueen,&cQueen);
    for(int a0 = 0; a0 < k; a0++){
        int rObstacle;
        int cObstacle;
        scanf("%d %d",&rObstacle,&cObstacle);
        grid[rObstacle][cObstacle]=-1;
    }
    int attack=0;

    // Vertical upwards
    for (int r = rQueen+1,c=cQueen; r < n+1 ; ++r) {
        if(grid[r][c] == -1)
            break;
        else
            attack++;
    }

    // Vertical Downwards
    for (int r = rQueen-1,c=cQueen; r >0 ; r--) {
        if(grid[r][c] == -1)
            break;
        else
            attack++;
    }

    //Horizontal right side
    for (int r = rQueen,c=cQueen+1; c < n+1 ; ++c) {
        if(grid[r][c] == -1)
            break;
        else
            attack++;
    }

    //Horizontal left side
    for (int r = rQueen,c=cQueen-1; c > 0 ; c--) {
        if(grid[r][c] == -1)
            break;
        else
            attack++;
    }

    // main Diagonal downwards
    for (int r = rQueen-1,c=cQueen+1; c < n+1 && r > 0 ; ++c,--r) {
        if(grid[r][c] == -1)
            break;
        else
            attack++;
    }

    // Main Diagonal upwards
    for (int r = rQueen+1,c=cQueen-1; r < n+1 && c > 0 ; ++r,--c) {
        if(grid[r][c] == -1)
            break;
        else
            attack++;
    }

    // Other Diagonal upwards

    for (int r = rQueen+1,c=cQueen+1; r < n+1 && c < n+1 ; ++r,++c) {
        if(grid[r][c] == -1)
            break;
        else
            attack++;
    }

    //Other Diagonal downwards
    for (int r = rQueen-1,c=cQueen-1; r >0 && c > 0 ; --r,--c) {
        if(grid[r][c] == -1)
            break;
        else
            attack++;
    }

    printf("%d",attack);

    return 0;
}