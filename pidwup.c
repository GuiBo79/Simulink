#include<mega8.h>
#include<delay.h> incluir lib

void main(void)
{

int lo,hi,hi_8;
int sinal,saida;
int T;
float T_q;
float sinal_q,saida_q;
float u[2],e[2],es[2];
float satin,satout;
float kp,ti;

//inicializacao de io B

PORTB=0x00;
DDRB=0x00;

//inicializacao de io C

PORTC=0x00;
DDRC=0x00;

//inicializacao de io D

PORTD=0x00;
DDRD=0xFF;

//inicializacao de timer e contador 0

TCCR0=0X00;
TCNT0=0X00;

//inicializacao de timer e contador 1

TCCR1A=0X00;
TCCR1B=0X00;
TCNT1H=0X00;
TCNT1L=0X00;
OCR1H=0X00;
OCR1L=0X00;

//inicializacao de interrupcao externa

GIMSK=0X00;
MCUCR=0X00;

//inicializacao da interrupcao do contador e timer

UBRRHI=0X00;

//inicializacao do comparador analogico

ACSR=0X80;

while(1)
{

  T=500;
  kp=7.1;
  ti=675/7.1;
  satin=0;
  satout=0;
  u[0]=0;
  u[1]=0;
  e[0]=0;
  e[1]=0;
  es[0]=0;
  es[1]=0;

  while(1)
  {
	ADMUX=0; //seleciona canal ad
	ADCSRA=0XE6; //inicia processo de conversao
	lo=ADCL; //8 bits menos significativos
	hi=ADCH; //2 bits mais significativos
	ADCSRA=0x80; //fim de conversao

	//codigo q transforma sinal lido em float

	hi_8=hi*256;
	sinal=lo+hi_8; //variavel de 10 bits 0 --> +1023
	sinal=sinal-512; //simetria de sinal -512 --> +512
	sinal_q=(float)sinal;
	sinal_q=(sinal_q*5)/512; //qunatizacao de -5 --> +5 volts
	
	//salvar o valor atual dos sinais lidos

	e[0]=sinal_q;
	es[0]=satout-satin;
	
	//lei de controle

	T_q=(float)T;

	escrever aqui a lei de controle

	//ajusta nivel de saturacao do sinal de controle
	
	satin=u[0]; // entrada do saturador para o anti-windup

	if(u[0]>=5)  u[0]=5;
	if(u[0]<=-5) u[0]=-5;

	satout=u[0]; //saida do saturador para calculo de anti-windup


	//escrever no conversor da

	saida_q=(u[0]*127)/5; //saida_q esta entre -127 --> 127
	saida=(int)saida_q;
	saida=saida+127; // saida esta entre 0 --> 255
	PORTD=saida; //escreve saida na porta D
	
	//atualizacao de variaveis

	u[1]=u[0];
	e[1]=e[0];
	es[1]=es[0];

	delay_us(500);

  }//laco while interno

}// laco while externo
}// laco do prog principal