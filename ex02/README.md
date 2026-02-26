# 🟢 Exercise 02: ft_ultimate_range

## 📝 Objective
Create a function that dynamically allocates and assigns an array of integers containing a range using a double pointer, returning the size of the range.

## 💡 The Logic
This logic is almost identical to `ex01`, but instead of returning the array directly, we use a double pointer (`int **range`) to overwrite a pointer in the calling function.
1. **Validation:** If `min >= max`, we point `*range` to `NULL` and return a size of `0`.
2. **Allocation & Error Handling:** We allocate the memory directly into `*range`. If the allocation fails, the function must return `-1`. 
3. **Population:** We populate the array using `(*range)[i] = min + i` and return the size of the range (`max - min`).

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`ft_ultimate_range.c`](ft_ultimate_range.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-07` directory. You must pass the `-D EX02` flag to the compiler to selectively activate the test for this specific exercise!
   ```bash
   cc -Wall -Wextra -Werror -D EX02 ../tester.c ft_ultimate_range.c -o test_ex02
   ./test_ex02
   ```
