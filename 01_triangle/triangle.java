public class triangle {

    public static void main(String[] args) {
        int height = 5;
        for (int i = 1; i <= height; i++) {
            System.out.println(" ".repeat(height - i) + "* ".repeat(i));
        }
    }
}
