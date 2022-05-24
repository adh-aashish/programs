#include <stdio.h>
#include <math.h>

int main(){
    int n;
    float x[10],y[10],sumX =0,sumLogY=0,sumX2=0,sumXLogY=0,a,b;
    printf("Enter the num: ");
    scanf("%d",&n);
    int i;
    for(i =0;i<n;i++){
        printf("Enter the %d th x and y values: ",i+1);
        scanf("%f %f",&x[i],&y[i]);
        sumX = sumX + x[i];
        sumLogY = sumLogY + log(y[i]);
        sumX2 = sumX2 +x[i]*x[i];
        sumXLogY = sumXLogY+ x[i]*log(y[i]);
    }
    a = (sumLogY*sumX2 - sumX*sumXLogY)/(n*sumX2 - sumX*sumX);
    b = (n*sumXLogY - sumX*sumLogY) /(n*sumX2 - sumX*sumX);
    // actual a is e^a;
    a = exp(a);
    printf("\n%f and %f\n",a,b);
    return 0;
}
