//------------------------------------------------------------------------------
// GameState implementation file
//
// Copyright (C) 2014 Ben Murrell
//------------------------------------------------------------------------------

#include "GameState.hpp"

// GameState constructor that takes a vector of int as its initial state
GameState::GameState( const std::vector<int>& aState ) {
    mState = aState;
    mScore[PLAYER_A] = 0;
    mScore[PLAYER_B] = 0;
}

// GameState constructor that takes an array of int as its initial state
GameState::GameState( const int* aState, const int& aLength ) {
    mState.reserve( aLength );
    for( int i = 0; i < aLength; ++i ) {
        mState.push_back( aState[i] );
    }

    mScore[PLAYER_A] = 0;
    mScore[PLAYER_B] = 0;
}

// GameState copy constructor
GameState::GameState( const GameState& aRight ) {
    *this = aRight;
}

// GameState assignment operator
GameState& GameState::operator=( const GameState& aRight ) {
    mState = aRight.mState;
    mScore[PLAYER_A] = aRight.mScore[PLAYER_A];
    mScore[PLAYER_B] = aRight.mScore[PLAYER_B];

    return *this;
}

// GameState destructor
GameState::~GameState() {
    // No resources to release
}

// Get the state of the game
const std::vector<int>& GameState::getState() const {
    return mState;
}

// Get the score for the given player
const int GameState::getScore( const PlayerId& aPlayerId ) const {
    return mScore[aPlayerId];
}

// Collect the pot on the given side for the given player
GameState GameState::makeMove( const PlayerId& aPlayerId, const Side& aSide ) const {
    GameState nextState = *this;

    // Take away the pot of gold
    int goldValue = 0;
    if( LEFT == aSide ) {
        goldValue = nextState.mState.front();
        nextState.mState.erase( nextState.mState.begin() );
    } else {
        goldValue = nextState.mState.back();
        nextState.mState.pop_back();
    }

    // Give it to the player
    nextState.mScore[aPlayerId] += goldValue;

    return nextState;
}
