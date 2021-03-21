<?php
$height = 5;
for ($i = 1; $i <= $height; $i++) {
    echo str_repeat(" ", $height - $i) . str_repeat("* ", $i);
    echo "\n";
}
