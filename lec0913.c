#include <stdio.h>
#include <math.h>

void p1();
void p2();
float find_max(float num1,float num2,float num3);
float find_min(float num1,float num2,float num3);
void p3();
void get_data(float* num,int* seq);
void calc_average(float* num,int* seq, double* average);
void calc_stdev(float* num,int* seq, double* average,double* variance);

int main(){
    //p1();
    //p2();
    p3();

    return 0;
}

/* first problem : self-introduction */
void p1(){
    char major[20],name[20];
    int grade,year;

    printf("학과 : ");
    scanf("%s",major);

    printf("학년 : ");
    scanf("%d",&grade);

    printf("입학년도 : ");
    scanf("%d",&year);

    printf("이름 : ");
    scanf("%s",name);

    printf("나는 %s %d학년 %d학번 %s입니다.\n\n",major,grade,year,name);
}

/* second problem : difference beteween max and min */
void p2(){
    float num1,num2,num3;
    float difference, max, min;
    printf("number 1 : ");
    scanf("%f",&num1);

    printf("number 2 : ");
    scanf("%f",&num2);

    printf("number 3 : ");
    scanf("%f",&num3);

    max=find_max(num1,num2,num3);
    min=find_min(num1,num2,num3);
    difference=max-min;

    printf("\n가장 큰 수와 작은 수의 차이 = %f \n\n",difference);
}

float find_max(float num1,float num2,float num3){
    float max=num1;
    if(num2>max) max=num2;
    if(num3>max) max=num3;

    return max;
}

float find_min(float num1,float num2,float num3){
    float min=num1;
    if(num2<min) min=num2;
    if(num3<min) min=num3;
    
     return min;
}

/* third problem : get mean-number and vairance-number */

void p3(){
    double average,stdev;
    float num[10];
    int seq=0;

    get_data(num,&seq);
    calc_average(num,&seq,&average);
    calc_stdev(num,&seq,&average,&stdev);

}

void get_data(float* num,int* seq){
    printf("최대 10개의 실수를 입력하세요.\n");
    printf("입력을 취소하려면, 0이하의 수를 입력하세요\n\n");
    while(*seq<10){
        printf("number #%d : ",(*seq)+1);
        scanf("%f",&num[*seq]);
        if(num[*seq]>0.0) (*seq)++;
        else return;
    }
}

void calc_average(float* num,int* seq, double* average){
    for(int i=0;i<(*seq);i++){
        (*average)+=num[i];
    }
    (*average)/=(*seq);
    printf("평균 : %.2lf\n",*average);
}

void calc_stdev(float* num,int* seq, double* average,double* stdev){
    float element=0.0;
    float variance=0.0;
    for(int i=0;i<(*seq);i++){
        element=num[i]-(*average);
        variance+=(element*element);
    }
    variance/=(*seq);
    *stdev=sqrt(variance);
    printf("표준 편차 : %lf\n",*stdev);
}