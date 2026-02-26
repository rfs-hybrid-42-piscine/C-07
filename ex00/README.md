# 🟢 Exercise 00: ft_strdup

## 📝 Objective
Reproduce the behavior of the standard C library function `strdup` (string duplicate) using dynamic memory allocation.

## 💡 The Logic
The goal is to create an exact copy of the string `src` on the Heap.
1. **Length:** First, we iterate through `src` to determine its length.
2. **Allocation:** We use `malloc` to request exactly `length + 1` bytes of memory (the `+ 1` is crucial to make space for the null-terminator).
3. **Safety Check:** We immediately check if `malloc` failed (returned `NULL`). If so, we return `NULL`.
4. **Copying:** We iterate through `src` again, copying each character into our newly allocated memory block, append the final `\0`, and return the pointer.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`ft_strdup.c`](ft_strdup.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-07` directory. You must pass the `-D EX00` flag to the compiler to selectively activate the test for this specific exercise!
   ```bash
   cc -Wall -Wextra -Werror -D EX00 ../tester.c ft_strdup.c -o test_ex00
   ./test_ex00
   ```
