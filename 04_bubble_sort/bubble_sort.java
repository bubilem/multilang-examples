import java.util.concurrent.ThreadLocalRandom;

public class bubble_sort {

    public static void main(String[] args) {

        int[] data = new int[10];

        // generate
        for (int i = 0; i < data.length; i++) {
            data[i] = ThreadLocalRandom.current().nextInt(0, 99);
        }

        // optimized bubble-sort
        int tmp;
        boolean swap;
        for (int j = 0; j < data.length - 1; j++) {
            swap = false;
            for (int i = 0; i < data.length - 1 - j; i++) {
                if (data[i] > data[i + 1]) {
                    tmp = data[i];
                    data[i] = data[i + 1];
                    data[i + 1] = tmp;
                    swap = true;
                }
            }
            if (!swap) {
                break;
            }
        }

        // show
        for (int number : data) {
            System.out.print(number + " ");
        }
    }

}
