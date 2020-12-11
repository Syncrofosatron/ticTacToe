# ticTacToe
Implementation of Tic-Tac-Toe with C++ where the computer make random moves (not smart, yet).

You will notice that sometimes the computer will take some time to make a move, or,
the console will output text flickering in fancy colors.
But this is not getting stuck in an infinite loop, нет нет. The thing is, the rand()
is unable to find the right number. So, just wait until it generates the right number.
