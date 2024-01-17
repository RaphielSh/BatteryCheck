#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
chdir("/sys/class/power_supply/BAT0/");

int batfull, batnow, fin;

char *bfull = "charge_full";
char *bnow = "charge_now";
	
//File open
FILE* fp = fopen(bfull, "r");
FILE* fp2 = fopen(bnow, "r");
	
//Check if it opened
if (NULL == fp || NULL == fp2){
	printf("Something went wrong\n");
	return 1;
}
//Fill array
fscanf(fp, "%d", &batfull);
fscanf(fp2, "%d", &batnow);

fin = (batnow * 100) / batfull;

//Print an array
printf("%d%%\n", fin);
	
//File close
fclose(fp);
fclose(fp2);

return 0;
}
