#include<stdio.h>
#include<stdlib.h>

struct file {
    int p;          
    int start;    
    int num;      
    int block[20];
} f[30];

void main() {
    int n, fnum, i, j, size;
   

    printf("Enter the number of blocks available: ");
    scanf("%d", &n);


    int exist[n];
    for(i = 0; i < n; i++) {
        exist[i] = 0;  
    }

    printf("Enter the number of files: ");
    scanf("%d", &fnum);

    int b[fnum];


    for(i = 0; i < fnum; i++) {
        f[i].p = i + 1;  

        printf("Enter the index block of file %d: ", f[i].p);
        scanf("%d", &f[i].start);
        f[i].block[0] = f[i].start;  

        printf("Enter the number of blocks in the file %d: ", f[i].p);
        scanf("%d", &f[i].num);


        for(j = 1; j < f[i].num; j++) {
            printf("Enter the index to allocate File %d block %d: ", f[i].p, j + 1);
            scanf("%d", &f[i].block[j]);


            if(exist[f[i].block[j] - 1] == 1) {
                printf("This block %d is already allocated. Please choose another block!!\n", f[i].block[j]);
                i--;  
                break;
            }

            exist[f[i].block[j] - 1] = 1;
        }

        if(j == f[i].num) {
            b[i] = 1;
        }
    }

    printf("File No.\tIndex Block\tNo.of Blocks\t Block occupied\n");
    for(i = 0; i < fnum; i++) {
        if(b[i] == 1) {  
            printf("%d\t\t%d\t\t%d\t\t", f[i].p, f[i].start, f[i].num);
            for(j = 0; j < f[i].num; j++) {
                printf("%d ", f[i].block[j]);
            }
            printf("\n");
        } else {  
            printf("%d\t\tNot allocated\t\t---\t\t\t---\n", f[i].p);
        }
    }
}
