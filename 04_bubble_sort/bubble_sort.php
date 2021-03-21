<?php
$data = [];

//generate
for ($i = 0; $i < 10; $i++) {
    $data[] = mt_rand(0, 99);
}

//optimized bubble-sort
for ($j = 0; $j < count($data) - 1; $j++) {
    $swap = false;
    for ($i = 0; $i < count($data) - 1 - $j; $i++) {
        if ($data[$i] > $data[$i + 1]) {
            $tmp = $data[$i];
            $data[$i] = $data[$i + 1];
            $data[$i + 1] = $tmp;
            $swap = true;
        }
    }
    if (!$swap) {
        break;
    }
}

//show
echo implode(" ", $data);
