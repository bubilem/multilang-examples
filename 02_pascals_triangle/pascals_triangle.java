public class pascals_triangle {

    public static int factorial(int n) {
        if (n <= 1) {
            return 1;
        }
        return factorial(n - 1) * n;
    }

    public static int n_over_k(int n, int k) {
        if (k == 0 || n == k) {
            return 1;
        }
        return factorial(n) / (factorial(n - k) * factorial(k));
    }

    public static void triangle(int height) {
        for (int row = 0; row < height; row++) {
            System.out.print("  ".repeat(height - row));
            for (int i = 0; i <= row; i++) {
                System.out.printf("%3d ", n_over_k(row, i));
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        triangle(13);
    }
}
