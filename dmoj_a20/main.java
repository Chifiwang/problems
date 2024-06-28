
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int num_iter = input.nextInt();
        input.nextLine();
        for (int i = 0; i < num_iter; ++i) {
            solve(input);
        }

        input.close();
    }

    static public void solve(Scanner input) {
        String s = input.nextLine();

        int hi = Integer.parseUnsignedInt(s, 16);
        int lo = hi & (~(0b1 << 20));

        // System.out.println(String.format("0X%08X", lo).substring(2));
        // System.out.println(String.format("0X%08X", hi).substring(2));
        if (hi == lo) {
            System.out.println(String.format("0X%08X", hi).substring(2));
        } else {
            System.out.println(String.format("0X%08X", lo).substring(2) + ' ' + String.format("0X%08X", hi).substring(2));
        }
    }
}
