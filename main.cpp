//------------------------------------------------------------------------------
// Solution for http://www.careercup.com/question?id=15422849
//
// Copyright (C) 2014 Ben Murrell
//------------------------------------------------------------------------------

#include "GameState.hpp"
#include "MiniMaxNode.hpp"

#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;

const int sampleIn[] = { 1,1,1,2,5,6,1,1,5,5,3,2,8,5,2,1,1,3,4,2,8,9,1,1,19,5,6,2,5,3,5,1,1,3,5,6,2,17,5,5,6,8,5 };

// Total implementation time: 2 hours

// Entry point for potsofgold
int main( int argc, char** argv ) {

    cout << "Pots Of Gold! Who will win?!" << endl;

    // Load game state
    GameState gameState( sampleIn, sizeof( sampleIn ) / sizeof( int ) );

    // Assign max & min players
    PlayerId maxPlayer = PLAYER_A;
    PlayerId minPlayer = PLAYER_B;

    // Play until game is finished...
    while( !gameState.getState().empty() ) {
        // Output current game state
        std::copy( gameState.getState().begin(), gameState.getState().end(), std::ostream_iterator<int>( cout, " " ) );
        cout << endl;

        // Solve for current player
        MiniMaxNode root( gameState );
        Side result = root.solve( minPlayer, maxPlayer, 20 );

        // Possible improvements:
        //  - We are solving the whole tree & discarding all of our work each iteration.
        //    Trim existing tree to prevent duplicate work.

        // Make optimal move for current player
        gameState = gameState.makeMove( maxPlayer, result );

        // Output player's move
        cout << "Player " << ( maxPlayer == PLAYER_A ? "A" : "B" ) << " chooses " << ( result == LEFT ? "left" : "right" ) << "!";
        cout << " (A: " << gameState.getScore( PLAYER_A ) << ", B: " << gameState.getScore( PLAYER_B ) << ")" << endl;
        cout << endl;

        // Change current player
        std::swap( maxPlayer, minPlayer );
    }

    // Output result
    cout << "Player " << ( gameState.getScore( PLAYER_A ) > gameState.getScore( PLAYER_B ) ? "A" : "B" ) << " wins!" << endl;

    return 0;
}
