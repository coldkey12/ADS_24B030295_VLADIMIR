package LAB1;

import java.util.*;

public class SuperPrimes {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        boolean[] isPrime = new boolean[10000];
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i < 10000; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < 10000; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        List<Integer> primes = new ArrayList<>();
        for (int i = 2; i < 10000; i++) {
            if (isPrime[i]) {
                primes.add(i);
            }
        }

        int count = 0;
        for (int i = 0; i < primes.size(); i++) {
            int index = i + 1;
            if (isPrime[index]) {
                count++;
                if (count == n) {
                    System.out.println(primes.get(i));
                    break;
                }
            }
        }
    }
}