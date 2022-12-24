#include <stdio.h>
#include <math.h>
#include "camera_matrix.h"

int main() {

    int fx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int fy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    int x_size = 472;
    int y_size = 473;

    int X[x_size-2][y_size-2];
    int Y[x_size-2][y_size-2];
    int F[x_size-2][y_size-2];

    for(int x = 0; x < x_size-2; x++) {
        for(int y = 0; y < y_size-2; y++) {
            X[x][y] = img[x][y] * fx[0][0] + img[x][y+1] * fx[0][1] + img[x][y+2] * fx[0][2] + img[x+1][y] * fx[1][0] + img[x+1][y+1] * fx[1][1] + img[x+1][y+2] * fx[1][2] + img[x+2][y] * fx[2][0] + img[x+2][y+1] * fx[2][1] + img[x+2][y+2] * fx[2][2];
        }
    }

    for(int y = 0; y < y_size-2; y++) {
        for(int x = 0; x < x_size-2; x++) {
            Y[x][y] = img[x][y] * fy[0][0] + img[x][y+1] * fy[0][1] + img[x][y+2] * fy[0][2] + img[x+1][y] * fy[1][0] + img[x+1][y+1] * fy[1][1] + img[x+1][y+2] * fy[1][2] + img[x+2][y] * fy[2][0] + img[x+2][y+1] * fy[2][1] + img[x+2][y+2] * fy[2][2];
        }
    }

    for(int x = 0; x < x_size-2; x++) {
        for(int y = 0; y < y_size-2; y++) {
            F[x][y] = sqrt((X[x][y] * X[x][y]) + (Y[x][y] * Y[x][y]));
        }
    }   

    printf("Hello Ilyas\n");
    printf("10: %d\n", F[10][10]);
    printf("100: %d\n", F[100][100]);
    printf("150: %d\n", F[150][150]);
    printf("200: %d\n", F[200][200]);
    printf("250: %d\n", F[250][250]);
    printf("300: %d\n", F[300][300]);
    return 0;
}
