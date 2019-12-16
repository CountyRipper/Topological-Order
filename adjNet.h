#ifndef _ADJNET_H_
#define _ADJNET_H_

#include <vector>
#include <stddef.h>
#include <iostream>
#include <string>
//表边节点
struct edgeNode
{
    int adjnum;//表头结点序号
    //int weight;//权重
    edgeNode* nextedgeNode;//指向下一个表边节点
    edgeNode();
    edgeNode(int adjn,edgeNode* next=nullptr){
        adjnum=adjn;nextedgeNode=next;
    }
};

//表头结点
struct adjNode{
    int vex;//表头序号，代表第几个节点
    std::string sname;//课程名称
    edgeNode* nextedgeNode;//指向下一个表边节点
    adjNode(){
        vex=0;
        //nextedgeNode=nullptr;
    }//无参
    adjNode(int v,std::string str,edgeNode* next=nullptr){
        vex=v;sname=str;nextedgeNode=next;
    }
};

class adjNet{
    protected:
        int vexnum,edgenum;//顶点数，边数
        std::vector<adjNode> adjlist;//顶点表
        void Destroy(){
        };//摧毁网
        int IndexVex(std::string str){
            for(int i=0;i<adjlist.size();i++){
                if(adjlist[i].sname== str){
                    return i;
                }
            }
            return -1;
        };//定位顶点位置(通过名称)

    public:
        adjNet();//无参构造函数
        ~adjNet();//析构函数
        int GetVexNum();//获得网的结点数
        int FirstAdjVex(int v1);//返回第一个邻接点
        int NextAdjVex(int v1,int v2);//返回v1相对于v2的下一个邻接点
        //int GetWeight(int v1,int v2);//返回两点间的权值
        int InsertEdge(int v1,int v2);//在末尾插入一条边
        void InsetVex(std::string str);//添加一个顶点,仅能从末尾追加
        std::string GetVexname(int v1);//通过名称定位
};


#endif