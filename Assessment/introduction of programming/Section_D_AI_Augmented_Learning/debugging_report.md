# Section D — AI-Augmented Learning Report

**Program:** Software Engineering  
**Assessment Code:** M3-A1  
**Section:** Section D — AI-Augmented Learning

---

## 1. Exact Prompt Given to the AI Tool
The following prompt was submitted to the AI model (stored in `prompt.txt`):
```text
Write a C program that accepts exactly 10 integers from the user using a loop and stores them in an array. Finds and displays the maximum value, minimum value, and arithmetic mean (displayed as a float with 2 decimal places). Sorts the array in ascending order using any sorting method and displays the sorted list. Prints whether the mean is closer to the minimum, closer to the maximum, or exactly midway between them.
```

---

## 2. Code Submissions
- **AI's Original Code:** `ai_original.c`
- **Corrected & Debugged Version:** `ai_corrected.c`

---

## 3. Explanatory Note (3–4 Lines)

> **I corrected the AI's flawed `min`/`max` zero-initialization by extracting them directly from the sorted array endpoints (`arr[0]` and `arr[9]`), which resolved severe calculation errors when inputs were strictly positive or strictly negative. I also replaced raw floating-point equality comparisons with an epsilon tolerance (`EPSILON 1e-6f`) to prevent IEEE-754 precision misclassifications when the mean is algebraically midway. Additionally, I introduced an explicit edge-case guard for identical input sets (`min == max`) where relative distance is non-existent, alongside robust `scanf()` input stream validation.**

---

## 4. Boundary Input Test Results Comparison

### Test (a): All 10 Values Identical
- **Input:** `5 5 5 5 5 5 5 5 5 5`
- **AI's Original Output:**
  ```text
  Minimum: 0
  Maximum: 5
  Mean: 5.00
  The mean is closer to the maximum.
  ```
  *(CRITICAL BUG: Because `min` was initialized to 0, `min` remained 0 instead of 5, erroneously reporting the mean was closer to the maximum!)*
- **Corrected Output:**
  ```text
  Minimum Value : 5
  Maximum Value : 5
  Sum           : 50
  Arithmetic Mean: 5.00
  Analysis: All 10 values are identical (5). The mean equals the bounds.
  ```

---

### Test (b): Mix of Positive and Negative Integers
- **Input:** `-10 -20 15 -5 30 -2 0 8 -12 6`
- **AI's Original Output (on all negative values):**
  *(CRITICAL BUG: Initializing `max` to 0 caused negative sets to report a false maximum of 0, corrupting all midpoint distances).*
- **Corrected Output:**
  ```text
  Sorted Array (Ascending): -20, -12, -10, -5, -2, 0, 6, 8, 15, 30
  Minimum Value : -20
  Maximum Value : 30
  Sum           : 10
  Arithmetic Mean: 1.00
  Analysis: The mean (1.00) is closer to the minimum (-20) by 8.00 units.
  ```

---

### Test (c): List Where Mean Falls Exactly Between Min and Max
- **Input:** `10 20 30 40 50 60 70 80 90 100`
- **Expected:** Min = 10, Max = 100, Midpoint = (10 + 100) / 2 = 55.00. Mean = 55.00.
- **Corrected Output:**
  ```text
  Sorted Array (Ascending): 10, 20, 30, 40, 50, 60, 70, 80, 90, 100
  Minimum Value : 10
  Maximum Value : 100
  Sum           : 550
  Arithmetic Mean: 55.00
  Analysis: The mean (55.00) is exactly midway between min (10) and max (100).
  ```
