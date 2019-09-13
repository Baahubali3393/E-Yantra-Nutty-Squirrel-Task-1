
//This is the complete code without using proximity sensor,we have commented code for the same.
//thank you


#include "NS_Task_1_Sandbox.h"
#include <stdio.h>
#include <limits.h>
#include <vector>
#include <deque>
#define V 24
unsigned char c1, c2, c3,d1;		//stores ADC values
unsigned int n = 0,p,x,q,r, g, b, f,R=0,G=0;	// flags
using namespace std;
vector <int> a = {};
int graph[V][V] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,231,0,0},
					   {0,0,0,713,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					   {0,0,0,0,713,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					   {0,713,0,0,0,713,0,0,0,19741,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					   {0,0,713,0,0,0,713,0,0,0,0,19741,0,0,0,0,0,0,0,0,0,0,0,0},
					   {0,0,0,713,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,713,0},
					   {0,0,0,0,713,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,713},
					   {0,0,0,0,0,0,0,0,0,0,0,2333,0,0,0,0,0,0,0,0,1219,0,1219,0},
					   {0,0,0,0,0,0,0,0,0,0,0,0,2333,0,0,0,0,0,0,0,1219,0,0,1219},
					   {0,0,0,19741,0,0,0,0,0,0,0,1086,0,20911,0,0,0,0,0,0,0,0,0,0},
					   {0,0,0,0,19741,0,0,0,0,0,0,0,1086,0,20911,0,0,0,0,0,0,0,0,0},
					   {0,0,0,0,0,0,0,2333,0,1086,0,0,0,0,0,1712,0,0,0,0,0,0,0,0},
					   {0,0,0,0,0,0,0,0,2333,0,1086,0,0,0,0,0,1712,0,0,0,0,0,0,0},
					   {0,0,0,0,0,0,0,0,0,20911,0,0,0,0,0,713,0,0,0,0,0,0,0,0},
					   {0,0,0,0,0,0,0,0,0,0,20911,0,0,0,0,0,713,0,0,0,0,0,0,0},
					   {0,0,0,0,0,0,0,0,0,0,0,1712,0,713,0,0,0,713,0,0,0,0,0,0},
					   {0,0,0,0,0,0,0,0,0,0,0,0,1712,0,713,0,0,0,713,0,0,0,0,0},
					   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,713,0,0,0,713,0,0,0,0},
					   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,713,0,0,713,0,0,0,0},
					   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,713,713,0,3396,0,0,0},
					   {0,0,0,0,0,0,0,1219,1219,0,0,0,0,0,0,0,0,0,0,3396,0,353,0,0},
					   {231,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,353,0,0,0},
					   {0,0,0,0,0,713,0,1219,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4876},
					   {0,0,0,0,0,0,713,0,1219,0,0,0,0,0,0,0,0,0,0,0,0,0,4876,0}};


// DIJKSTRA ALGORITHM FUNCTIONS

int minDistance(int dist[],bool sptSet[])
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
	{
		if (sptSet[v] == false && dist[v] <= min)
		{
			min = dist[v], min_index = v;
		}
	}
		return min_index;
	
}


int Path(int parent[], int j)
{
	if (parent[j] == -1)
	{
		return j;
	}

	Path(parent, parent[j]);
	a.push_back(j);
}


void printSolution(int dist[], int parent[], int src, int dest)
{
	
	int i = dest;
	Path(parent, i);
}


void dijkstra(int src, int dest)
{
	a.push_back(src);
	int dist[V];
	bool sptSet[V];
	int parent[V];
	for (int i = 0; i < V; i++)
	{
		parent[src] = -1;
		dist[i] = INT_MAX;
		sptSet[i] = false;
	}
	dist[src] = 0;
	for (int count = 0; count < V - 1; count++)
	{
		int u = minDistance(dist, sptSet);
		sptSet[u] = true;
		for (int v = 0; v < V; v++)
		{
			if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
			{
				parent[v] = u;
				dist[v] = dist[u] + graph[u][v];
			}
		}
	}

	printSolution(dist, parent, src, dest);

}



/*
*
* Function Name: left_turn_wls
* Input: void
* Output: void
* Logic: moves left till line is detected
* Example Call: left_turn_wls(); 
*/

void left_turn_wls(void)
{
	forward();
	_delay_ms(225);
	left();
	_delay_ms(100);
	c1 = ADC_Conversion(1);
	while (!c1) 
	{
		left();
		c1 = ADC_Conversion(1);
     }
}

/*
*
* Function Name: right_turn_wls
* Input: void
* Output: void
* Logic: moves right till line is detected
* Example Call: right_turn_wls();
*/

void right_turn_wls(void)
{
	forward();
	_delay_ms(225);
	right();
	_delay_ms(100);
	c3 = ADC_Conversion(3);
	while (!c3)
	{
		right();
		c3 = ADC_Conversion(3);
	}
}


/*
*
* Function Name: line_follow
* Input: void
* Output: void
* Logic: follows black line till a node is detected
* Example Call: line_follow(); //follows line
*/


void line_follow(void)
{
	_delay_ms(2);
	//d1 = ADC_Conversion(4);
	//_delay_ms(5);
	c1 = ADC_Conversion(1);
	c2 = ADC_Conversion(2);
	c3 = ADC_Conversion(3);
	
	while (((c1&&c2&&c3) == 0)/*&& (ADC_Conversion(4) < 20)*/)
	{
		
		if (!c1 && c2 && !c3)
		{
			forward();
		}
		else if (!c1 && c2 && c3)
		{
			soft_right();
		}
		else if (c1 && c2 && !c3)
		{
			soft_left();
		}
        else if (!c1 && !c2 && c3)
		{
			soft_right();
		}
		else if (c1 && !c2 && !c3)
		{
			soft_left();
		}
		else if (!c1 && !c2 && !c3)					//All sensors are white i.e. bot is out of line
		{
			stop();
			n = 1;
        }
		//d1 = ADC_Conversion(4);
		_delay_ms(5);
		c1 = ADC_Conversion(1);
		c2 = ADC_Conversion(2);
		c3 = ADC_Conversion(3);
		_delay_ms(5);
		
		//if (n == 0)
		//	printf("\n %d ",ADC_Conversion(4));
		//_delay_ms(5);
		//t++;
    }
/*	if (ADC_Conversion(4) <= 20)
	{
		printf("/nNo Path Ahead");
		right();
		_delay_ms(90);
		right_turn_wls();
		line_follow();
		graph[a[x]][a[x-1]]=0;
		graph[a[x-1]][a[x]]=0;
	}
	*/
	
}

/*
*
* Function Name: run
* Input: past, present and future node no.
* Output: void
* Logic: provides which turn is needed at a particular node to reach the desired node
* Example Call: run(a[x-1],a[x],a[x+1]);
*/

void run (int i, int j, int k)
{
	_delay_ms(3);

	if (((i == 5) && (j == 22) && (k == 7)) || ((i == 22) && (j == 7) && (k == 11)) || ((i == 7) && (j == 11) && (k == 9)) || ((i == 11) && (j == 15) && (k == 13)) ||
		(((i - 1) == 1) && ((j - 1) == 3) && ((k - 1) == 5)) || (((i - 1) == 3) && ((j - 1) == 9) && ((k - 1) == 11)) || (((i - 1) == 9) && ((j - 1) == 13) && ((k - 1) == 15)) || (((i - 1) == 11) && ((j - 1) == 15) && ((k - 1) == 17))||
		((k == 1) && (j == 3) && (i == 5)) || ((k == 3) && (j == 9) && (i == 11)) || ((k == 9) && (j == 13) && (i == 15)) || ((k == 11) && (j == 15) && (i == 17)) ||
		(((k - 1) == 5) && ((j - 1) == 22) && ((i - 1) == 7)) || (((k - 1) == 22) && ((j - 1) == 7) && ((i - 1) == 11)) || (((k - 1) == 7) && ((j - 1) == 11) && ((i - 1) == 9)) || (((k - 1) == 11) && ((j - 1) == 15) && ((i - 1) == 13)))
	{
		//left();
		//_delay_ms(20);
		left_turn_wls();
		printf("LEFT");
		line_follow();
	}

	else if (((i == 7) && (j == 20) && (k == 19)) || ((i == 20) && (j == 19) && (k == 17)) || ((i == 21) && (j == 20) && (k == 7))|| ((i == 20) && (j == 8) && (k == 12))||
		((k == 8) && (j == 20) && (i == 19)) || ((k == 20) && (j == 19) && (i == 18)) || ((k == 21) && (j == 20) && (i == 8)) || ((k == 20) && (j == 7) && (i == 11)))
	     {
		//  left();
		//  _delay_ms(20);
		  left_turn_wls();
		  printf("LEFT");
		  line_follow();
	     }

	else if (((i == 8) && (j == 20) && (k == 19)) || ((i == 20) && (j == 19) && (k == 18)) || ((i == 21) && (j == 20) && (k == 8)) || ((i == 20) && (j == 7) && (k == 11))||
		((k == 7) && (j == 20) && (i == 19)) || ((k == 20) && (j == 19) && (i == 17)) || ((k == 21) && (j == 20) && (i == 7)) || ((k == 20) && (j == 8) && (i == 12)))
	     {

		//right();
		//_delay_ms(20);
		right_turn_wls();
		printf("RIGHT");
		line_follow();
	}

	else if (((i == 1) && (j == 3) && (k == 5)) || ((i == 3) && (j == 9) && (k == 11)) || ((i == 9) && (j == 13) && (k == 15)) || ((i == 11) && (j == 15) && (k == 17)) ||
		(((i - 1) == 5) && ((j - 1) == 22) && ((k - 1) == 7)) || (((i - 1) == 22) && ((j - 1) == 7) && ((k - 1) == 11)) || (((i - 1) == 7) && ((j - 1) == 11) && ((k - 1) == 9)) || (((i - 1) == 11) && ((j - 1) == 15) && ((k - 1) == 13))||
		((k == 5) && (j == 22) && (i == 7)) || ((k == 22) && (j == 7) && (i == 11)) || ((k == 7) && (j == 11) && (i == 9)) || ((k == 11) && (j == 15) && (i == 13)) ||
		(((k - 1) == 1) && ((j - 1) == 3) && ((i - 1) == 5)) || (((k - 1) == 3) && ((j - 1) == 9) && ((i - 1) == 11)) || (((k - 1) == 9) && ((j - 1) == 13) && ((i - 1) == 15)) || (((k - 1) == 11) && ((j - 1) == 15) && ((i - 1) == 17)))
	{
		//right();
		//_delay_ms(20);
		right_turn_wls();
		printf("RIGHT");
		line_follow();
	}

	else
	{
		forward();
		_delay_ms(215);
		printf("FORWARD");
		line_follow();
	}
	
}

/*
*
* Function Name: node_logic
* Input: current and future node and a flag 's'
* Output: void
* Logic: provides turns taken at pick zone and last nodes of the shortest path 
* Example Call: node_logic(a[x]),a[x+1],s);
*/

void node_logic(int j, int k,int s) {
	if (((j == 13) && (k == 15)) || ((j == 15) && (k == 17)) || ((j == 17) && (k == 19)) || ((j == 19) && (k == 18)) || ((j == 18) && (k == 16)) || ((j == 16) && (k == 14)))
	{
		if (s == 0)
		{
			printf("LEFT");
			left_turn_wls();
			left();
			_delay_ms(70);
			stop();
			_delay_ms(5);
		}
		else
		{
			left();
			_delay_ms(40);
			c1 = ADC_Conversion(1);
			while (!c1)
			{
				left();
				c1 = ADC_Conversion(1);
			}
			stop();
			_delay_ms(50);
		}
		
		//_delay_ms(10);
	}

	else if (((k == 13) && (j == 15)) || ((k == 15) && (j == 17)) || ((k == 17) && (j == 19)) || ((k == 19) && (j == 18)) || ((k == 18) && (j == 16)) || ((k == 16) && (j == 14)))
	{
		if (s == 0)
		{
			printf("RIGHT");
			right_turn_wls();
			stop();
			_delay_ms(5);
		}
		else
		{
			right();
			_delay_ms(40);
			c3 = ADC_Conversion(3);
			while (!c3)
			{
				right();
				c3 = ADC_Conversion(3);
			}
			stop();
			_delay_ms(50);
		}
	}
	else
	{
		left();
		_delay_ms(900);
	}

}

/*
*
* Function Name: colour_sensor
* Input: void
* Output: void
* Logic: detects the colour of nut and calls the desired path to place nut
* Example Call: colour_sensor
*/

void colour_sense()
{
	_delay_ms(2);
	filter_red();
	r = color_sensor_pulse_count;
	filter_green();
	g = color_sensor_pulse_count;
	//filter_blue();
	//b = color_sensor_pulse_count;
	filter_clear();
	f = color_sensor_pulse_count;
	printf("\n%d   %d ", r, g);
	_delay_ms(3000);
	if (r > g)
	{
		printf("red");
		if (R == 0)
		{
			dijkstra(q, 1);
		}
		else if (R == 1)
		{
			dijkstra(q, 5);
		}
		R++;
	}
	else if (r < g)
	{
		printf("green");
		if (G == 0)
		{
			dijkstra(q, 2);
		}
		else if (G == 1)
		{
			dijkstra(q, 6);
		}
		G++;
	}
	
}
/*
*
* Function Name: Task_1_2
* Input: void
* Output: void
* Logic: executes the logic of task 1.2
* Example Call:Task_1_2();
*/


void Task_1_2(void)
{
	line_follow();
	dijkstra(0,13);     //moves intially from start to 13 no. node
	_delay_ms(5);
	for ( x = 1; x < (a.size() - 1); x++)
	{
		//_delay_ms(2);
		printf("\n%d", a[x]);
		run(a[(x - 1)], a[x], a[(x + 1)]);
		_delay_ms(5);
		
	}
	x--;
	q = a[x + 1];
	node_logic(a[x], a[x + 1],0);                            //specifies the turn taken to face node
	_delay_ms(5);
	a.clear();
	//_delay_ms(10);
	_delay_ms(5);
	colour_sense();                                          //decides which placing zone to move
	_delay_ms(2);
	pick();                                                  //picks the first nut
	node_logic(a[1],q,1);                                    //specifies the initial turn to commense path following
	_delay_ms(2);
	line_follow();
	_delay_ms(10);
	for (x = 1; x < (a.size() - 1); x++)
	{
		_delay_ms(2);
		printf("\n%d", a[x]);
		_delay_ms(10);
		run(a[(x - 1)], a[x], a[(x + 1)]);
		_delay_ms(3);
	}
	forward();
	_delay_ms(230);
	place();                                               //places 1st nut
    stop();
	_delay_ms(500);
	x--;
	q = a[x + 1];
	a.clear();
	left();
	_delay_ms(950);
	line_follow();
	dijkstra(q, 15);
	_delay_ms(5);
	for (x = 1; x < (a.size() - 1); x++)
	{
		_delay_ms(2);
		printf("\n%d", a[x]);
		run(a[(x - 1)], a[x], a[(x + 1)]);
		_delay_ms(3);
    }

	x--;
	q = a[x + 1];
	node_logic(a[x], a[x + 1], 0);
	_delay_ms(5);
	a.clear();
	_delay_ms(5);
	colour_sense();
	_delay_ms(3);
	pick();
	node_logic(a[1], q, 1);
	_delay_ms(2);
	line_follow();
	_delay_ms(10);
	for (x = 1; x < (a.size() - 1); x++)
	{
		_delay_ms(2);
		printf("\n%d", a[x]);
		_delay_ms(10);
		run(a[(x - 1)], a[x], a[(x + 1)]);
		_delay_ms(3);
	}
	forward();
	_delay_ms(230);
	place();
	stop();
	_delay_ms(500);

	x--;
	q = a[x + 1];
	a.clear();
	left();
	_delay_ms(950);
	line_follow();
	dijkstra(q, 16);
	_delay_ms(5);
	for (x = 1; x < (a.size() - 1); x++)
	{
		_delay_ms(2);
		printf("\n%d", a[x]);
		run(a[(x - 1)], a[x], a[(x + 1)]);
		_delay_ms(3);
	}

	x--;
	q = a[x + 1];
	node_logic(a[x], a[x + 1], 0);
	_delay_ms(5);
	a.clear();
	_delay_ms(5);
	colour_sense();
	_delay_ms(3);
	pick();
	node_logic(a[1], q, 1);
	_delay_ms(2);
	line_follow();
	_delay_ms(10);
	for (x = 1; x < (a.size() - 1); x++)
	{
		_delay_ms(2);
		printf("\n%d", a[x]);
		_delay_ms(10);
		run(a[(x - 1)], a[x], a[(x + 1)]);
		_delay_ms(3);
	}
	forward();
	_delay_ms(230);
	place();
	stop();
	_delay_ms(500);

	x--;
	q = a[x + 1];
	a.clear();
	left();
	_delay_ms(950);
	line_follow();
	dijkstra(q, 14);
	_delay_ms(5);
	for (x = 1; x < (a.size() - 1); x++)
	{
		_delay_ms(2);
		printf("\n%d", a[x]);
		run(a[(x - 1)], a[x], a[(x + 1)]);
		_delay_ms(3);
	}

	x--;
	q = a[x + 1];
	node_logic(a[x], a[x + 1], 0);
	_delay_ms(5);
	a.clear();
	_delay_ms(5);
	colour_sense();
	_delay_ms(3);
	pick();
	node_logic(a[1], q, 1);
	_delay_ms(2);
	line_follow();
	_delay_ms(10);
	for (x = 1; x < (a.size() - 1); x++)
	{
		_delay_ms(2);
		printf("\n%d", a[x]);
		_delay_ms(10);
		run(a[(x - 1)], a[x], a[(x + 1)]);
		_delay_ms(3);
	}
	forward();
	_delay_ms(230);
	place();
	stop();
	_delay_ms(500);
	

	
	
}

//N.B. WINDOWS 10,64-bit,intel i5 core.

void maze_solver(void)
{
	int n, i = 0, t = 1;
	char a[50], b[50];
	printf("Enter the no of turns/nodes :");
	scanf("%d", &n);
	printf("\nEnter the turns performed in each node :");
	while (i < n)
	{
		scanf("%c", &a[i]);
		i++;
	}
	while (t = 1)
	{
		t=short(&a, &b);
		a = b;
		for (i = 0; i < n; i++)
		{
			if (a[i] == 'l' &&a[i + 1] == 'b' &&a[i + 2] == 'r')
			{
				b[i] = 'b';
				i = i + 2;
			}
			else if (a[i] == 'l' &&a[i + 1] == 'b' &&a[i + 2] == 's')
			{
				b[i] = 'r';
				i = i + 2;
			}
			else if (a[i] == 'r' &&a[i + 1] == 'b' &&a[i + 2] == 'l')
			{
				b[i] = 'b';
				i = i + 2;
			}
			else if (a[i] == 's' &&a[i + 1] == 'b' &&a[i + 2] == 'l')
			{
				b[i] = 'r';
				i = i + 2;
			}
			else if (a[i] == 's' &&a[i + 1] == 'b' &&a[i + 2] == 's')
			{
				b[i] = 'b';
				i = i + 2;
			}
			else if (a[i] == 'l' &&a[i + 1] == 'b' &&a[i + 2] == 'l')
			{
				b[i] = 's';
				i = i + 2;
			}
		}
	}
}
void short(char *a, char *b)
{

}
