from PyQt6.QtWidgets import (QWidget, QVBoxLayout, QHBoxLayout, QPushButton,
                             QListWidget, QLineEdit, QLabel, QMessageBox,
                             QTableWidget, QTableWidgetItem, QHeaderView)
from logic import ExpenseManager


class ExpenseManagerUI(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Menedżer Wydatków z Kategoriami")
        self.setGeometry(100, 100, 750, 450)  # Zwiększamy szerokość okna na dwa panele

        self.expense_manager = ExpenseManager()

        # --- GŁÓWNY UKŁAD POZIOMY ---
        self.main_layout = QHBoxLayout()

        #  LEWY PANEL (Główna lista i formularz)
        self.left_layout = QVBoxLayout()

        self.expense_list = QListWidget()
        self.left_layout.addWidget(self.expense_list)

        self.total_label = QLabel("Suma wydatków: 0.00 zł")
        self.total_label.setStyleSheet("font-weight: bold; font-size: 14px; color: #2c3e50;")
        self.left_layout.addWidget(self.total_label)

        self.title_input = QLineEdit()
        self.title_input.setPlaceholderText("Nazwa wydatku... (np. chleb, mleko)")
        self.left_layout.addWidget(self.title_input)

        self.amount_input = QLineEdit()
        self.amount_input.setPlaceholderText("Kwota... (np. 45.50)")
        self.left_layout.addWidget(self.amount_input)

        self.category_input = QLineEdit()
        self.category_input.setPlaceholderText("Kategoria... (np. Jedzenie, Rozrywka)")
        self.left_layout.addWidget(self.category_input)

        self.add_button = QPushButton("Dodaj Wydatek")
        self.add_button.clicked.connect(self.add_expense)
        self.left_layout.addWidget(self.add_button)

        self.remove_button = QPushButton("Usuń Wybrany Wydatek")
        self.remove_button.clicked.connect(self.remove_expense)
        self.left_layout.addWidget(self.remove_button)

        # PRAWY PANEL (Podsumowanie kategorii)
        self.right_layout = QVBoxLayout()

        self.category_title = QLabel("Podsumowanie kategorii:")
        self.category_title.setStyleSheet("font-weight: bold; font-size: 12px;")
        self.right_layout.addWidget(self.category_title)

        # Tworzymy tabelę do wyświetlania kategorii i sum
        self.category_table = QTableWidget()
        self.category_table.setColumnCount(2)
        self.category_table.setHorizontalHeaderLabels(["Kategoria", "Suma (zł)"])
        # Automatyczne rozciąganie kolumn tabeli
        self.category_table.horizontalHeader().setSectionResizeMode(QHeaderView.ResizeMode.Stretch)
        self.right_layout.addWidget(self.category_table)

        # ŁĄCZENIE PANELÓW
        self.main_layout.addLayout(self.left_layout, stretch=2)  # Lewy panel zajmie więcej miejsca
        self.main_layout.addLayout(self.right_layout, stretch=1)  # Prawy panel będzie węższy

        self.setLayout(self.main_layout)
        self.update_ui()

    def add_expense(self):
        title = self.title_input.text().strip()
        amount = self.amount_input.text().strip()
        category = self.category_input.text().strip()

        if not title or not amount or not category:
            QMessageBox.warning(self, "Błąd", "Wszystkie pola muszą być wypełnione!")
            return

        if self.expense_manager.add_expense(title, amount, category):
            self.title_input.clear()
            self.amount_input.clear()
            self.category_input.clear()
            self.update_ui()
        else:
            QMessageBox.warning(self, "Błąd", "Wprowadź poprawną kwotę (liczba dodatnia)!")

    def remove_expense(self):
        selected = self.expense_list.currentRow()
        if selected >= 0:
            self.expense_manager.remove_expense(selected)
            self.update_ui()
        else:
            QMessageBox.warning(self, "Błąd", "Nie wybrano wydatku do usunięcia!")

    def update_ui(self):
        """Aktualizuje listę wydatków, ogólną sumę oraz tabelę kategorii."""
        # Aktualizacja lewej listy
        self.expense_list.clear()
        self.expense_list.addItems(self.expense_manager.get_expenses_strings())

        total = self.expense_manager.get_total_expenses()
        self.total_label.setText(f"Suma wydatków: {total:.2f} zł")

        # Aktualizacja prawej tabeli kategorii
        category_data = self.expense_manager.get_expenses_by_category()
        self.category_table.setRowCount(len(category_data))

        for row, (category, total_amount) in enumerate(category_data.items()):
            self.category_table.setItem(row, 0, QTableWidgetItem(category))
            self.category_table.setItem(row, 1, QTableWidgetItem(f"{total_amount:.2f}"))