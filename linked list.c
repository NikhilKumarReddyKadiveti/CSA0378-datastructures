#include <stdio.h>

struct Node {
    int data;
    int next_index;
};

int main() {
    struct Node pool[100];
    int pool_size = 0;
    int head = -1;
    int choice;

    while (1) {
        printf("\n1.Insert End\n2.Delete Value\n3.Display\n4.Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int val;
            printf("Enter value: ");
            scanf("%d", &val);
            if (pool_size < 100) {
                pool[pool_size].data = val;
                pool[pool_size].next_index = -1;
                
                if (head == -1) {
                    head = pool_size;
                } else {
                    int curr = head;
                    while (pool[curr].next_index != -1) {
                        curr = pool[curr].next_index;
                    }
                    pool[curr].next_index = pool_size;
                }
                pool_size++;
            } else {
                printf("Pool full\n");
            }
        } 
        else if (choice == 2) {
            int val;
            printf("Enter value to delete: ");
            scanf("%d", &val);
            
            int curr = head;
            int prev = -1;
            int found = 0;

            while (curr != -1) {
                if (pool[curr].data == val) {
                    found = 1;
                    if (prev == -1) {
                        head = pool[curr].next_index;
                    } else {
                        pool[prev].next_index = pool[curr].next_index;
                    }
                    break;
                }
                prev = curr;
                curr = pool[curr].next_index;
            }
            if (!found) {
                printf("Value not found\n");
            }
        } 
        else if (choice == 3) {
            printf("List: ");
            int curr = head;
            while (curr != -1) {
                printf("%d -> ", pool[curr].data);
                curr = pool[curr].next_index;
            }
            printf("NULL\n");
        } 
        else if (choice == 4) {
            break;
        }
    }
    return 0;
}
