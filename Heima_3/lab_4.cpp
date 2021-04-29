#include<iostream>
using namespace std;
#include<vector>
#include<map>

#define CEHUA 0
#define MEISHU 1
#define YANFA 2


class Worker
{
public:
    string m_Name;
    int m_Salary;
};
void createWorker(vector<Worker>&v)
{
    string nameSeed = "ABCDEFGHIJ";
    for (int i = 0; i < 10;i++)
    {
        Worker worker;
        worker.m_Name = "员工";
        worker.m_Name+=nameSeed[i];

        worker.m_Salary = rand() % 10000 + 10000;
        v.push_back(worker);
    }
}
void setGroup(vector<Worker>&v,multimap<int,Worker>&m)
{
    for (vector<Worker>::iterator it = v.begin(); it != v.end();it++)
    {
        int deptId = rand() % 3;
        m.insert(make_pair(deptId, *it));
    }
}

void showWorkerByGroup(multimap<int,Worker>&m)
{
    cout << "策划：" << endl;
    multimap<int, Worker>::iterator pos = m.find(CEHUA);
    int count = m.count(CEHUA);
    int index = 0;
    for (; pos != m.end()&&index<count;pos++,index++)
    {
        cout << "name: " << pos->second.m_Name << " salary: " << pos->second.m_Salary<<endl;
    }
}
int main()
{
    //创建员工
    vector<Worker> vWorker;
    createWorker(vWorker);

    //分组
    multimap<int, Worker> mWorker;
    setGroup(vWorker, mWorker);

    //显示员工
    showWorkerByGroup(mWorker);
    //测试
    // for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end();it++)
    // {
    //     cout << "name: " << it->m_Name << " salary: " << it->m_Salary << endl;
    // }

        system("pause");
    return 0;
}