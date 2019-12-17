#include "adjNet.h"

//构造函数:根据所给图生成相应图
adjNet::adjNet(){
    adjlist.push_back(adjNode());
}
adjNet::~adjNet(){
    
}

int adjNet::InsertEdge(int v1,int v2){
    int num =adjlist.size();
    if(v1>num||v2>num){
        return -1;
    }
    if(adjlist[v1].nextedgeNode==nullptr){
        adjlist[v1].nextedgeNode = new edgeNode(v2,nullptr);
    }
    else{
        edgeNode * n=adjlist[v1].nextedgeNode;
        while(n->nextedgeNode!=nullptr){
            n = n->nextedgeNode;
        }
        n->nextedgeNode = new edgeNode(v2);//添加新节点到末尾
    }
    return 1;
}
//添加顶点，通过课程名
void adjNet::InsetVex(std::string str){
    int n=adjlist.size();
    adjNode *a1= new adjNode(n,str);
    adjlist.push_back((*a1));
}

//获得结点数
int adjNet::GetVexNum(){
    return adjlist.size()-1;
}

//返回第一个邻接结点
int adjNet::FirstAdjVex(int v1){
    if(adjlist[v1].nextedgeNode!=nullptr){
        return adjlist[v1].nextedgeNode->adjnum;
    }
    else{
        return -1;
    }
}

//返回v1到v2之后的下一个邻接点
int adjNet::NextAdjVex(int v1,int v2){
    //bool tag=true;
    edgeNode* n;
    for(n=adjlist[v1].nextedgeNode;n!=nullptr;n=n->nextedgeNode){
        if(n->adjnum==v2)break;
    }
    n = n->nextedgeNode;
    if(n==nullptr){
        return -1;
    }
    else{
        return n->adjnum;
    }
}

//获取顶点名称
std::string adjNet::GetVexname(int v1){
    return adjlist[v1].sname;
}

int adjNet::GetVexindex(std::string str){
    return IndexVex(str);
}