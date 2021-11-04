#include <stdio.h>
#include <conio.h>
#include <math.h>

double F(double x)//����� ���� �������
    {
    double f;
    double sqrt(double (X));
    f = sqrt(x+1);
    return f;
    }

double Parabola(double a,double b, int N)// ���������� ��������� �������� �������� ��� ���������
{
        int r;
        double h = (b - a)/N;
        double sum =F(a)+F(b);
        for(int i=1;i<=N-1;i++)
        {
            r = 2+2*(i%2);
            sum+=r*F(a+i*h);
        }
        sum*=h/3;
    return sum;
}

double Left_Triangle(double a,double b,int N)//���������� ��������� �������� ������ ������������
{
        double h = (b - a)/N;
        double sum =0.0;
        for(int i=0;i<=N-1;i++)
        {
            sum+=h*F(a+i*h);
        }

    return sum;
}

double Right_Triangle(double a,double b,int N)//���������� ��������� �������� ������� ������������
{
        double h = (b - a)/N;
        double sum =0.0;
        for(int i=1;i<=N;i++)
        {
            sum+=h*F(a+i*h);
        }

    return sum;
}

double Trapezoid(double a,double b,int N)//���������� ��������� �������� ��������
{
        double h = (b - a)/N;
        double sum =F(a)+F(b);
        for(int i=1;i<=N-1;i++)
        {
            sum+=2*F(a+i*h);
        }
        sum*=h/2;
    return sum;
}

int main()
{
    int N,z, i1=0, N1=10;
    double a, b, calculation;
    const double measurement_error = 0.0001;//�����������
    printf("Hello World");
    printf("\nMy variant is 23.\nMy function is (x+1)^(1/2).\n");
    printf("\nEnter the initial x value:");
    scanf("%lf", &a);
    printf("The initial x value:%.2lf", a);
    printf("\nEnter the final x value:");
    scanf("%lf", &b);
    printf("\nThe final x value:%.2lf", b);
    do{
        printf("\n\nChoose how many parts to split the function into.\nThe higher the number, the better. The number must be even.");
        scanf("%d", &N);
        printf("N=%d",N);
        printf("\n");
    }while(N%2!=0);
    printf("\nAllowable measurement error = 0.0001");
    printf("\n");

    do{//����� �����������
        i1++;
        calculation = (Left_Triangle( a, b, N1*i1) - Left_Triangle( a, b, N1*(i1+1)));
    }while(calculation > measurement_error);
    z = N1*(i1+1);
    printf("\nLeft_Triangle = %lf", Left_Triangle( a, b, N) );
    printf("\nN=%d",z );
    i1= 0;

    do{//������ �����������
        i1++;
        calculation = (Right_Triangle( a, b, N1*i1) - Right_Triangle( a, b, N1*(i1+1)));
    }while(calculation > measurement_error);
    z = N1*(i1+1);
    printf("\n\nRight Triangle = %lf", Right_Triangle( a, b, N) );
    printf("\nN=%d",z );
    i1=0;

    do{//��������
        i1++;
        calculation = (Parabola( a, b, N1*i1) - Parabola( a, b, N1*(i1+1)));
    }while(calculation >= measurement_error);
    z = N1*(i1+1);
    printf("\n\nParabola = %lf", Parabola( a, b, N) );
    printf("\nN=%d",z );
    i1=0;

    do{//��������
        i1++;
        calculation = (Trapezoid( a, b, N1*i1) - Trapezoid( a, b, N1*(i1+1)));
    }while(calculation > measurement_error);
    z = N1*(i1+1);
    printf("\n\nTrapezoid = %lf", Trapezoid( a, b, N) );
    printf("\nN=%d",z );
    return 0;
}
