#include<stdio.h>
#include<string.h>

char Text[80],Pattern[20];
int stable[128];
int m,n;

void shifttable(){
    m=strlen(Pattern);
    n=strlen(Text);
    for(int i=0;i<=127;i++) stable[i]=m;
    for(int i=0;i<m-2;i++) stable[Pattern[i]]=m-i-1;
    for(int i=0;i<=127;i++) printf("%d\t",stable[i]);
}

int horspool(){
    int i=m-1;
    while(i<n-1){
        int k=0;
        while(k<=m-1 && Pattern[m-1-k]==Text[i-k]) k++;
        if(k==m) return i-m+1;
        else i=i+stable[Text[i]];
    }
    return -1;
}

void main(){
    printf("Enter the Text string\n");
    gets(Text);
    printf("Enter the Pattern String to be searched\n");
    gets(Pattern);
    shifttable();
    int index=horspool();
    if(index==-1) printf("Pattern not found\n");
    else printf("Pattern found at %d",index);
}