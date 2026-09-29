// Task 1
function calculateTotal(itemPrice, quantity) {
  return itemPrice * quantity;
}
console.log("Task 1:", calculateTotal(499, 3));

// Task 2: Flipkart-style discount
function finalPrice(price, discountPercent, isMember) {
  let discounted = price - (price * discountPercent) / 100;
  if (isMember) {
    discounted = discounted - (discounted * 5) / 100; // extra 5% off
  }
  return discounted;
}
console.log("Task 2 (member):    ", finalPrice(1000, 20, true));   // 760
console.log("Task 2 (non-member):", finalPrice(1000, 20, false));  // 800

// Task 3
function isEligibleForOffer(age, orderValue) {
  return age >= 18 && orderValue > 500;
}
console.log("Task 3:", isEligibleForOffer(20, 600), isEligibleForOffer(17, 900), isEligibleForOffer(25, 500));

// Task 4: trending post  (likes >= 1000) OR (comments > 200 AND shares >= 50)
let likes = 800, comments = 250, shares = 60;
let trending = likes >= 1000 || (comments > 200 && shares >= 50);
console.log("Task 4: trending?", trending);

// Task 5: pre vs post increment
let followerCount = 100;
console.log("Before:", followerCount);
console.log("++followerCount ->", ++followerCount);  // increments first, then uses: 101
console.log("After pre:", followerCount);            // 101
console.log("followerCount++ ->", followerCount++);  // uses first (101), then increments
console.log("After post:", followerCount);           // 102
