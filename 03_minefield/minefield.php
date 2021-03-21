<?php

$minefield = init(20, 10);
generateMines($minefield, 30);
evaluate($minefield);
show($minefield);

function init(int $width, int $height): array
{
    $minefield = [];
    for ($y = 0; $y < $height; $y++) {
        for ($x = 0; $x < $width; $x++) {
            $minefield[$x][$y] = 0;
        }
    }
    return $minefield;
}

function generateMines(array &$minefield, int $count)
{
    if ($count > count($minefield) * count($minefield[0])) {
        return;
    }
    for ($i = 0; $i < $count; $i++) {
        do {
            $x = mt_rand(0, count($minefield) - 1);
            $y = mt_rand(0, count($minefield[0]) - 1);
        } while ($minefield[$x][$y] === 9);
        $minefield[$x][$y] = 9;
    }
}

function evaluate(array &$minefield)
{
    $neighbors = [
        [-1, -1], [0, -1], [1, -1],
        [-1, 0], [1, 0],
        [-1, 1], [0, 1], [1, 1]
    ];
    for ($y = 0; $y < count($minefield[0]); $y++) {
        for ($x = 0; $x < count($minefield); $x++) {
            if ($minefield[$x][$y] !== 9) {
                continue;
            }
            foreach ($neighbors as $neighbor) {
                $nx = $x + $neighbor[0];
                $ny = $y + $neighbor[1];
                if (
                    $nx >= 0
                    && $nx < count($minefield)
                    && $ny >= 0
                    && $ny < count($minefield[0])
                    && $minefield[$nx][$ny] !== 9
                ) {
                    $minefield[$nx][$ny]++;
                }
            }
        }
    }
}

function show(array &$minefield)
{
    foreach (range(0, count($minefield[0]) - 1) as $y) {
        foreach (range(0, count($minefield) - 1) as $x) {
            echo ($minefield[$x][$y] === 0 ? ' ' : ($minefield[$x][$y] === 9 ? "*" : $minefield[$x][$y])) . " ";
        }
        echo "\n";
    }
}
