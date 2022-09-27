#Go-Fish

The game
Alice and Bob are playing a game a bit like Go Fish, although neither of them is very good at it. The players are dealt two sets of cards which are provided in two separate files as inputs to your program. Although the cards in each player’s hand is unique, duplicates exist in the other player’s hand.

Once you have the sets of cards, the game begins. Alice and Bob take turns playing the game. Alice iterates forward through her hand in increasing order of the card values (see next section on how cards are ordered), checking whether Bob has that card. Once a matching card is found, your program should print the line “Alice picked matching card <card value as a number/character>". The card should then be removed from both players hands.

The process then repeats, except this time, Bob looks through his cards starting with the largest card and working towards the smallest card. This means that while the first card Alice finds should be the first shared card (in order), the first card Bob finds should be the last shared card (in order). The game ends once they do not have any cards in common and you should print out the final hands of both players. Note that players do not draw any new cards during this process.

The ordering of cards is described in the next section.

Card ordering
The ordering of cards is determined first by its suit and then by the value:

The ordering least to greatest is: clubs, diamonds, spades, hearts. Thus a club of any value is less than a diamond of any value.

The ordering within each suit is determined by the value from least to greatest as follows: ace, 2, 3, . . . 10, jack, queen, king.

Based on the above two rules, the correct ordering of

h 9, c k, s 3, c a, h j, d 3

would be

c a, c k, d 3, s 3, h 9, h j

Your approach
At the start of the program, you will read in Alice and Bob’s starting hands from two files. The names of these files are provided as command line arguments with Alice’s file in argv[1] and Bob’s in argv[2]. The starter code opens the files for you as ifstream objects, which you can treat much like cin. You should read Alice and Bob’s cards into two binary search trees. You must implement the binary search trees yourself. Don’t worry about balancing the binary search trees (though you can try and optimize this if you like). Your binary search tree class should obey the card ordering rules given above. While implementing this, you may find it helpful to overload the operators ==, <, and > on your card class so that you can easily choose which branches to go down on your binary tree. Note that you need to correctly handle the case of cards with the value 10 (which has two characters) and separately compare the value and suit, so storing the cards as strings is probably not the best approach.

Once you have the sets of cards, the game begins as described before.

As before, you should write your own Makefile for this lab so that running make builds an executable called game.
