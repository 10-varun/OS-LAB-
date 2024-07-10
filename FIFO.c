#include<stdio.h>
#include<stdlib.h>
char ch[100];
char frame[10];
int n,h=0,f=0;
int front=-1,rear=-1;

int checkframe(char c){
  for(int i=0;i<n;i++){
    if(c==frame[i])
      return 1;
  }
  return 0;
}

void enq(char c){
  if((rear+1)%n==front){
    front=(front+1)%n;
  }
  if(front==-1){
    front=0;
  }
  rear=(rear+1)%n;
  frame[rear]=c;
for(int i=0;i<n;i++)
  printf("%c   ",frame[i]);
printf("\n");
} 

void fifo(){
  int ind=0;
  while(ch[ind]!='\0'){
    if(checkframe(ch[ind])){
      h++;
    }
    else{
      f++;
      enq(ch[ind]);}
    ind++;
  }
}


void main(){
  printf("Enter charcaters:\n");
  scanf("%s",ch);
  printf("Enter no of frames:");
  scanf("%d",&n);

  fifo();
  printf("Hit %f\nFalut%f",(float)h/(float)(h+f),(float)f/(float)(h+f));

}
