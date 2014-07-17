//------------------------------------------------------------------------------
// MiniMaxNode header file
//
// Copyright (C) 2014 Ben Murrell
//------------------------------------------------------------------------------

#ifndef _MINIMAXNODE_HPP
#define _MINIMAXNODE_HPP

#include "GameState.hpp"

#include <climits>

//------------------------------------------------------------------------------
// Class that represents a node in a MiniMax tree for the PotsOfGold GameState.
// To use it, construct a node with a PotsOfGold game state, then call solve
// with the desired player arrangement.
//------------------------------------------------------------------------------
class MiniMaxNode {
    //--------------------------------------------------------------------------
    // Public functions
    //--------------------------------------------------------------------------
    public:
        MiniMaxNode( const GameState& aState );
        ~MiniMaxNode();

        Side solve( const PlayerId& aMinPlayer, const PlayerId& aMaxPlayer, const unsigned int& aDepth = UINT_MAX );

        bool isTerminal() const;
        int getValue() const;

    //--------------------------------------------------------------------------
    // Private functions
    //--------------------------------------------------------------------------
    private:
        static int minimax( MiniMaxNode* aNode, const int& aDepth, const PlayerId& aMinPlayer, const PlayerId& aMaxPlayer, bool aMaximize );

    //--------------------------------------------------------------------------
    // Private data
    //--------------------------------------------------------------------------
    private:
        GameState mState;
        MiniMaxNode* mLeft;
        MiniMaxNode* mRight;
        int mValue;
};

#endif
