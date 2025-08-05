# 📊 Mini Excel Spreadsheet using Linked List (C++)

A simple C++ console-based spreadsheet system that mimics Excel functionalities using a 2D linked list data structure. Each cell supports integer values and basic arithmetic formulas, with dependency tracking and auto-recalculation.

---

## 🧠 Features

- **Grid-based Spreadsheet:** Create a spreadsheet of any size (default 5x5, customizable).
- **Set Cell Value:** Assign integer values to any cell by row/column or Excel-style notation (e.g., A1).
- **Set Cell Formula:** Use formulas like `A1 = B3 + C2`, supporting `+`, `-`, `*`, `/` operators.
- **Dependency Tracking:** Automatically track and update dependent cells when referenced cells change.
- **Recalculation:** All formula-based cells are recalculated on any update.
- **Add Row/Column:** Dynamically add rows or columns to the spreadsheet.
- **Insert Values into Row/Column:** Fill an entire row or column with user input.
- **Display Sheet:** Print the spreadsheet in a tabular format with row and column headers.
- **User-friendly CLI Menu:** Simple menu-driven interface for all operations.
- **Safe Memory Management:** Custom destructor to free all allocated memory.

---

## 🧪 Example Formula

You can set cell formulas like:
A1 = B3 + C2 A2 = D3 * E4

The spreadsheet will:
- Automatically evaluate the expression
- Track dependencies
- Recalculate on value updates

---


=========== Mini Excel ===========
1. Display Sheet
2. Set Cell Value
3. Set Cell Formula (A1=A2+A3)
4. Add Row
5. Add Column
...
Enter choice:


📌 Future Improvements

- Support for saving and loading sheets from files
- Add more formula complexity (e.g., nested formulas, parentheses)
- GUI support using Qt or ImGui
- Sorting row or column based on values
- Support for different data types (string, float, etc.)
- Undo/Redo functionality
- Import/Export to CSVs
