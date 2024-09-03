def calc_bmi(height_cm, weight_kg):
    """
    Calculate BMI given height in cm and weight in kg.
    """
    height_m = height_cm / 100.0
    bmi = weight_kg / (height_m * height_m)
    return bmi


def main():
    # Ask user for the number of users
    num_users = int(input("Enter the number of users: "))


    # Lists to store height, weight, and BMI for each user
    heights = [0] * num_users
    weights = [0] * num_users
    bmis = [0] * num_users


    # Variables to count each category
    underweight = 0
    normal_weight = 0
    overweight = 0
    mild_obesity = 0
    moderate_obesity = 0
    severe_obesity = 0


    # Read data for each user
    for i in range(num_users):
        print(f"User {i + 1}")


        # Ask user for height in centimeters
        heights[i] = float(input("Enter your height in cm: "))


        # Ask user for weight in kilograms
        weights[i] = float(input("Enter your weight in kg: "))


        # Calculate BMI for the current user
        bmis[i] = calc_bmi(heights[i], weights[i])


        # Classify BMI into categories
        if bmis[i] < 18.5:
            underweight += 1
        elif bmis[i] < 24.9:
            normal_weight += 1
        elif bmis[i] < 29.9:
            overweight += 1
        elif bmis[i] < 34.9:
            mild_obesity += 1
        elif bmis[i] < 39.9:
            moderate_obesity += 1
        else:
            severe_obesity += 1


    # Display results for each user
    print("\nBMI Results:")
    for i in range(num_users):
        print(f"User {i + 1}: BMI = {bmis[i]:.2f} kg/m^2")


        # Print BMI category
        if bmis[i] < 18.5:
            print(f"User {i + 1}: You are underweight")
        elif bmis[i] < 24.9:
            print(f"User {i + 1}: Your weight is ideal")
        elif bmis[i] < 29.9:
            print(f"User {i + 1}: You are overweight")
        elif bmis[i] < 34.9:
            print(f"User {i + 1}: You have mild obesity")
        elif bmis[i] < 39.9:
            print(f"User {i + 1}: You have moderate obesity")
        else:
            print(f"User {i + 1}: You are severely obese")


    # Calculate and display percentages
    print("\nPercentage of people in each category:")
    print(f"Underweight: {(underweight / num_users) * 100:.2f}%")
    print(f"Normal weight: {(normal_weight / num_users) * 100:.2f}%")
    print(f"Overweight: {(overweight / num_users) * 100:.2f}%")
    print(f"Mild obesity: {(mild_obesity / num_users) * 100:.2f}%")
    print(f"Moderate obesity: {(moderate_obesity / num_users) * 100:.2f}%")
    print(f"Severe obesity: {(severe_obesity / num_users) * 100:.2f}%")


if __name__ == "__main__":
    main()
