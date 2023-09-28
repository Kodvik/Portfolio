String dadoRecebido,overflowDeDados;
int aux, memoria[292];
//nota: a memoria tem 292 slots pois são 4 registradores e 96 conjuntos
//para armazenar os conjuntos de comandos ((96 x 3) + 4)
char aHex, bHex, sHex;
boolean A[4], B[4], S[4], Wbin[4], flagDeErro; //

#define bit3 13
#define bit2 12
#define bit1 11
#define bit0 10
#define ledErro 8

int tempoDeIntervalo = 2000; // em milisegundos

//Registradores
#define PC memoria[0]
#define W memoria[1]
#define X memoria[2]
#define Y memoria[3]

//indexes de controle
int numeroDeInstrucoes = 0, indexA=4, indexB=5, indexS=6;

void setup()
{

    PC = 4;
  	W='0';
  	X='0';
  	Y='0';
    Serial.begin(9600);
    pinMode(bit3, OUTPUT);
    pinMode(bit2, OUTPUT);
    pinMode(bit1, OUTPUT);
    pinMode(bit0, OUTPUT);
}
void loop()
{

    if (Serial.available() == 3)
    {
      	//obtenção de dados via serial
      	if(Serial.available() > 3)
        {
        	overflowDeDados = Serial.readString();
          	dadoRecebido = overflowDeDados.substring(0,2);
          	//Serial.println(dadoRecebido);
        }
      
        else
        {
        	dadoRecebido = Serial.readString();
        }
          
        if (dadoRecebido != "FIM")
        {
            memoria[indexA] = dadoRecebido[0];
          	indexA+=3;
          	//Serial.println(indexA);
         	
          	memoria[indexB] = dadoRecebido[1];
          	indexB+=3;
			//Serial.println(indexB);
          
          	memoria[indexS] = dadoRecebido[2];
          	indexS+=3;
          	//Serial.println(indexS);
          
            numeroDeInstrucoes++;
        }
        else
        {
          	indexA=4;
          	indexB=5;
          	indexS=6;
          	dumpMemoria(); //dumb de memoria de inicio de execução
            executarInstrucoes();
          	flagDeErro=false;
        }

    }
}
	
void separarBinarioA(int aux)
{
  	A[3] = aux / 1000;
    aux %= 1000;
    A[2] = aux / 100;
    aux %= 100;
    A[1] = aux / 10;
    aux %= 10;
    A[0] = aux;
  
}

void separarBinarioB(int aux)
{
 	B[3] = aux / 1000;
    aux %= 1000;
    B[2] = aux / 100;
    aux %= 100;
    B[1] = aux / 10;
    aux %= 10;
    B[0] = aux;
}

void separarBinarioS(int aux)
{
  	S[3] = aux / 1000;
    aux %= 1000;
    S[2] = aux / 100;
    aux %= 100;
    S[1] = aux / 10;
    aux %= 10;
    S[0] = aux;  
}

void separarBinarioW(int aux)
{
  		
  	Wbin[3] = aux / 1000;  		
    aux %= 1000;  		
    Wbin[2] = aux / 100;  		
    aux %= 100;  		
    Wbin[1] = aux / 10;  		
    aux %= 10;  		
    Wbin[0] = aux;  
  		
}

char WbinarioParaHex(){
	char tempChar;
  	if((!Wbin[3])&&(!Wbin[2])&&(!Wbin[1])&&(!Wbin[0])) return '0';
  	else if((!Wbin[3])&&(!Wbin[2])&&(!Wbin[1])&&(Wbin[0])) return '1';
    else if((!Wbin[3])&&(!Wbin[2])&&(Wbin[1])&&(!Wbin[0])) return '2';
    else if((!Wbin[3])&&(!Wbin[2])&&(Wbin[1])&&(Wbin[0])) return '3';
    else if((!Wbin[3])&&(Wbin[2])&&(!Wbin[1])&&(!Wbin[0])) return '4';
    else if((!Wbin[3])&&(Wbin[2])&&(!Wbin[1])&&(Wbin[0])) return '5';
    else if((!Wbin[3])&&(Wbin[2])&&(Wbin[1])&&(!Wbin[0])) return '6';
    else if((!Wbin[3])&&(Wbin[2])&&(Wbin[1])&&(Wbin[0])) return '7';
    else if((Wbin[3])&&(!Wbin[2])&&(!Wbin[1])&&(!Wbin[0])) return '8';
    else if((Wbin[3])&&(!Wbin[2])&&(!Wbin[1])&&(Wbin[0])) return '9';
    else if((Wbin[3])&&(!Wbin[2])&&(Wbin[1])&&(!Wbin[0])) return 'A';
    else if((Wbin[3])&&(!Wbin[2])&&(Wbin[1])&&(Wbin[0])) return 'B';
    else if((Wbin[3])&&(Wbin[2])&&(!Wbin[1])&&(!Wbin[0])) return 'C';
    else if((Wbin[3])&&(Wbin[2])&&(!Wbin[1])&&(Wbin[0])) return 'D';
    else if((Wbin[3])&&(Wbin[2])&&(Wbin[1])&&(!Wbin[0])) return 'E';
    else if((Wbin[3])&&(Wbin[2])&&(Wbin[1])&&(Wbin[0])) return 'F';
}
	
int hexPara4bit(char K)
{
	int tempInt;
    if (K == '0') tempInt = 0;
    else if (K == '1') tempInt = 1;
    else if (K == '2') tempInt = 10;
    else if (K == '3') tempInt = 11;
    else if (K == '4') tempInt = 100;
    else if (K == '5') tempInt = 101;
    else if (K == '6') tempInt = 110;
    else if (K == '7') tempInt = 111;
    else if (K == '8') tempInt = 1000;
    else if (K == '9') tempInt = 1001;
    else if ((K == 'A') || (K == 'a')) tempInt = 1010;
    else if ((K == 'B') || (K == 'b')) tempInt = 1011;
    else if ((K == 'C') || (K == 'c')) tempInt = 1100;
    else if ((K == 'D') || (K == 'd')) tempInt = 1101;
    else if ((K == 'E') || (K == 'e')) tempInt = 1110;
    else if ((K == 'F') || (K == 'f')) tempInt = 1111;
    else
    {
    	flagDeErro = true;
      	digitalWrite(ledErro,HIGH);
    	Serial.print("\n\n FLAG = TRUE \n\n");
    }
   	return tempInt;
}

void executarInstrucoes()
{
	if (flagDeErro == 1)
	{
		Serial.println("uma das instrucoes inseridas apresenta valor fora dos parametros");
	}
	else
	{
		for (int i = 0; i < numeroDeInstrucoes; i++)
		{
          	X=memoria[indexA];
            Y=memoria[indexB];
          	W=execOPcode(hexPara4bit(memoria[indexS]));
          	indexA+=3;
          	indexB+=3;
          	indexS+=3;
          	PC++;
          	dumpMemoria();
          	delay(tempoDeIntervalo);
        }
    }

}

void dumpMemoria(){
	Serial.print("|");
  	Serial.print(PC);
  	Serial.print("|");
  	Serial.print((char)W);
  	Serial.print("|");
  	Serial.print((char)X);
  	Serial.print("|");
  	Serial.print((char)Y);
  	Serial.print("|");
  	for(int i=3;i <= (numeroDeInstrucoes*3);)
    {
      	//loop de impressao do OPcode
      	i++;
    	Serial.print((char)memoria[i]);
      	i++;
    	Serial.print((char)memoria[i]);
      	i++;
    	Serial.print((char)memoria[i]);
      	Serial.print("|");
    }
  	Serial.println();
}

char execOPcode(int opCode)
{
  	switch(opCode){
      	int tempA,tempB,tempResultado;
      	case 0: //not A
      	{	
          	tempResultado = hexPara4bit(memoria[indexA]);
        	separarBinarioW(tempResultado);
          	
          	Wbin[3] = !Wbin[3];
          	
          	Wbin[2] = !Wbin[2];
          	
          	Wbin[1] = !Wbin[1];
         	
          	Wbin[0] = !Wbin[0];
         	
          	digitalWrite(bit3,Wbin[3]);
          	digitalWrite(bit2,Wbin[2]);
          	digitalWrite(bit1,Wbin[1]);
          	digitalWrite(bit0,Wbin[0]);
               	
          	return (WbinarioParaHex());
          	break;
        }
      	case 1: // not(A or B)
      	{
        	tempA = hexPara4bit(memoria[indexA]);
          	tempB = hexPara4bit(memoria[indexB]);
          	separarBinarioA(tempA);
          	separarBinarioB(tempB);
          	
          	Wbin[3] = !(A[3]|(B[3]));
          	Wbin[2] = !(A[2]|(B[2]));
          	Wbin[1] = !(A[1]|(B[1]));
          	Wbin[0] = !(A[0]|(B[0]));
          
          	digitalWrite(bit3,Wbin[3]);
          	digitalWrite(bit2,Wbin[2]);
          	digitalWrite(bit1,Wbin[1]);
          	digitalWrite(bit0,Wbin[0]);
          	
          	return(WbinarioParaHex());
          	break;
        }
      	case 10: // not A and B
      	{
          	tempA = hexPara4bit(memoria[indexA]);
          	tempB = hexPara4bit(memoria[indexB]);
          	separarBinarioA(tempA);
          	separarBinarioB(tempB);
          
          	Wbin[3] = (!A[3])&(B[3]);
          	Wbin[2] = (!A[2])&(B[2]);
          	Wbin[1] = (!A[1])&(B[1]);
          	Wbin[0] = (!A[0])&(B[0]);
          
          	digitalWrite(bit3,Wbin[3]);
          	digitalWrite(bit2,Wbin[2]);
          	digitalWrite(bit1,Wbin[1]);
          	digitalWrite(bit0,Wbin[0]);
          	
          	return(WbinarioParaHex());
          	break;
        }
      	case 11: // zero logico
      	{
          	Wbin[3] = 0;
          	Wbin[2] = 0;
          	Wbin[1] = 0;
          	Wbin[0] = 0;
          
          	digitalWrite(bit3,Wbin[3]);
          	digitalWrite(bit2,Wbin[2]);
          	digitalWrite(bit1,Wbin[1]);
          	digitalWrite(bit0,Wbin[0]);
          	return(WbinarioParaHex());
          	break;
    	}
      	case 100: // not(A and B)
      	{
			tempA = hexPara4bit(memoria[indexA]);
          	tempB = hexPara4bit(memoria[indexB]);
          	separarBinarioA(tempA);
          	separarBinarioB(tempB);
          
          	Wbin[3] = !((A[3])&(B[3]));
          	Wbin[2] = !((A[2])&(B[2]));
          	Wbin[1] = !((A[1])&(B[1]));
          	Wbin[0] = !((A[0])&(B[0]));
          
          	digitalWrite(bit3,Wbin[3]);
          	digitalWrite(bit2,Wbin[2]);
          	digitalWrite(bit1,Wbin[1]);
          	digitalWrite(bit0,Wbin[0]);
          	
          	return(WbinarioParaHex());
          	break;
        }
      	case 101: //not B
      	{	
          	tempResultado = hexPara4bit(memoria[indexB]);
        	separarBinarioW(tempResultado);
          	
          	Wbin[3] = !Wbin[3];
          	
          	Wbin[2] = !Wbin[2];
          	
          	Wbin[1] = !Wbin[1];
         	
          	Wbin[0] = !Wbin[0];
         	
          	digitalWrite(bit3,Wbin[3]);
          	digitalWrite(bit2,Wbin[2]);
          	digitalWrite(bit1,Wbin[1]);
          	digitalWrite(bit0,Wbin[0]);
               	
          	return (WbinarioParaHex());
          	break;
        }
      	case 110: // A xor B
      	{
			tempA = hexPara4bit(memoria[indexA]);
          	tempB = hexPara4bit(memoria[indexB]);
          	separarBinarioA(tempA);
          	separarBinarioB(tempB);
          
          	Wbin[3] = ((A[3])^(B[3]));
          	Wbin[2] = ((A[2])^(B[2]));
          	Wbin[1] = ((A[1])^(B[1]));
          	Wbin[0] = ((A[0])^(B[0]));
          
          	digitalWrite(bit3,Wbin[3]);
          	digitalWrite(bit2,Wbin[2]);
          	digitalWrite(bit1,Wbin[1]);
          	digitalWrite(bit0,Wbin[0]);
          	
          	return(WbinarioParaHex());
          	break;
        }
      	case 111: // A and not B
      	{
			tempA = hexPara4bit(memoria[indexA]);
          	tempB = hexPara4bit(memoria[indexB]);
          	separarBinarioA(tempA);
          	separarBinarioB(tempB);
          
          	Wbin[3] = ((A[3])&(!B[3]));
          	Wbin[2] = ((A[2])&(!B[2]));
          	Wbin[1] = ((A[1])&(!B[1]));
          	Wbin[0] = ((A[0])&(!B[0]));
          
          	digitalWrite(bit3,Wbin[3]);
          	digitalWrite(bit2,Wbin[2]);
          	digitalWrite(bit1,Wbin[1]);
          	digitalWrite(bit0,Wbin[0]);
          	
          	return(WbinarioParaHex());
          	break;
        }
      	case 1000: // not A or B
      	{
			tempA = hexPara4bit(memoria[indexA]);
          	tempB = hexPara4bit(memoria[indexB]);
          	separarBinarioA(tempA);
          	separarBinarioB(tempB);
          
          	Wbin[3] = ((!A[3])|(B[3]));
          	Wbin[2] = ((!A[2])|(B[2]));
          	Wbin[1] = ((!A[1])|(B[1]));
          	Wbin[0] = ((!A[0])|(B[0]));
          
          	digitalWrite(bit3,Wbin[3]);
          	digitalWrite(bit2,Wbin[2]);
          	digitalWrite(bit1,Wbin[1]);
          	digitalWrite(bit0,Wbin[0]);
          	
          	return(WbinarioParaHex());
          	break;
        }
      	case 1001: // not (A xor B)
      	{
			tempA = hexPara4bit(memoria[indexA]);
          	tempB = hexPara4bit(memoria[indexB]);
          	separarBinarioA(tempA);
          	separarBinarioB(tempB);
          
          	Wbin[3] = !((A[3])^(B[3]));
          	Wbin[2] = !((A[2])^(B[2]));
          	Wbin[1] = !((A[1])^(B[1]));
          	Wbin[0] = !((A[0])^(B[0]));
          
          	digitalWrite(bit3,Wbin[3]);
          	digitalWrite(bit2,Wbin[2]);
          	digitalWrite(bit1,Wbin[1]);
          	digitalWrite(bit0,Wbin[0]);
          	
          	return(WbinarioParaHex());
          	break;
        }
      	case 1010: // B
      	{	
          	tempResultado = hexPara4bit(memoria[indexB]);
        	separarBinarioW(tempResultado);
          	
          	digitalWrite(bit3,Wbin[3]);
          	digitalWrite(bit2,Wbin[2]);
          	digitalWrite(bit1,Wbin[1]);
          	digitalWrite(bit0,Wbin[0]);
               	
          	return (WbinarioParaHex());
          	break;
        }
      	case 1011: // A and B
      	{
			tempA = hexPara4bit(memoria[indexA]);
          	tempB = hexPara4bit(memoria[indexB]);
          	separarBinarioA(tempA);
          	separarBinarioB(tempB);
          
          	Wbin[3] = ((A[3])&(B[3]));
          	Wbin[2] = ((A[2])&(B[2]));
          	Wbin[1] = ((A[1])&(B[1]));
          	Wbin[0] = ((A[0])&(B[0]));
          
          	digitalWrite(bit3,Wbin[3]);
          	digitalWrite(bit2,Wbin[2]);
          	digitalWrite(bit1,Wbin[1]);
          	digitalWrite(bit0,Wbin[0]);
          	
          	return(WbinarioParaHex());
          	break;
        }
      	case 1100: // um logico
      	{
          	Wbin[3] = 0;
          	Wbin[2] = 0;
          	Wbin[1] = 0;
          	Wbin[0] = 1;
          
          	digitalWrite(bit3,Wbin[3]);
          	digitalWrite(bit2,Wbin[2]);
          	digitalWrite(bit1,Wbin[1]);
          	digitalWrite(bit0,Wbin[0]);
          	return(WbinarioParaHex());
          	break;
    	} 
      	case 1101: // A and not B
      	{
			tempA = hexPara4bit(memoria[indexA]);
          	tempB = hexPara4bit(memoria[indexB]);
          	separarBinarioA(tempA);
          	separarBinarioB(tempB);
          
          	Wbin[3] = ((A[3])&(!B[3]));
          	Wbin[2] = ((A[2])&(!B[2]));
          	Wbin[1] = ((A[1])&(!B[1]));
          	Wbin[0] = ((A[0])&(!B[0]));
          
          	digitalWrite(bit3,Wbin[3]);
          	digitalWrite(bit2,Wbin[2]);
          	digitalWrite(bit1,Wbin[1]);
          	digitalWrite(bit0,Wbin[0]);
          	
          	return(WbinarioParaHex());
          	break;
        }
      	case 1110: // A and B
      	{
			tempA = hexPara4bit(memoria[indexA]);
          	tempB = hexPara4bit(memoria[indexB]);
          	separarBinarioA(tempA);
          	separarBinarioB(tempB);
          
          	Wbin[3] = ((A[3])&(B[3]));
          	Wbin[2] = ((A[2])&(B[2]));
          	Wbin[1] = ((A[1])&(B[1]));
          	Wbin[0] = ((A[0])&(B[0]));
          
          	digitalWrite(bit3,Wbin[3]);
          	digitalWrite(bit2,Wbin[2]);
          	digitalWrite(bit1,Wbin[1]);
          	digitalWrite(bit0,Wbin[0]);
          	
          	return(WbinarioParaHex());
          	break;
        }
    	case 1111: // A
      	{	
          	tempResultado = hexPara4bit(memoria[indexB]);
        	separarBinarioW(tempResultado);
          	
          	digitalWrite(bit3,Wbin[3]);
          	digitalWrite(bit2,Wbin[2]);
          	digitalWrite(bit1,Wbin[1]);
          	digitalWrite(bit0,Wbin[0]);
               	
          	return (WbinarioParaHex());
          	break;
        }
    }
}