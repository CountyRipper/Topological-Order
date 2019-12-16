#include <iostream>
#include "topological.h"

void createGrap(adjNet &g);

int main(int, char**) {
    std::cout<<"--------------计算机专业课程表--------------"<<std::endl;
    std::cout<<"课表清单："<<std::endl;
    std::cout<<"高等数学-I，高等数学-II<高等数学-I>,线性代数(理工),概率统计(理工)<高等数学-I>,"<<std::endl<<
                "高级语言程序设计-I,高级语言程序设计-II<高级语言程序设计-I>,数字逻辑,UNIX操作系统,计算机导论,"<<std::endl<<
                "汇编语言程序设计<数字逻辑,高级语言程序设计-I>,数据结构<高级语言程序设计-II>,"<<std::endl<<
                "离散数学<高等数学-I，高等数学-II>,计算机组成原理<汇编语言程序设计,数字逻辑>,"<<std::endl<<
                "操作系统原理<计算机组成原理,UNIX操作系统>,数据库系统原理<数据结构,操作系统原理>,计算机网络<计算机组成原理,操作系统原理>,"<<std::endl<<
                "微机接口原理技术<计算机组成原理>,计算机体系结构<计算机组成原理,微机接口原理技术>,编译原理<操作系统原理>"<<std::endl;
    adjNet graph;
    createGrap(graph);//生成课表图
    int *output = new int[graph.GetVexNum()];
    int t= topsort(graph,output);
    if(t==1){
        //拓扑排序成功
        for(int i=0;i<graph.GetVexNum();i++){
            if(graph.GetVexname(output[i])=="高等数学-II"){
                std::cout<<"大一下学期："<<std::endl;
            }
            if(graph.GetVexname(output[i])=="数据结构"){
                std::cout<<"大二上学期："<<std::endl;
            }
            if(graph.GetVexname(output[i])=="操作系统原理"){
                std::cout<<"大二下学期："<<std::endl;
            }
            if(graph.GetVexname(output[i])=="数据库系统原理"){
                std::cout<<"大三上学期："<<std::endl;
            }
            if(graph.GetVexname(output[i])=="计算机体系结构"){
                std::cout<<"大三下学期："<<std::endl;
            }
            std::cout<<graph.GetVexname(output[i]);
        }
        std::cout<<std::endl;
        std::cout<<"大四下学期："<<std::endl<<"毕业设计"<<std::endl;
    }
    else{
        //没有成功
    }
}
void createGrap(adjNet &g){
    g.InsetVex("高等数学-I");
    g.InsetVex("高等数学-II");
    g.InsertEdge(g.GetVexindex("高等数学-I"),g.GetVexindex("高等数学-II"));
    g.InsetVex("线性代数(理工)");
    g.InsetVex("概率统计(理工)");
    g.InsertEdge(g.GetVexindex("高等数学-I"),g.GetVexindex("概率统计(理工)"));
    g.InsetVex("高级语言程序设计-I");
    g.InsetVex("高级语言程序设计-II");
    g.InsertEdge(g.GetVexindex("高级语言程序设计-I"),g.GetVexindex("高级语言程序设计-II"));
    g.InsetVex("数字逻辑");
    g.InsetVex("UNIX操作系统");
    g.InsetVex("计算机导论");
    g.InsetVex("汇编语言程序设计");
    g.InsertEdge(g.GetVexindex("高级语言程序设计-I"),g.GetVexindex("汇编语言程序设计"));
    g.InsertEdge(g.GetVexindex("数字逻辑"),g.GetVexindex("汇编语言程序设计"));
    g.InsetVex("数据结构");
    g.InsertEdge(g.GetVexindex("高级语言程序设计-II"),g.GetVexindex("数据结构"));
    g.InsetVex("离散数学");
    g.InsertEdge(g.GetVexindex("高等数学-I"),g.GetVexindex("离散数学"));
    g.InsertEdge(g.GetVexindex("高等数学-II"),g.GetVexindex("离散数学"));
    g.InsetVex("计算机组成原理");
    g.InsertEdge(g.GetVexindex("数字逻辑"),g.GetVexindex("计算机组成原理"));
    g.InsertEdge(g.GetVexindex("汇编语言程序设计"),g.GetVexindex("计算机组成原理"));
    g.InsetVex("操作系统原理");
    g.InsertEdge(g.GetVexindex("UNIX操作系统"),g.GetVexindex("操作系统原理"));
    g.InsertEdge(g.GetVexindex("计算机组成原理"),g.GetVexindex("操作系统原理"));
    g.InsetVex("数据库系统原理");
    g.InsertEdge(g.GetVexindex("数据结构"),g.GetVexindex("数据库系统原理"));
    g.InsertEdge(g.GetVexindex("操作系统原理"),g.GetVexindex("数据库系统原理"));
    g.InsetVex("计算机网络");
    g.InsertEdge(g.GetVexindex("计算机组成原理"),g.GetVexindex("计算机网络"));
    g.InsertEdge(g.GetVexindex("操作系统原理"),g.GetVexindex("计算机网络"));
    g.InsetVex("微机接口原理技术");
    g.InsertEdge(g.GetVexindex("计算机组成原理"),g.GetVexindex("微机接口原理技术"));
    g.InsetVex("计算机体系结构");
    g.InsertEdge(g.GetVexindex("计算机组成原理"),g.GetVexindex("计算机体系结构"));
    g.InsertEdge(g.GetVexindex("微机接口原理技术"),g.GetVexindex("计算机体系结构"));
    g.InsetVex("编译原理");
    g.InsertEdge(g.GetVexindex("计算机体系结构"),g.GetVexindex("编译原理"));
}