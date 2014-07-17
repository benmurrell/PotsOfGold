//------------------------------------------------------------------------------
// MiniMaxNode implementation file
//
// Copyright (C) 2014 Ben Murrell
//------------------------------------------------------------------------------

#include "MiniMaxNode.hpp"

#include <algorithm>
using std::min;
using std::max;

// Constructor that takes a PotsOfGold GameState as its state
MiniMaxNode::MiniMaxNode( const GameState& aState ) : mState( aState ) {
    mLeft = NULL;
    mRight = NULL;
    mValue = 0;
}

// Destructor
MiniMaxNode::~MiniMaxNode() {
    delete mLeft;
    delete mRight;
}

// Find the optimal move for the given maxPlayer, exploring to the given depth in the minimax tree
Side MiniMaxNode::solve( const PlayerId& aMinPlayer, const PlayerId& aMaxPlayer, const unsigned int& aDepth ) {
    int bestValue = minimax( this, aDepth, aMinPlayer, aMaxPlayer, true );

    int leftValue = mLeft->mValue;
    int rightValue = mRight->mValue;

    return leftValue >= rightValue ? LEFT : RIGHT;
}

// Get whether or not this node is a terminal state in the game
bool MiniMaxNode::isTerminal() const {
    return mState.getState().empty();
}

// Get the minimax value for this node - only valid if tree has been solved
int MiniMaxNode::getValue() const {
    return mValue;
}

// Recursive minimax implementation - returns the best value for the maximizing player
int MiniMaxNode::minimax( MiniMaxNode* aNode, const int& aDepth, const PlayerId& aMinPlayer, const PlayerId& aMaxPlayer, bool aMaximize ) {

    // Reached the end
    if( aNode->isTerminal() ) {
        aNode->mValue = aNode->mState.getScore( aMaxPlayer ) - aNode->mState.getScore( aMinPlayer );
        return aNode->mValue;
    }

    // Ran out of depth - heuristic time
    if( aDepth == 0 ) {
        aNode->mValue = aNode->mState.getScore( aMaxPlayer ) - aNode->mState.getScore( aMinPlayer );
        return aNode->mValue;
    }

    int bestValue = 0;
    if( aMaximize ) {
        bestValue = INT_MIN;

        // Expand node
        aNode->mLeft = new MiniMaxNode( aNode->mState.makeMove( aMaxPlayer, LEFT ) );
        aNode->mRight = new MiniMaxNode( aNode->mState.makeMove( aMaxPlayer, RIGHT ) );

        bestValue = max( minimax( aNode->mLeft, aDepth - 1, aMinPlayer, aMaxPlayer, false ), bestValue );
        bestValue = max( minimax( aNode->mRight, aDepth - 1, aMinPlayer, aMaxPlayer, false ), bestValue );

    } else {
        bestValue = INT_MAX;

        // Expand node
        aNode->mLeft = new MiniMaxNode( aNode->mState.makeMove( aMinPlayer, LEFT ) );
        aNode->mRight = new MiniMaxNode( aNode->mState.makeMove( aMinPlayer, RIGHT ) );

        bestValue = min( minimax( aNode->mLeft, aDepth - 1, aMinPlayer, aMaxPlayer, true ), bestValue );
        bestValue = min( minimax( aNode->mRight, aDepth - 1, aMinPlayer, aMaxPlayer, true ), bestValue );
    }

    aNode->mValue = bestValue;
    return bestValue;
}
