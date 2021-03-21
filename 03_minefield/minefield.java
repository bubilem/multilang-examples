import java.util.concurrent.ThreadLocalRandom;

public class minefield {

    public static int[][] minefield;

    public static void init(int width, int height) {
        minefield = new int[width][height];
    }

    public static void generateMines(int count, int j) {
        if (count > minefield.length * minefield[0].length) {
            return;
        }
        int x, y;
        for (int i = 0; i < count; i++) {
            do {
                x = ThreadLocalRandom.current().nextInt(0, minefield.length);
                y = ThreadLocalRandom.current().nextInt(0, minefield[0].length);
            } while (minefield[x][y] == 9);
            minefield[x][y] = 9;
        }
    }

    public static void evaluate() {
        int[][] neighbors = { { -1, -1 }, { 0, -1 }, { 1, -1 }, { -1, 0 }, { 1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 } };
        int nx, ny;
        for (int y = 0; y < minefield[0].length; y++) {
            for (int x = 0; x < minefield.length; x++) {
                if (minefield[x][y] != 9) {
                    continue;
                }
                for (int[] neighbor : neighbors) {
                    nx = x + neighbor[0];
                    ny = y + neighbor[1];
                    if (nx >= 0 && nx < minefield.length && ny >= 0 && ny < minefield[0].length
                            && minefield[nx][ny] != 9) {
                        minefield[nx][ny]++;
                    }
                }
            }
        }
    }

    public static void show() {
        for (int y = 0; y < minefield[0].length; y++) {
            for (int x = 0; x < minefield.length; x++) {
                if (minefield[x][y] == 9) {
                    System.out.print("* ");
                } else if (minefield[x][y] == 0) {
                    System.out.print("  ");
                } else {
                    System.out.print(minefield[x][y] + " ");
                }
            }
            System.out.println();
        }

    }

    public static void main(String[] args) {
        init(20, 10);
        generateMines(20, 9);
        evaluate();
        show();
    }

}
