#include <stdio.h>


// Prototype of calcBmi function
float calcBmi(float height_cm, float weight_kg);


int main() {
    int numUsers;  // Number of users
    // Ask user for the number of users
    printf("Enter the number of users: ");
    scanf("%d", &numUsers);


    // Arrays to store height and weight for each user
    float heights[numUsers];
    float weights[numUsers];
    float bmis[numUsers];


    // Read data for each user
    for (int i = 0; i < numUsers; i++) {
        printf("User %d\n", i + 1);


        // Ask user for height in centimeters
        printf("Enter your height in cm: ");
        scanf("%f", &heights[i]);


        // Ask user for weight in kilograms
        printf("Enter your weight in kg: ");
        scanf("%f", &weights[i]);


        // Calculate BMI for the current user
        bmis[i] = calcBmi(heights[i], weights[i]);
    }


    // Display results for each user
    printf("\nBMI Results:\n");
    for (int i = 0; i < numUsers; i++) {
        printf("User %d: BMI = %.2f kg/m^2\n", i + 1, bmis[i]);
       
        // Print BMI category
        if (bmis[i] < 18.5) {
            printf("User %d: You are underweight\n", i + 1);
        } else if (bmis[i] >= 18.5 && bmis[i] < 24.9) {
            printf("User %d: Your weight is ideal\n", i + 1);
        } else if (bmis[i] >= 25 && bmis[i] < 29.9) {
            printf("User %d: You are overweight\n", i + 1);
        } else if (bmis[i] >= 30 && bmis[i] < 34.9) {
            printf("User %d: You have mild obesity\n", i + 1);
        } else if (bmis[i] >= 35 && bmis[i] < 39.9) {
            printf("User %d: You have moderate obesity\n", i + 1);
        } else if (bmis[i] >= 40) {
            printf("User %d: You are morbidly obese\n", i + 1);
        }
    }


    return 0; // Return 0 to indicate successful execution
}


// Implementation of calcBmi function
float calcBmi(float height_cm, float weight_kg) {
    float height_m = height_cm / 100.0;
    // Compute body mass index
    float bmi = weight_kg / (height_m * height_m);
    return bmi;
}
