//quadratic equation ax2 + bx + c = 0
var a = 2;
var b = 0;
var c = -1;

var D = b * b - 4 * a * c;
if (D < 0) {
  console.log("No solution in R");
} else if (D > 0) {
  var x1 = Math.round(((-b + Math.sqrt(D)) / (2 * a)) * 100) / 100;
  var x2 = Math.round(((-b - Math.sqrt(D)) / (2 * a)) * 100) / 100;
  console.log("Two solution: x1 = " + x1 + ", x2 = " + x2);
} else {
  console.log("One solution: x = " + -b / (2 * a));
}
