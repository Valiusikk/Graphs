//Выделение памяти
void allocMem(int** &x,int n,int m){
		x=new int* [n];
		
		if (x==NULL){
		std::cout<<"Error 404"<<std::endl;
		return;
	}	
		for(int i=0;i<n;i++){
			x[i]=new int[m];
			
			if (x[i]==NULL){
			std::cout<<"Error 505"<<std::endl;
			return;
		}
}std::cout<<"Память успешно выделена"<<std::endl;
}
//запонение нулями
void fill(int **x,int n,int m)
{
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			x[i][j]=0;
	}		
}
//ФУНКЦИИ РАСПЕЧАТКИ
//Вывод с помощью матрицы смежности
//Ну и удаление массива из памяти
void Delete(int** &x,int n){
		if(x==NULL)
		std::cout<<"А ты его и не создавал"<<std::endl;
		else{
			for(int i=0;i<n;i++)
			delete []x[i];
			delete []x;
			std::cout<<"Память успешно освобождена"<<std::endl;
		}	
}
int GraphInputMatSmej(int** g,int n,int& p){
	int k=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(j==i)std::cout<<"Образуется ли петля у вершины "<<i+1<<" ? "<<std::endl;
			else std::cout<<"Из "<<i+1<<" -> "<<j+1<<"?"<<std::endl;
			std::cin>>g[i][j];
			
			if(g[i][j])p++;// считаю вершины связанные ребрами
			
			if(g[j][i] && g[i][j])// считаю ребра
			k++;
		}
	}
	return k;// ребра
}
int GraphInputMethodInt(int** g,int n,int reb)
{	int i_1,i_2,k;
	k=reb;
	fill(g,reb,n);
	char a=97;
	int i=0;
	while(i<reb){
		for(int j=0;j<1;j++){
			std::cout<<"Ребро "<<a<<" выходит из ?"<<std::endl;
			std::cin>>i_1;
			g[i][i_1-1]=-1;
			std::cout<<"В ?"<<std::endl;
			std::cin>>i_2;
			g[i][i_2-1]=1;
			a++;
		}
		i++;
	}
	return k;
}
void print(int** g,int reb,int len)
{
	if(g==NULL)return;
	else{std::cout<<"       ";
		for(int i=0;i<len;i++)
			std::cout<<" X"<<i+1;
		std::cout<<std::endl;
		if(reb==len){
		for(int i=0;i<reb;i++){
			std::cout<<"X"<<i+1<<"	";
			for(int j=0;j<len;j++){
				std::cout<<g[i][j]<<"  ";
			}
		std::cout<<std::endl;
		}	
		}
		else{
		for(int i=0;i<reb;i++){
			std::cout<<"E"<<i+1<<"	";
			
			for(int j=0;j<len;j++){
				std::cout<<g[i][j]<<"  ";
			}
		std::cout<<std::endl;
		}
		}
	}
}
int** IdentToSmej(int **y,int ver,int reb)
{
	int** smej=NULL;
	allocMem(smej,ver,ver);
	fill(smej,ver,ver);
	int in,to;
	for (int i = 0;i<reb; i++){
		in=-1,to=-1;
		for (int j = 0;j<ver &&(in==-1 || to==-1); j++){
			if(y[i][j]==-1)
				in = j;
			else if(y[i][j]==1)
				to=j;
		}
		smej[in][to]=1;
	}
	Delete(y,ver);
	return smej;
}
void ListToIntMat(node* x,int** y,int reb,int ver)
{
	fill(y,reb,ver);
	int k;
	for(int i=k=0;i<ver;i++){
		node * ptr =  &x[i];
	while (ptr->next)
	{	
		y[k][i]=-1;
		y[k][ptr->value-1]=1;
		k++;
		ptr = ptr->next;
	}
	}
}
void MatIntToList(node*& x,int **y,int reb,int ver)
{
	x = new node[ver];
	int count,k,tmp,temp,out,in;
//выделяю память списку
for (int i = 0; i <ver; i++){
	node * ptr =  &x[i];
	for (int j = 0; j <reb; j++){
		if(y[j][i]==-1)
		ptr =ptr->next= new node(0);}}
		
	for (int i = 0;i<reb; i++){
		out=-1,in=-1;
		for (int j = 0;j<ver &&(out==-1 || in==-1); j++){
			if(y[i][j]==-1)
				out = j;
			else if(y[i][j]==1)
				in=j;
		}
		node * ptr =  &x[out];
		if(ptr->value!=0){
			ptr =ptr->next;
			ptr->value=in+1;
		}
		else{
			ptr->value=in+1;
		}	
			
	}
}
//из матрицы смежности в матрицу инцидентности
int** SmejIdent(int** x,int ver,int reb)
{	int k;
	int** intin=NULL;
	allocMem(intin,reb,ver);
	fill(intin,reb,ver);
	for(int i=k=0;i<ver;i++)
		for(int j=0;j<ver;j++)
			if(x[i][j]==1){
				intin[k][i]=-1;
				intin[k][j]=1;
				k++;
			}
			else if(x[i][j]==1){
				intin[k][i]=2;
				k++;
			}
	Delete(x,ver);		
	return intin;
	}

