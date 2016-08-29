#include<stdio.h>
#include<math.h>

/*Lance uma partícula mediante um dispositivo que consiste
essencialmente em uma mola comprimida.
Primeiro, a partícula desliza ao longo de um plano horizon-
tal.
Logo, entra em um loop e continuando, depois de descrevê-lo,
passa a um plano inclinado.*/

#define CONST_MOLA 500 // Constante da mola K = 500 N/m;
#define RAIO 0.5       // Raio do loop R = 0.5 m;
#define ATRITO 0.2     // Coeficiente de atrito u = 0.2;
#define MASSA 1        // Massa do Bloco m = 1 Kg;
#define GRAVIDADE 9.8

double energ_PE_A(double x) // Energia Potencial Elastica no ponto A;
{

    return (CONST_MOLA*x*x)/2; // x - deformação dada na mola;

}
double energ_ATRITO(double x) // Energia de atrito no trajeto;
{

    return ATRITO*MASSA*GRAVIDADE*(x+0.7);

}
double velocidade_B(double x) // Velocidade no ponto B;
{

    return sqrt((2*(energ_PE_A(x) - energ_ATRITO(x)))/MASSA);

}
// O Loop
double power_cent(double x)// Força centrípeta;
{
    return MASSA*velocidade_B(x)/RAIO;
}
double power_pes(double x)// Força Peso;
{
    return MASSA*GRAVIDADE;
}
double normal(double x)// Força Normal;
{
    return power_cent(x)- power_pes(x);
}
double energ_cinet_B(double x) // Energia Potencial Elastica no ponto B;
{
    return MASSA*velocidade_B(x)*velocidade_B(x)/2;
}
double velocidade_C(double x) // Velocidade no ponto C;
{
    return sqrt(2*(energ_cinet_B(x) - (2*MASSA*GRAVIDADE*RAIO))/MASSA);
}
double velocidade_D(double x) // Velocidade no ponto D;
{
    return sqrt(2*(energ_cinet_B(x) - (MASSA*GRAVIDADE*RAIO*(1 - cos(30*M_PI/180)))/MASSA));
}
double energ_cin_D(double x)// energia cinética no ponto D;
{
    return MASSA*velocidade_D(x)*velocidade_D(x)/2;
}
double deslocamento(double x)//deslocamento do corpo no plano inclinado;
{
    float v =  GRAVIDADE*sin(30*M_PI/180);
    printf("\n%f",v);
    float y = velocidade_D(x)*velocidade_D(x)*0.5;
    printf("\n%f",y);
    float k = ATRITO*GRAVIDADE*cos(30*M_PI/180);
    printf("\n%f",k);
    return -((GRAVIDADE*sin(30*M_PI/180)) - (velocidade_D(x)*velocidade_D(x)*0.5)/(ATRITO*GRAVIDADE*cos(30*M_PI/180)));
}

int main()
{
    double x;
    printf("Digite a deformacao da mola:");
    scanf("%lf",&x);
    fflush(stdin);
    printf("\nEnergia no ponto A: %lf", energ_PE_A(x));
    printf("\nEnergia de atrito: %lf", energ_ATRITO(x));
    printf("\nVelocidade no ponto B =  %lf", velocidade_B(x));

        if (normal(x)>=0)
        {
         printf("\nVelocidade no ponto C = %lf", velocidade_C(x));
         printf("\nVelocidade angular no ponto C = %lf", (velocidade_C(x)/RAIO));

         printf("\nVelocidade no ponto D = %lf", velocidade_D(x));
         printf("\nEnergia Cinetica no porto D = %lf", energ_cin_D(x));
         printf("\nDescolamento do bloco = %lf", deslocamento(x));

        }
        else
        {
            printf("\nO bloco caiu");

        }

    return 0;
}
