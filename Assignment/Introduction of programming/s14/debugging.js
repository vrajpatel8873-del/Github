// Task 1: fixed Zomato total
let items = ["Burger", "Pizza", "Fries"];
let prices = [120, 250, 90];
let total = 0;
for (let i = 0; i < items.length; i++) {   // FIX 1: declare i with let (else it becomes an implicit global / error in strict mode)
  total += prices[i];                      // FIX 2: `=+` just assigns +prices[i]; `+=` adds
}
console.log("Total price is: " + total);   // 460

// Task 2: readable isEven
function isEven(num) {
  // % gives the remainder after dividing by 2
  if (num % 2 === 0) {
    return true;   // no remainder -> even
  } else {
    return false;  // remainder -> odd
  }
}
console.log("Task 2:", isEven(4), isEven(7));

// Task 3
function formatFollowersCount(count) {
  if (count < 1000) {
    return String(count);                              // below 1000: as-is
  } else if (count < 1000000) {
    return (count / 1000).toFixed(1).replace(".0", "") + "K";   // 1500 -> 1.5K
  } else {
    return (count / 1000000).toFixed(1).replace(".0", "") + "M"; // 1200000 -> 1.2M
  }
}
console.log("Task 3:", formatFollowersCount(950), formatFollowersCount(1500), formatFollowersCount(1200000), formatFollowersCount(2000));

// Task 4: `=` assigns, `===` compares
for (let i = 1; i <= 10; i++) {
  if (i % 2 === 0) {      // FIX: was `i % 2 = 0` (assignment -> SyntaxError)
    console.log(i);       // print only even numbers
  }
}
