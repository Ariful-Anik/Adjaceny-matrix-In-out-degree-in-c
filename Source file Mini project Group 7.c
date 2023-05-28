#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define n 10

int matrix[n][n];

int main()
{


    {
        int indeg,outdeg,total_in=0,total_out=0;

        double total_time,executing_time;
        clock_t start,end;
        start=clock();
        srand(time(0));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                matrix[i][j]=rand()%2;
                if(i==j)
                {
                    matrix[i][j]=0;
                }
            }
        }
        for(int i=0; i<n; i++ )
        {
            for(int j=0; j<n; j++ )
            {
                printf(" %d",matrix[i][j]);
            }
            printf("\n");
        }


        printf("\n Vertex \t In-degree \t Out-degree");
        for(int i=0; i<n; i++)
        {
            indeg=0;
            outdeg=0;
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j]==1)
                {
                    indeg++;
                    total_in++;
                }
                if(matrix[j][i]==1)
                {
                    outdeg++;
                    total_out++;
                }
            }

            printf("\n\n %d \t\t %d \t\t %d",i+1,indeg,outdeg);
        }
        printf("\n");
        printf("\n\n Total In degree=%d",total_in);
        printf("\n\n Total Out degree=%d",total_out);

        end=clock();
        total_time=((double)(end-start)/CLOCKS_PER_SEC)*(1000000000);
        executing_time = (total_time*1e-6);

        printf("\n\n\n Computational time is : %1f ms \n",executing_time);
        printf("\n\n");

    }

}
