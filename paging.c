#include<stdio.h>
int main(){
    int las,nop,ps,np,rempages,i,j,x,y,pa,offset;
    int s[10],fno[10][20];
    printf("\nEnter the logical memory size: ");
    scanf("%d",&las);
    printf("\nEnter the page size:");
    scanf("%d",&ps);
    nop = las/ps;
    printf("\nNumber of pages available in memory are %d",nop);
    printf("\nEnter the number of processes");
    scanf("%d",&np);
    rempages = nop;
    for(i=1;i<=np;i++){
        printf("\nEnter the number of page required for p[%d] ",i);
        scanf("%d",&s[i]);
        if(s[i]>rempages){
            printf("\nMemory full");
            break;
        }
        rempages = rempages-s[i];
        printf("\nEnter page table for p[%d] ",i);
        for(j=1;j<=s[i];j++){
            scanf("%d",&fno[i][j]);
        }
    }
    printf("\nEnter the logical address to find the physical address");
    printf("\nEnter process number and page number and offset");
    scanf("%d %d %d",&x,&y,&offset);
    if(x>np||y>=s[x]||offset>=ps){
        printf("\nInvalid process number or page number or offset");
    }
    else{
        pa = (fno[x][y]*ps)+offset;
        printf("\nThe physical address is %d",pa);
    }
}
