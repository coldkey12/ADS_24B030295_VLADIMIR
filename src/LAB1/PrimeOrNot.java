package LAB1;

import java.util.*;

public class PrimeOrNot {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();

        if (isPrime(n)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }

    static boolean isPrime(long n) {
        if (n < 2) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;

        for (long i = 3; i * i <= n; i += 2) {
            if (n % i == 0) return false;
        }
        return true;
    }
}