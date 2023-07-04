int main() {
   int size;
   printf("Enter the size:\n");
   scanf("%d", &size);
   int matrix[size][size];
   int i, j = 0;
   int sum = 0, sum1 = 0, sum2 = 0;
   int flag = 0;

   printf("\nEnter matrix:\n");
   for (i = 0; i < size; i++) {
      for (j = 0; j < size; j++)
         scanf("%d", &matrix[i][j]);
   }

   printf("Entered matrix is:\n");
   for (i = 0; i < size; i++) {
      printf("\n");
      for (j = 0; j < size; j++) {
         printf("%d ", matrix[i][j]);
      }
   }

   for (i = 0; i < size; i++) {
      for (j = 0; j < size; j++) {
         if (i == j)
            sum += matrix[i][j];
      }
   }

   for (i = 0; i < size; i++) {
      sum1 = 0;
      for (j = 0; j < size; j++) {
         sum1 += matrix[i][j];
      }
      if (sum == sum1)
         flag = 1;
      else {
         flag = 0;
         break;
      }
   }

   for (i = 0; i < size; i++) {
      sum2 = 0;
      for (j = 0; j < size; j++) {
         sum2 += matrix[j][i];
      }
      if (sum == sum2)
         flag = 1;
      else {
         flag = 0;
         break;
      }
   }

   if (flag == 1)
      printf("\nMagic square");
   else
      printf("\nNo Magic square");

   return 0;
}
