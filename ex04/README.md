# 🟢 Exercise 04: ft_convert_base

## 📝 Objective
Create a function that translates a number string from a given base into a dynamically allocated string representing it in a different base.

## 💡 The Logic
This combines logic from `C 04` with dynamic memory allocation, and is split into two files to respect the 42 Norm limits.
1. **Parsing to Decimal:** We rigorously validate both `base_from` and `base_to`. Then, we parse the `nbr` string through standard `atoi_base` logic to get its real base-10 integer value.
2. **Calculating String Length:** Using a helper function `ft_digit_places`, we simulate dividing the number by the length of the new base to count exactly how many characters we need to allocate (accounting for negative signs and a null-terminator).
3. **Base Translation:** After using `malloc`, we translate the integer into the new base system, inserting characters starting from the end of our allocated string, finally returning the pointer.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source files here:* **[`ft_convert_base.c`](ft_convert_base.c)** | **[`ft_convert_base2.c`](ft_convert_base2.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-07` directory. You must pass the `-D EX04` flag to the compiler to selectively activate the test for this specific exercise! Note that you must compile *both* `.c` files together!
   ```bash
   cc -Wall -Wextra -Werror -D EX04 ../tester.c ft_convert_base.c ft_convert_base2.c -o test_ex04
   ./test_ex04
   ```
