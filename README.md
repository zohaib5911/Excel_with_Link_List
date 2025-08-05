# Excel with Linked List

A simple spreadsheet application implemented in C++ using a linked list data structure for cell management. This project demonstrates how to build a basic Excel-like grid, support cell dependencies, and perform arithmetic operations between cells.

## Features

- Dynamic 2D spreadsheet using linked cells (`Cell<T>`)
- Set and get cell values by row and column
- Display spreadsheet in a tabular format with row and column headers
- Support for cell formulas (e.g., `A1=A2+A3`)
- Dependency tracking and automatic recalculation of dependent cells
- Safe memory management with a custom destructor

## How It Works

- Each cell is a node in a 2D linked list, with `right` and `down` pointers.
- The spreadsheet supports setting values directly or via formulas.
- Dependencies between cells are tracked, so when a referenced cell changes, all dependent cells are updated.
- The spreadsheet can be displayed in a human-readable format.

## Usage

1. **Build the project**  
   Compile with any C++ compiler:
   ```
   g++ main.cpp -o main
   ```

2. **Run the program**
   ```
   ./main
   ```

3. **Interact with the spreadsheet**
   - Set values or formulas as prompted.
   - View the spreadsheet after each operation.

## Example

```
------- Spread Sheet -------
        A       B       C       D       E
0       0       0       0       0       0
1       0       0       0       0       0
2       0       0       0       0       0
3       0       0       0       0       0
4       0       0       0       0       0

Set value
Updating.......

------- Spread Sheet -------
        A       B       C       D       E
0       0       0       0       0       0
1       0       0       0       0       0
2       0       0       0       0       0
3       0       0       0       33      0
4       0       0       0       0       0
```

## File Structure

- `main.cpp` — Entry point and user interaction
- `spreadSheet.h` — Spreadsheet class and logic
- `cell.h` — Cell node definition

## Requirements

- C++11 or later

## License

This project is licensed under
