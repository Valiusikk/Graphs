#include <iostream>
struct node 
{
	int value;
	node *next;
	node () : value (0), next(0){}
	node (int x) : value (x), next(0){}
};
#include "func.h"
#include "menu.h"
#include "list.h"
int main(int argc, char* argv[])
{
	setlocale(LC_ALL,"Russian");
	int vertice,k,x,rebra,versh;
	bool isList=false,isMatS=false,isMatI=false;//������ � ��������� ������
	bool Ltbdlt=false,MatStbdl=false,MatItbdl=false;//������ � ���,��� �� ������� �������
	int **graph=NULL;
	node* root=NULL;
	std::cout<<"������� ������ � ������ �����?"<<std::endl;
	std::cin>>vertice;
	std::cout<<"������� �����?"<<std::endl;
	std::cin>>rebra;
	menu();
	
		while(1){
		std::cin>>k;
		if(k>0 && k<5){
			switch(k){
			case 1:{
				std::cout<<"����� ������� ��� ������ ����?"<<std::endl;
				std::cout<<"1) � ���� ������ ���������"<<std::endl;
				std::cout<<"2) � ���� ������� ���������"<<std::endl;
				std::cout<<"3) � ���� ������� �������������"<<std::endl;
				int p;
			std::cin>>p;
			if(p>0 && p<4){
				
				if(p==1){
					MemAllocForList(root,vertice);
					FillList(root,vertice);
					isList=true;
					Ltbdlt=true;
				}
				if(p==2){
					allocMem(graph,vertice,vertice);
					fill(graph,vertice,vertice);
					GraphInputMatSmej(graph,vertice,versh);
					isMatS=true;
					MatStbdl=true;
				
				}
				else if(p==3){
					allocMem(graph,rebra,vertice);
					GraphInputMethodInt(graph,vertice,rebra);
					isMatI=true;
					MatItbdl=true;
				}	
			}else std::cout<<"�� ������ �� �� �����"<<std::endl;
				break;
			}
			case 2:{//==============��������� �� �����===============
				output();
				std::cin>>x;
			if(x>0 && x<4)
			{
				if(x==1){//������� ���������
					if(isList){
					allocMem(graph,vertice,vertice);
					fill(graph,vertice,vertice);
					FromListToSmejMatrix(root,graph,vertice);
					print(graph,vertice,vertice);
					Ltbdlt=true;
					}
					else if(isMatS){
							print(graph,vertice,vertice);
						}
					else if(isMatI){
						graph=IdentToSmej(graph,vertice,rebra);
						print(graph,vertice,vertice);
						MatStbdl=true;
					}
				}
				else if(x==2){//������� �������������
					if(isMatS){
						graph=SmejIdent(graph,vertice,rebra);
						print(graph,rebra,vertice);
					}
					if(isMatI){
						//������
						print(graph,rebra,vertice);
					}
					else if(isList)
					{
						//������
						allocMem(graph,rebra,vertice);
						ListToIntMat(root,graph,rebra,vertice);
						print(graph,rebra,vertice);
						MatItbdl=true;
					}
				}
				else if(x==3){//list
					if(isList){
						//������
						PrintList(root,vertice);
					}
					else if(isMatS){
						//������
						SmejMatToList(root,graph,rebra,vertice);
						fill(root,graph,rebra,vertice);
						PrintList(root,vertice);
						Ltbdlt=true;
					}
					if(isMatI){
						//������
						MatIntToList(root,graph,rebra,vertice);
						PrintList(root,vertice);
						Ltbdlt=true;
					}
				}
			}
			else
				std::cout<<"�� ���� ������ ��������! �������� ������ ��!\n���� ������ ������ �� ����!"<<std::endl;
				break;
			}
			case 3:{
				if(Ltbdlt){
				DeleteWholeList(root,vertice);
				isList=false;
			}
			else if(MatStbdl){
			Delete(graph,vertice);	
			isMatS=false;
			}
			else if(MatItbdl){
				Delete(graph,rebra);
				isMatI = false;
			}
				break;
			}
			case 4:{
				std::cout<<"�� ���,����� ����� :)*"<<std::endl;
				return 0;
				break;
			}
		}
		}
		else{
		std::cout<<"��� ��� �������?";
		return 0;
	}
	}
	return 0;
}
