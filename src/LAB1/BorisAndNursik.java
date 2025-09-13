package LAB1;

import java.io.*;
import java.util.*;

public class BorisAndNursik {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] borisCards = br.readLine().split(" ");
        String[] nursikCards = br.readLine().split(" ");

        Queue<Integer> boris = new LinkedList<>();
        Queue<Integer> nursik = new LinkedList<>();

        for (String card : borisCards) {
            boris.add(Integer.parseInt(card));
        }

        for (String card : nursikCards) {
            nursik.add(Integer.parseInt(card));
        }

        int moves = 0;
        int maxMoves = 100000;

        while (!boris.isEmpty() && !nursik.isEmpty() && moves < maxMoves) {
            int borisCard = boris.poll();
            int nursikCard = nursik.poll();

            boolean borisWins = false;

            if (borisCard == 0 && nursikCard == 9) {
                borisWins = true;
            } else if (nursikCard == 0 && borisCard == 9) {
                borisWins = false;
            } else {
                borisWins = borisCard > nursikCard;
            }

            if (borisWins) {
                boris.add(borisCard);
                boris.add(nursikCard);
            } else {
                nursik.add(borisCard);
                nursik.add(nursikCard);
            }

            moves++;
        }

        if (moves == maxMoves) {
            System.out.println("draw");
        } else if (boris.isEmpty()) {
            System.out.println("Nursik " + moves);
        } else {
            System.out.println("Boris " + moves);
        }
    }
}