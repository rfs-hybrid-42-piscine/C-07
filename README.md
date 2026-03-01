*This project has been created as part of the 42 curriculum by maaugust.*

<div align="center">
  <img src="https://raw.githubusercontent.com/rfs-hybrid/42-piscine-artwork/main/assets/covers/cover-c07.png" alt="C 07 Cover" width="100%" />
</div>

<div align="center">
  <h1>💻 C 07: Dynamic Memory Allocation</h1>
  <p><i>Mastering malloc, free, and Heap memory manipulation.</i></p>
  
  <img src="https://img.shields.io/badge/Language-C-blue" alt="Language badge" />
  <img src="https://img.shields.io/badge/Grade-100%2F100-success" alt="Grade badge" />
  <img src="https://img.shields.io/badge/Norminette-Passing-success" alt="Norminette badge" />
</div>

---

## 💡 Description
**C 07** introduces the concept of **Dynamic Memory Allocation**.

Previously, all arrays and strings were allocated on the Stack, meaning their sizes had to be known at compile time. In this module, you will use the `malloc` function to request memory blocks from the Heap at runtime. You will learn how to accurately calculate the required byte sizes for strings and integer arrays, safely allocate memory, and prevent Segmentation Faults by checking for allocation failures.

---

## 🧠 Exercise Breakdown & Logic

*The following section explains the core concepts required to solve each exercise. It focuses on the fundamental logic of C programming, emphasizing manual memory manipulation and edge-case management.*

### 🔹 Memory Allocation Basics
| Exercise | Concept & Logic |
| :--- | :--- |
| **[`ex00: ft_strdup`](ex00)** | **String Duplication:** Reproducing the standard `strdup` function using `malloc`. <br><br>**Logic:** We first find the length of the source string `src`. We then use `malloc` to allocate `length + 1` bytes of memory (the `+ 1` is strictly for the null-terminator `\0`). After verifying the allocation didn't fail (return `NULL`), we copy the characters from `src` into our newly allocated memory block and return the pointer. |
| **[`ex01: ft_range`](ex01)** | **Integer Arrays:** Generating an array of numbers between `min` (included) and `max` (excluded). <br><br>**Logic:** If `min >= max`, the range is invalid, and we immediately return `NULL`. Otherwise, the total number of elements is `max - min`. We allocate memory by multiplying this count by `sizeof(int)`. Finally, we use a loop to populate the array with the incremental values and return the pointer. |
| **[`ex02: ft_ultimate_range`](ex02)** | **Double Pointers:** Allocating and assigning a range of numbers via a pointer to a pointer. <br><br>**Logic:** Similar to `ex01`, but instead of simply returning the array, we assign the allocated array directly to `*range`. If `min >= max`, we set `*range = NULL` and return `0`. On an allocation error, we return `-1`. Otherwise, we populate the array and return the total size (`max - min`). |

### 🔢 Advanced String Manipulation
| Exercise | Concept & Logic |
| :--- | :--- |
| **[`ex03: ft_strjoin`](ex03)** | **Concatenation:** Joining an array of strings together, divided by a separator string. <br><br>**Logic:** If `size` is 0, we must `malloc` and return an empty string (`\0`). Otherwise, we iterate through all strings in the `strs` array to calculate their total combined length, plus the length of the `sep` string multiplied by `size - 1`. We allocate this exact amount of memory (`+ 1` for the null terminator), copy each string in order, and interleave the separator. |
| **[`ex05: ft_split`](ex05)** | **Parsing:** Splitting a single string into an array of smaller strings based on a set of separator characters. <br><br>**Logic:** This is notoriously difficult. <br>1. **Count Words:** Iterate through `str` to count how many distinct "words" exist between the `charset` characters. <br>2. **Allocate Array:** `malloc` an array of character pointers: `(word_count + 1) * sizeof(char *)`. The `+ 1` is to `NULL`-terminate the array itself. <br>3. **Allocate Words:** Iterate through `str` again. Find the length of each word, `malloc` `len + 1` bytes for it, copy the characters over, and attach the resulting pointer to your master array. Empty strings must be ignored. |

### 👑 The Final Boss
| Exercise | Concept & Logic |
| :--- | :--- |
| **[`ex04: ft_convert_base`](ex04)** | **Base Translation:** Converting a string from one mathematical base directly into another. <br><br>**Logic:** This requires joining two separate `.c` files. We must validate both `base_from` and `base_to` (no duplicates, no signs). We use the logic from `ft_atoi_base` to convert the string `nbr` into a standard `int`. Then, we calculate exactly how many characters that integer will require in `base_to`, allocate the string using `malloc`, and convert the integer into the new base string (handling negative signs properly). |

---

## 🛠️ Instructions

### 🧪 Compilation & Testing (The Master Test)
Unlike Shell scripts, C programs must be compiled before they can be executed. Furthermore, these exercises strictly ask for functions, not complete programs. 

To make testing incredibly easy while avoiding "undefined reference" linker errors, the **[`tester.c`](tester.c)** file in the root directory uses **C Preprocessor Macros** (`#ifdef`). This allows you to selectively compile and test only the exercises you want.

1. **Clone the repository:**
   You can clone this module directly, or pull the entire 42 Piscine parent repository which includes this module as a submodule.

   **Option A: Clone this module directly**
   ```bash
   git clone git@github.com:rfs-hybrid-42-piscine/C-07.git C-07
   cd C-07
   ```

   **Option B: Clone the parent repository (with submodules)**
   ```bash
   git clone --recurse-submodules git@github.com:rfs-hybrid/42-Piscine.git 42-Piscine
   cd 42-Piscine/C-07
   ```
   *(Note: The `--recurse-submodules` flag ensures all nested module repositories are populated immediately.)*

2. **Test a Single Exercise:**
   Pass the corresponding `-D EX**` flag to activate that specific test block inside **[`tester.c`](tester.c)**.
   ```bash
   # Example for ex00:
   cc -Wall -Wextra -Werror -D EX00 tester.c ex00/ft_strdup.c -o test_ex00
   ./test_ex00
   ```

3. **Test Multiple Exercises Together:**
   You can chain multiple `-D` flags to test several functions at once, provided you include all their `.c` files in the command.
   ```bash
   # Example for ex00 and ex01:
   cc -Wall -Wextra -Werror -D EX00 -D EX01 tester.c ex00/ft_strdup.c ex01/ft_range.c -o test_multiple
   ./test_multiple
   ```

4. **Test ALL Exercises at Once:**
   By passing the `-D TEST_ALL` master flag, you can activate the entire testing suite in one go!
   ```bash
   cc -Wall -Wextra -Werror -D TEST_ALL tester.c ex00/ft_strdup.c ex01/ft_range.c ex02/ft_ultimate_range.c ex03/ft_strjoin.c ex04/ft_convert_base.c ex04/ft_convert_base2.c ex05/ft_split.c -o test_all
   ./test_all
   ```

> **⚠️ WARNING for 42 Students:** Do not push **[`tester.c`](tester.c)** or any executable files to your final Moulinette repository! They are strictly for local testing purposes. Submitting unauthorized files will result in a 0.

### 🚨 The Norm
Moulinette relies on a program called `norminette` to check if your files comply with the Norm. Every single `.c` and `.h` file must pass. 

**The 42 Header:**
Before writing any code, every file must start with the standard 42 header. `norminette` will automatically fail any file missing this specific signature.
```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:34:52 by maaugust          #+#    #+#             */
/*   Updated: 2025/03/06 15:01:48 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
```

Run the following command before pushing:
```bash
norminette -R CheckForbiddenSourceHeader <file.c>
```

---

## 📚 Resources & References

* `man 3 malloc` / `man 3 free` - Manuals for dynamic memory allocation.
* `man 3 strdup` - The standard manual for string duplication.
* [42 Norm V4](https://cdn.intra.42.fr/pdf/pdf/96987/en.norm.pdf) - The strict coding standard for 42 C projects.
* [Official 42 Norminette Repository](https://github.com/42School/norminette) - The open-source linter enforcing the strict 42 coding standard.

### 🤖 AI Usage Guidelines
* **Code:** No AI-generated code was used to solve these exercises. All C functions were built manually to strictly comply with the 42 Norm and deeply understand manual memory manipulation, enforcing the concept that learning is about developing the ability to find an answer, not just getting one directly.
* **Documentation:** AI tools were utilized to structure this `README.md` and format the logic breakdowns to create a clean, accessible educational resource for fellow 42 students.
