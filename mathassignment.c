#include <stdio.h>
void minorandcofactormatA(float matA[][10], int rows, int column) {   
    float determinant(float mat[][10], int n);
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < column; j++) {
            printf("Enter element [%d][%d]= ", i + 1, j + 1);
            scanf("%f", &matA[i][j]);
        }
    }
    printf("Matrix A is: \n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < column; j++) {
            printf("%f \t", matA[i][j]);
        }
        printf("\n");
    }
    if(rows == 1 && column == 1) {   
        printf("Minor is: \n");
        printf("%f\n", matA[0][0]);
        printf("Cofactor is: \n");
        printf("%f\n", matA[0][0]); 
    } else {
        int a, b;
        float minor[10][10];
        printf("Enter row number and column number: ");
        scanf("%d %d", &a, &b);
        printf("Minor of matrix A is: \n");
        int minorRow = 0;
        int minorColumn = 0;
        for(int i = 0; i < rows; i++) {   
            if(i == a - 1)
                continue;
            minorColumn = 0;
            for(int j = 0; j < column; j++) {   
                if (j == b - 1)
                    continue;
                minor[minorRow][minorColumn] = matA[i][j];
                minorColumn++;
            }
            minorRow++;
        }
        for(int i = 0; i < rows - 1; i++) {
            for(int j = 0; j < column - 1; j++) {
                printf("%f \t", minor[i][j]);
            }
            printf("\n");
        }
           printf("The cofactor is: \n");
    if((a+b)%2==0)
    {
     for(int i=0;i<rows-1;i++)
    {
        for(int j=0;j<column-1;j++)
        {
            printf("%f \t",minor[i][j]);
        }
        printf("\n");
    }
    }
    else
    {
        {
     for(int i=0;i<rows-1;i++)
    {
        for(int j=0;j<column-1;j++)
        {
            printf("%f \t",0-minor[i][j]);
        }
        printf("\n");
    }
    }
}
        printf("The minor of the element in position [%d%d] is: %f\n",a,b, determinant(minor, rows - 1));

        float cofactor = determinant(minor, rows - 1);
        if ((a + b) % 2 != 0) {

            cofactor *= -1; 
        }
        printf("The cofactor of the element in position [%d%d]is : %f\n",a,b, cofactor);
    }
}
float determinant(float mat[][10], int n) {
    float det = 0;
    float temp[10][10]; 

    if(n == 1) 
        return mat[0][0];
    else if(n == 2) 
        return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    else {
        for(int k = 0; k < n; k++) {
            int tRow = 0, tCol = 0;
            for(int i = 1; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(j == k)
                        continue;
                    temp[tRow][tCol++] = mat[i][j];
                    if(tCol == n - 1) {
                        tCol = 0;
                        tRow++;
                    }
                }
            }
            det += mat[0][k] * determinant(temp, n - 1) * (k % 2 == 0 ? 1 : -1);
        }
    }
    return det;
}
int main() {
    float matA[10][10];
    int a, b;
    printf("Enter the size of matrix A: \n");
    scanf("%d %d", &a, &b);
    minorandcofactormatA(matA, a, b);
    return 0;
}
