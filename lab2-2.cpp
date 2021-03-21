struct Node {
	int id;   //结点
	int dis;  //这个结点到起点的距离
	Node(int v, int w) : id(v), dis(w) {}
	bool friend operator < (const Node& a, const Node& b) {
		return a.dis  > b.dis;
	}
};
int n, m;
int pre[NN];
void print_path(int s, int t) {  //打印s到t的最短距离
	if (s  == t) {
		printf("%d\n", s);
		return;
	}
	print_path(s, pre[t]);
	printf("%d\n", t);
}
void dijkstra() {
	int s  = 1;      //起点是1
	int dis[NN];    //计算所有结点到起点的距离
	bool done[NN];  //值为true表示到结点i的最短路径已经找到
	for (int i  = 1; i  <= n; i++) {  //初始化
		dis[i] = INF;
		done[i] = false;
	}
	dis[s] = 0;  //表示起点到自己的距离是0
	priority_queue<Node> q;
	q.push(Node(s, dis[s]));
	while (!q.empty()) {
		Node u  = q.top();
		q.pop();  // pop出距离起点最近的结点u
		if (done[u.id])
			continue;  //若该结点已经找到最短路径，则跳过
		done[u.id] = true;
		for (int i  = head[u.id]; i  != -1; i  = edge[i].next) {  //检查结点的所有邻居
			Edge v  = edge[i];
			if (done[v.to])
				continue;
			if (dis[v.to] > v.dis  + u.dis) {
				dis[v.to] = v.dis  + u.dis;
				q.push(Node(v.to, dis[v.to]));  //拓展新邻居，放入优先队列
				pre[v.to] = u.id;               //记录路径
			}
		}
	}
	printf("%d\n", dis[n]);
	// print_path(s,n);//若有需要则打印路径
}