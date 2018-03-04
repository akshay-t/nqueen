#include<stdio.h>

int check(int b[6][6],int r,int c){
    
    int i;
    //check row
    for(i=0;i<c;i++){
        if(b[r][i])
            return 0;
    }
    int j;
    //check upper left diagonal
    for(i=r,j=c;i>=0 && j>=0;i--,j--){
        if(b[i][j])
            return 0;
    }
    //check right left diagonal
    for(i=r,j=c;i<6 && j>=0;i++,j--){
        if(b[i][j])
            return 0;
    }
    return 1;
}

int nqueen(int b[6][6],int c){
    int i;
    if(c>=6)
        return 1;
    for(i=0;i<6;i++){
        
        if(check(b,i,c)){
            b[i][c]=1;
            
            if(nqueen(b,c+1))
                return 1;
                
            b[i][c]=0;
                
        }
        
    }
    
    return 0;
}


int main(){
    int b[6][6] = { {0, 0, 0, 0,0,0},
        {0, 0, 0, 0,0,0},
        {0, 0, 0, 0,0,0},
        {0, 0, 0, 0,0,0},{0, 0, 0, 0,0,0},{0, 0, 0, 0,0,0}
    };
    
    if(!nqueen(b,0))
        printf("No Solution");
        
    int i,j;
    for(i=0;i<6;i++){
        printf("\n");
        for(j=0;j<6;j++)
            printf(" %d ",b[i][j]);
    }
    
    return 0;
}
