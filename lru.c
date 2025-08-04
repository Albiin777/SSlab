#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int p_no;
    int valid;
    int frequency;
    int last_used;
} pageframe;
int main() {
    int nf;
    int np;
    printf("Enter the number of page frames: ");
    scanf("%d", &nf);
    printf("Enter the number of pages: ");
    scanf("%d", &np);
    pageframe *frames = (pageframe *)malloc(nf * sizeof(pageframe));
    if (frames == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < nf; i++) {
        frames[i].valid = 0;
        frames[i].p_no = -1;
        frames[i].frequency = 0;
        frames[i].last_used = 0;
    }
    int *pages = (int *)malloc(np * sizeof(int));
    if (pages == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    printf("Enter the page reference string (separated by spaces):\n");
    for (int i = 0; i < np; i++) {
        scanf("%d", &pages[i]);
    }
    int page_faults = 0;
    int time = 0;
    printf("\nPage Replacement (LFU):\n");
    for (int i = 0; i < np; i++) {
        int current_page = pages[i];
        int page_hit = 0;
        time++;
        printf("Referencing page %d: ", current_page);
        for (int j = 0; j < nf; j++) {
            if (frames[j].valid && frames[j].p_no == current_page) {
                page_hit = 1;
                frames[j].frequency++;
                frames[j].last_used = time;
                break;
            }
        }
        if (page_hit) {
            printf("Page Hit\n");
        } else {
            page_faults++;
            int lfu_index = -1;
            int min_frequency = __INT_MAX__;
            for (int j = 0; j < nf; j++) {
                if (!frames[j].valid) {
                    lfu_index = j;
                    break;
                }
            }
           
            if (lfu_index == -1) {
                int oldest_time = __INT_MAX__;
                for (int j = 0; j < nf; j++) {
                    if (frames[j].frequency < min_frequency) {
                        min_frequency = frames[j].frequency;
                        lfu_index = j;
                        oldest_time = frames[j].last_used;
                    } else if (frames[j].frequency == min_frequency && frames[j].last_used < oldest_time) {
                        lfu_index = j;
                        oldest_time = frames[j].last_used;
                    }
                }
            }
           
            if (frames[lfu_index].valid) {
                printf("Page Fault - Replacing page %d\n", frames[lfu_index].p_no);
            } else {
                printf("Page Fault - Allocated to empty frame\n");
            }
            frames[lfu_index].p_no = current_page;
            frames[lfu_index].valid = 1;
            frames[lfu_index].frequency = 1;
            frames[lfu_index].last_used = time;
        }
        printf("Frames: ");
        for (int j = 0; j < nf; j++) {
            if (frames[j].valid) {
                printf("%d ", frames[j].p_no);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
    printf("\nTotal Page Faults: %d\n", page_faults);
    printf("Total Page Hits: %d\n", np - page_faults);
    printf("\nHit Ratio: %.2f\n", (float)(np - page_faults) / np);
    printf("Miss Ratio: %.2f\n", (float)page_faults / np);
    free(frames);
    free(pages);
    return 0;
}




"""#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int p_no;
    int valid;
    int frequency;
    int last_used;
} pageframe;

int main() {
    int nf;
    int np;
    
    printf("Enter the number of page frames: ");
    scanf("%d", &nf);
    printf("Enter the number of pages: ");
    scanf("%d", &np);
    
    pageframe *frames = (pageframe *)malloc(nf * sizeof(pageframe));
    if (frames == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    
    // Initialize frames
    for (int i = 0; i < nf; i++) {
        frames[i].valid = 0;
        frames[i].p_no = -1;
        frames[i].frequency = 0;
        frames[i].last_used = 0;
    }
    
    int *pages = (int *)malloc(np * sizeof(int));
    if (pages == NULL) {
        perror("Memory allocation failed");
        free(frames);
        exit(EXIT_FAILURE);
    }
    
    printf("Enter the page reference string (separated by spaces):\n");
    for (int i = 0; i < np; i++) {
        scanf("%d", &pages[i]);
    }
    
    int page_faults = 0;
    int time = 0;
    
    printf("\nPage Replacement (LFU):\n");
    
    for (int i = 0; i < np; i++) {
        int current_page = pages[i];
        int page_hit = 0;
        time++;
        
        printf("Referencing page %d: ", current_page);
        
        // Check for page hit
        for (int j = 0; j < nf; j++) {
            if (frames[j].valid && frames[j].p_no == current_page) {
                page_hit = 1;
                frames[j].frequency++;
                frames[j].last_used = time;
                break;
            }
        }
        
        if (page_hit) {
            printf("Page Hit\n");
        } else {
            page_faults++;
            int lfu_index = -1;
            
            // First, check for empty frame
            for (int j = 0; j < nf; j++) {
                if (!frames[j].valid) {
                    lfu_index = j;
                    break;
                }
            }
            
            // If no empty frame, find LFU frame
            if (lfu_index == -1) {
                int min_frequency = frames[0].frequency;
                int oldest_time = frames[0].last_used;
                lfu_index = 0;
                
                for (int j = 1; j < nf; j++) {
                    if (frames[j].frequency < min_frequency || 
                        (frames[j].frequency == min_frequency && frames[j].last_used < oldest_time)) {
                        min_frequency = frames[j].frequency;
                        oldest_time = frames[j].last_used;
                        lfu_index = j;
                    }
                }
            }
            
            if (frames[lfu_index].valid) {
                printf("Page Fault - Replacing page %d\n", frames[lfu_index].p_no);
            } else {
                printf("Page Fault - Allocated to empty frame\n");
            }
            
            // Update the selected frame
            frames[lfu_index].p_no = current_page;
            frames[lfu_index].valid = 1;
            frames[lfu_index].frequency = 1;
            frames[lfu_index].last_used = time;
        }
        
        // Display current frame state
        printf("Frames: ");
        for (int j = 0; j < nf; j++) {
            if (frames[j].valid) {
                printf("%d ", frames[j].p_no);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
    
    printf("\nTotal Page Faults: %d\n", page_faults);
    printf("Total Page Hits: %d\n", np - page_faults);
    printf("\nHit Ratio: %.2f\n", (float)(np - page_faults) / np);
    printf("Miss Ratio: %.2f\n", (float)page_faults / np);
    
    free(frames);
    free(pages);
    return 0;
}"""
