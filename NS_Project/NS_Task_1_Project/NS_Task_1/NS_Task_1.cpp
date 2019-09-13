#include "NS_Task_1_Sandbox.h"

int main(int argc, char* argv[])
{
	init();
	std::thread t_1(threadCalls);
	/* 
	*  Your code will be called below this. Before Submitting encapsulate your code in a single function.
	*  That is, in your submission there should only be a single function called as shown below.
	*/
	//left_turn_wls();
	//Square();		//For Testing The Square Shape
	//Task_1_1();	//For executing your Task 1.1
	//Task_1_2();	//For executing your Task 1.2
	maze_solver();
	cleanUp();
	t_1.detach();
}