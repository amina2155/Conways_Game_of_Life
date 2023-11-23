//**Conway's Game of Life**
//Prepared by:
//*200041105_Tawsif Tashwar Dipto
//*200041155_Amina

#include<stdio.h>
#include<stdlib.h>
#define GRID_ROW 20
#define GRID_COL 60
int simulation_of_life(int temp_value, int row, int col, int func_arr[GRID_ROW][GRID_COL]);

int main()
{
//Declaring the array:
    int n,x,y,z,pop;
    int grid [GRID_ROW][GRID_COL] = {0};
    int buffer_grid[GRID_ROW][GRID_COL] ;


    printf("Enter the cycle count: ");
    scanf("%d",&n);
    printf("How many cells do you want to populate: ");
    scanf("%d",&pop);

    printf("Enter the cells to be populated: \n");
//populating the values:
   for(z=0;z<pop;z++)
    {
        scanf("%d,%d",&x,&y);
        grid[x][y] = 1;
    }
//printing the grid:
  system("cls");
  for(int i=0; i<GRID_ROW; i++)
        {
            printf("(%.2d)", i);
            for (int j=0; j<GRID_COL; j++)
            {
                if(grid[i][j]==1)
                   {printf("\033[1;33m");
                    printf("O");
                    printf("\033[0m");}
                else
                    printf(".");
            }
            printf("\n");
        }

            getchar();
            getchar();

         system("cls");
//simulation starts:
 for(int a=0;a<n;a++)
        {
            for(int i=0; i<GRID_ROW; i++)
        {
            for (int j=0; j<GRID_COL;j++)
            {
                int temp_value = grid[i][j];
                int Life_change = simulation_of_life(temp_value, i, j, grid);
                buffer_grid[i][j] = Life_change;
            }
        }
        for(int i=0; i<GRID_ROW; i++)
        {
            for(int j=0; j<GRID_COL; j++)
            {
                grid[i][j] = buffer_grid[i][j];
            }
        }
        for(int i=0; i<GRID_ROW; i++)
        {
            printf("(%.2d)", i);
            for (int j=0; j<GRID_COL; j++)
            {
                if(grid[i][j]==1)
                    {printf("\033[1;33m");
                    printf("O");
                    printf("\033[0m");}
                else
                    printf(".");
            }
            printf("\n");
        }
           getchar();

        system("cls");
    }
    return 0;
}
//function:
int simulation_of_life(int temp_value, int row, int col, int func_arr[GRID_ROW][GRID_COL])
{
    int sum = 0;
    if(row==0 && col==0)
    {
        sum = sum+func_arr[0][1]+func_arr[1][0]+func_arr[1][1];
    }
    else if(row==GRID_ROW-1 && col==GRID_COL-1)
    {
        sum = sum+func_arr[GRID_ROW-2][GRID_COL-2]+func_arr[GRID_ROW-2][GRID_COL-1]+func_arr[GRID_ROW-1][GRID_COL-2];
    }
    else if(row==0 && col==GRID_COL-1)
    {
        sum = sum+func_arr[0][GRID_COL-2]+func_arr[1][GRID_COL-2]+func_arr[1][GRID_COL-1];

    }
    else if(row==GRID_ROW-1 && col==0)
    {
        sum = sum+func_arr[GRID_ROW-1][1]+func_arr[GRID_ROW-2][0]+func_arr[GRID_ROW-2][1];
    }
    else if(row==0)
    {
        for(int i=0; i<2; i++)
        {
            for(int j=col-1; j<col+2; j++)
            {
                if(i==row && j==col)
                {
                    continue;
                }
                else
                {
                    sum = sum+func_arr[i][j];
                }
            }
        }
    }
    else if(row==GRID_ROW-1)
    {
        for(int i=GRID_ROW-1; i>GRID_ROW-3; i--)
        {
            for(int j=col-1; j<col+2; j++)
            {
                if(i==row && j==col)
                {
                    continue;
                }
                else
                {
                    sum = sum+func_arr[i][j];
                }
            }
        }
    }
    else if(col==0)
    {
        for(int i=0; i<2; i++)
        {
            for(int j=row-1; j<row+2; j++)
            {
                if(i==row && j==col)
                {
                    continue;
                }
                else
                {
                    sum = sum+func_arr[j][i];
                }
            }
        }
    }
    else if(col==GRID_COL-1)
    {
        for(int i=GRID_COL-1; i>GRID_COL-3; i--)
        {
            for(int j=row-1; j<row+2; j++)
            {
                if(i==row && j==col)
                {
                    continue;
                }
                else
                {
                    sum = sum+func_arr[j][i];
                }
            }
        }
    }
    else
    {
        for(int i=row-1; i<row+2; i++)
        {
            for(int j=col-1; j<col+2; j++)
            {
                if(i==row && j==col)
                {
                    continue;
                }
                else
                {
                    sum = sum+func_arr[i][j];
                }
            }
        }
    }
//The rules of life:
    if((sum==2 || sum==3)&& temp_value==1)
    {
        return 1;
    }
    else if((sum==3) && temp_value==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
