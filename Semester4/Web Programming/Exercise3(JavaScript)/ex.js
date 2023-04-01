// Άσκηση 1
console.log(`1η άσκηση`);
for (let i = 1; i <= 10; i++) {
  console.log(`${i}η δύναμη του 2: ${2 ** i}`);
}

// Άσκηση 2
console.log(`2η άσκηση`);
function findLargest(a, b, c) {
  let largest = a;

  if (b > largest)
    largest = b;

  if (c > largest)
    largest = c;

  return largest;
}

console.log(`Κλήση συνάρτησης με ορίσματα: 10, 14, 9`);
console.log(findLargest(10, 14, 9));
console.log(`Κλήση συνάρτησης με ορίσματα: 'aa', 'ba', 'ca'`);
console.log(findLargest('aa', 'ba', 'ca')); 

// Άσκηση 3
console.log(`3η άσκηση`);
function positivePower(num1, num2) {
  if (Number.isInteger(num1) && Number.isInteger(num2) && num1 > 0 && num2 > 0) 
    return num1 ** num2;
  else 
    return undefined;
}

console.log(`Κλήση συνάρτησης με ορίσματα: 3, 3`);
console.log(positivePower(3, 3));
console.log(`Κλήση συνάρτησης με ορίσματα: 3.2, 3`);
console.log(positivePower(3.2, 3));
console.log(`Κλήση συνάρτησης με ορίσματα: -3, 3`);
console.log(positivePower(-3, 3));
console.log(`Κλήση συνάρτησης με ορίσματα: 'aa', 'ba'`);
console.log(positivePower('aa', 'ba')); 
