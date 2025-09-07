#include <stdio.h>

int main() {
    printf("What kind of Array do you want? 1.1D\t 2.2D\t 3.3D\n");
    int type;
    scanf("%d", &type);

    int n, m,p;

    switch(type) {

        case 1: {
            printf("Enter length of array: ");
            scanf("%d", &n);

            int arr[n];  // 1D array

            printf("Enter elements of the array:\n");
            for(int i = 0; i < n; i++) {
                scanf("%d", &arr[i]);
            }

            printf("The array: ");
            for(int i = 0; i < n; i++) {
                printf("%d\t", arr[i]);
            }
            printf("\n");
            break;
        }

        case 2: {
            printf("Enter rows: ");
            scanf("%d", &n);

            printf("Enter columns: ");
            scanf("%d", &m);

            int arr[n][m];  // 2D array

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    scanf("%d", &arr[i][j]);
                    printf("\t");
                }
                printf("\n");
            }

            printf("The array:\n");
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    printf("%d\t", arr[i][j]);
                }
                printf("\n");
            }
            break;
        }

        case 3: {
    printf("Enter depth: ");
    scanf("%d", &n);
    printf("Enter rows: ");
    scanf("%d", &m);
    printf("Enter columns: ");
    scanf("%d", &p);

    int arr[n][m][p];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < p; k++) {
                printf("Element at [%d][%d][%d]: ", i, j, k);
                scanf("%d", &arr[i][j][k]);
            }
        }
    }

    printf("\nThe 3D array:\n");
    for(int i = 0; i < n; i++) {
        printf("Depth %d:\n", i);
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < p; k++) {
                printf("%d\t", arr[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    break;
}

        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}
