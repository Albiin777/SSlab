#include <stdio.h>
#include <stdlib.h>

struct block {
    int block_num;
    struct block *next;
};

struct file {
    int p;
    int start;
    int num;
    struct block *head;
} f[30];

int main() {
    int n, fnum, i, j;
    printf("Enter the number of blocks available: ");
    scanf("%d", &n);

    int exist[n];
    for (i = 0; i < n; i++) {
        exist[i] = 0;
    }

    printf("Enter the number of files: ");
    scanf("%d", &fnum);

    for (i = 0; i < fnum; i++) {
        f[i].p = i + 1;
        f[i].head = NULL;

        printf("Enter the number of blocks required for file %d: ", f[i].p);
        scanf("%d", &f[i].num);

        struct block *prev = NULL;

        for (j = 0; j < f[i].num; j++) {
            int blk;
            printf("Enter block number for block %d of file %d: ", j + 1, f[i].p);
            scanf("%d", &blk);

            if (blk < 0 || blk >= n) {
                printf("Invalid block number! Must be between 0 and %d.\n", n - 1);
                j--;

                continue;
            }

            if (exist[blk] == 1) {
                printf("Block %d already allocated. Choose another.\n", blk);
                j--;
                continue;
            }

            exist[blk] = 1;

            struct block *new_block = (struct block *)malloc(sizeof(struct block));
            new_block->block_num = blk;
            new_block->next = NULL;

            if (f[i].head == NULL) {
                f[i].head = new_block;
                f[i].start = blk;
            } else {
                prev->next = new_block;
            }

            prev = new_block;
        }
    }


    printf("\nFile No.\tHead Block\tNo. of Blocks\tBlocks Occupied\n");
    for (i = 0; i < fnum; i++) {
        printf("%d\t\t\t%d\t\t%d\t\t\t", f[i].p, f[i].start, f[i].num);
        struct block *temp = f[i].head;
        while (temp != NULL) {
            printf("%d", temp->block_num);
            temp = temp->next;
   if(temp){
printf(" -> ");}
        }
        printf("\n");
    }

    return 0;
}
