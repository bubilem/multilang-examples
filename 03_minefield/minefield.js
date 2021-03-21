var minefield = [];
init(20, 10);
generateMines(30);
evaluate();
show();

function init(width, height) {
  minefield = [...Array(width)].map((e) => Array(height).fill(0));
}

function generateMines(count) {
  if (count > minefield.length * minefield[0].length) {
    return;
  }
  var x, y;
  for (let i = 0; i < count; i++) {
    do {
      x = Math.floor(Math.random() * minefield.length);
      y = Math.floor(Math.random() * minefield[0].length);
    } while (minefield[x][y] == 9);
    minefield[x][y] = 9;
  }
}

function evaluate() {
  var neighbors = [
    [-1, -1],
    [0, -1],
    [1, -1],
    [-1, 0],
    [1, 0],
    [-1, 1],
    [0, 1],
    [1, 1],
  ];
  var nx, ny;
  for (let y = 0; y < minefield[0].length; y++) {
    for (let x = 0; x < minefield.length; x++) {
      if (minefield[x][y] != 9) {
        continue;
      }
      for (let neighbor of neighbors) {
        nx = x + neighbor[0];
        ny = y + neighbor[1];
        if (
          nx >= 0 &&
          nx < minefield.length &&
          ny >= 0 &&
          ny < minefield[0].length &&
          minefield[nx][ny] != 9
        ) {
          minefield[nx][ny]++;
        }
      }
    }
  }
}

function show() {
  var row;
  for (let y = 0; y < minefield[0].length; y++) {
    row = "";
    for (let x = 0; x < minefield.length; x++) {
      row += (minefield[x][y] == 9 ? "*" : minefield[x][y] == 0 ? " " : minefield[x][y]) + " ";
    }
    console.log(row);
  }
}
