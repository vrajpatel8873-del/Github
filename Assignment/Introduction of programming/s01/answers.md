# Session 1 – What is Programming?

## Task 1 – What is a program?
A program is a set of step-by-step instructions written in a programming language that tells a computer how to do a task.
Example: when I order on Zomato, the app is a program. It takes my location, shows restaurants, adds items to the cart, calculates the bill and sends the order — each step is an instruction written by programmers.

## Task 2 – Three programming languages
| Language | Compiled / Interpreted |
|---|---|
| Java | Both: compiled to bytecode by `javac`, then run/interpreted (and JIT-compiled) by the JVM |
| Python | Usually interpreted (CPython first compiles to bytecode, then interprets it) |
| JavaScript | Interpreted / JIT-compiled by the browser or Node.js engine (V8) |
(C, for reference, is compiled.)

## Task 3 – Flowchart
See `bookmyshow_flowchart.png` (source: `flowchart.dot`).

## Task 4 – Algorithm: ordering food on Swiggy
1. Start.
2. Open the Swiggy app.
3. Allow / enter delivery location.
4. Browse or search for a restaurant or dish.
5. Select a restaurant.
6. Add the desired items to the cart.
7. Open the cart and check items, quantity and bill.
8. Apply a coupon (optional).
9. Choose or confirm the delivery address.
10. Choose a payment method (UPI / card / net banking / cash).
11. Pay. If payment fails, go to step 10.
12. Receive order confirmation.
13. End.
