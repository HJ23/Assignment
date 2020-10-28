
#include "Solver.h"



int loop(char **content,int** lenghtMatrix ,int a, int b,int row,int col)
{
    int x = a, y = b;
    int memx=a,memy=b;

    content[a][b] = 0;
    int **tfmatrix;

    tfmatrix = (int**)calloc(col, sizeof(int*));

    for (int i = 0; i < row; i++)
        tfmatrix[i] = (int *)calloc(4, sizeof(int));
    

    while(x>=0 && x<row && y>=0 && y<col){
        tfmatrix[x][y]=1;
        if (lenghtMatrix[x][y] != -1){
                if (lenghtMatrix[memx][memy] < lenghtMatrix[x][y]){
                    lenghtMatrix[memx][memy] = lenghtMatrix[x][y];
                    break;
                }
        }



        lenghtMatrix[memx][memy] += 1;
        lenghtMatrix[x][y] = lenghtMatrix[memx][memy];
            
            if (y < row - 1 && ((content[x][y]) == content[x][y + 1]) && tfmatrix[x][y + 1]==0){
                y += 1;
                continue;
            }

            if (y>=0 && (content[x][y] == content[x][y - 1]) && tfmatrix[x][y - 1]==0 ){
                y -= 1;
                continue;
            }

            if (x>0 && (content[x][y] == content[x - 1][y]) && tfmatrix[x - 1][y]==0){ 
                x -= 1;
                continue ;
            }

            if (x < col - 1 && (content[x][y] == content[x + 1][y]) && tfmatrix[x + 1][y]==0){
                x += 1;
                continue;
            }
            break;

        return lenghtMatrix[memx][memy];

    }



}

void display(char** content,int r,int c){
    for(int a=0;a<r;a++){
        for(int b=0;b<c;b++)
          printf((char)content[a][b]);
          printf(" ");
        printf("\n");
    }

}


int32_t solve(char** content,int row,int col)
{
   // display(content,row,col);

    int **lenghtMatrix;
    lenghtMatrix = (int**)calloc(row, sizeof(int*));

    for (int i = 0; i < row; i++)
        lenghtMatrix[i] = (int *)calloc(col, sizeof(int));

    for(int tmpr=0;tmpr<row;tmpr++){
        for(int tmpc=0;tmpc<col;tmpc++)
            lenghtMatrix[tmpr][tmpc]=-1;
    }

    int32_t maxiPath = 1;

    for (int a=0;a<row;a++){
        for(int b=0;b<col;b++){
            if(lenghtMatrix[a][b]==-1)
                lenghtMatrix[a][b]=loop(content,lenghtMatrix,a,b,row,col);

            if(maxiPath<lenghtMatrix[a][b])
                maxiPath=lenghtMatrix[a][b];
            
            
            if(lenghtMatrix[a][b]==row*col)
               return maxiPath;
            

        }
    }
        return maxiPath;
}

