# 🟢 Exercise 03: ft_strjoin

## 📝 Objective
Write a function that concatenates an array of strings, separating each element with a custom separator string, and returning the newly allocated result.

## 💡 The Logic
1. **Total Size Calculation:** Before we can allocate memory, we need to know exactly how big the final string will be. We write a helper function `ft_joinlen` to sum the length of all strings in the array, plus the length of the separator string multiplied by `size - 1` (since there is no separator after the final string).
2. **The Zero Trap:** If `size` is 0, the function must return an empty string that can be freed. In this case, our length resolves to 0, we allocate 1 byte, set it to `\0`, and skip the concatenation entirely.
3. **Concatenation:** We allocate memory of `total_length + 1`. We iterate through the array, using a custom `ft_strcat` helper function to append each string and interleave the separator into our allocated heap memory.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`ft_strjoin.c`](ft_strjoin.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-07` directory. You must pass the `-D EX03` flag to the compiler to selectively activate the test for this specific exercise!
   ```bash
   cc -Wall -Wextra -Werror -D EX03 ../tester.c ft_strjoin.c -o test_ex03
   ./test_ex03
   ```
