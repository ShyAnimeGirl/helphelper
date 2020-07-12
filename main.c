#include <stdio.h>

FILE *help;
char printhead[9] = {'p','r','i','n','t','f','(','"',0};
char printend[6] = {'"',')',';',0xD,0xA,0};
int main (int argc, const char * argv[]) {
	int i;
	char buffer[105];
    help = fopen("./help.txt","a"); //opens in append mode
    printf("Welcome to Help Helper. 80chars per line plz\n");
	while(1 == 1){
		fgets(buffer, 102, stdin);
		for(i=0;i<105;i++){
			if(buffer[i] == 0xA){
				buffer[i] = 92;
				buffer[i + 1] = 'n';
				buffer[i + 2] = 0;
			}
			else;
		}
		fprintf(help, "%s", printhead);
		fprintf(help, "%s", buffer);
		fprintf(help, "%s", printend);
		fclose(help);
		help = fopen("./help.txt","a");
	}
    return 0;
}
