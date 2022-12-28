#include <stdio.h>
#include <math.h>
#include "input_matrix.h"

#define threshold 250

int main()
{

    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    int x_size = sizeof(img[0]) / sizeof(img[0][0]);
    int y_size = sizeof(img) / sizeof(img[0]);

    int X, Y, x, y;
    int finalImage[x_size - 2][y_size - 2];

    for (x = 0; x < x_size - 2; x++)
    {
        for (y = 0; y < y_size - 2; y++)
        {
            X = img[x][y] * Gx[0][0] + img[x][y + 1] * Gx[0][1] + img[x][y + 2] * Gx[0][2] + img[x + 1][y] * Gx[1][0] + img[x + 1][y + 1] * Gx[1][1] + img[x + 1][y + 2] * Gx[1][2] + img[x + 2][y] * Gx[2][0] + img[x + 2][y + 1] * Gx[2][1] + img[x + 2][y + 2] * Gx[2][2];
            Y = img[x][y] * Gy[0][0] + img[x][y + 1] * Gy[0][1] + img[x][y + 2] * Gy[0][2] + img[x + 1][y] * Gy[1][0] + img[x + 1][y + 1] * Gy[1][1] + img[x + 1][y + 2] * Gy[1][2] + img[x + 2][y] * Gy[2][0] + img[x + 2][y + 1] * Gy[2][1] + img[x + 2][y + 2] * Gy[2][2];
            finalImage[x][y] = sqrt((X*X) + (Y*Y)) < threshold ? 0 : 255;
        }
    }
    
    // Save image

    FILE *pimg;
    pimg = fopen("pgmimg.pgm", "wb");

    // writing  the Magic Number into the file
    fprintf(pimg, "P2\n");

    // width and height writing into the file
    int w = x_size;
    int h = y_size;
    fprintf(pimg, "%d %d\n", w, h);

    // Max grey color value
    fprintf(pimg, "255\n");
    int cnt = 0;
    int tp = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            tp = finalImage[i][j];

            // 2D array grey value into file
            fprintf(pimg, "%d ", tp);
        }
        fprintf(pimg, "\n");
    }
    fclose(pimg);

    return 0;
}
