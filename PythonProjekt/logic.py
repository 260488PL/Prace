import difflib


class ExpenseManager:
    def __init__(self):
        self.expenses = []  # Lista wydatków

    def add_expense(self, title, amount, category):
        """Dodaje nowy wydatek do listy z automatyczną korektą kategorii."""
        try:
            amount_float = float(amount)
            if amount_float <= 0:
                return False

            category = category.strip().capitalize()
            title = title.strip()

            # Inteligentne wykrywanie literówek
            category = self._auto_correct_category(category)

            self.expenses.append({
                "title": title,
                "amount": amount_float,
                "category": category
            })
            return True
        except ValueError:
            return False

    def _auto_correct_category(self, user_category):
        """Wykrywa literówki i dopasowuje tekst do już istniejących kategorii."""
        # Pobiera listę unikalnych kategorii, które już są w systemie
        existing_categories = list(self.get_expenses_by_category().keys())

        if not existing_categories:
            return user_category

        # cutoff=0.6 oznacza, że słowa muszą być podobne w co najmniej 60%
        matches = difflib.get_close_matches(user_category, existing_categories, n=1, cutoff=0.6)

        if matches:
            # Znaleziono bardzo podobną kategorię (np. dla "Jdzenie" znajdzie "Jedzenie")
            return matches[0]

        # Jeśli nie ma podobnych, zwraca to, co wpisał użytkownik jako nową kategorię
        return user_category

    def remove_expense(self, index):
        """Usuwa wydatek z listy na podstawie indeksu."""
        if 0 <= index < len(self.expenses):
            self.expenses.pop(index)
            return True
        return False

    def get_total_expenses(self):
        """Zwraca sumę wszystkich wydatków."""
        return sum(item["amount"] for item in self.expenses)

    def get_expenses_strings(self):
        """Zwraca listę wydatków w formacie tekstowym."""
        return [
            f"[{item['category']}] {item['title']}: {item['amount']:.2f} zł"
            for item in self.expenses
        ]

    def get_expenses_by_category(self):
        """Zwraca słownik z sumami dla poszczególnych kategorii."""
        category_sums = {}
        for item in self.expenses:
            cat = item["category"]
            if cat not in category_sums:
                category_sums[cat] = 0.0
            category_sums[cat] += item["amount"]
        return category_sums