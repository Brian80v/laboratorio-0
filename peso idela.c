#include <stdio.h>


// Función para calcular el índice de masa corporal (BMI)
float calc_bmi(float height_cm, float weight_kg) {
    float height_m = height_cm / 100.0;
    float bmi = weight_kg / (height_m * height_m);
    return bmi;
}


// Función para calcular el peso ideal según la altura y el BMI objetivo
float calc_ideal_weight(float height_cm, float target_bmi) {
    float height_m = height_cm / 100.0;
    float ideal_weight = target_bmi * (height_m * height_m);
    return ideal_weight;
}


int main() {
    int num_users;
    printf("Enter the number of users: ");
    scanf("%d", &num_users);


    float heights[num_users];
    float weights[num_users];
    float bmis[num_users];


    int underweight = 0;
    int normal_weight = 0;
    int overweight = 0;
    int mild_obesity = 0;
    int moderate_obesity = 0;
    int severe_obesity = 0;


    for (int i = 0; i < num_users; i++) {
        printf("User %d\n", i + 1);
        printf("Enter your height in cm: ");
        scanf("%f", &heights[i]);
        printf("Enter your weight in kg: ");
        scanf("%f", &weights[i]);


        bmis[i] = calc_bmi(heights[i], weights[i]);


        if (bmis[i] < 18.5) {
            underweight++;
        } else if (bmis[i] < 24.9) {
            normal_weight++;
        } else if (bmis[i] < 29.9) {
            overweight++;
        } else if (bmis[i] < 34.9) {
            mild_obesity++;
        } else if (bmis[i] < 39.9) {
            moderate_obesity++;
        } else {
            severe_obesity++;
        }


        float ideal_weight = calc_ideal_weight(heights[i], 24.9);
        float weight_diff = ideal_weight - weights[i];


        printf("\nBMI Results:\n");
        printf("User %d: BMI = %.2f kg/m^2\n", i + 1, bmis[i]);


        if (bmis[i] < 18.5) {
            printf("User %d: You are underweight\n", i + 1);
        } else if (bmis[i] < 24.9) {
            printf("User %d: Your weight is ideal\n", i + 1);
        } else if (bmis[i] < 29.9) {
            printf("User %d: You are overweight\n", i + 1);
        } else if (bmis[i] < 34.9) {
            printf("User %d: You have mild obesity\n", i + 1);
        } else if (bmis[i] < 39.9) {
            printf("User %d: You have moderate obesity\n", i + 1);
        } else {
            printf("User %d: You are severely obese\n", i + 1);
        }


        if (weight_diff > 0) {
            printf("User %d: You need to gain %.2f kg to reach your ideal weight\n", i + 1, weight_diff);
        } else if (weight_diff < 0) {
            printf("User %d: You need to lose %.2f kg to reach your ideal weight\n", i + 1, -weight_diff);
        } else {
            printf("User %d: Your weight is already ideal\n", i + 1);
        }
    }


    printf("\nPercentage of people in each category:\n");
    printf("Underweight: %.2f%%\n", (float)underweight / num_users * 100);
    printf("Normal weight: %.2f%%\n", (float)normal_weight / num_users * 100);
    printf("Overweight: %.2f%%\n", (float)overweight / num_users * 100);
    printf("Mild obesity: %.2f%%\n", (float)mild_obesity / num_users * 100);
    printf("Moderate obesity: %.2f%%\n", (float)moderate_obesity / num_users * 100);
    printf("Severe obesity: %.2f%%\n", (float)severe_obesity / num_users * 100);


    return 0;
}
