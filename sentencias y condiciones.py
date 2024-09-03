# Función para calcular el IMC
def calc_bmi(height, weight):
    # Calcular el índice de masa corporal
    bmi = weight / ((height / 100.0) ** 2)
    return bmi


# Función principal
def main():
    # Solicitar la altura en cms
    height = float(input("Enter your height in cms: "))


    # Solicitar el peso en kgs
    weight = float(input("Enter your weight in kgs: "))


    # Calcular el IMC
    bmi = calc_bmi(height, weight)


    # Imprimir el resultado
    print(f"Your body mass index is {bmi:.2f} kg/m^2")


    # Determinar la categoría de peso
    if bmi < 18.5:
        print("You are underweight")
    elif 18.5 <= bmi < 24.9:
        print("Your weight is ideal")
    elif 25 <= bmi < 29.9:
        print("You are overweight")
    elif 30 <= bmi < 34.9:
        print("You have mild obesity")
    elif 35 <= bmi < 39.9:
        print("You have average obesity")
    elif bmi >= 40:
        print("You have morbidly obese")


# Llamar a la función principal
if __name__ == "__main__":
    main()
