//------------------------------------------------------------------------------
// GameState header file
//
// Copyright (C) 2014 Ben Murrell
//------------------------------------------------------------------------------

#ifndef _GAMESTATE_HPP
#define _GAMESTATE_HPP

#include <vector>

// Player ID's used in game state
enum PlayerId {
    PLAYER_A,
    PLAYER_B,
    NUM_PLAYERS
};

// Side of line of pots of gold in game state
enum Side {
    LEFT,
    RIGHT
};

// Class that represents the game state in a game of PotsOfGold
class GameState {
    //--------------------------------------------------------------------------
    // Public Functions
    //--------------------------------------------------------------------------
    public:
        GameState( const std::vector<int>& aState );
        GameState( const int* aState, const int& aLength );
        GameState( const GameState& aRight );
        GameState& operator=( const GameState& aRight );
        ~GameState();

        const std::vector<int>& getState() const;
        const int getScore( const PlayerId& aPlayerId ) const;

        GameState makeMove( const PlayerId& aPlayerId, const Side& aSide ) const;

    //--------------------------------------------------------------------------
    // Private Data
    //--------------------------------------------------------------------------
    private:
        std::vector<int> mState;
        int mScore[NUM_PLAYERS];
};

#endif
