//
//  main.c
//  NumberOnly2
//
//  Created by Eric on 15-8-19.
//  Copyright (c) 2015年 Bakantu Eric. All rights reserved.
//

#include <stdio.h>
int sudoku (int n, int table[9][9]);
int a_count = 0;
int main(int argc, const char * argv[]) {
    // insert code here...
    int table[9][9];
    FILE *fp = fopen("NO2.in", "r");
    for (int x = 0; x < 9; x++)
        for(int y = 0; y < 9; y++){
            fscanf(fp, "%1d", &table[x][y]);
        }
    fclose(fp);
    printf("成功读取文件!\n");
    printf("正在求解...\n");
    sudoku(0, table);
    printf("完成, 共有: %d 种解\n",a_count);
    return 0;
}
int sudoku (int n, int table[9][9]){
    int x = (n/9), y = n - (x*9),j = 0,k = 0;
    if (n < 81){
        
    if (table[x][y] == 0){
        for (int i = 1; i <= 9; i++){
            int ifnot = 1;
            for (int j = 0; j <= 8; j++) {
                if((table[x][j] == i) || (table[j][y] == i)){
                    ifnot = 0;
                    break;
                }
            }
            if (ifnot == 0) continue;
            for (j = ((x/3)*3); j < ((x/3)*3)+3; j++)
                for (k = ((y/3)*3); k < ((y/3)*3)+3; k++){
                    if(table[j][k] == i) ifnot = 0;
                }
            if (ifnot == 0) continue;
            table[x][y] = i;
            
            sudoku(n+1, table);
            table[x][y] = 0;
        }
    }
    else{
        sudoku(n+1, table);
    }
        
    }
    else{
        ++a_count;
        printf("第 %d 种解\n",a_count);
        for (int w = 0; w < 9; w++){
            for(int s = 0; s < 9; s++){
                printf("%d ",table[w][s]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
