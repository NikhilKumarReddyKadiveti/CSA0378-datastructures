#include <stdio.h>

int main() {
    int arr[100] = {10, 20, 30, 40, 50};
    int size = 5;
    int choice;

    while (1) {
        printf("\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int pos, val;
            printf("Enter position (0 to %d) and value: ", size);
            scanf("%d %d", &pos, &val);
            if (pos >= 0 && pos <= size && size < 100) {
                for (int i = size; i > pos; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[pos] = val;
                size++;
            } else {
                printf("Invalid position\n");
            }
        } 
        else if (choice == 2) {
            int pos;
            printf("Enter position (0 to %d): ", size - 1);
            scanf("%d", &pos);
            if (pos >= 0 && pos < size) {
                for (int i = pos; i < size - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                size--;
            } else {
                printf("Invalid position\n");
            }
        } 
        else if (choice == 3) {
            int val, found = -1;
            printf("Enter value to search: ");
            scanf("%d", &val);
            for (int i = 0; i < size; i++) {
                if (arr[i] == val) {
                    found = i;
                    break;
                }
            }
            if (found != -1) {
                printf("Found at index %d\n", found);
            } else {
                printf("Not found\n");
            }
        } 
        else if (choice == 4) {
            printf("Array: ");
            for (int i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        } 
        else if (choice == 5) {
            break;
        }
    }
    return 0;
}
