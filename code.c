#include <stdlib.h> 
#include <stdio.h>
#include <string.h>

typedef struct action{
	int dimstato;
	char ** testostato;
}azione;

char str[1025]="";
azione * storia;
char ** testo;
char istruzione[20]="";
int riga1;
int riga2;
char car1;
char car2;
int dimtesto=0;
int dimstoria=0;
int undo=0;
int redo=0;
int switchh=0;
int storiaswitch=-100;

void C();
void P();
void D();
void UR();
void annullaredo();

int main(){
	storia=(azione*) malloc(sizeof(azione));
	testo=(char**) malloc(sizeof(char*));
	fgets(istruzione,20,stdin);
	while(istruzione[0]!='q'){
		sscanf(istruzione,"%d%c%d%c",&riga1,&car1,&riga2,&car2);
		switch(car1){
			case 'u':
				UR();
				break;
			case 'r':
				UR();		
				break;
			case ',':
				switch(car2){
					case 'c':
						if(redo>0){
							annullaredo();
						}
						C();
						undo++;
						break;
					case 'd':
						if(redo>0){
							annullaredo();
						}
						D();
						undo++;					
						break;
					case 'p':
						P();
						break;	
				}
				fgets(istruzione,20,stdin);	
				break;		
		}			
	}
}
////////COPY////////COPY////////COPY////////COPY////////COPY////////COPY////////COPY////////COPY////////COPY////////COPY////////COPY////////COPY////////COPY////////COPY////////COPY////////COPY////////COPY////////COPY////////COPY////////COPY////////COPY////////COPY////////COPY////////COPY
void C(){
	int i;
	int len;
	if(riga1>0&&riga1<=dimtesto+1){
		if(riga1==dimtesto+1&&switchh==0){
			dimstoria=dimstoria+1;
			storia=(azione *) realloc(storia,dimstoria*sizeof(azione));
			dimtesto=dimtesto+(riga2-riga1+1);
			storia[dimstoria-1].dimstato=dimtesto;
			testo=(char **) realloc(testo,dimtesto*sizeof(char*));
			storia[dimstoria-1].testostato=(char **) malloc((riga2-riga1+1)*sizeof(char*));
			for(i=0;i<riga2-riga1+1;i++){
				gets(str);
				testo[riga1-1+i]=(char *) malloc((strlen(str)+2)*sizeof(char));
				strcpy(testo[riga1-1+i],str);
				storia[dimstoria-1].testostato[i]=testo[riga1-1+i];
			}
			getchar();
			getchar();
			return;
		}
		if(switchh==0){
			switchh=1;
			storiaswitch=dimstoria-1;
		}		
		dimstoria=dimstoria+1;
		storia=(azione *) realloc(storia,dimstoria*sizeof(azione));
		if(riga2>dimtesto){
			dimtesto=riga2;
		}
		testo=realloc(testo,dimtesto*sizeof(char**));
		storia[dimstoria-1].dimstato=dimtesto;
		storia[dimstoria-1].testostato=(char**) malloc(dimtesto*sizeof(char*));
		for(i=riga1-1;i<=riga2-1;i++){
			gets(str);
			testo[i]=(char *) malloc((strlen(str)+2)*sizeof(char));
			strcpy(testo[i],str);
		}
		for(i=0;i<dimtesto;i++){
			storia[dimstoria-1].testostato[i]=testo[i];
		}
	}
	else{
		printf("C con riga1 che non rispetta i parametri");
	}
	getchar();//questi due getchar dovrebbero consumare il punto e il \n successivi alle righe.
	getchar();
}
/////////PRINT/////////PRINT/////////PRINT/////////PRINT/////////PRINT/////////PRINT/////////PRINT/////////PRINT/////////PRINT/////////PRINT/////////PRINT/////////PRINT/////////PRINT/////////PRINT/////////PRINT
void P(){
	int i;
	if(riga1>0&&riga2<=dimtesto){
		for(i=riga1-1;i<=riga2-1;i++){
			printf("%s\n",testo[i]);
		}
		return;
	}
	if(riga1<1&&riga2<1){
		for(i=0;i<-riga1+riga2+1;i++){
			printf(".\n");
		}
		return;
	}
	if(riga1<=0&&riga2>=1){
		for(i=0;i>=riga1;i--){
			printf(".\n");
		}
		if(riga2>dimtesto){
			for(i=0;i<=dimtesto-1;i++){
				printf("%s\n",testo[i]);
			}
			for(i=0;i<riga2-dimtesto;i++){
				printf(".\n");
			}
		}
		else{
			for(i=0;i<=riga2-1;i++){
				printf("%s\n",testo[i]);
			}
		}
		return;
	}
	if(riga1>0&&riga2>dimtesto){
		if(riga1>dimtesto){
			for(i=riga1-1;i<=riga2-1;i++){
				printf(".\n");
			}
			return;
		}
		else{
			for(i=riga1-1;i<=dimtesto-1;i++){
				printf("%s\n",testo[i]);
			}
			for(i=0;i<riga2-dimtesto;i++){
				printf(".\n");
			}
			return;
		}
	}
}
//////////DELETE////////////DELETE////////////DELETE////////////DELETE////////////DELETE////////////DELETE////////////DELETE////////////DELETE////////////DELETE////////////DELETE////////////
void D(){
	int i;
	int ii;
	int len;
	if(switchh==0){
		switchh=1;
		storiaswitch=dimstoria-1;
	}
	if(riga2<1||riga1>dimtesto||dimtesto==0){//ultima condizione aggiunta ora;
		dimstoria=dimstoria+1;
		storia=(azione *) realloc(storia,dimstoria*sizeof(azione));
		storia[dimstoria-1].dimstato=dimtesto;
		if(dimtesto!=0){
			storia[dimstoria-1].testostato=(char**) malloc(dimtesto*sizeof(char*));
			for(i=0;i<dimtesto;i++){
				storia[dimstoria-1].testostato[i]=testo[i];
			}
		}
		else{
			storia[dimstoria-1].testostato=(char**) malloc(sizeof(char*));
		}
		
		return;
	}
	else{
		if(riga1<1){
			riga1=1;
		}
		if(riga2>dimtesto){
			riga2=dimtesto;
		}
		if(riga2==dimtesto){
			dimtesto=riga1-1;
			if(riga1==1){
				testo=(char **) realloc(testo,sizeof(char*));
			}
			else{
				testo=(char **) realloc(testo,dimtesto*sizeof(char*));
			}
		}
		else{
			ii=0;
			for(i=riga2;i<dimtesto;i++){
				testo[riga1-1+ii]=testo[i];
				ii++;
			}
			dimtesto=dimtesto-(riga2-riga1+1);
			testo=(char **) realloc(testo,dimtesto*sizeof(char*));
		}
		dimstoria=dimstoria+1;
		storia=(azione *) realloc(storia,dimstoria*sizeof(azione));
		storia[dimstoria-1].dimstato=dimtesto;
		if(dimtesto!=0){
			storia[dimstoria-1].testostato=(char**) malloc(dimtesto*sizeof(char*));
			for(i=0;i<dimtesto;i++){
				storia[dimstoria-1].testostato[i]=testo[i];
			}
		}
		else{
			storia[dimstoria-1].testostato=(char**) malloc(sizeof(char*));
		}
	}
}
///////////UNDO-REDO///////////UNDO-REDO///////////UNDO-REDO///////////UNDO-REDO///////////UNDO-REDO///////////UNDO-REDO///////////UNDO-REDO///////////
void UR(){
	int prevundo=undo;
	int prevredo=redo;
	int i;
	int ii;
	int iii;
	while(istruzione[0]!='q'&&car1!=','){
		if(car1=='u'){
			if(riga1<=undo){
				undo=undo-riga1;
				redo=redo+riga1;
			}
			else{
				redo=redo+undo;
				undo=0;
			}
		}
		if(car1=='r'){	
			if(riga1<=redo){
				redo=redo-riga1;
				undo=undo+riga1;
			}
			else{
				undo=undo + redo;
				redo=0;
			}
		}
		fgets(istruzione,20,stdin);	
		sscanf(istruzione,"%d%c%",&riga1,&car1);
	}
	if(istruzione[0]=='q'){
		return;
	}
	if(prevundo!=undo&&prevredo!=redo){
		if(undo==0){
			dimtesto=0;
			testo=(char **) realloc(testo,sizeof(char*));
			return;
		}
		if(switchh==0||undo-1<=storiaswitch){
			ii=0;
			for(i=0;i<=undo-1;i++){
				dimtesto=storia[undo-1].dimstato;
				testo=(char **) realloc(testo,dimtesto*sizeof(char*));
				iii=0;
				if(i==0){
					while(iii<storia[i].dimstato){
						testo[ii]=storia[i].testostato[iii];
						iii++;
						ii++;
					}
				}
				else{
					while(iii<storia[i].dimstato-storia[i-1].dimstato){
						testo[ii]=storia[i].testostato[iii];
						iii++;
						ii++;
					}
				}	
			}
			return;
		}
		dimtesto=storia[undo-1].dimstato;
		testo=(char **) realloc(testo,dimtesto*sizeof(char*));
		for(i=0;i<dimtesto;i++){
			testo[i]=storia[undo-1].testostato[i];
		}
	}	
}
void annullaredo(){
	dimstoria=undo;
	redo=0;
	if(switchh!=0&&undo-1<=storiaswitch){
		switchh=0;
	}
	if(dimstoria!=0){
	storia=(azione*) realloc(storia,dimstoria*sizeof(azione));
	}
	else{
		storia=(azione*) realloc(storia,sizeof(azione));
	}
}
