#include<stdio.h>
#include<math.h>

int main()
{
    int n;
    scanf("%d",&n);
    int arm[n];

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arm[i]);

    }


    for(int j=0;j<n;j++)
    {
        int temp=arm[j];
        int z=temp;
        int x=z;
        int y=0;
        while(temp>0)
        {
            y=y+1;
            temp=temp/10;
        }

        int r,b=0;

        while(z>0)
        {
            r=z%10;
            b=b+pow(r,y);
            z=z/10;
        }

        if(x==b){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }

    }
}
