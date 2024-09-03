#include <stdio.h>


// Prototype of calcBmi function
float calcBmi(float height_cm, float weight_kg);


int main() {
    int numUsers;  // Number of users


    // Ask user for the number of users
    printf("Enter the number of users: ");
    scanf("%d", &numUsers);


    // Arrays to store height, weight, and BMI for each user
    float heights[numUsers];
    float weights[numUsers];
    float bmis[numUsers];


    // Variables to count each category
    int underweight = 0, normal_weight = 0, overweight = 0;
    int mild_obesity = 0, moderate_obesity = 0, severe_obesity = 0;


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


        // Classify BMI into categories
        if (bmis[i] < 18.5) {
            underweight++;
        } else if (bmis[i] >= 18.5 && bmis[i] < 24.9) {
            normal_weight++;
        } else if (bmis[i] >= 25 && bmis[i] < 29.9) {
            overweight++;
        } else if (bmis[i] >= 30 && bmis[i] < 34.9) {
            mild_obesity++;
        } else if (bmis[i] >= 35 && bmis[i] < 39.9) {
            moderate_obesity++;
        } else if (bmis[i] >= 40) {
            severe_obesity++;
        }
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
            printf("User %d: You are severely obese\n", i + 1);
        }
    }


    // Calculate and display percentages
    printf("\nPercentage of people in each category:\n");
    printf("Underweight: %.2f%%\n", (underweight / (float)numUsers) * 100);
    printf("Normal weight: %.2f%%\n", (normal_weight / (float)numUsers) * 100);
    printf("Overweight: %.2f%%\n", (overweight / (float)numUsers) * 100);
    printf("Mild obesity: %.2f%%\n", (mild_obesity / (float)numUsers) * 100);
    printf("Moderate obesity: %.2f%%\n", (moderate_obesity / (float)numUsers) * 100);
    printf("Severe obesity: %.2f%%\n", (severe_obesity / (float)numUsers) * 100);


    return 0; // Return 0 to indicate successful execution
}


// Implementation of calcBmi function
float calcBmi(float height_cm, float weight_kg) {
    float height_m = height_cm / 100.0;
    // Compute body mass index
    float bmi = weight_kg / (height_m * height_m);
    return bmi;
}
