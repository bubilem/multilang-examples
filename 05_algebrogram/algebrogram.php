<?php
/* 
 * algebrogram: ABCD*D = DCBA 
 * brute force solution
 */
for ($a = 0; $a <= 9; $a++) {
    for ($b = 0; $b <= 9; $b++) {
        if ($b == $a) {
            continue;
        }
        for ($c = 0; $c <= 9; $c++) {
            if ($c == $b || $c == $a) {
                continue;
            }
            for ($d = 0; $d <= 9; $d++) {
                if ($d == $c || $d == $b || $d == $a) {
                    continue;
                }
                if ((int)"$a$b$c$d" * (int)"$d" == (int)"$d$c$b$a") {
                    $r = "$a$b$c$d";
                    break;
                }
            }
        }
    }
}
if (!empty($r)) {
    echo "abcd*d = dcba\n";
    echo $r[0] . $r[1] . $r[2] . $r[3] . "*" . $r[3] . " = " . $r[3] . $r[2] . $r[1] . $r[0] . "\n";
} else {
    echo "none\n";
}
