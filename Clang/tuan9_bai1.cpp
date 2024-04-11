#include <stdio.h>
#include <stdbool.h>

// A function to check if a number is prime
bool is_prime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

// A function to input an integer array with n elements
void input_array(int arr[], int n)
{
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

// A function to output an integer array with n elements
void output_array(int arr[], int n)
{
    printf("The array is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// A function to insert an element with value x at position y in the array
void insert_at(int arr[], int *n, int x, int y)
{
    // Check if the position is valid
    if (y < 0 || y > *n)
    {
        printf("Invalid position\n");
        return;
    }
    // Shift the elements to the right from the position y
    for (int i = *n; i > y; i--)
    {
        arr[i] = arr[i - 1];
    }
    // Insert the element x at position y
    arr[y] = x;
    // Increase the size of the array by one
    (*n)++;
}

// A function to insert an element with value x into the sorted array without changing the sorted order of the array
void insert_sorted(int arr[], int *n, int x)
{
    // Find the position to insert x
    int pos = -1;
    for (int i = 0; i < *n; i++)
    {
        if (arr[i] > x)
        {
            pos = i;
            break;
        }
    }
    // If x is larger than all elements, insert it at the end
    if (pos == -1)
        pos = *n;
    // Insert x at the position using the previous function
    insert_at(arr, n, x, pos);
}

// A function to delete an element at position y in the array
void delete_at(int arr[], int *n, int y)
{
    // Check if the position is valid
    if (y < 0 || y >= *n)
    {
        printf("Invalid position\n");
        return;
    }
    // Shift the elements to the left from the position y + 1
    for (int i = y; i < *n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    // Decrease the size of the array by one
    (*n)--;
}

// A function to delete all prime number elements in the array
void delete_prime(int arr[], int *n)
{
    // Loop through the array from the end to the beginning
    for (int i = *n - 1; i >= 0; i--)
    {
        // If the element is prime, delete it using the previous function
        if (is_prime(arr[i]))
        {
            delete_at(arr, n, i);
        }
    }
}

// A function to input a matrix with n rows and m columns
void input_matrix(int mat[][20], int n, int m)
{
    printf("Enter %d rows and %d columns:\n", n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
}

// A function to output a matrix with n rows and m columns
void output_matrix(int mat[][20], int n, int m)
{
    printf("The matrix is:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// A function to calculate the sum of all elements in the first column of a matrix
int sum_first_column(int mat[][20], int n, int m)
{
        int sum = 0;
        for (int i = 0; i < n; i++)
            // Add the element in the first column to the sum
            sum += mat[i][0];
    return sum;
}

// A function to find the smallest element in the last row of a matrix
int min_last_row(int mat[][20], int n, int m)
{
    // Initialize the minimum as the first element in the last row
    int min = mat[n - 1][0];
    for (int j = 1; j < m; j++)
    {
        // If the element is smaller than the current minimum, update it
        if (mat[n - 1][j] < min)
        {
            min = mat[n - 1][j];
        }
    }
    return min;
}

// The main function to test the program
int main()
{
    // Declare an array and a matrix
    int arr[50], n;
    int mat[20][20], r, c;

    // Input and output an array
    printf("Enter the size of the array:\n");
    scanf("%d", &n);
    input_array(arr, n);
    output_array(arr, n);

    // Insert an element with value x at position y in the array
    int x, y;
    printf("Enter the value and position to insert:\n");
    scanf("%d %d", &x, &y);
    insert_at(arr, &n, x, y);
    output_array(arr, n);

    // Insert an element with value x into the sorted array without changing the sorted order of the array
    printf("Enter the value to insert into the sorted array:\n");
    scanf("%d", &x);
    insert_sorted(arr, &n, x);
    output_array(arr, n);

    // Delete an element at position y in the array
    printf("Enter the position to delete:\n");
    scanf("%d", &y);
    delete_at(arr, &n, y);
    output_array(arr, n);

    // Delete all prime number elements in the array
    printf("Deleting all prime number elements in the array:\n");
    delete_prime(arr, &n);
    output_array(arr, n);

    // Input and output a matrix
    printf("Enter the number of rows and columns of the matrix:\n");
    scanf("%d %d", &r, &c);
    input_matrix(mat, r, c);
    output_matrix(mat, r, c);

    // Calculate the sum of all elements in the first column of a matrix
    printf("The sum of all elements in the first column is: %d\n", sum_first_column(mat, r, c));

    // Find the smallest element in the last row of a matrix
    printf("The smallest element in the last row is: %d\n", min_last_row(mat, r, c));

    return 0;
}
