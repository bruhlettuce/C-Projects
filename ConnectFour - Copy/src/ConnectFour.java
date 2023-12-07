//By: Lorne Huxtable
import java.util.Scanner;
public class ConnectFour {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        System.out.print("What would you like the height of the board to be? ");
        int height = input.nextInt();
        System.out.print("What would you like the length of the board to be? ");
        int length = input.nextInt();
        char[][] board = new char[height][length];
        initializeBoard(board);
        printBoard(board);
        System.out.println("Player 1: x");
        System.out.println("Player 2: o");
        System.out.println("");

        for (int i = 1; i <= (height * length) / 2; i++) { //For loop for the game, goes by max number of move (h * l) or until a player wins
            System.out.print("Player 1: Which column would you like to choose? (Starts with 0) ");
            int player1Col = input.nextInt();
            int player1Row = insertChip(board, player1Col, 'x');
            printBoard(board);
            System.out.println(" ");
            boolean player1Win = checkIfWinner(board, player1Row, player1Col, 'x');
            if (player1Win) {
                System.out.println("Player 1 won the game!");
                break;
            }
            System.out.print("Player 2: Which column would you like to choose? (Starts with 0) ");
            int player2Col = input.nextInt();
            int player2Row = insertChip(board, player2Col, 'o');
            printBoard(board);
            System.out.println(" ");
            boolean player2Win = checkIfWinner(board, player2Row, player2Col, 'o');
        if (player2Win) {
            System.out.println("Player 2 won the game!");
            break;
        }
        if (i == (height * length) / 2) { // ends the game when there are no moves left amongst players
            System.out.println("Draw. Nobody wins.");
        }

        }
    }

    public static void printBoard(char[][] array) { // Method prints board

        int row;
        int col;
        for (row = array.length - 1; row >= 0; row--) { // Prints backwards
            System.out.println("");
            for (col = 0; col < array[row].length; col++) {
                System.out.print(array[row][col] + " ");
            }
        }
        System.out.println("");
    }

    public static void initializeBoard(char[][] array) { // Method gives every element a dash

        int i;
        int j;
        for (i = 0; i < array.length; i++) {
            for (j = 0; j < array[i].length; j++) {
                array[i][j] = '-';
            }
        }
    }

    public static int insertChip(char[][] array, int col, char chipType) { // Method returns the row of where the chip was placed
        int i;
        int j;
        int chip = 0;
        for (i = 0; i < array.length; i++) {
            for (j = 0; j < array[i].length; j++) {
                if (j == col && array[i][j] == chipType) {
                    continue;
                }
                if (j == col && array[i][j] == '-') { // checks if the spot is empty
                    chip = i;
                    array[chip][col] = chipType;
                    return chip;
                }

            }
        }
        return chip;
    }

    public static boolean checkIfWinner(char[][] array, int col, int row, char chipType) { // checks if there are 4 chips in a row, horizontally and vertically
        int i;
        int j;
        boolean whosTheWinner = false;
        int colcount = 0;
        int rowcount = 0;
        for (i = 0; i < array[row].length; i++) {
            if (array[col][i] == chipType) { // checks all the chips in a column
                colcount++;
            }
            if (colcount == 4) { // if there are 4 chips the player wins
                whosTheWinner = true;
            }
            if (array[col][i] != chipType) { // if there is a different chip the counter is reset
                colcount = 0;
            }
        }
        for (j = 0; j < array.length; j++) { // this and below does the same things as above, just for the rows
            if (array[j][row] == chipType) {
                rowcount++;
            }
            if (rowcount == 4) {
                whosTheWinner = true;
            }
            if (array[j][row] != chipType) {
                rowcount = 0;
            }
        }
        return whosTheWinner;
    }
}
