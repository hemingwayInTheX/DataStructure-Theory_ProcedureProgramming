#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning (disable : 4996)

#define MAX_CHILD 10

typedef struct ano* nodeptr;
typedef struct ano {
	char name[30];
	float gpa;
	char place[100];
	nodeptr links[MAX_CHILD];
}nodetype;

nodeptr root = NULL;
nodeptr stack[100];
int top = -1;


int read_upper(FILE* fp, char buf[20][50]); 	// 데이터 파일의 상반부의 한 줄 읽는 함수, function that reads a single line at the top of a data file
void read_store_lower_data(FILE* fp);			// 데이터 파일의 하반부의 한 줄 읽는 함수, function that reads a single line frome the bottom half of the data file
void print_general_tree(nodeptr curr);			// 모든 노드의 내용을 출력, output the contents of all nodes
void make_node_and_attach_to_parent(nodeptr parent, char* tname, int loc);	// parent의 loc 위치에 자식 노드를 만들어 매달고 이름은 tname을 넣어줌, create a child node in the loc location of the parents, hang it, and insert the name tname
void push_stack(nodeptr nptr);
void pop_stack();

nodeptr search_node(nodeptr cur, char name[]);	// 이름으로 노드 탐색, searching nodes by name
void calc_height(nodeptr cur, int par_height, int* tree_height);	// Find the height of the whole tree
int calc_depth(nodeptr cur, int par_height, char* sname);		// Find the depth of a specific person
int find_ancestors(nodeptr cur, char* sname);	// Find all ancestors of a specific person
void calc_descendants(nodeptr cur, int* cnt);	// Find the number of descendants of a specific person

int main() {
	char buf[20][50];
	char line[100];
	char command[100];
	char name[10];
	int num_persons, k, i, res;
	nodeptr np;
	
	FILE* fp;
	fp = fopen("tree_data.txt", "r");
	if(!fp) {
		printf("file open error\n");
		return 0;
	}
	
	do {
		num_persons = read_upper(fp, buf);	// read one line of several names
		if(num_persons == 0)	// '-' in first letter of the first person's name
			break;
		if(!root) {	// no node in the tree
			np = (nodeptr)malloc(sizeof(nodetype));
			strcpy(np->name, buf[0]);	// 부모 이름 넣음, put parent name
			root = np;
			np->links[0] = NULL;
			for(k=1; k<num_persons; k++)	// 자식들을 만들어 매달음, making child and hanging them
				make_node_and_attach_to_parent(np, buf[k], k-1);
			// put NULL in links field after the last child
			np->links[k-1] = NULL; 
		}
		else {	// ordinary case of a tree with one or more nodes
			np = search_node(root, buf[0]);
			if(!np) {
				printf("Error: 2째 줄 이하의 첫 이름 노드가 없음\n");	// Error: No first name node less than second line
				getchar();
			}
			for(k=1; k<num_persons; k++)
				make_node_and_attach_to_parent(np, buf[k], k-1);
			// put NULL in links field after the last child
			np->links[k-1] = NULL; 
		}
	} while(1);
	
	// 각 노드에 대한 데이터를 읽어서 저장, read and save data for each node
	read_store_lower_data(fp);
	
	// 트리 안의 모든 노드의 데이터를 preorder 방식으로 출력, output data from all nodes in the tree in a preorder manner
	print_general_tree(root);
	
	do {
		printf("Type a command> ");
		gets(line);
		
		i = 0;
		while(line[i] == ' ' || line[i] == '\t') i++;	// move to 1st letter of the command
		k = 0;
		while(!(line[i] == ' ' || line[i] == '\t' || line[i] == '\0')) {
			command[k] = line[i];
			i++; k++;
		}
		command[k] = '\0';	// finish the command
		
		if(strcmp(command, "ex") == 0)
			break;
		else if(strcmp(command, "ht") == 0) {
			int tree_height = 0;
			calc_height(root, 0, &tree_height);
			printf("Height of the tree : %d \n", tree_height);
			continue;
		}
		
		// read a name given after the command
		k = 0;
		while(line[i] == ' ' || line[i] == '\t') i++;	// move to 1st letter of the command
		while(!(line[i] == ' ' || line[i] == '\t' || line[i] == '\0')) {
			name[k] = line[i];
			i++; k++;
		}
		name[k] = '\0';
		
		if(strcmp(command, "se") == 0) {
			np = search_node(root, name);
			if(np)
				printf("Search success: %s %5.2f %s\n", np->name, np->gpa, np->place);
			else
				printf("Such a person does not exist\n");
		}
	else if(strcmp(command, "dp") == 0) {
			res = calc_depth(root, 0, name);
			if(!res)
				printf("Such a name does not exist in the tree\n");
		}
		else if(strcmp(command, "ac") == 0) {
			top = -1;
			res = find_ancestors(root, name);
			if(!res)
				printf("Such a name does not exist in the tree\n");
		}
		else if(strcmp(command, "nm") == 0) {
			int cnt = 0;
			np = search_node(root, name);
			calc_descendants(np, &cnt);
			printf("%d 명\n", cnt);	// order
		}
		else {
			printf("Wrong command\n");
		}
	} while(1);
	 
	return 0;
}

// 데이터 파일의 상반부의 한 줄 읽는 함수, function that reads a single line at the top of a data file
// 한 줄을 읽어서 2차원 배열 buf에 넣고, 사람 수를 반환, read one line and put it in a tow-dimensional array buf, returning the number of people
// 0은 --- 줄을 읽은 경우에 반환됨, 0 returned when --- line read
int read_upper(FILE* fp, char buf[20][50]) {
	// read "parent-children" lines to create the tree
	int i, j, k;
	char line[400];
	char* cp;
	cp = fgets(line, 400, fp);
	if(!cp) {
		// fail in reading
		printf("Impossible for the control to reach here\n");
		return 0;
	}
	else {
		if(line[0] == '-')  // 파일 상단부 읽기 종료, end file top read
			return 0;
		
		i = 0;		// number of names read so far
		j = 0; 		// index to line
		while(1) {
			k = 0; 	// index to a character of the i-th name
			while(line[j] != ' ' && line[j] != '\n') {
				buf[i][k] = line[j];
				j++; k++;
			}
			buf[i][k] = '\0';	// finish one name
			i++;	// increase the name count
			if(line[j] == '\n')
				break;
			else {
				do j++; while(line[j] == ' ');
			}
		}
		return i;
	}
}

// 데이터 파일의 하단부를 읽어 정보를 저장, store information by reading the lower part of the data file
void read_store_lower_data(FILE* fp) {
	char rname[30], address[100];
	float rgpa;
	nodeptr np;
	int read_num;
	
	do {
		read_num = fscanf(fp, "%s%f%s", rname, &rgpa, address);
		if(read_num != 3)
			break;
		else {
			// 읽은 이름을 가진 노드를 트리에서 찾음, found nodes with read names in the tree
			np = search_node(root, rname);
			if(!np)
				printf("이런 이름을 가진 노드가 없습니다.\n");	// No node with this name exists
			else {
				// 읽은 데이터를 저장, save read data
				strcpy(np->name, rname);
				np->gpa = rgpa;
				strcpy(np->place, address);
			}
		}		
	} while(1);
}

// 모든 노드의 내용을 출력, output the contents of all nodes
void print_general_tree(nodeptr cur) {
	int i;
	if(!cur)
		return;
	printf("이름: %s\t학점: %5.2f\t주소: %s \n", cur->name, cur->gpa, cur->place);	// Name: %s\tGrade: %5.2f\tAddress: %s \n
	for(i=0; cur->links[i]; i++)
		print_general_tree(cur->links[i]);
} 

// parent의 loc 위치에 자식 노드를 만들어 매달고 이름은 tname을 넣어줌, create a child node in the loc location of the parents, hang it, and insert the name tname
void make_node_and_attach_to_parent(nodeptr parent, char* tname, int loc) {
	nodeptr np1;
	np1 = (nodeptr)malloc(sizeof(nodetype));
	strcpy(np1->name, tname);
	np1->links[0] = NULL;
	parent->links[loc] = np1;
} 

void push_stack(nodeptr nptr) {
	top++;
	stack[top] = nptr;
}

// this pop des not return the element
void pop_stack() {
	top--;
}

// 이름으로 search, search by name
// cur : 트리의 노드에 대한 포인터, pointer to nodes in the tree
// name : 찾을 이름, name to look for
// 반환값 : 찾은 노드의 포인터 (못 찾을 경우 NULL), return value: pointer of found node (NULL if not found)
nodeptr search_node(nodeptr cur, char name[]) {
	int i;
	nodeptr rptr;
	
	if(!cur)
		return NULL;
	
	if(strcmp(cur->name, name) == 0)
		return cur;		// 성공, success
	else {
		for(i=0; cur->links[i] != NULL; i++) {
			rptr = search_node(cur->links[i], name);
			if(rptr) return rptr;
		}
		return NULL;	// 자식들 모두에서도 못 찾았으므로 실패, failed because none of the child found it
	} 
}

// Find the height of the whole tree
void calc_height(nodeptr cur, int par_height, int* tree_height) {

	// Fill your code
	

	/*====높이 계산====
	1) 첫 번째 인덱스 ( [0] )가 NULL이면 단말노드임을 고려 --> 0번째 인덱스 NULL인지 아닌지가 중요
	2) 각 인덱스마다 연결된 자식노드들의 갯수 계산  --> ROOT노드 인덱스 기준
	3) 특정 배열의 동일한 인덱스에 갯수 저장 --> maxArr
	4) maxArr에서 최대값 탐색 후 출력매개변수 tree_height을 통해 반환*/

	nodeptr pcur = cur->links[0];//단말노드 탐색을 위한 장치 --> Lv 1이 이미 계산되었다고 가정
	int maxArr[MAX_CHILD] = { 0 };
	int idx = 0;//ROOT노드의 멤버 변수인 배열의 반복제어변수 -->이름을 "진용진"으로 갖는 노드의 links배열이 탐색 제어
	int maxHeight = 0;//maxArr의 최대 높이 원소

	while (cur->links[idx] != NULL) {//포인터 배열의 원소가 NULL이면 루프 탈출
		if (pcur == NULL) {//links 배열의 첫 번째 원소가 null 이면 단말노드
			maxArr[idx] = par_height + 1; //갯수 + 1 --> ex) "진용진" 0번째 인덱스에서 단말노드까지 연결된 자식의 갯수 --> 3
			idx++;//ROOT인덱스의 0번째 인덱스에서 1번째 인덱스 탐색을 위한 제어 변수 갱신
			par_height = 0;//갯수 확인 변수 초기화
			pcur = cur->links[idx];//단말노드 탐색 장치 초기화
		}
		else {//포인터 배열의 첫 번째 원소가 NULL이 아니면 단말노드가 아님 --> 갯수 증가
			pcur = pcur->links[0];//탐색 노드 자식으로 이동
			par_height++;
		}
	}//LOOP1_각 인덱스마다 높이 계산 후 maxArr 저장

	for (int i = 0; i < MAX_CHILD; i++) {
		maxHeight = maxArr[0];
		if (maxArr[0] > maxHeight) maxHeight = maxArr[i];
	}//LOOP2_최대 높이 탐색 

	*tree_height = maxHeight;//출력매개변수로 값 반환

}

// Find the depth of a specific person
// return value : 1 if the name has been found and its depth was printed
//				  0 if the name was not found in the subtree with root of cur
int calc_depth(nodeptr cur, int par_height, char* sname) {

	// Fill your code
	nodeptr pcur = NULL;
	int idx = 1;
	int cntDp = par_height;

	if (cur->links[0] == NULL) {
		return 0;
	}
	else {
		 calc_depth(cur->links[idx], cntDp, sname);
		 pcur = cur->links[1];
		 calc_depth(pcur, cntDp, sname);

	}
}
	
//	if (pcur->links[idx] != NULL) {
//		if (strcmp(pcur->name, sname) == 0) {//이름 찾으면
//			printf("Height of the node of %s : %d", pcur->name, cntDp);
//			return 1;
//		}
//		return calc_depth(pcur->links[idx], cntDp, sname);
//	}


// Find all ancestors of a specific person
int find_ancestors(nodeptr cur, char* sname) {

	// Fill your code
	

}

// Find the number of descendants of a specific person
void calc_descendants(nodeptr cur, int* cnt) {

	// Fill your code
	

}

