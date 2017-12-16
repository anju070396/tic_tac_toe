#include<stdio.h>
#include<stdlib.h>

void fillmatrix(char** p, int rows, int cols)
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            p[i][j] = '*';
        }
    }
}

void printmatrix(char** p, int rows, int cols)
{
    for(int i=rows-1; i>=0; i--)
    {  printf(" -------");
        printf("\n");
        printf("%d|",i);
        
        for(int j=0; j<cols; j++)
        {
            printf("%c|",p[i][j]);
        }

        printf("\n");
    }
    printf(" -------");
    printf("\n");
    printf("  ");
    for(int k=0; k<cols; k++)
    {
        printf("%d ",k);
    }

    printf("\n");

}

void makemove(char** p, int row, int col, char c)
{
        p[row][col] = c;
}

int isSame(char *z, int count, char c)
{
    if(c == '*')
    {return 0;}
    else
    {
        for(int i=0; i<count; i++)
        {
            if(c == z[i])
            {   continue;  }
            else
            {   return 0;   }

        }
        return 1;
    }
}
int horizwin(char** p, int rows, int cols, char c)
{
    for(int i=0; i<rows; i++)
    {
        int t = isSame(p[i], cols, c);
        if(t == 1)
        {   return 1;   }
    }
    return 0;
}

int vertiwin(char **z, int rows, int cols, char c)
{
    int count = 0;
    for(int i=0; i<cols; i++)
    {   
        count = 0;
        for(int j=0; j<rows; j++)
        {   
            if(c == z[j][i])
            {
                count++;
            }

        }
        if(count == 3)
        {    return 1;  }

    }
    return 0;
}

int diagwin(char **z, int rows, int cols, char c)
{
    int which = 1;
    if(c == '*') {   return 0;  }

    for(int i=0,j=0; i<rows,j<cols; i++,j++)
    {
        if(c == z[i][j])
        {   continue; }
        else
        {   which = 0;
            break;      }
    }

    if(which == 0)
    {   
        for(int i=rows-1,j=0; i>=0,j<cols; i--,j++)
        {
            if(c == z[i][j])
            {   continue; }
            else
            {return 0;}
        }
        return 1;
    }
    else
    {   return 1;  }
}

int drawgame(char **p, int rows, int cols)
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            if(p[i][j] == '*')
            {  
                return 0;   }
        }
    }
    return 1;
}

int win(char **p, int rows, int cols, char c)
{
    if(horizwin(p, rows, cols, c ))
    {   return 1;   }
    else if(vertiwin(p, rows, cols, c))
    {   return 1;   }
    else if(diagwin(p, rows, cols, c))
    {   return 1;   }
    else
    {
        return 0;
    }
}

int validate(char **p, int rows, int cols, int row, int col)
{
    if(row>=rows || col>=cols || row<0 || col<0 || p[row][col] != '*')
    {
        return 0;
    }
    else
    {   return 1;   }  
}

int main()
{
    int rows = 3, cols = 3;
    char **p;

    p = (char**)malloc(rows * sizeof(char*));

    for(int i=0; i<rows; i++)
    {
        p[i] = (char*)malloc(cols * sizeof(char));
    }

    fillmatrix(p, rows, cols);
    printmatrix(p, rows, cols);
    
    char sym[2] = "XO";
    int player = 1;
    int x,y;
    do
    {
        player = !player;
        do
        {
            printf("player %d turn\n",player+1);
            printf("enter your position please as (i j): ");
            scanf("%d %d",&x,&y);

            
        }while(!validate(p, rows, cols, x, y));
        
        makemove(p, x, y, sym[player]);
        printmatrix(p, rows, cols);
    }while(!win(p, rows, cols, sym[player]) && !drawgame(p, rows, cols));

    if(drawgame(p, rows, cols))
    {   printf("game is draw \n"); }
    else
        printf("%d player is win", player+1);
    return 0;
    
}


