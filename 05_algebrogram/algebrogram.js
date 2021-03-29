var left, right;
var r = [];
for (let a = 0; a <= 9; a++) {
  for (let b = 0; b <= 9; b++) {
    if (b == a) {
      continue;
    }
    for (let c = 0; c <= 9; c++) {
      if (c == b || c == a) {
        continue;
      }
      for (let d = 0; d <= 9; d++) {
        if (d == c || d == b || d == a) {
          continue;
        }
        left = (a * 1000 + b * 100 + c * 10 + d) * d;
        right = d * 1000 + c * 100 + b * 10 + a;
        if (left == right) {
          r.push(a);
          r.push(b);
          r.push(c);
          r.push(d);
          break;
        }
      }
    }
  }
}
if (r.length === 4) {
  console.log("abcd*d = dcba");
  console.log(
    r[0].toString() +
      r[1].toString() +
      r[2].toString() +
      r[3].toString() +
      "*" +
      r[3].toString() +
      " = " +
      r[3].toString() +
      r[2].toString() +
      r[1].toString() +
      r[0].toString()
  );
} else {
  console.log("No success");
}
