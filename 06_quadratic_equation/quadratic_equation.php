<?php
//quadratic equation ax2 + bx + c = 0
$a = 2;
$b = 0;
$c = -1;

$D = ($b * $b) - (4 * $a * $c);
if ($D < 0) {
    echo "No solution in R";
} else if ($D > 0) {
    $x1 = round((-$b + sqrt($D)) / (2 * $a), 2);
    $x2 = round((-$b - sqrt($D)) / (2 * $a), 2);
    echo "Two solution: x1 = $x1, x2 = $x2";
} else {
    echo "One solution: x = " . round((-$b) / (2 * $a), 2);
}
