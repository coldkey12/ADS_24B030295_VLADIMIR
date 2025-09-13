package LAB1;

import java.util.*;

public class RoyalFlush {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        List<String> results = new ArrayList<>();

        for (int test = 0; test < t; test++) {
            int n = sc.nextInt();
            LinkedList<Integer> deck = new LinkedList<>();

            for (int i = n; i >= 1; i--) {
                deck.addFirst(i);
                for (int j = 0; j < i && deck.size() > 1; j++) {
                    deck.addFirst(deck.removeLast());
                }
            }

            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < deck.size(); i++) {
                if (i > 0) sb.append(" ");
                sb.append(deck.get(i));
            }
            results.add(sb.toString());
        }

        for (String result : results) {
            System.out.println(result);
        }
    }
}