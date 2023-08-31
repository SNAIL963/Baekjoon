import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        BigInteger first = s.nextBigInteger();
        BigInteger second = s.nextBigInteger();

        System.out.println(first.add(second));
        System.out.println(first.subtract(second));
        System.out.print(first.multiply(second));

    }
}