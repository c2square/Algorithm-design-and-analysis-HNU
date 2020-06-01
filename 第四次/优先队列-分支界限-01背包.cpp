#include <bits/stdc++.h>
using namespace std;
struct Node {
	Node() {
		value = 0;
		weight = 0;
		level = 0;
		parent = 0;
		bound = 0;
	}
	int value;           //搜索到该节点时的价值
	int weight;          //搜索到该节点时的总重量
	float bound;		 //搜索以该节点为根的子树能达到的价值上界
	int level;           //该节点所处层次，从0开始
	struct  Node *parent;//指向父节点
};

struct cmp {
	bool operator () (Node *a, Node *b) {
		return a->bound < b->bound;
	}
};

struct Item{
	int ItemID;			//物品编号
	int value;			//物品价值
	int weight;			//物品重量
	float ratio;		//价值/重量
};

bool ItemCmp(Item item1, Item item2) {
	return item1.ratio > item2.ratio;
}


int branchAndBound(Item items[], int c);
float maxBound(Node *node, Item items[], int c);
int N,c;//背包容量
Item items[100];
int maxVlue;
int maxSize=0;
int searchCount=0;
int main() {

 	cin>>c>>N;
	for (int i = 0; i < N; i++) {
		cin>> items[i].weight>> items[i].value;
		items[i].ratio = (float)items[i].value / items[i].weight;
		items[i].ItemID = i;
	}
	sort(items,items+N,ItemCmp);//按价值率排序

	maxVlue = branchAndBound(items, c);
	cout << "最大价值为:" << maxVlue << endl;
	return 0;
}

int branchAndBound(Item items[], int c) {
	int x[N] = { 0 };
	//保存当前搜索到的最大价值
	int maxValue;
	//保存当前最大价值节点（叶节点）
	Node *maxNode = new Node();
	//最大价值优先队列
	priority_queue<Node *, vector<Node *>, cmp> maxQueue;

    //构建第一个节点
	Node *firstNode, *curNode;
	searchCount = 1;
	firstNode = new Node();
	firstNode->bound = maxBound(firstNode,items,c);
	firstNode->parent = NULL;
	//入队第一个结点
	maxQueue.push(firstNode);
	maxValue = 0;
	maxNode = firstNode;

	while (!maxQueue.empty())
	{
		curNode = maxQueue.top();
		maxQueue.pop();
		//扩展左孩子结点：取该物品
		if (curNode->weight + items[curNode->level].weight <= c)
        {	//在最大重量限界内
			Node *leftNode = new Node();
			leftNode->value = curNode->value + items[curNode->level].value;
			leftNode->weight = curNode->weight + items[curNode->level].weight;
			leftNode->level = curNode->level + 1;
			leftNode->parent = curNode;
			leftNode->bound = curNode->bound;
            //N层以内，加入优先队列
			if (leftNode->level<N) {
				maxQueue.push(leftNode);
			}
			//更新最优解结点
			if (maxValue < leftNode->value) {
				maxValue = leftNode->value;
				maxNode = leftNode;
			}
		}
		//扩展右孩子结点：不取该物品
		if (maxBound(curNode, items, c)>maxValue)
        {	//如果不取该元素的最大价值 小于现有的最大价值，则剪枝
			Node *rightNode = new Node();
			rightNode->value = curNode->value;
			rightNode->weight = curNode->weight;
			rightNode->level = curNode->level + 1;
			rightNode->parent = curNode;
			rightNode->bound = maxBound(rightNode,items,c);
			if (rightNode->level < N) {
				maxQueue.push(rightNode);
			}
		}
		//跟踪队列大小
		if (maxQueue.size()>maxSize)
			maxSize = maxQueue.size();
	}
//	curNode = maxNode;
//	while (curNode) {
//		int tempValue = curNode->value;
//		curNode = curNode->parent;
//		if (curNode && curNode->value != tempValue)
//			x[items[curNode->level].ItemID] = 1;
//	}
//	for (int i = 0; i < N; i++) {
//		cout << x[i] << " ";
//	}
//	cout << endl;
	return maxValue;
}
//限界函数
float maxBound(Node *node, Item items[], int c)
{	//求以该节点为根的子树能达到的价值上界
	float maxValue;
	int restCapacity;				//扩展到该节点时的剩余容量
	int i;

	maxValue = node->value;
	restCapacity = c - node->weight;
	i = node->level;
	while (i<N && restCapacity>items[i].weight) {
		maxValue += items[i].value;
		restCapacity -= items[i].weight;
		i++;
	}
	if (restCapacity != 0) {
		maxValue += restCapacity*items[i].ratio;
	}
	return maxValue;
}
