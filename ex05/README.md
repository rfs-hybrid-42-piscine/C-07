# 🟢 Exercise 05: ft_split

## 📝 Objective
Create a function that dynamically splits a string into an array of smaller strings using multiple characters as delimiters.

## 💡 The Logic
This is an incredibly complex function that involves allocating a parent array of pointers (`char **`), and then individually allocating each substring (`char *`).
1. **Counting Words:** We iterate through `str`, treating any character found in `charset` as a delimiter. Using a boolean flag, we count how many distinct "words" exist so we can `malloc` the parent array.
2. **Extracting Words:** We iterate through the string again. When we find a word, we measure its length, `malloc` the substring, and copy the characters. 
3. **The Memory Leak Safeguard:** If *any* substring `malloc` fails, returning `NULL` immediately will cause a catastrophic memory leak because all previously allocated words are lost in the Heap. We use a `free_split` helper to iterate backward and safely free all previous words before destroying the main array.
4. Finally, we append a `NULL` pointer at the end of the array to signify its end.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`ft_split.c`](ft_split.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-07` directory. You must pass the `-D EX05` flag to the compiler to selectively activate the test for this specific exercise!
   ```bash
   cc -Wall -Wextra -Werror -D EX05 ../tester.c ft_split.c -o test_ex05
   ./test_ex05
   ```
