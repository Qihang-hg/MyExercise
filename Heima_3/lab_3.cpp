#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<deque>
#include<algorithm>

/*
有五名选手ABCDE，10个评委对每名选手打分，去掉最高分，去掉最低分，取平均分。
*/
class Person
{
public:
    Person(string name,int score)
    {
        this->m_Name = name;
        this->m_Sorce = score;
    }

    string m_Name;
    int m_Sorce;
};

void createPerson(vector<Person>&v)
{
    string nameSeed = "ABCDE";
    for (int i = 0; i < 5;i++)
    {
        string name = "选手";
        name += nameSeed[i];

        int score = 0;
        Person p(name, score);
        v.push_back(p);

    }   

}

void setScore(vector<Person>&v)
{
    for (vector<Person>::iterator it = v.begin(); it != v.end();it++)
    {
        //将评委分数放入deque容器
        deque<int>d;
        for (int i = 0; i < 10;i++)
        {
            int score = rand()%41+60; //60~100
            d.push_back(score);
        }
        cout << "选手： " << it->m_Name << "    分数：" << endl;
        for (deque<int>::iterator dit = d.begin(); dit != d.end();dit++)
        {
            cout << *dit << " ";
        }
        cout << endl;
        //排序
        sort(d.begin(), d.end());
        d.pop_back();
        d.pop_front();
        //平均分
        int sum = 0;
        for (deque<int>::iterator dit = d.begin(); dit != d.end();dit++)
        {
            sum += *dit;
        }
        int avg = sum / d.size();
        //将平均分赋值给选手
        it->m_Sorce = avg;
    }
}

void showScore(vector<Person>&v)
{
    for (vector<Person>::iterator it = v.begin(); it != v.end();it++)
    {
        cout << "name: " << it->m_Name << "平均分：" << it->m_Sorce << endl;
    }
}
int main()
{
    //create persons
    vector<Person> v;
    createPerson(v);
    //打分
    setScore(v);
    //显示最后得分
    showScore(v);
    system("pause");
    return 0;
}