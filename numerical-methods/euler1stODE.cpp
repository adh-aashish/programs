# include <stdio.h>

double evaluate(double x){
    // this is the dy/dx value i.e. dy/dx = 3*x*x -10*x
    return 3*x*x -48*x;
}

int main(){
    char function[30]="x^3-9x^2";
    double x0,y0;
    int n;
    double xn;
    printf("Enter the x0,y0,xn and n: ");
    scanf("%lf %lf %lf %d",&x0,&y0,&xn,&n);
    double h = (xn-x0)/n;
    int i;
    for(i = 0;i<n;i++){
        printf("\n %lf\t%lf",x0,y0);
        x0 = x0+h;
        y0 = y0+h*evaluate(x0);
    }

    printf("\nThe value of y(xn) is: %lf\n",y0);
    return 0;
}
