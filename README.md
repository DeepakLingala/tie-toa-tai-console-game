# Tic-Tac-Toe Game in C++

## About the Game
Tic-Tac-Toe is a classic two-player game where players alternate marking spaces in a 3x3 grid. The objective is to place three of their respective symbols (X or O) in a horizontal, vertical, or diagonal row. The game can end in a win for one of the players or a draw if the grid is fully occupied without a winner.

This implementation in C++ allows two game modes:
1. **Computer vs. Player**
2. **Player vs. Player**

## Features
- **Interactive Gameplay:** Prompts players for input during their turn.
- **Computer AI:** The computer makes random valid moves when playing against a player.
- **Dynamic Game Board:** The board updates after each move and is displayed in a visually structured format.
- **Win and Draw Detection:** The game identifies and announces a winner or a draw.
- **Replay Option:** Players can choose to play again after a match ends.

## How It Works

### Functions
1. **`reset_board()`**
   - Resets the game board to its initial empty state.

2. **`show_board()`**
   - Displays the current state of the game board in a user-friendly format.

3. **`get_X_player_choice()`**
   - Allows the X player to input their move and validates the input.

4. **`get_O_player_choice()`**
   - Allows the O player to input their move and validates the input.

5. **`get_Computer_choice()`**
   - Generates a random valid move for the computer.

6. **`count_board(char symbol)`**
   - Counts the occurrences of a given symbol (X or O) on the board.

7. **`check_Winner()`**
   - Checks if there is a winner or if the game ends in a draw.
   - Returns `X`, `O`, `D` (Draw), or `C` (Continue).

8. **`Computer_VS_Player()`**
   - Manages the game loop for a player competing against the computer.

9. **`Player_VS_Player()`**
   - Manages the game loop for two players competing against each other.

10. **`print_welcome_message()`**
    - Displays the welcome message at the start of the game.

11. **`print_game_mode_message()`**
    - Prompts the user to select a game mode.

### Game Flow
1. The program starts by displaying a welcome message and prompts the user to select a game mode.
2. Based on the chosen mode, the respective function (`Computer_VS_Player` or `Player_VS_Player`) is executed.
3. Players take turns making their moves until a winner is determined or the game ends in a draw.
4. After the game, the program asks the user if they want to play again.

## How to Run the Code
1. Copy the code into a C++ file (e.g., `tic_tac_toe.cpp`).
2. Compile the code using a C++ compiler. For example:
   ```bash
   g++ tic_tac_toe.cpp -o tic_tac_toe
   ```
3. Run the executable:
   ```bash
   ./tic_tac_toe
   ```

## Sample Output
```
==================================
    Welcome to Tic-Tac-Toe Game   
==================================

 ----->1. Computer VS Player. <----- 
 ----->2. Player VS Player. <----- 
 ----->>> Select Any Game Mode. <<<----- 
1
Enter Your Name: Alex

     |     |     
       |     |     
_____|_____|_____
     |     |     
       |     |     
_____|_____|_____
     |     |     
       |     |     

Alex's Turn.
Select Your Position (1 - 9): 5
...
Game is Draw.
Do you want to play again? (Y/N): N
Thanks for playing! See You Again!
```

## Improvements
- Implement a smarter AI for the computer to make strategic moves.
- Add a graphical user interface (GUI) for enhanced user experience.
- Allow saving and loading game states.

## License
This project is licensed under the MIT License. Feel free to modify and use it for personal or educational purposes.
