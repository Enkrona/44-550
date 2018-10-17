#include <stdio.h>
#include <pthread.h> 
#include <unistd.h>

void * alice(void * args);
void * bob(void * args);

//  One shared (global) puppy and toy 
pthread_mutex_t puppy_mut, chewToy_mut;

int main(int argc, char * argv[])
{
	//  Semaphores are defined in semaphore.h, with some useful funmctions
	//  Linux does not support semaphore sharing 
	//  init is to create a semaphore
	//  destroy - gets rid of it so it cannot be used 
	//  wait is waiting until available
	//  post is to use the semaphore
	//  Mutexes:
	//  	- 4 seps
	//  	1. Crating/Init
	//  	2. Locking - lock the semaphore from being used
	//  	3. Unlock and return the semaphore
	//  	4. Destroy the semaphore so it cannot be used
	//  	Just like with Vector, we to manually specifiy things
	//  	pthread_mutex_init(pthread_mutex_t *mutex, 
	//  		const pthread_mutextattr_t * attr) 
	//  		- this is used to create the "key" or semaphore
	//  		we will specifiy defaults, this is a GLOBAL VARIABLE
	//  	pthread_mutex_lock - has a internal loop and waits until mutex is avail
	//  	unlock - returns the key to the "key holder" or arbitor
	//	destroy - destroy the key for safety sake
	//
	
	//  Now we are going to write some code! 
	// We can look at bad_things.c 
	
	//  Init two threads called alice_th and bob_th
	pthread_t alice_th, bob_th;
	void * whoCares;  //  Junk pointer non-important

	//  Created mutex for puppy and toy
	pthread_mutex_init(&puppy_mut, NULL);
	pthread_mutex_init(&chewToy_mut, NULL);
	
	//  Creation of the threads
	pthread_create(&alice_th, NULL, alice, NULL);
	pthread_create(&bob_th, NULL, bob, NULL);
	pthread_join(alice_th, &whoCares);
	pthread_join(bob_th, &whoCares);

	//  Need to create puppies (resources) and create two toys  (mutex)
	//  Done above! 
	
	pthread_mutex_destroy(&puppy_mut);
	pthread_mutex_destroy(&chewToy_mut);
	

	return 0;
}

void * alice(void *args)
{
	//  Need to get access to toy and puppy
	pthread_mutex_lock(&chewToy_mut);
	pthread_mutex_lock(&puppy_mut);
	
	//  Just a simple print to say she has both mutex	
	printf("Alice is now petting the puppy!\n");
	
	//  Releasing the mutex, she is done playing with the puppy
	pthread_mutex_unlock(&chewToy_mut);
	pthread_mutex_unlock(&puppy_mut);
	
	//  Instead of a return we just exit the thread
	pthread_exit(NULL);
	
}

void * bob(void * args)
{
	pthread_mutex_lock(&puppy_mut);
	pthread_mutex_lock(&chewToy_mut);

	printf("Bob is now playing with the puppy!\n");

	pthread_mutex_unlock(&chewToy_mut);
	pthread_mutex_unlock(&puppy_mut);

	pthread_exit(NULL);
}
