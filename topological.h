#include "adjNet.h"
#include <queue>

//统计每个节点的入度
void sumindegree(adjNet &g,int *indegree){
    for(int i=0;i<=g.GetVexNum();i++){
        //因为有头节点所以是等于0，并且原函数返回值是邻接表-1
        indegree[i]=0;
    }
    for(int i=1;i<=g.GetVexNum();i++){
        for(int v1=g.FirstAdjVex(i);v1!=-1;v1=g.NextAdjVex(i,v1)){
            //v1为i的一个邻接点
            indegree[i]++;
        }
    }
}

//template<class Type> 可以根据data值做抽象，这里为了方便直接使用string
int topsort(adjNet &g,int *output){
    int *indegree=new int[g.GetVexNum()+1];
    std::queue<int>q;
    int count=0;
    sumindegree(g,indegree);//统计入度

    for(int i=1;i<g.GetVexNum();i++){
        if(indegree[i]==0){
            q.push(i);//入度为零，进入队列
        }
    }
    while(!q.empty()){
        //队列非空
        int v1;
        v1=q.front();//得到队列第一个顶点
        q.pop();//第一个数出队
        output[count++]=v1;//输出队列获取第一个数
        //接下来对v1的所有边进行删除(仅在indegree数组中做)
        for(int v2=g.FirstAdjVex(v1);v2!=-1;v2=g.NextAdjVex(v1,v2)){
            if(--indegree[v2]==0){
                q.push(v2);//如果v2入度变为0了，就把他入队
            }
        }
    }
    delete []indegree;
    if(count<g.GetVexNum()){
        return -1;//有回路，失败
    }
    else return 1;
}

