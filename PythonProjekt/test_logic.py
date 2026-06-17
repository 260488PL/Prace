import pytest
from logic import ExpenseManager


@pytest.fixture
def manager():
    """Tworzy czystą instancję ExpenseManager do każdego testu."""
    return ExpenseManager()


def test_add_expense_valid(manager):
    assert manager.add_expense("Kino", "35.00", "Rozrywka") is True
    assert len(manager.expenses) == 1
    assert manager.get_total_expenses() == 35.00


def test_add_expense_invalid_amount(manager):
    # Tekst zamiast liczby
    assert manager.add_expense("Kino", "za_darmo", "Rozrywka") is False
    # Liczba ujemna
    assert manager.add_expense("Kino", "-10", "Rozrywka") is False
    assert len(manager.expenses) == 0


def test_remove_expense(manager):
    manager.add_expense("Buty", "200", "Odzież")
    manager.add_expense("Chleb", "5.50", "Jedzenie")

    assert manager.remove_expense(0) is True
    assert len(manager.expenses) == 1
    assert manager.get_total_expenses() == 5.50


def test_remove_expense_invalid_index(manager):
    manager.add_expense("Buty", "200", "Odzież")
    assert manager.remove_expense(5) is False  # indeks poza zakresem


def test_get_total_expenses(manager):
    manager.add_expense("Prąd", "150.20", "Opłaty")
    manager.add_expense("Internet", "60.00", "Opłaty")
    assert manager.get_total_expenses() == 210.20


def test_get_expenses_strings(manager):
    manager.add_expense("Chleb", "4.5", "Jedzenie")
    assert manager.get_expenses_strings() == ["[Jedzenie] Chleb: 4.50 zł"]