#include<iostream>
#include<iomanip>
using namespace std;
// 枚举
// 袋子中有五色球，取三球，有多少种
enum Color
{
   red,
   yellow,
   blue,
   white,
   black
};
int main()
{
   int i, j, k, l, num = 0;
   Color col;
   for (i = red; i <= black;i++)
   {
      for (j = red; j <= black;j++)
      {
         if(i !=j)
         {
            for (k = red; k <= black;k++)
            {
               if(i!=k &&j!=k)
               {
                  cout << "\n";
                  num += 1;
                  cout << num << "\t";
                  for (l = 1; l <= 3;l++)
                  {
                     switch(l)
                     {
                        case 1:
                           col = Color(i);
                           break;
                        case 2:
                           col = Color(j);
                           break;
                        case 3:
                           col = Color(k);
                           break;
                     }
                     switch (col)
                     {
                     case red:
                        cout << "red"<<"\t";
                        break;
                     case yellow:
                        cout << "yellow"<<"\t";
                        break;
                     case blue:
                        cout << "blue"<<"\t";
                        break;
                     case white:
                        cout << "white"<<"\t";
                        break;
                     case black:
                        cout << "black"<<"\t";
                        break;
                     default:
                        break;
                     }
                  }
               }
            }
         }
      }
   }
   return 0;
}
