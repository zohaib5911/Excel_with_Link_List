📊 Mini Excel Spreadsheet using Linked List (C++)
A simple C++ console-based spreadsheet system that mimics Excel functionalities using a 2D linked list data structure. Each cell supports integer values and basic arithmetic formulas.

🧠 Features
Create a grid-based spreadsheet (default 5x5)

Set individual cell values

Set cell values using formulas (e.g. A1 = B3 + C2)

Add rows and columns dynamically

Insert values into entire row or column

Empty entire row or column

Recalculate dependent formula-based cells automatically

Find:

Row-wise Max/Min

Column-wise Max/Min

User-friendly CLI menu

🔧 Technologies
Language: C++

Compiler: g++ (MinGW or any C++14+ supported compiler)

📁 File Structure
bash
Copy
Edit
├── main.cpp             # Main user interface
├── spreadSheet.h        # Spreadsheet class (template)
├── cell.h               # Definition of the Cell<T> node
🧪 Sample Formula
You can set cell formulas like:

ini
Copy
Edit
A1 = B3 + C2
A2 = D3 * E4
And the spreadsheet will:

Automatically evaluate the expression

Track dependencies

Recalculate on value updates

🚀 How to Run
Clone or Download this repository.

Compile using any C++ compiler:

bash
Copy
Edit
g++ main.cpp -o sheet
Run the executable:

bash
Copy
Edit
./sheet      # On Linux/Mac
sheet.exe    # On Windows
🎯 Demo Output
mathematica
Copy
Edit
=========== Mini Excel ===========
1. Display Sheet
2. Set Cell Value
3. Set Cell Formula (A1=A2+A3)
4. Add Row
5. Add Column
...
Enter choice: 
📌 Future Improvements
Support for saving and loading sheets from files

Add more formula complexity (e.g., nested formulas)

GUI support using Qt or ImGui

Sorting row or column based on values