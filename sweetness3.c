#include <stdio.h>

// Function to find the minimum number of operations
int minOperations(int cookies[], int n, int k) {
    int operations = 0;

    while (1) {
        // Sort the array in ascending order
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (cookies[j] > cookies[j + 1]) {
                    int temp = cookies[j];
                    cookies[j] = cookies[j + 1];
                    cookies[j + 1] = temp;
                }
            }
        }

        // Check if the least sweet cookie is greater than or equal to k
        if (cookies[0] >= k) {
            return operations;
        }

        // If there are fewer than 2 cookies left, it's not possible
        if (n < 2) {
            return -1;
        }

        // Combine the two least sweet cookies
        int newCookie = cookies[0] + 2 * cookies[1];

        // Replace the least sweet cookie with the new one
        cookies[0] = newCookie;

        // Remove the second least sweet cookie
        for (int i = 1; i < n - 1; i++) {
            cookies[i] = cookies[i + 1];
        }

        n--;  // Decrement the number of cookies
        operations++;
    }
}

int main() {
    int n, k;
    printf("Enter the number of cookies: ");
    scanf("%d", &n);

    int cookies[n];

    printf("Enter the sweetness of each cookie:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &cookies[i]);
    }

     printf("Enter the sweetness threshold (k): ");
      scanf("%d", &k);

     int result = minOperations(cookies, n, k);
     
      printf("Minimum number of operations required: %d\n", result);
    

    return 0;
}
