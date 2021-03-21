// generate
var data = Array.from({ length: 10 }, () => Math.floor(Math.random() * 100));

// optimized bubble-sort
var tmp;
var swap;
for (let j = 0; j < data.length - 1; j++) {
  swap = false;
  for (let i = 0; i < data.length - 1 - j; i++) {
    if (data[i] > data[i + 1]) {
      tmp = data[i];
      data[i] = data[i + 1];
      data[i + 1] = tmp;
      swap = true;
    }
  }
  if (!swap) {
    break;
  }
}

// show
console.log(data.join(" "));
