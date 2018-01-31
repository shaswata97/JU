#define MAXQ 1024
#define TRUE 1
#define FALSE 0
struct queue_t 
{
	int front, rear ;
	int count ;
	int val [MAXQ] ;
};

typedef struct queue_t * queue ;
queue init_q (queue q)
{
	if ((q = (queue) malloc(sizeof (struct queue_t)))== NULL)
	{
		printf("Memory allocation error\n");
		exit(0);
	}
	q->front = 0 ;
	q->rear = -1 ;
	q->count = 0 ;
	return q;
}

void dispose_q (queue q)
{ 
	if (q != NULL)
	free(q);
}

int empty_q (queue q)
{
	return ( q->count == 0) ;
}

int full_q (queue q)
{
	return (q->count == MAXQ) ;
}


void enqueue ( queue q , int e )
{ 
	if (!(full_q(q)))
	{
		q->rear = ( q->rear + 1) % MAXQ;
		q->val [ q->rear ] = e ;
		(q->count) ++ ;
	}
	else printf("Queue full error\n");
}

int dequeue ( queue q)
{
	int x ;
	if (!(empty_q(q)))
	{
		x = q->val [q-> front ] ;
		q->front = (q->front + 1) % MAXQ;
		(q->count) -- ;
		return x;
	}
	else printf("Queue empty error\n");
}

void printq(queue q)
{
	int i;
	for(i=q->rear;i<=q->front;i++)
	{
		printf(">%d\t",q->val[i]);
	}
	printf("\n");
}