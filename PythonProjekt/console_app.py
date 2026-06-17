from logic import ExpenseManager

def show_menu():
    print("\n--- Menedżer Wydatków ---")
    print("1. Pokaż listę wydatków i sumę")
    print("2. Dodaj wydatek")
    print("3. Usuń wydatek")
    print("4. Wyjście")

def main():
    manager = ExpenseManager()

    while True:
        show_menu()
        choice = input("Wybierz opcję (1-4): ").strip()

        match choice:
            case "1":
                expenses = manager.get_expenses_strings()
                if not expenses:
                    print("Brak wydatków na liście.")
                else:
                    print("\nTwoje wydatki:")
                    for idx, exp in enumerate(expenses):
                        print(f"{idx}. {exp}")
                    print(f"Razem: {manager.get_total_expenses():.2f} zł")
            case "2":
                title = input("Nazwa wydatku: ").strip()
                amount = input("Kwota: ").strip()
                category = input("Kategoria: ").strip()

                if manager.add_expense(title, amount, category):
                    print("Dodano wydatek.")
                else:
                    print("Błąd: Niepoprawna kwota lub brakujące dane.")
            case "3":
                index = input("Podaj numer wydatku do usunięcia: ").strip()
                if index.isdigit() and manager.remove_expense(int(index)):
                    print("Wydatek usunięty.")
                else:
                    print("Błędny numer wydatku.")
            case "4":
                print("Do widzenia!")
                break
            case _:
                print("Nieprawidłowy wybór. Spróbuj ponownie.")

if __name__ == "__main__":
    main()