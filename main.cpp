#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
using namespace std;
int *TOWER1=new int[15];
int *TOWER2=new int[15];
int *TOWER3=new int[15];
int n;
int counter=0;
void def_tower1(int nx){
    if ((nx>15)||(nx<0)) return;
    int i=0;
    for(i=0;i<15-nx;i++){
        TOWER1[i]=0;
        TOWER2[i]=0;
        TOWER3[i]=0;
    }
    int x=1;
    for(i=15-nx;i<15;i++){
        TOWER1[i]=x;
        TOWER2[i]=0;
        TOWER3[i]=0;
        x++;
    }
}
void print_Current(){
    int i;
    printf("\n\n\n\n\n");
    for (i=0;i<15;i++)
    {
        int j=1;
        for(j=1;j<13;j++) putchar(32);
        j=1;
        for(j=1;j<=92;j++){
            if(j<=15-TOWER1[i]) putchar(32);
            if((j>15-TOWER1[i])&&(j<=16+TOWER1[i])) {if (TOWER1[i]==0) putchar(124);
                                                        else putchar(61);}
            if((j>=17+TOWER1[i])&&(j<=32)) putchar(32);
            if((j<=47-TOWER2[i])&&(j>=33)) putchar(32);
            if((j>47-TOWER2[i])&&(j<=48+TOWER2[i])) {if (TOWER2[i]==0) putchar(124);
                                                        else putchar(61);}
            if((j<=64)&&(j>48+TOWER2[i])) putchar(32);
            if((j>=65)&&(j<=79-TOWER3[i])) putchar(32);
            if((j>79-TOWER3[i])&&(j<=80+TOWER3[i])) {if(TOWER3[i]==0) putchar(124);
                                                    else putchar(61);}
            if((j<=95)&&(j>80+TOWER3[i])) putchar(32);
        }
        printf("\n");
    }
}
int p1(){
    int i=0;
    while((TOWER1[i]==0)&&(i<15)){
    i++;
    }
    return i;
}
int p2(){
    int i=0;
    while((TOWER2[i]==0)&&(i<15)){
    i++;
    }
    return i;
}
int p3(){
    int i=0;
    while((TOWER3[i]==0)&&(i<15)){
    i++;
    }
    return i;
}
void button_1_to_2(){
    if((TOWER1[p1()]>TOWER2[p2()])&&(TOWER2[p2()]>0) )printf("error");
    else{int temp=TOWER1[p1()];
    TOWER1[p1()]=0;
    TOWER2[p2()-1]=temp;}
}
void button_2_to_1(){
    if((TOWER2[p2()]>TOWER1[p1()])&&(TOWER1[p1()]>0) )printf("error");
    else{int temp=TOWER2[p2()];
    TOWER2[p2()]=0;
    TOWER1[p1()-1]=temp;}
}
void button_1_to_3(){
    if((TOWER1[p1()]>TOWER3[p3()])&&(TOWER3[p3()]>0) )printf("error");
    else{int temp=TOWER1[p1()];
    TOWER1[p1()]=0;
    TOWER3[p3()-1]=temp;}
}
void button_3_to_1(){
    if((TOWER3[p3()]>TOWER1[p1()])&&(TOWER1[p1()]>0) )printf("error");
    else{int temp=TOWER3[p3()];
    TOWER3[p3()]=0;
    TOWER1[p1()-1]=temp;}
}
void button_3_to_2(){
    if((TOWER3[p3()]>TOWER2[p2()])&&(TOWER2[p2()]>0) )printf("error");
    else{int temp=TOWER3[p3()];
    TOWER3[p3()]=0;
    TOWER2[p2()-1]=temp;}
}
void button_2_to_3(){
    if((TOWER2[p2()]>TOWER3[p3()])&&(TOWER3[p3()]>0) )printf("error");
    else{int temp=TOWER2[p2()];
    TOWER2[p2()]=0;
    TOWER3[p3()-1]=temp;}
}
void number_rings(){
     while(1){
    printf("enter number of rings(1..15)\n>>");
    string st;
    //gets(st);
    //fgets(st, 100, cin);
    cin>>st;
    if (st.size()>2){system("clear"); continue;}
    if (st.size()==1){
        if ((st[0]>=48)&&(st[0]<=57)) n=st[0]-48;
        else {system("clear");continue;}
    }
    if (st.size()==2){
        if (st[0]!=49) {system("clear");continue;}
        if ((st[1]<48)||(st[1]>53)){system("clear");continue;}
        n=10+(st[1]-48);
    }
    system("clear");
    if ((n>15)||(n<=0)) continue;
    if ((n>0)&&(n<=15)){
            def_tower1(n);
            break;}
    }
}
void Move(int from, int to){
    if ((from>3)||(from<1)) return;
    if ((to>3)||(to<1)) return;
    if (from==to) return;
    if ((from==1)&&(to==2)) button_1_to_2();
    if ((from==1)&&(to==3)) button_1_to_3();
    if ((from==2)&&(to==1)) button_2_to_1();
    if ((from==2)&&(to==3)) button_2_to_3();
    if ((from==3)&&(to==1)) button_3_to_1();
    if ((from==3)&&(to==2)) button_3_to_2();
    counter++;
}

void Solution(int quantity, int from, int to, int buf_peg)
{
	if (quantity > 0)
	{
		Solution(quantity-1, from, buf_peg, to);
        Move(from,to);
        print_Current();
        cout <<" "<<from<< ">>" << to << endl;
        cout <<" moves:"<<counter<<endl;
        //Sleep(1000);
	system("sleep 0.1s");
        system("clear");
		Solution(quantity-1, buf_peg, to, from);
	}
}
void Single_Play(){
    int f,t;
    while (p3()!=15-n){
                print_Current();
                cout<<" moves: "<<counter<<endl;
                printf(" Enter your command (example: 1>>3) - from first to third tower\n Or enter command zero-command (example 0>>0) to exit to main menu\n");
                string st;
                //gets(st);
                cin>>st;
		if (st.size()!=4) {system("clear");continue;}
                if ((st[1]!=62)||(st[2]!=62)) {system("clear");continue;}
                if ((st[0]<48)||(st[0]>51)) {system("clear");continue;}
                if ((st[3]<48)||(st[3]>51)) {system("clear");continue;}
                f=st[0]-48;
                t=st[3]-48;
                if ((f==0)||(t==0)) {system("clear");break;}
                Move(f,t);
                system("clear");
                }
    print_Current();
    if (p3()==15-n) {printf("YOU ARE THE WINNER!\n");
    system("pause");}
    system("clear");
    print_Current();
}
void choose_game_mode(){
    while(1){
        printf("Press keys(1..4) to ...\n 1.Single play\n 2.Demonstration \n 3.Back \n 4.Exit \n >>");
        int b=0;
        char c =getchar();
	if (c==49) b=1;
        if (c==50) b=2;
        if (c==51) b=3;
        if (c==52) b=4;
        system("clear");

        if(b==1){
            counter=0;
            Single_Play();
            def_tower1(n);
            system("clear");
            choose_game_mode();
            break;
        }
        if(b==2){
            counter=0;
            Solution(n,1,3,2);
            print_Current();
            printf("YOU ARE THE WINNER!\n");
            system("pause");
            system("clear");
            def_tower1(n);
            choose_game_mode();
            break;
            }
        if (b==3){
            number_rings();
            choose_game_mode();
        }
        if (b==4) break;
        if(((b!=1)&&(b!=4))&&((b!=2)&&(b!=3))) continue;
    }
}
int main(){
    //HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
    system("title HANOI TOWER");//смена заголовка
    system("color A0");
    number_rings();
    choose_game_mode();
    return 0;
}
