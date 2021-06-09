#include <stdio.h>
#include "ArrayGraph.h"

int main() {
	int i;
	Graph *G1, *G2;

	G1 = createGraph();
	//G2 = createGraph();
	
	// 방향 그래프 G1, direction graph G1
	for(i=0; i<5; i++)
		insertVertex(G1, i);	// G1의 정점 0~4 삽입, insert G1 vertex 0~4
	insertEdge(G1, 0, 1, 10); 
	insertEdge(G1, 0, 2, 5);
	insertEdge(G1, 1, 2, 2);
	insertEdge(G1, 1, 3, 1);
	insertEdge(G1, 2, 1, 3);
	insertEdge(G1, 2, 3, 9);
	insertEdge(G1, 2, 4, 2);
	insertEdge(G1, 3, 4, 4);
	insertEdge(G1, 4, 0, 7);
	insertEdge(G1, 4, 3, 6);
	
	printf("\nG1 가중치 행렬\n");	// G1 Weight Matrix
	displayGraph(G1);
	printf("\n");
	
	dijkstra(G1, 0);
	printf("G1: 시작 정점 0, Dijkstra Algorithm 결과\n");	// G1: Start vertex 0, Dijkstra Algorithm result
	for(i=1; i<G1->n; i++) {
		printShortestPath(G1, 0, i);
		printShortestPathCost(G1, 0, i);
	}
	printf("\n");
	
	// 방향 그래프 G2, direction graph G2
	//for(i=0; i<5; i++)
	//	insertVertex(G2, i);	// G2의 정점 0~7 삽입, insert G2 vertex 0~7
	//insertEdge(G2, 0, 1, 6);
	//insertEdge(G2, 0, 3, 7);
	//insertEdge(G2, 1, 2, 5);
	//insertEdge(G2, 1, 3, 8);
	//insertEdge(G2, 1, 4, -4);
	//insertEdge(G2, 2, 1, -2);
	//insertEdge(G2, 3, 2, -3);
	//insertEdge(G2, 3, 4, 9);
	//insertEdge(G2, 4, 2, 7);
	//
	//printf("G2 가중치 행렬\n");	// G2 Weight Matrix
	//displayGraph(G2);
	//printf("\n");
	//
	//if(bellmanFord(G2, 0)) {
	//	printf("G2: 시작 정점 0, Bellman-Ford Algorithm 결과\n");	// G2: Start vertex 0, Bellman-Ford Algorithm result
	//	for(i=1; i<G2->n; i++) {
	//		printShortestPath(G2, 0, i);
	//		printShortestPathCost(G2, 0, i);
	//	}
	//}
	//else
	//	printf("[ERROR]G2에 음수 사이클이 있음");	// [ERROR]G2 has negative cycles!
	//printf("\n");
	//
	floyd(G1);
	printf("G1: 모든 정점 쌍의 최단 경로 경비(Flyod-Warshall Algorithm 결과)\n");	// G1: Shortest path cost for all vertex pairs (Flyod-Warshall Algorithm result)
	printAllPairShortestCost(G1);
	
	//destroyGraph(G1);
	//destroyGraph(G2);
		 
	return 0;
}
