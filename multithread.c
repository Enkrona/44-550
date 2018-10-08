#include <stdio.h>
#include <pthread.h> 

//  Starvation is where the thread gets no resources because we take resources away everytime
//  Deadlock is where it is stuck and cannot access resources as all resources are in-use 
//  	standoff
//  Livelock is where it doesn't use resources can change between process stayes but makes
//  	no progress in the process

/*
 *  Dining Philosphers: 
 *	Circular table 
 *	We have (N) number of philosphers at the table:
 *		In front of each is a bowl of rice
 *		In between each pair sits a single chopstick
 *	Philospher needs 2 basic tasks:
 *		Think - between eating
 *		Eat - between thinking with both chopsticks
 *	A chopstick can only be held by one philospher:
 *		Can only eat if they have both copsticks
 *	Solution:
 *		Right handed
 *		Thinking until right chopstick is available
 *		Each chopstick to the philospher's right is available. they pick it up
 *		Continue thinking until they left chopstick is available
 *		--- This doesn't work, the left is never available, preventing from eating
 *			Think until starving to death
 *		** Caused by DEADLOCK **
 *
 *	Real solution:
 *		Each philospher as a thread and chopsticks as mu-tex
 *		Introduce a Waitor (watch_dog) -- arbitrator solution
 *		Dijkstra's solution is #1 - WE ARE #1!
 *
 *	Dijkstra's Solution:
 *		Enforce ordering on chopsticks
 *		Every philospher picks up the chopstick:
 *			1. closest to them 
 *			2. with the lowest index
 *			-- Causes a race condition, where one of them gets it, other doesnt
 *			A philospher gets two while one does't -- AT LEAST 1 is eating
 *			Process: 
 *				Grab one, and the other is available
 *					At least one gets the second cs and eats
 *				The one with both eats, other think
 *				One is now eating, then finishes and puts them down
 *				Cycle repeats
 *
 */


int main(int argc, char * argv[])
{
	

	return 0;

}
