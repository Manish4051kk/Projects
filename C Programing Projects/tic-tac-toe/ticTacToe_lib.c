#include "ticTacToe_lib.h" // Import the Tic-Tac-Toe library header

// Initialize the board with empty spaces
void initializeBoard(char board[ROWS][COLS]) {
    // Loop through each row and column to set the initial values
    for (int i = 0; i < ROWS; i++) { // Iterate through each row
        for (int j = 0; j < COLS; j++) { // Iterate through each column
            board[i][j] = ' '; // Set the cell to empty space
        }
    }
}

// Display the current state of the board
void displayBoard(const char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) { // Iterate through each row
        for (int j = 0; j < COLS; j++) { // Iterate through each column
            printf(" %c ", board[i][j]); // Print the cell content
            if (j < COLS - 1) { // Check if not the last column
                printf("|"); // Print the vertical separator
            }
        }
        printf("\n"); // Move to the next line after each row
        if (i < ROWS - 1) { // Check if not the last row
            printf("-----------\n"); // Print the horizontal separator
        }
    }
}

// Check if the board is full
bool isBoardFull(const char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) { // Iterate through each row
        for (int j = 0; j < COLS; j++) { // Iterate through each column
            if (board[i][j] == ' ') { // If any cell is empty
                return false; // Return false if the board is not full
            }
        }
    }
    return true; // Return true if the board is completely full
}

// Check if a player has won the game
bool checkWin(const char board[ROWS][COLS], char playerSymbol) {
    // Check for horizontal win
    for (int i = 0; i < ROWS; i++) { // Iterate through each row
        bool horizontalWin = true; // Assume it's a horizontal win
        for (int j = 0; j < COLS; j++) { // Iterate through each column
            if (board[i][j] != playerSymbol) { // If any cell doesn't match
                horizontalWin = false; // It's not a win
                break; // Break the loop if condition is not met
            }
        }
        if (horizontalWin) { // If it's a win
            return true; // Return true
        }
    }

    // Check for vertical win
    for (int j = 0; j < COLS; j++) { // Iterate through each column
        bool verticalWin = true; // Assume it's a vertical win
        for (int i = 0; i < ROWS; i++) { // Iterate through each row
            if (board[i][j] != playerSymbol) { // If any cell doesn't match
                verticalWin = false; // It's not a win
                break; // Break the loop if condition is not met
            }
        }
        if (verticalWin) { // If it's a win
            return true; // Return true
        }
    }

    // Check for diagonal win (from top-left to bottom-right)
    bool diagonalWin = true; // Assume it's a diagonal win
    for (int i = 0; i < ROWS; i++) { // Iterate through each diagonal element
        if (board[i][i] != playerSymbol) { // If any cell doesn't match
            diagonalWin = false; // It's not a win
            break; // Break the loop if condition is not met
        }
    }
    if (diagonalWin) { // If it's a win
        return true; // Return true
    }

    // Check for diagonal win (from top-right to bottom-left)
    diagonalWin = true; // Assume it's a diagonal win
    for (int i = 0; i < ROWS; i++) { // Iterate through each diagonal element
        if (board[i][COLS - i - 1] != playerSymbol) { // If any cell doesn't match
            diagonalWin = false; // It's not a win
            break; // Break the loop if condition is not met
        }
    }
    if (diagonalWin) { // If it's a win
        return true; // Return true
    }

    return false; // Return false if none of the win conditions are met
}

// Implement the Tic-Tac-Toe game
void play() {
    // Declare the board and initialize it
    char board[ROWS][COLS]; // Tic-Tac-Toe board
    int row, col; // Row and column inputs
    int currentPlayer = 0; // 0 for player1, 1 for player2
    bool gameInProgress = true; // Boolean to keep track of the game state

    initializeBoard(board); // Initialize the board with empty spaces
    displayBoard(board); // Display the current state of the board

    // Loop while the game is still in progress
    while (gameInProgress) {
        printf("Player %d: Enter row (0-2) and column (0-2) separated by space: ", currentPlayer + 1);
        scanf("%d %d", &row, &col); // Read row and column input

        // Validate the input, ensuring it's within bounds and the cell is empty
        if (row < 0 || row >= ROWS || col < 0 || col >= COLS || board[row][col] != ' ') {
            printf("Invalid move. Try again.\n"); // Notify the player of an invalid move
            continue; // Skip to the next iteration
        }

        // Set the board cell with the current player's symbol
        board[row][col] = (currentPlayer == 0) ? PLAYER1_SYMBOL : PLAYER2_SYMBOL;

        // Display the updated state of the board
        displayBoard(board);

        // Check if the current player has won the game
        if (checkWin(board, board[row][col])) {
            printf("Congratulations, player %d won the game!\n", currentPlayer + 1);
            gameInProgress = false; // End the game if there's a winner
            break;
        }

        // Check if the board is full, indicating a draw
        if (isBoardFull(board)) {
            printf("It's a draw!\n"); // Notify that the game ends in a draw
            gameInProgress = false; // End the game
            break;
        }

        // Switch to the next player
        currentPlayer = (currentPlayer + 1) % 2;
    }
}
