#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<Windows.h>

int x=30,y=19;
int leny=20,lenx=60;
char a='-',b='|',c='*',d='-';
int blockx,blocky;
int gameover=0,key;
int score=0,count=0,num=0,time,speed;

void boundary1(){
	
	system("cls");
	for (int i=1;i<=lenx;i++){
			printf("%c",a);
		}
		printf("\n");

	for (int z=1;z<=leny-2;z++){
	   for (int j=1;j<=lenx;j++ ){
		if (j==1|| j==lenx){
		printf("%c",b);
		}
		else if(j==blockx && z==blocky){
			printf("%c",c);
		}
		else if((j==x-1 || j==x ||j==x+1 )&& z==y-1){
			printf("%c",d);
		}
		else {
			printf(" ");
		}
	   }
		printf("\n");
	}
	
	for (int i=1;i<=lenx;i++){
			printf("%c",a);
		}
		printf("\n");
		
			printf("Score=%d",score);
				printf("\n%s","Press X to exist.");
				blocky++;

}

void boundary2(){
	
	system("cls");
	for (int i=1;i<=lenx;i++){
			printf("%c",a);
		}
		printf("\n");

	for (int z=1;z<=leny-2;z++){
	   for (int j=1;j<=lenx;j++ ){
		if (j==1|| j==lenx){
			printf("%c",b);
		}
		else if(j==blockx && z==blocky){
			printf("%c",c);
		}
		else if((j==x-1 || j==x ||j==x+1 )&& z==y-1){
			printf("%c",d);
		}
		else {
			printf(" ");
		}
	   }
		printf("\n");
	}
	
	for (int i=1;i<=lenx;i++){
			printf("%c",a);
		}
		printf("\n");
		
			printf("Score=%d",score);
				printf("\n%s","Press X to exist.");
				blocky++;
                num=count%9;
				switch(num){
					case 0:blockx++;
						break;
					case 1:blockx--;
					    break;
					case 2:blockx++;
						break;
					case 3:blockx++;
						break;
					case 4:blockx++;
						break;
					case 5:blockx--;
					    break;
					case 6:blockx--;
					    break;
					case 7:blockx--;
					    break;
					case 8:blockx--;
					    break;
					default : blockx=blockx;
						break;
				}	   
				 count ++ ;

}

void block(){
  	blockx=rand()%lenx;
  	blocky=1;
	if (blockx==1 || blockx==60){
	blockx=10;
	}
}

void input(){
	if(kbhit()){
        switch (getch()) {
	
		case 'a': key=1;
		       break;
		case 'd': key=2;
			 break;
		case 'x': gameover=1;
			break;
		default :key=5;
			break;
	    }
	} 
}

void logic(){
	switch(speed){
		case 1:time=50;
		break;
		case 2:time=10;
		 break;
		case 3:time=0;
		 break;
	}
	Sleep(time);
	switch(key){
		case 1:if(x>5 && x<=58) x-=3;
		break;
		case 2:if(x>=3 && x<56) x+=3;
		break;
		default:x=x;
		break;
	}
	
    if( blocky==20){
	gameover=1;
     }
	if(x==3){
		x=3;
	 }
    if(x==58 ){
		x=58;
	 }
	if ((blockx==x-1 || blockx==x || blockx==x+1) && blocky==y-1 ){
	score+=10;
	block();
	}

}
 
int main (){
	int game;
	printf("                                          CATCH THE BALL GAME            \n");
	printf("\n");
	printf("Rule:Catch the ball within the boundary.\n");
	printf("\n");
	printf("Press A for left movement,D for right movement and any random key to stop the movement.\n");
	printf("\n");
	for (int i=0;i<100;i++){
	printf("Enter Game level(1 for Easy & 2 for Difficult):");
	scanf("%d",&game);
	printf("Enter Speed(1 for Low,2 for Medium and 3 for High):");
	scanf("%d",&speed);
    	if (game ==1){
			block();
			while (gameover==0){
    			boundary1();
				input();
				logic();
			}
		score=0;
		x=30,y=19;	
		printf("\n");
		gameover=0;
		}
		else if (game==2){
			block();
			while (gameover==0){
    			boundary2();
				input();
				logic();
			}
		score =0;	
		x=30,y=19;	
		printf("\n");
		gameover=0;
		}
	}
	return 0;
}