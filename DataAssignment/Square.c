#include <stdio.h>
#include <math.h>


double Area(double x, double y, double result){
    
    result = x * y;

    return result;
}

int main(){

    double a, b, result;
    
    scanf("%lf %lf",&a ,&b);

    printf("Area is: %.2lf",Area(a, b, result));

}