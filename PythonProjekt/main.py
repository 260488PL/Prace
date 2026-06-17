from PyQt6.QtWidgets import QApplication
from ui import ExpenseManagerUI
import sys

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = ExpenseManagerUI()
    window.show()
    sys.exit(app.exec())