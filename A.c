
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include <stdbool.h>
#include<windows.h>
struct d{
    char pl[1000];
    int scr;
}temp;
char convertInt(int a){
    int h;
    int f = a;
    int c = 0;
    int *s;
    c = (a == 0) ? 1 : (log10(a) + 1);
    s = (int*)malloc(c);
    for (int i = 0; i<c; i++){
        h = f % 10;
        f = f / 10;
        s[i] = h;
    }
    int*t;
    t = (int*)malloc(c);
    for (int i = 0; i< c; i++){
        t[i] = s[(c - 1) - i];


    }
    char p[100];
   
    for (int i = 0; i< c; i++){
        p[i] = (char)(t[i] + 48);
    }

    printf("%s\n", p);

}

int lineCount(){
    FILE *f = fopen("i.txt", "r");
    char us[1000];
    int g;
    int count = 0;
    for (; !feof(f);) {
        fscanf(f, "%s %d", us, &g);
        count++;
        if (feof(f)) {
            break;
        }
    }
    return count;
}

void rankScore(){
    int k = lineCount();
    
    struct d *x;
    x = (struct d *)malloc(k * sizeof(struct d));
    FILE *a = fopen("i.txt", "r+");

    for (int i = 0; i<k; i++) {
        fscanf(a, "%s %d", x[i].pl, &x[i].scr);
    }
    fclose(a);
    char z[1000];
    for (int i = 0; i<k; i++) {
        for (int j = i + 1; j < k; j++) {
            if (x[i].scr < x[j].scr) {
                int temp = x[i].scr;
                x[i].scr = x[j].scr;
                x[j].scr = temp;
                strcpy(z,x[i].pl);
                strcpy(x[i].pl,x[j].pl);
                strcpy(x[j].pl,z);
            }
        }
    }
    FILE *n = fopen("i.txt", "w+");


    for (int i = 0; i < k-1; i++) {
        fprintf(n, "%s\t", x[i].pl);
        fprintf(n, "%d\n", x[i].scr);

    }
    free(x);
    fclose(n);
}


void setHigh(char* player, long int scr) {
    int u;
    long int y;
    char c[1000];
    int i;
    FILE *a;
    FILE *g;
    struct d plr;
    strcpy(plr.pl, player);
    plr.scr = scr;

    bool k = false;
    a = fopen("i.txt", "r");
    if (a == NULL) {

        a = fopen("i.txt", "w");
        k = true;
        fclose(a);
    }
    else {
        a = fopen("i.txt", "a");
        fclose(a);
    }
    if (k == false){
        g = fopen("i.txt", "a+");
        fprintf(g, " %s %d \n", plr.pl,plr.scr);
        
        fclose(g);
        rankScore();
    }
    else if (k == true) {
        g = fopen("i.txt", "w+");
        fprintf(g, " %s %d \n", plr.pl,plr.scr);
        k = false;
        fclose(g);
    }
    
}

void showHigh(){
    FILE *a;
    a = fopen("i.txt", "r");
    if (a == NULL){
        printf("%s\n","suck a dick" );      
    }
    else{
        int count = 0;
        int i = 0;
        int scr;
        char pl[1000];
        char *p;
        char *v;
        if (a != NULL) {
            while (fscanf(a, "%s %d", pl, &scr) != EOF) {
                if (count < 10) {
                    
                    printf("%s ",pl );
                    printf("%d\n",scr );
                   
                }
                else{

                    fclose(a);
                    break;

                }
                count++;
                i += 40;
                
                

            }
            free(p);
            fclose(a);
        }
    }
}

int main(){
  
   char user[1000];
   gets(user);
   int scr;
   scanf("%d",&scr);
   setHigh(&user[0],scr);
   showHigh();

}