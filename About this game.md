# HANGMAN-final-ver
Game Hangman final version (project submission version)
- Running .exe file
- C++ window will pop up
- Press in letter 'p' and then press Enter to play (or letter 'e' to exit)
- If you play, SDL window will pop up with blank white color
How to play
- Don't switch to SDL window
- The words database will be saved in HANGMANWORDS.inp file
     The contents in the HANGMANWORDS.inp file include
           - The number of words in the file on the first line of the file
           - The words which will be choose randomized will be on the second line onward, each word on each line

- You started play like a normal Hangman game, the program randomly pick a word in HANGMANWORDS.inp file, each time it will ask 
you to input a letter in the C++ window, you then input a letter. If the letter you choose exist in the picked word, the program will
show all of its position in the word and there will be no penalty, if the letter you choose doesn't exist in the word you will be penalize
and it will draw the hangman in the SDL window started with the head, body, 2 arms, 2 legs and finally the rope which means you can guess
the wrong letter at most is 7 times. If you guessed all the letter in the word with less than 7 times penalty you win and the game will 
show the word, the program also show the word when you lose which means you commit the 7th penalty. Your progress will be show everytime
after you guess a letter (the number of letter in the word, the letters you guessed right and their locations, the locations of the letter
that still hidden)

WEAKNESSES
- You still have to manually make the words database (the existed HANGMANWORDS.inp file already contain some words which are animals name)
- All the game progress include inputting letters, showing texts,... only do on c++ window. If you attempt to switch to the SDL window
and pressing buttons, it might crash.
- This game is still not at its finest, the hangman image and the way to play can still be improved


      
