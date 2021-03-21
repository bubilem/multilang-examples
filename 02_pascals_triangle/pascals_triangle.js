pascals_triangle(13);

function factorial(n) {
  return n <= 1 ? 1 : factorial(n - 1) * n;
}

function n_over_k(n, k) {
  if (k == 0 || n == k) {
    return 1;
  }
  return factorial(n) / (factorial(n - k) * factorial(k));
}

function pascals_triangle(height) {
  for (row = 0; row < height; row++) {
    let str = "  ".repeat(height - 1 - row);
    for (i = 0; i <= row; i++) {
      str += n_over_k(row, i).toString().padStart(3, " ") + " ";
    }
    console.log(str);
  }
}
