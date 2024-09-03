def calc_bmi(height_cm, weight_kg):
    """
    Calcula el índice de masa corporal (BMI).
    """
    height_m = height_cm / 100.0
    bmi = weight_kg / (height_m * height_m)
    return bmi


def main():
    # Pedir al usuario el número de personas
    num_users = int(input("Enter the number of users: "))


    # Listas para almacenar altura y peso de cada usuario
    heights = [0] * num_users
    weights = [0] * num_users
    bmis = [0] * num_users


    # Leer datos para cada usuario
    for i in range(num_users):
        print(f"User {i + 1}")


        # Pedir altura en centímetros
        heights[i] = float(input("Enter your height in cm: "))


        # Pedir peso en kilogramos
        weights[i] = float(input("Enter your weight in kg: "))


        # Calcular BMI para el usuario actual
        bmis[i] = calc_bmi(heights[i], weights[i])


    # Mostrar resultados para cada usuario
    print("\nBMI Results:")
    for i in range(num_users):
        print(f"User {i + 1}: BMI = {bmis[i]:.2f} kg/m^2")
       
        # Imprimir categoría del BMI
        if bmis[i] < 18.5:
            print(f"User {i + 1}: You are underweight")
        elif 18.5 <= bmis[i] < 24.9:
            print(f"User {i + 1}: Your weight is ideal")
        elif 25 <= bmis[i] < 29.9:
            print(f"User {i + 1}: You are overweight")
        elif 30 <= bmis[i] < 34.9:
            print(f"User {i + 1}: You have mild obesity")
        elif 35 <= bmis[i] < 39.9:
            print(f"User {i + 1}: You have moderate obesity")
        else:
            print(f"User {i + 1}: You are morbidly obese")


if __name__ == "__main__":
    main()
