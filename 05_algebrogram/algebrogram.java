public class algebrogram {

    public static void main(String[] args) {
        int left, right;
        int[] r = { 0 };
        for (int a = 0; a <= 9; a++) {
            for (int b = 0; b <= 9; b++) {
                if (b == a) {
                    continue;
                }
                for (int c = 0; c <= 9; c++) {
                    if (c == b || c == a) {
                        continue;
                    }
                    for (int d = 0; d <= 9; d++) {
                        if (d == c || d == b || d == a) {
                            continue;
                        }
                        left = (a * 1000 + b * 100 + c * 10 + d) * d;
                        right = d * 1000 + c * 100 + b * 10 + a;
                        if (left == right) {
                            r = new int[] { a, b, c, d };
                            break;
                        }
                    }
                }
            }
        }
        if (r.length == 4) {
            System.out.println("abcd*d = dcba");
            System.out.println("" + r[0] + r[1] + r[2] + r[3] + "*" + r[3] + " = " + r[3] + r[2] + r[1] + r[0]);
        } else {
            System.out.println("No success");
        }
    }
}
