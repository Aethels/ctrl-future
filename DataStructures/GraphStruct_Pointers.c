#include <stdio.h> 
#include <stdlib.h>

#define SIZE 40 // max queue size

// structure for courses in the neighborhood list
struct node { 
	int vertex; // number of nodes
	struct node* next; // next element pointer
	};
	
// structure for the graph 
struct Graph { 
	int numVertices; 
	struct node** adjLists; // array of neighborhood list
};	

// function to save entered courses as nodes
struct node* createNode(int v) { 
	struct node* newNode = malloc(sizeof(struct node));  
	newNode->vertex = v;  
	newNode->next = NULL;  
	return newNode; 
}

// function of creating graphs from the courses entered
struct Graph* createGraph(int vertices) { 
	struct Graph* G = malloc(sizeof(struct Graph)); 
	G->numVertices = vertices; 
	G->adjLists = malloc(vertices * sizeof(struct node*)); 
	int i;
	for (i = 0; i < vertices; i++) {
    	G->adjLists[i] = NULL; 
	}
	return G; 
}

// adding an edge between courses according to prerequisites 
void addEdge(struct Graph* G, int src, int dest) { 
	// add the prerequisite course as a new node and put it in the neighborhood list  
	struct node* newNode = createNode(dest); 
	newNode->next = G->adjLists[src]; 
	G->adjLists[src] = newNode; 
}

// function that prints the prerequisites for each course
void printIndegree(struct Graph* G) {
    int i;
    for (i = 0; i < G->numVertices; i++) {
        int indegree = 0;
        for (int j = 0; j < G->numVertices; j++) {
            struct node* temp = G->adjLists[j];
            while (temp != NULL) {
                if (temp->vertex == i) {
                    indegree++;
                    break;
                }
                temp = temp->next;
            }
        }
        printf("Ders %d ,%d onkosullu derse sahip.\n", i, indegree);
    }
}


// printing the generated graph as a neighborhood list
void printGraph(struct Graph* G) { 
	int i; 
	for (i = 0; i < G->numVertices; i++) { 
		struct node* temp = G->adjLists[i]; 
		printf("\n Ders %d'in komsuluk listesi:\n ", i); 
		while (temp) { 
			printf("Ders %d -> ", temp->vertex); 
			temp = temp->next; 
			} 
		printf("\n"); 
	} 
}

// creating queue with front and rear pointers
struct queue { 
	int items[SIZE]; // queue of lectures
	int front; 
	int rear; 
};

// creating an empty queue in memory and assigning pointers to -1
struct queue* createQueue() { 
	struct queue* q = malloc(sizeof(struct queue)); 
	q->front = -1; 
	q->rear = -1; 
	return q; 
}

// check if the queue is empty 
int isEmpty(struct queue* q) { 
	if (q->rear == -1) 
		return 1; 
	else return 0; 
}

//  adding lessons to the queue and increasing the rear
void enqueue(struct queue* q, int value) { 
	if (q->rear == SIZE - 1) { 
		printf("\nKuyruk Dolu!"); 
	} 
	else { 
		if (q->front == -1) {  
		q->front = 0; 
		} 
	q->rear++; 
	q->items[q->rear] = value; // placement of the added course in the rear 
	} 
}

// function of course deletion from the queue
int dequeue(struct queue* q) { 
	int item; 
	if (isEmpty(q)) { 
		printf("\nKuyruk Bos!"); 
		item = -1; 
	} 
	else { 
		item = q->items[q->front];  
		q->front++; 
		if (q->front > q->rear) { // check if queue is empty after deletion
        	
        	q->front = q->rear = -1;  
    	}
	}
	return item; // return deleted course
}

// determining the tail size based on the difference between the pointers
int queueSize(struct queue *q) { 
	if (isEmpty(q)) { 
		return 0; 
	} 
	else { 
		return (q->rear - q->front + 1); 
	} 
}


int main() {
	int N, E, i, j;
	printf("Ders sayisini giriniz: "); scanf("%d", &N);
	printf("Onkosul sayisini giriniz: "); scanf("%d", &E);
	struct Graph* G = createGraph(N);
	int indegree[N];
	for (i = 0; i < N; i++) { 
		indegree[i] = 0; 
	}
	printf("Onkosul durumuna gore komsuluk matrisini giriniz:\n");
	for (i = 0; i < N; i++) { 
		for (j = 0; j < N; j++) { 
			int edge; 
			scanf("%d", &edge); 
			if (edge == 1) { 
				addEdge(G, i, j); 
				indegree[j]++; 
			} 
		} 
	}
	printIndegree(G);
	printGraph(G);
	struct queue* q = createQueue();
	for (i = 0; i < N; i++) {
		if (indegree[i] == 0) { 
			enqueue(q, i); 
		} 
	}
	int semester = 0;
	while (!isEmpty(q)) {
		semester++; 
		printf("\n %d. donemde alinabilecek dersler: \n", semester);
		int size = queueSize(q); 
		for (i = 0; i < size; i++) { 
			int v = dequeue(q); 
			printf("Ders %d\t", v);
			struct node* temp = G->adjLists[v]; 
			while (temp != NULL) { 
				int u = temp->vertex;
				indegree[u]--; 
				if (indegree[u] == 0) { 
                	enqueue(q, u); 
          		}
			temp = temp->next;
     		}
  		}
		printf("\n");
	}
	
	printf("\nMezuniyet icin gerekli minimum donem sayisi: %d\n", semester);
	return 0; 
}
