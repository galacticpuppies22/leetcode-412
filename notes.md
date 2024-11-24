# Notes on Leetcode 1672

## Why is `case1AccountPointers` needed?

***As answered by CoPilot***

When working with 2D arrays in C, functions expecting a pointer to a pointer (`int**`) can't directly handle statically allocated 2D arrays because the memory layout and access patterns differ. Here's why you need `case1AccountPointers` (or similar arrays) when calling your `maximumWealth` function:

### Understanding 2D Arrays and Pointers in C

1. **Static 2D Array**:
   - A static 2D array like `int case1InputNums[2][3]` is stored contiguously in memory, but accessing it involves both row and column indices.

2. **Pointer to Pointer (`int**`)**:
   - Functions that take `int**` expect a different layout: an array of pointers, where each pointer refers to a row of the 2D array.

### Why `case1AccountPointers` is Needed

1. **Memory Layout Compatibility**:
   - `case1AccountPointers` is an array of pointers, with each pointer pointing to a row in the static 2D array. This matches the expected `int**` layout.

2. **Function Signature**:
   - The `maximumWealth` function signature expects `int**`, `int`, and `int*`. Directly passing a statically allocated 2D array would cause incompatibility. Using pointers ensures the data is accessed correctly.

### Example Breakdown

#### Static 2D Array:
```c
int case1InputNums[2][3] = {
    {1, 2, 3},
    {3, 2, 1}
};
```

#### Array of Pointers (`case1AccountPointers`):
```c
int* case1AccountPointers[2];
for (int i = 0; i < 2; i++) {
    case1AccountPointers[i] = case1InputNums[i];
}
```

### How it Works:
- **`case1InputNums`**: A contiguous block of memory for the entire 2D array.
- **`case1AccountPointers`**: An array of pointers, each pointing to a row in `case1InputNums`.

When you pass `case1AccountPointers` to the function, it translates the access pattern from `accounts[i][j]` to the correct memory location in `case1InputNums`.

### Function Call:
```c
maximumWealth(case1AccountPointers, case1AccountsSize, (int*)case1AccountsColSize);
```

This setup ensures your function accesses the correct rows and columns, maintaining the intended behavior.

By using `case1AccountPointers`, you bridge the gap between the static 2D array's memory layout and the function's expected pointer-to-pointer layout, ensuring correct access and manipulation of data. If you have further questions or need more clarification, feel free to ask!