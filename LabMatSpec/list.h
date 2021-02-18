void FromListToSmejMatrix(node* x,int **y,int m)
{
	for (int i = 0;i<m; i++){
		node * ptr =  &x[i];
	while (ptr)
	{
		y[i][ptr->value-1]=1;
		ptr = ptr->next;
	}
	}
}
void MemAllocForList(node*& x,int m){
	int len=0;
	x = new node[m];
	for (int i = 0;i<m; i++)
	{ 
		node* ptr =  &x[i];
			std::cout<<"Сколько соседей у "<<i+1<<" вершины?  ";
			std::cin>>len;
		for (int j = 1; j <=len; j++)
			ptr = ptr->next = new node(0);}
}
void FillList(node* x,int m)
{int k;
	for (int i = 0;i<m; i++){
		node* ptr =  &x[i];
		while(ptr->next){
			std::cout<<"С какой вершиной связана "<<i+1<<" вершинa?  ";
			std::cin>>k;
			ptr->value=k;	
			ptr=ptr->next;
		}
	}
}
void PrintList(node* x,int m)
{
	for (int i = 0;i<m; i++){
		node * ptr =  &x[i];
		std::cout<<i+1;
	while (ptr)
	{
		std::cout<<"->"<<ptr->value;
		ptr = ptr->next;
	}std::cout<<std::endl;
	}
}
void DeleteWholeList(node*& x,int m)
{
	for (int i = m; i--;)
	{ 
		node* ptr =  x[i].next;
		while (ptr)
		{
			node * temp = ptr;
			ptr = ptr->next;
			delete temp;
		}
		
	}
	delete []x;
	x=NULL;
	std::cout<<"Массив списков был удален из памяти"<<std::endl;
}
void SmejMatToList(node*& x,int **y,int reb,int ver)
{	int count,z,k;
	x = new node[ver];
	for (int i = 0;i<ver; i++){
		count = 1;
		int j = 0;
		while (j<ver){
			if(y[i][j])
				count++;
			j++;
		}
		node * ptr =  &x[i];
		for(int j=1;j <count;j++){
			ptr =ptr->next= new node(0);
		}
	}
}
//заполнение списка из матрицы смежности 
void fill(node* x,int **y,int reb,int ver)
{
	for (int i = 0;i<ver; i++){
		node * ptr =  &x[i];
		int j=0;
		while(ptr->next || j<ver){
			if(y[i][j]){
				ptr->value = j+1;
				ptr=ptr->next;
			}	
			j++;
		}
	}
}

