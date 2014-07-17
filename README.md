PotsOfGold
==========

This is my implementation for the practice interview question located at http://www.careercup.com/question?id=15422849. I utilized the minimax algorithm to solve for the optimal move for each player.

Pros
----
* Guaranteed to find the optimal move given enough time and memory

Cons
----
* Time complexity of O(2^d) means that as the number of pots of gold in the game increases, the amount of work increases exponentially.
* Space complexity of O(2^d) means that as the number of pots of gold in the game increases, the amount of memory required to find the optimal solution increases exponentially.

Possible Improvements
---------------------
In addition to the possible improvements noted in the code, the following improvements could be made:
* The whole minimax tree doesn't need to be stored - once the value for a terminal state has been determined, its node can be removed since it will not be used again. This would reduce the space complexity drastically, potentially down to O(d).
* A better (in terms of time complexity) solution may exist to this problem - I jumped to minimax because I knew it can be proven to give the optimal move for a player in the given situation.
* Alpha-beta pruning could be used to try to reduce the number of branches that are fully explored in the tree.
