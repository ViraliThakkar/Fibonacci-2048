#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
using namespace std;
time_t t;
class fibonacci
{
protected:
    int a[20];
public:
    fibonacci()
    {
        a[0]=1;
        a[1]=1;
    }
    void create()
    {
        for(int i=2;i<20;i++)
        {
            a[i]=a[i-1]+a[i-2];
        }
    }
    int check(int p,int q)
    {
        int i=1;
        //cout<<p<<" "<<q<<endl;
        while(i<20)
        {
            if(a[i]==p)
            {
                if(a[i-1]==q||a[i+1]==q)
                    return 1;
                    break;
            }
            else if(a[i]==q)
            {
                if(a[i-1]==p||a[i+1]==p)
                    return 1;
                    break;
            }
            else if(p==0||q==0)
            {
                return 1;
                break;
            }
            else if(i>20)
            {
                    return 0;
                    break;
            }
            else
                i++;
        }
    }

};

class random
{
protected:
    int i,j,k;
public:
    random(){}
    //time_t t;
    //srand((unsigned)time(&t));
    void generate1()
    {
        i=rand()%4;
        j=rand()%4;
    }
    void generate2()
    {
        k=rand()%3;
        while(k==0)
            k=rand()%3;
    }
};
class matrix:public random
{
protected:
    int v[4][4];
    int t;
public:
    matrix()
    {
        for(int m=0;m<4;m++)
        {
            for(int n=0;n<4;n++)
                v[m][n]=0;
        }
    }
    void check1()
    {
        generate1();
        while(v[i][j]!=0)
        generate1();
    }
    void assign1()
    {
        generate2();
        t=k;
     v[i][j]=t;
    }
    int overflow()
    {
        t=1;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(v[i][j]==0)
                    t=0;
                    break;
            }
        }
        return t;
    }
};

class fibo_matrix:public fibonacci,public matrix
{
    int ch=0,a,b;
public:
    fibo_matrix(){}
    void display()
    {
        for(int m=0;m<4;m++)
        {
            for(int n=0;n<4;n++)
                if(v[m][n]==0)
                cout<<"_  ";
            else
            cout<<v[m][n]<<"  ";
            cout<<endl<<endl;
        }
    }
    void play()
    {
        int m1,m2;
        create();
        int cnt=0,flag=1;
        abc:
            while(ch!=13)
            {
            check1();
            assign1();

            cout<<cnt<<" "<<flag<<endl;
            display();

        cout<<"press key:";
        getch();
        ch=getch();
        cout<<ch;
        flag=0;
        cnt=0;
            if(ch==77)
            {
                flag=0;
                int r,m;
                {
                    for(int n=0;n<4;n++)
                    {
                        m=3;m1=m;
                        while(m>0)
                        {
                            //cnt=0;
                            a=v[n][m];

                            m1=m-1;
                            while(v[n][m1]==0&&m1>0)
                            {
                                m1--;
                            }
                            b=v[n][m1];
                        r=check(a,b);
                        cout<<r<<endl;
                        if(r==1&&v[n][m]!=0&&v[n][m1]!=0)
                        {
                            v[n][m]+=v[n][m1];
                            v[n][m1]=0;
                            m-=2;
                        }
                        else if(r==1&&v[n][m]==0&&v[n][m1]!=0)
                        {
                            v[n][m]=v[n][m1];
                            v[n][m1]=0;
                            m--;
                        }
                        else if(r==1&&v[n][m]==0&&v[n][m1]==0)
                        {
                            m--;
                        }
                        else{
                        m--;cnt++;}
                        }
                        //if(cnt>=12)
                            //flag=0;
                        for(int cnt1=0;cnt1<3;cnt1++)
                        {
                        m1=0;

                            while(m1<3)
                            {
                                m1++;
                                if(v[n][m1]==0)
                                {
                                    v[n][m1]=v[n][m1-1];
                                    v[n][m1-1]=0;
                                }
                            }
                        }

                 }   }

                cout<<endl;
                system("cls");
        }

        else if(ch==75)
            {
                flag=0;
                int r,m;
                {
                    for(int n=0;n<4;n++)
                    {
                        m=0;m1=m;
                        while(m<3)
                        {
                            a=v[n][m];

                            m1=m+1;
                            while(v[n][m1]==0&&m1<3)
                            {
                                m1++;
                            }
                            b=v[n][m1];
                        r=check(a,b);
                        cout<<r<<endl;
                        if(r==1&&v[n][m]!=0&&v[n][m1]!=0)
                        {
                            v[n][m]+=v[n][m1];
                            v[n][m1]=0;
                            m+=2;
                        }
                        else if(r==1&&v[n][m]==0&&v[n][m1]!=0)
                        {
                            v[n][m]=v[n][m1];
                            v[n][m1]=0;
                            m++;
                        }
                        else if(r==1&&v[n][m]==0&&v[n][m1]==0)
                        {
                            m++;
                        }
                        else {
                        m++;cnt++;}
                        }
                        //if(cnt>=12)
                          //  flag=0;
                        for(int cnt1=0;cnt1<3;cnt1++)
                        {
                        m1=3;

                            while(m1>0)
                            {
                                m1--;
                                if(v[n][m1]==0)
                                {
                                    v[n][m1]=v[n][m1+1];
                                    v[n][m1+1]=0;
                                }
                            }
                        }

                 }   }

                cout<<endl;
                system("cls");
        }





        else if(ch==72)
            {
                flag=0;
                int r,m;
                {
                    for(int n=0;n<4;n++)
                    {
                        m=0;m1=m;
                        while(m<3)
                        {
                            a=v[m][n];

                            m1=m+1;
                            while(v[m1][n]==0&&m1<3)
                            {
                                m1++;
                            }
                            b=v[m1][n];
                        r=check(a,b);
                        cout<<r<<endl;
                        if(r==1&&v[m][n]!=0&&v[m1][n]!=0)
                        {
                            v[m][n]+=v[m1][n];
                            v[m1][n]=0;
                            m+=2;
                        }
                        else if(r==1&&v[m][n]==0&&v[m1][n]!=0)
                        {
                            v[m][n]=v[m1][n];
                            v[m1][n]=0;
                            m++;
                        }
                        else if(r==1&&v[m][n]==0&&v[m1][n]==0)
                        {
                            m++;
                        }
                        else {
                        m++;cnt++;}
                        }
                        //if(cnt>=12)
                          //  flag=0;
                        for(int cnt1=0;cnt1<3;cnt1++)
                        {
                        m1=3;

                            while(m1>0)
                            {
                                m1--;
                                if(v[m1][n]==0)
                                {
                                    v[m1][n]=v[m1+1][n];
                                    v[m1+1][n]=0;
                                }
                            }
                        }

                 }   }

                cout<<endl;
                system("cls");
        }




        if(ch==80)
            {
                flag=0;
                int r,m;
                {
                    for(int n=0;n<4;n++)
                    {
                        m=3;m1=m;
                        while(m>0)
                        {
                            a=v[m][n];

                            m1=m-1;
                            while(v[m1][n]==0&&m1>0)
                            {
                                m1--;
                            }
                            b=v[m1][n];
                        r=check(a,b);
                        cout<<r<<endl;
                        if(r==1&&v[m][n]!=0&&v[m1][n]!=0)
                        {
                            v[m][n]+=v[m1][n];
                            v[m1][n]=0;
                            m-=2;
                        }
                        else if(r==1&&v[m][n]==0&&v[m1][n]!=0)
                        {
                            v[m][n]=v[m1][n];
                            v[m1][n]=0;
                            m--;
                        }
                        else if(r==1&&v[m][n]==0&&v[m1][n]==0)
                        {
                            m--;
                        }
                        else {
                        m--;cnt++;}
                        }
                       // if(cnt>=12)
                         //   flag=0;

                       for(int cnt1=0;cnt1<3;cnt1++)
                        {
                        m1=0;

                            while(m1<3)
                            {
                                m1++;
                                if(v[m1][n]==0)
                                {
                                    v[m1][n]=v[m1-1][n];
                                    v[m1-1][n]=0;
                                }
                            }
                        }

                 }   }

                cout<<endl;
                cout<<cnt<<" "<<flag<<endl;
                system("cls");
        }
        }
        cout<<"GAME OVER "<<cnt<<" "<<flag;
    }

};
int main()
{
    int r;
    fibo_matrix f;
    //f.check1();
    //f.assign1();
    //f.display();
    f.play();
    cout << "Hello world!" << endl;
    return 0;
}

