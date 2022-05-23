#include <stdio.h>
#include <stdlib.h>
typedef struct veri{
    int k,v;
}v;

v a[6];

int h(int x){
return (x%7);
}

int put(v data){
    if(a[h(data.k)].k==-1){
        a[h(data.k)] = data;
        return 1;
    }
    else{
        int cycleCount=0;
        int i = h(data.k);
        while(a[i].k!=-1&&a[i].k!=data.k){
            i++;
            if(i>=6){
                    if(cycleCount>=1)
                    {
                       printf("Hash dolu\n");
                       return;
                    }
                 i=i%6;
                 cycleCount++;
            }

        }
        if(a[i].k==data.k){
            printf("Duplicate--> key:%d value:%d\n",data.k,data.v);
        }
        else
        a[i].k=data.k;
        a[i].v=data.v;

    }

}
void printAll(){
for(int s=0;s<6;s++){
    printf("Element:%d--key: %d value: %d\n",s+1,a[s].k,a[s].v);
    }
}

int get(int k){
    if(a[h(k)].k==k){
            return printf("|Wanted key: %d<-->wanted value: %d\n",a[h(k)],a[h(k)].v);
    }
    else{
        int cycleCount=0;
        int i = h(k);
        while(a[i].k!=k){
            i++;
            if(i>=6){
                    if(cycleCount>=1)
                    {
                       printf("Hash kayit yok\n");
                       return -1;
                    }
                 i=i%6;
                 cycleCount++;
            }

        }
        return a[k].v;

}
}

int main()
{
    for(int i=0;i<6;i++){
        a[i].k=-1;
    }
    v data;
    data.k=100;
    data.v=701;
    put(data);
    data.k=214;
    data.v=145;
    put(data);
    data.k=114;
    data.v=217;
    put(data);
    data.k=29;
    data.v=19;
    put(data);
    data.k=39;
    data.v=13;
    put(data);
    data.k=751;
    data.v=749;
    put(data);

    get(10);
    get(1);
    get(100);
    get(65);
    printAll();
}
