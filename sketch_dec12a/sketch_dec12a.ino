#include <LedControl.h>

#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 2
#define CS_PIN 10


#define DATA_PIN 11
#define CLK_PIN 13
MD_Parola matriz = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

LedControl matrizJuego = LedControl(DATA_PIN,CLK_PIN,CS_PIN,MAX_DEVICES);

int matrix1 [8][8]= {{1,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0}};
int matrix2 [8][8]= {{0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0}};       
//asignando pines a botones
const int bt_Msj = 9; 
const int bt_Direccion=8;
const int bt_Up=6;
const int bt_Down=5;
const int bt_Lefth=4;
const int bt_Right=3;


//variables a utilizar para poicion de la cabeza de la serpiente
int x =0;
int y=0;

bool change=true;
bool changeLedDown=true;
bool changeLedUp=true;
bool changeLedLefth=true;
bool changeLedRight=true;

void setup() {
  Serial.begin(9600);
  pinMode(bt_Msj, INPUT);
  pinMode(bt_Direccion,INPUT);
  pinMode(bt_Up,INPUT); 
  pinMode(bt_Down,INPUT);
  pinMode(bt_Lefth,INPUT);
  pinMode(bt_Right,INPUT);
  
  matrizJuego.shutdown(0,false);
  matrizJuego.shutdown(1,false);
  matrizJuego.setIntensity(0,8);
  matrizJuego.setIntensity(1,8);  
  
     dibujarMatriz();
}

void loop() {  
  movDown();
  movUp();
  movRight();
  movLefth();
}

//mover Izquierda
void movLefth(){
  if(digitalRead(bt_Lefth)==HIGH){  
  changeLedLefth =false;
  }else{
   if(!changeLedLefth){
  
      matrix1[x][y]=0;
      y=y-1;
      matrix1[x][y]=1;
      dibujarMatriz();
     
    changeLedLefth=true; 
    }
    }  
  }
//mover Derecha
void movRight(){
  if(digitalRead(bt_Right)==HIGH){  
  changeLedRight =false;
  }else{
   if(!changeLedRight){

      matrix1[x][y]=0;
      y=y+1;
      matrix1[x][y]=1;
      dibujarMatriz();
     
    changeLedRight=true; 
    }
    }  
  }
//mover arriba
void movUp(){
  if(digitalRead(bt_Up)==HIGH){  
  changeLedUp =false;
  }else{
   if(!changeLedUp){
  
      matrix1[x][y]=0;
      x=x-1;
      matrix1[x][y]=1;
      dibujarMatriz();
     
    changeLedUp=true; 
    }
    }  
  }
//mover abajo
void movDown(){
  if(digitalRead(bt_Down)==HIGH){  
  changeLedDown =false;
  }else{
   if(!changeLedDown){
  
      matrix1[x][y]=0;
      x=x+1;
      matrix1[x][y]=1;
      dibujarMatriz();
     
    changeLedDown=true; 
    }
    }  
  }
void dibujarMatriz(){
  for (int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      matrizJuego.setLed(0,i,j,matrix1[i][j]);
      }
    }
  }

void borrarMatriz(){
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      matrizJuego.setLed(0,i,j,0);
      }
    }
  }
  
