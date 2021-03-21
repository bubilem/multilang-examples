<?php
pascals_triangle(13);

function factorial(int $n): int
{
    $factorial = 1;
    for ($i = 2; $i <= $n; $i++) {
        $factorial *= $i;
    }
    return $factorial;
}

function n_over_k(int $n, int $k): int
{
    if ($k == 0 || $n == $k) {
        return 1;
    }
    return factorial($n) / (factorial($n - $k) * factorial($k));
}

function pascals_triangle(int $height)
{
    for ($row = 0; $row < $height; $row++) {
        echo str_repeat("  ", $height - 1 - $row);
        for ($i = 0; $i <= $row; $i++) {
            echo str_pad(n_over_k($row, $i), 4, " ", STR_PAD_LEFT);
        }
        echo "\n";
    }
}
