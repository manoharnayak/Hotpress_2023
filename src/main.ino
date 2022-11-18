//<App !Start!>
// FILE: [220711-hotpress.ino]
// Created by GUIslice Builder version: [0.17.b11]
//
// GUIslice Builder Generated File
//
// For the latest guides, updates and support view:
// https://github.com/ImpulseAdventure/GUIslice
//
//<App !End!>

// ------------------------------------------------
// Headers to include
// ------------------------------------------------
#include "220711-hotpress_GSLC.h"
#include <Vcc.h>
#include <EEPROM.h>
#include <math.h>
#include <PID_v1.h>



// ------------------------------------------------
// Program Globals
// ------------------------------------------------

#define runEvery(t) for (static uint16_t _lasttime;\
                         (uint16_t)((uint16_t)millis() - _lasttime) >= (t);\
                         _lasttime += (t))
#define RELAY_PINK1 48 // Bottom heater pair 1
#define RELAY_PINK2 49 // Bottom heater pair 2
#define RELAY_PINK3 50 // Top heater pair
#define RELAY_PINK4 51 // piston valve retract
#define RELAY_PINK5 52 // piston valve extend
#define RELAY_PINK6 53 // cooler






//char *dtostrf(double val, signed char width, unsigned char prec, char *s);

char tbuffer[50];
char debugoutX[200];

int pistonposition = 0;

//PID vars

double Setpointbot, Inputbot, Outputbot;
double Setpointtop, Inputtop, Outputtop;
double Setpointbotex, Inputbotex, Outputbotex;
double Setpointtopex, Inputtopex, Outputtopex;

double Kpbot=300, Kibot=0, Kdbot=0;
double Kptop=300, Kitop=0, Kdtop=0;
double kpbotex=200, kibotex=0, kdbotex=0;
double kptopex=300, kitopex=0, kdtopex=0;

PID myPIDbot(&Inputbot, &Outputbot, &Setpointbot, Kpbot, Kibot, Kdbot, DIRECT);
PID myPIDtop(&Inputtop, &Outputtop, &Setpointtop, Kptop, Kitop, Kdtop, DIRECT);
PID myPIDbotex(&Inputbotex, &Outputbotex, &Setpointbotex, kpbotex, kibotex, kdbotex, DIRECT);
PID myPIDtopex(&Inputtopex, &Outputtopex, &Setpointtopex, kptopex, kitopex, kdtopex, DIRECT);


int windowsize = 5000;
unsigned long windowstarttime;


float maxPressure = 10.0; //in Bar
int Forcefactor = 1000;

int coolerstate = 0;
int heatingstate = 0;
int heatingstateK1and2 = 0;
int heatingstateK3 = 0;
int useexternalTtop = 0;
int useexternalTbot = 0;
int showForce = 0;




int t1 = 20;
int t2 = 20;
int t3 = 20;
int t4 = 20;
int t5 = 20;
int t6 = 20;
int tt1 = A8; //internal base plate sensor
int tt2 = A9; //internal bottom plate sensor
int tt3 = A10; //internal top plate sensor
int tt4 = A11; //internal piston plate sensor
int tt5 = A12; //external top plate sensor
int tt6 = A13; //external bottom plate sensor

//A14 actual pressure in from festo
//A15 pressure setting from poti
//A6 SETTOP temperature setting from poti
//A7 SETBOT temperature setting from poti


float vccm = 5.00;                       // check!
                                        //  and set to the measured Vcc.
long pad = 2692;                       // voltage divider resistance
                                        // 
long thermr = 100000;                   // thermistor nominal resistance
long Resistance; 
int RawADC;

#define runEvery(t) for (static uint16_t _lasttime;\
                         (uint16_t)((uint16_t)millis() - _lasttime) >= (t);\
                         _lasttime += (t))

double Thermistor(int RawADC) {
  float Resistance;  
  float Temp;  // Dual-Purpose variable to save space.
  float vout;
  vout = vccm*(RawADC/1023.00);
  Resistance=(vout*pad)/(vccm-vout);
  float kA = 0.000723569702452097;
  float kB = 0.000216399730853633;
  float kC = 0.000000092453905203713;
  Temp = log(Resistance);
  Temp = 1/(kA+(kB*Temp)+(kC*Temp*Temp*Temp));  
  Temp = Temp - 273.15;  // Convert Kelvin to Celsius        
  return Temp;
}            

// ------------------------------------------------
// Program Globals
// ------------------------------------------------

const float VccMin   = 0.0;           // Minimum expected Vcc level, in Volts.
const float VccMax   = 5.1;           // Maximum expected Vcc level, in Volts.
const float VccCorrection = 4.94/4.71;  // Measured Vcc by multimeter divided by reported Vcc
Vcc vcc(VccCorrection);


int index = 0;
int intPsetp = 0;


//analogsmoothing
const int numReadings = 10;


float tempFloat1 = 0.00;
float tempFloat2 = 0.00;
float tempFloat3 = 0.00;
float tempFloat4 = 0.00;
float actPressure = 0.0;
double t1temp = 0;
double t2temp = 0;
double t3temp = 0;
double t4temp = 0;
double t5temp = 0;
double t6temp = 0;

int t1tempreadIndex = 0;
int t2tempreadIndex = 0;
int t3tempreadIndex = 0;
int t4tempreadIndex = 0;
int t5tempreadIndex = 0;
int t6tempreadIndex = 0;
int tempFloat1readIndex = 0;
int tempFloat2readIndex = 0;
int tempFloat3readIndex = 0;
int tempFloat4readIndex = 0;

float readingstempFloat1[numReadings];
float readingstempFloat2[numReadings];
float readingstempFloat3[numReadings];
float readingstempFloat4[numReadings];
int readingst1temp[numReadings];
int readingst2temp[numReadings];
int readingst3temp[numReadings];
int readingst4temp[numReadings];
int readingst5temp[numReadings];
int readingst6temp[numReadings];

float totaltempFloat1 = 0.00;
float totaltempFloat2 = 0.00;
float totaltempFloat3 = 0.00;
float totaltempFloat4 = 0.00;
int totalt1temp = 0;
int totalt2temp = 0;
int totalt3temp = 0;
int totalt4temp = 0;
int totalt5temp = 0;
int totalt6temp = 0;

float averagetempFloat1 = 0.00;
float averagetempFloat2 = 0.00;
float averagetempFloat3 = 0.00;
float averagetempFloat4 = 0.00;
int averaget1temp = 0;
int averaget2temp = 0;
int averaget3temp = 0;
int averaget4temp = 0;
int averaget5temp = 0;
int averaget6temp = 0;

double Force = 0;


// Save some element references for direct access
//<Save_References !Start!>
gslc_tsElemRef* HEATING           = NULL;
gslc_tsElemRef* K1                = NULL;
gslc_tsElemRef* K2                = NULL;
gslc_tsElemRef* K3                = NULL;
gslc_tsElemRef* K4                = NULL;
gslc_tsElemRef* K5                = NULL;
gslc_tsElemRef* K6                = NULL;
gslc_tsElemRef* Pdown             = NULL;
gslc_tsElemRef* Pnull             = NULL;
gslc_tsElemRef* Psetp             = NULL;
gslc_tsElemRef* Pup               = NULL;
gslc_tsElemRef* SETPLABEL         = NULL;
gslc_tsElemRef* TBOTSETLABEL      = NULL;
gslc_tsElemRef* TTOPSETLABEL      = NULL;
gslc_tsElemRef* Tbot              = NULL;
gslc_tsElemRef* Tbot2             = NULL;
gslc_tsElemRef* Tbotex            = NULL;
gslc_tsElemRef* Tbotset           = NULL;
gslc_tsElemRef* Tpist             = NULL;
gslc_tsElemRef* Ttop              = NULL;
gslc_tsElemRef* Ttopex            = NULL;
gslc_tsElemRef* Ttopset           = NULL;
gslc_tsElemRef* cooler            = NULL;
//<Save_References !End!>

// Define debug message function
static int16_t DebugOut(char ch) { if (ch == (char)'\n') Serial.println(""); else Serial.write(ch); return 0; }

// ------------------------------------------------
// Callback Methods
// ------------------------------------------------
// Common Button callback
bool CbBtnCommon(void* pvGui,void *pvElemRef,gslc_teTouch eTouch,int16_t nX,int16_t nY)
{
  // Typecast the parameters to match the GUI and element types
  gslc_tsGui*     pGui     = (gslc_tsGui*)(pvGui);
  gslc_tsElemRef* pElemRef = (gslc_tsElemRef*)(pvElemRef);
  gslc_tsElem*    pElem    = gslc_GetElemFromRef(pGui,pElemRef);

  if ( eTouch == GSLC_TOUCH_UP_IN ) {
    // From the element's ID we can determine which button was pressed.
    switch (pElem->nId) {
//<Button Enums !Start!>
      case E_ELEM_BTN7_PUP:
        pistonposition = 1;
        break;
      case E_ELEM_BTN8_PDOWN:
        pistonposition = 2;
        break;
      case E_ELEM_BTN9_PNULL:
        pistonposition = 0;
        break;
      case E_ELEM_BTN10_COOLER:
        coolerstate++;
        if (coolerstate == 2){
          coolerstate = 0;
        }
        break;
      case E_ELEM_BTN11_HEATING:
        heatingstate++;
        if (heatingstate == 2){
          heatingstate = 0;
        }
        break;
      case E_ELEM_BTN12_TTOPSET:
        useexternalTtop++;
        if (useexternalTtop == 2){
          useexternalTtop = 0;
        }
        break;
      case E_ELEM_BTN13_TBOTSET:
        useexternalTbot++;
        if (useexternalTbot == 2){
          useexternalTbot = 0;
        }
        break;
      case E_ELEM_BTN14_SETP:
        showForce++;
        if (showForce == 2){
          showForce = 0;
        }
        break;
//<Button Enums !End!>
      default:
        break;
    }
  }
  return true;
}
//<Checkbox Callback !Start!>
//<Checkbox Callback !End!>
//<Keypad Callback !Start!>
//<Keypad Callback !End!>
//<Spinner Callback !Start!>
//<Spinner Callback !End!>
//<Listbox Callback !Start!>
//<Listbox Callback !End!>
//<Draw Callback !Start!>
//<Draw Callback !End!>
//<Slider Callback !Start!>
//<Slider Callback !End!>
//<Tick Callback !Start!>
//<Tick Callback !End!>

void setup()
{
 // Set all RELAY pins to OFF
  pinMode(RELAY_PINK1, OUTPUT);
  pinMode(RELAY_PINK2, OUTPUT);
  pinMode(RELAY_PINK3, OUTPUT);
  pinMode(RELAY_PINK4, OUTPUT);
  pinMode(RELAY_PINK5, OUTPUT);
  pinMode(RELAY_PINK6, OUTPUT);

  pinMode(47, INPUT); // D3 switching output data from Pressure Regulator

  digitalWrite(RELAY_PINK1, LOW);
  digitalWrite(RELAY_PINK2, LOW);
  digitalWrite(RELAY_PINK3, LOW);
  digitalWrite(RELAY_PINK4, LOW);
  digitalWrite(RELAY_PINK5, LOW);
  digitalWrite(RELAY_PINK6, LOW);

  //PWM set up


  pinMode(45, OUTPUT);
  TCCR5A = _BV(COM5B1) | _BV(WGM51);
  TCCR5B = _BV(WGM53) | _BV(WGM52) | _BV(CS50) ; 
  OCR5B = 30000; // (should be 50% duty cycle (ocr/icr)
  ICR5 = 60000; // (should set freq to 267 Hz (16MHz/60000))

  //analogsmoothing setup

  vccm = vcc.Read_Volts(); //reference calibration

  for (int thisReading = 0; thisReading < numReadings; thisReading++){
    readingstempFloat1[thisReading] = 0;
    readingstempFloat2[thisReading] = 0;
    readingstempFloat3[thisReading] = 0;
    readingstempFloat4[thisReading] = 0;
    readingst1temp[thisReading] = 0;
    readingst2temp[thisReading] = 0;
    readingst3temp[thisReading] = 0;
    readingst4temp[thisReading] = 0;
    readingst5temp[thisReading] = 0;
    readingst6temp[thisReading] = 0;
  }  


  // begin serial comm with usb and wifi  
  Serial.begin(115200);
  Serial3.begin(115200);
  delay(1000);




  //PID STUFF
  
  windowstarttime = millis();
  
  myPIDbot.SetOutputLimits(0,windowsize);
  myPIDtop.SetOutputLimits(0,windowsize);
  myPIDbotex.SetOutputLimits(0,windowsize);
  myPIDtopex.SetOutputLimits(0,windowsize);


  // ------------------------------------------------
  // Create graphic elements
  // ------------------------------------------------
  InitGUIslice_gen();

}

// -----------------------------------
// Main event loop
// -----------------------------------
void loop()
{
  Force = actPressure * Forcefactor;
  Force = Force / 100;
  Force = round(Force);
  Force = 100 * Force;

//set relay states

  if (pistonposition == 1){
    digitalWrite(RELAY_PINK5, LOW);
    digitalWrite(RELAY_PINK4, HIGH);
    gslc_ElemSetCol(&m_gui,K5,GSLC_COL_BLUE_DK4,GSLC_COL_BROWN,GSLC_COL_BLUE_DK4);
    gslc_ElemSetCol(&m_gui,K4,GSLC_COL_BLUE_DK4,GSLC_COL_GREEN,GSLC_COL_BLUE_DK4); 
  } 

  else if (pistonposition==2){
    digitalWrite(RELAY_PINK4, LOW);
    digitalWrite(RELAY_PINK5, HIGH);
    gslc_ElemSetCol(&m_gui,K4,GSLC_COL_BLUE_DK4,GSLC_COL_BROWN,GSLC_COL_BLUE_DK4);
    gslc_ElemSetCol(&m_gui,K5,GSLC_COL_BLUE_DK4,GSLC_COL_GREEN,GSLC_COL_BLUE_DK4);
  }

  else if (pistonposition == 0){
    digitalWrite(RELAY_PINK4, LOW);
    digitalWrite(RELAY_PINK5, LOW);
    gslc_ElemSetCol(&m_gui,K4,GSLC_COL_BLUE_DK4,GSLC_COL_BROWN,GSLC_COL_BLUE_DK4);
    gslc_ElemSetCol(&m_gui,K5,GSLC_COL_BLUE_DK4,GSLC_COL_BROWN,GSLC_COL_BLUE_DK4);
  }

  
  if (coolerstate==0){
    digitalWrite(RELAY_PINK6, LOW);
    gslc_ElemSetCol(&m_gui,K6,GSLC_COL_BLUE_DK4,GSLC_COL_BROWN,GSLC_COL_BLUE_DK4);
    gslc_ElemSetCol(&m_gui,cooler,GSLC_COL_BLUE_DK4,GSLC_COL_GRAY,GSLC_COL_BLUE_DK4);
  }
  else if (coolerstate==1){
    digitalWrite(RELAY_PINK6, HIGH);
    gslc_ElemSetCol(&m_gui,K6,GSLC_COL_BLUE_DK4,GSLC_COL_GREEN,GSLC_COL_BLUE_DK4);
    gslc_ElemSetCol(&m_gui,cooler,GSLC_COL_BLUE_DK4,GSLC_COL_GREEN,GSLC_COL_BLUE_DK4);
  }

  if (heatingstate==0){
    myPIDbot.SetMode(MANUAL);
    myPIDtop.SetMode(MANUAL);
    myPIDbotex.SetMode(MANUAL);
    myPIDtopex.SetMode(MANUAL);
    Outputtop = 0;
    Outputbot = 0;
    Outputtopex = 0;
    Outputbotex = 0;

    gslc_ElemSetCol(&m_gui,HEATING,GSLC_COL_BLUE_DK4,GSLC_COL_GRAY,GSLC_COL_BLUE_DK4);
    gslc_ElemSetTxtCol(&m_gui,HEATING,GSLC_COL_RED);

    digitalWrite(RELAY_PINK1, LOW);
    gslc_ElemSetCol(&m_gui,K1,GSLC_COL_BLUE_DK4,GSLC_COL_BROWN,GSLC_COL_BLUE_DK4);
    digitalWrite(RELAY_PINK2, LOW);
    gslc_ElemSetCol(&m_gui,K2,GSLC_COL_BLUE_DK4,GSLC_COL_BROWN,GSLC_COL_BLUE_DK4);
    digitalWrite(RELAY_PINK3, LOW);
    gslc_ElemSetCol(&m_gui,K3,GSLC_COL_BLUE_DK4,GSLC_COL_BROWN,GSLC_COL_BLUE_DK4);
  }
  else if(heatingstate==1){

    if (useexternalTbot==1){
      Inputbotex=t6;
      myPIDbotex.SetMode(AUTOMATIC);
      myPIDbotex.Compute();

      if (millis() - windowstarttime > windowsize)
      { //time to shift the Relay Window
      windowstarttime += windowsize;
      }
      if (Outputbotex > millis() - windowstarttime) heatingstateK1and2=1;
      else heatingstateK1and2=0;

    }
    else if(useexternalTbot==0){
      Inputbot=t2;
      myPIDbot.SetMode(AUTOMATIC);
      myPIDbot.Compute();

      if (millis() - windowstarttime > windowsize)
      { //time to shift the Relay Window
      windowstarttime += windowsize;
      }
      if (Outputbot > millis() - windowstarttime) heatingstateK1and2=1;
      else heatingstateK1and2=0;
    }
    if (useexternalTtop==1){
      Inputtopex=t5;
      myPIDtopex.SetMode(AUTOMATIC);
      myPIDtopex.Compute();

      if (millis() - windowstarttime > windowsize)
      { //time to shift the Relay Window
      windowstarttime += windowsize;
      }
      if (Outputtopex > millis() - windowstarttime) heatingstateK3=1;
      else heatingstateK3=0;
    }
    else if (useexternalTtop==0){
      Inputtop=t3;
      myPIDtop.SetMode(AUTOMATIC);
      myPIDtop.Compute();

      if (millis() - windowstarttime > windowsize)
      { //time to shift the Relay Window
      windowstarttime += windowsize;
      }
      if (Outputtop > millis() - windowstarttime) heatingstateK3=1;
      else heatingstateK3=0;
    }
    


    gslc_ElemSetCol(&m_gui,HEATING,GSLC_COL_BLUE_DK4,GSLC_COL_RED,GSLC_COL_BLUE_DK4);
    gslc_ElemSetTxtCol(&m_gui,HEATING,GSLC_COL_BLACK);

    if (heatingstateK1and2==0){
      digitalWrite(RELAY_PINK1, LOW);
      gslc_ElemSetCol(&m_gui,K1,GSLC_COL_BLUE_DK4,GSLC_COL_BROWN,GSLC_COL_BLUE_DK4);
      digitalWrite(RELAY_PINK2, LOW);
      gslc_ElemSetCol(&m_gui,K2,GSLC_COL_BLUE_DK4,GSLC_COL_BROWN,GSLC_COL_BLUE_DK4);
    }
    else if (heatingstateK1and2==1){
      digitalWrite(RELAY_PINK1, HIGH);
      gslc_ElemSetCol(&m_gui,K1,GSLC_COL_BLUE_DK4,GSLC_COL_GREEN,GSLC_COL_BLUE_DK4);
      digitalWrite(RELAY_PINK2, HIGH);
      gslc_ElemSetCol(&m_gui,K2,GSLC_COL_BLUE_DK4,GSLC_COL_GREEN,GSLC_COL_BLUE_DK4);
    }
    if (heatingstateK3==0){
      digitalWrite(RELAY_PINK3, LOW);
      gslc_ElemSetCol(&m_gui,K3,GSLC_COL_BLUE_DK4,GSLC_COL_BROWN,GSLC_COL_BLUE_DK4);
    }
    else if (heatingstateK3==1){
      digitalWrite(RELAY_PINK3, HIGH);
      gslc_ElemSetCol(&m_gui,K3,GSLC_COL_BLUE_DK4,GSLC_COL_GREEN,GSLC_COL_BLUE_DK4);
    }
  }

  
  //end set relay states

  
  //Take Poti Values and set
  // runEvery(500){
    totaltempFloat1 = totaltempFloat1 - readingstempFloat1[tempFloat1readIndex];
    readingstempFloat1[tempFloat1readIndex] = analogRead(A15);
    totaltempFloat1 = totaltempFloat1 + readingstempFloat1[tempFloat1readIndex];
    tempFloat1readIndex++;
    if (tempFloat1readIndex >= numReadings) tempFloat1readIndex = 0;
    averagetempFloat1 = totaltempFloat1 / numReadings;
    OCR5B = (averagetempFloat1/1023) * 60000;


    totaltempFloat2 = totaltempFloat2 - readingstempFloat2[tempFloat2readIndex];
    readingstempFloat2[tempFloat2readIndex] = analogRead(A6);
    totaltempFloat2 = totaltempFloat2 + readingstempFloat2[tempFloat2readIndex];
    tempFloat2readIndex++;
    if (tempFloat2readIndex >= numReadings) tempFloat2readIndex = 0;
    averagetempFloat2 = totaltempFloat2 / numReadings;
    float newSETTOP = (averagetempFloat2/1023) * 260;

    totaltempFloat3 = totaltempFloat3 - readingstempFloat3[tempFloat3readIndex];
    readingstempFloat3[tempFloat3readIndex] = analogRead(A7);
    totaltempFloat3 = totaltempFloat3 + readingstempFloat3[tempFloat3readIndex];
    tempFloat3readIndex++;
    if (tempFloat3readIndex >= numReadings) tempFloat3readIndex = 0;
    averagetempFloat3 = totaltempFloat3 / numReadings;
    float newSETBOT = (averagetempFloat3/1023) * 260;
    
    totaltempFloat4 = totaltempFloat4 - readingstempFloat4[tempFloat4readIndex];
    readingstempFloat4[tempFloat4readIndex] = analogRead(A14);
    totaltempFloat4 = totaltempFloat4 + readingstempFloat4[tempFloat4readIndex];
    tempFloat4readIndex++;
    if (tempFloat4readIndex >= numReadings) tempFloat4readIndex = 0;
    averagetempFloat4 = totaltempFloat4 / numReadings;
    float newPressure = 1.02*((averagetempFloat4/1023) * maxPressure); //correction factor 1.02

    runEvery(700){

      if (Setpointbot != newSETBOT){
        Setpointbot = newSETBOT;
        Setpointbotex = newSETBOT;
        dtostrf(newSETBOT, 3,0, tbuffer);
        sprintf(tbuffer, "%s", tbuffer);
        gslc_ElemSetTxtStr(&m_gui, Tbotset, tbuffer);
      }
      
      if (Setpointtop != newSETTOP){
        Setpointtop = newSETTOP;
        Setpointtopex = newSETTOP;
        dtostrf(newSETTOP, 3,0, tbuffer);
        sprintf(tbuffer, "%s", tbuffer);
        gslc_ElemSetTxtStr(&m_gui, Ttopset, tbuffer);
      }
      if (actPressure != newPressure){
         actPressure = newPressure;
         if (actPressure>9.9){ actPressure = 9.9;}
         if (showForce==0){
            dtostrf(newPressure, 3,1, tbuffer);
            sprintf(tbuffer, "%s", tbuffer);
            gslc_ElemSetTxtStr(&m_gui, Psetp, tbuffer);
            gslc_ElemSetTxtStr(&m_gui, SETPLABEL, "Pressure(Bar)");

         }
         if (showForce==1){
            dtostrf(Force,4,0,tbuffer);
            sprintf(tbuffer, "%s", tbuffer);
            gslc_ElemSetTxtStr(&m_gui, Psetp, tbuffer);
            gslc_ElemSetTxtStr(&m_gui, SETPLABEL, "Force (N)");
          }
      }
    } 
  // }

  //end poti value set block

  //read temperatures from NTCs


  

  totalt1temp = totalt1temp - readingst1temp[t1tempreadIndex];
  readingst1temp[t1tempreadIndex] = analogRead(tt1);
  totalt1temp = totalt1temp + readingst1temp[t1tempreadIndex];
  t1tempreadIndex++;
  if (t1tempreadIndex >= numReadings) t1tempreadIndex = 0;
  averaget1temp = totalt1temp / numReadings;
  if (averaget1temp>0) t1temp = Thermistor(averaget1temp);
  if (t1temp > 0 && t1temp < 260){t1 = t1temp;}
  
  totalt2temp = totalt2temp - readingst2temp[t2tempreadIndex];
  readingst2temp[t2tempreadIndex] = analogRead(tt2);
  totalt2temp = totalt2temp + readingst2temp[t2tempreadIndex];
  t2tempreadIndex++;
  if (t2tempreadIndex >= numReadings) t2tempreadIndex = 0;
  averaget2temp = totalt2temp / numReadings;
  if (averaget2temp>0) t2temp = Thermistor(averaget2temp);
  if (t2temp > 0 && t2temp < 260){t2 = t2temp;}

  totalt3temp = totalt3temp - readingst3temp[t3tempreadIndex];
  readingst3temp[t3tempreadIndex] = analogRead(tt3);
  totalt3temp = totalt3temp + readingst3temp[t3tempreadIndex];
  t3tempreadIndex++;
  if (t3tempreadIndex >= numReadings) t3tempreadIndex = 0;
  averaget3temp = totalt3temp / numReadings;
  if (averaget3temp>0) t3temp = Thermistor(averaget3temp);
  if (t3temp > 0 && t3temp < 260){t3 = t3temp;}

  totalt4temp = totalt4temp - readingst4temp[t4tempreadIndex];
  readingst4temp[t4tempreadIndex] = analogRead(tt4);
  totalt4temp = totalt4temp + readingst4temp[t4tempreadIndex];
  t4tempreadIndex++;
  if (t4tempreadIndex >= numReadings) t4tempreadIndex = 0;
  averaget4temp = totalt4temp / numReadings;
  if (averaget4temp>0) t4temp = Thermistor(averaget4temp);
  if (t4temp > 0 && t4temp < 260){t4 = t4temp;}

  totalt5temp = totalt5temp - readingst5temp[t5tempreadIndex];
  readingst5temp[t5tempreadIndex] = analogRead(tt5);
  totalt5temp = totalt5temp + readingst5temp[t5tempreadIndex];
  t5tempreadIndex++;
  if (t5tempreadIndex >= numReadings) t5tempreadIndex = 0;
  averaget5temp = totalt5temp / numReadings;
  if (averaget5temp>0) t5temp = Thermistor(averaget5temp);
  if (t5temp > 0 && t5temp < 260){t5 = t5temp;}

  totalt6temp = totalt6temp - readingst6temp[t6tempreadIndex];
  readingst6temp[t6tempreadIndex] = analogRead(tt6);
  totalt6temp = totalt6temp + readingst6temp[t6tempreadIndex];
  t6tempreadIndex++;
  if (t6tempreadIndex >= numReadings) t6tempreadIndex = 0;
  averaget6temp = totalt6temp / numReadings;
  if (averaget6temp>0) t6temp = Thermistor(averaget6temp);
  if (t6temp > 0 && t6temp < 260){t6 = t6temp;}




  //end read temperatures block

  //update display temperatures
  runEvery(700){
    dtostrf(t1, 3,0, tbuffer);  
    sprintf(tbuffer, "%s", tbuffer);
    gslc_ElemSetTxtStr(&m_gui, Tbot2, tbuffer);
    
    dtostrf(t2, 3,0, tbuffer);
    sprintf(tbuffer, "%s", tbuffer);
    gslc_ElemSetTxtStr(&m_gui, Tbot, tbuffer);
    
    dtostrf(t3, 3,0, tbuffer);
    sprintf(tbuffer, "%s", tbuffer);
    gslc_ElemSetTxtStr(&m_gui, Ttop, tbuffer);
    
    dtostrf(t4, 3,0, tbuffer);
    sprintf(tbuffer, "%s", tbuffer);
    gslc_ElemSetTxtStr(&m_gui, Tpist, tbuffer);
    
    dtostrf(t5, 3,0, tbuffer);
    sprintf(tbuffer, "%s", tbuffer);
    gslc_ElemSetTxtStr(&m_gui, Ttopex, tbuffer);
    
    dtostrf(t6, 3,0, tbuffer);
    sprintf(tbuffer, "%s", tbuffer);
    gslc_ElemSetTxtStr(&m_gui, Tbotex, tbuffer);
  }

  //end update display temperatures

  //temperature control

    //set NTC ext/int display
    if (useexternalTbot==0){
      gslc_ElemSetTxtCol(&m_gui,Tbotset,GSLC_COL_ORANGE);
      gslc_ElemSetTxtCol(&m_gui,TBOTSETLABEL,GSLC_COL_ORANGE);
    }
    else if (useexternalTbot==1){
      gslc_ElemSetTxtCol(&m_gui,Tbotset,GSLC_COL_RED);
      gslc_ElemSetTxtCol(&m_gui,TBOTSETLABEL,GSLC_COL_RED);
    }
    if (useexternalTtop==0){
      gslc_ElemSetTxtCol(&m_gui,Ttopset,GSLC_COL_WHITE);
      gslc_ElemSetTxtCol(&m_gui,TTOPSETLABEL,GSLC_COL_WHITE);
    }
    else if (useexternalTtop==1){
      gslc_ElemSetTxtCol(&m_gui,Ttopset,GSLC_COL_PURPLE);
      gslc_ElemSetTxtCol(&m_gui,TTOPSETLABEL,GSLC_COL_PURPLE);
    }

    //end set NTC ext/int display

    //Graph Ttopset and Tbotset and Ttop/Ttopex and Tbot/Tbotex

  
  //end temperature control

  runEvery(5000){
    Serial.println(t5);
    Serial.println(t6);
    Serial.println(Force);
    Serial.println(actPressure);
    Serial.println(pistonposition);
    Serial.println("---------------");
  }
  // ------------------------------------------------
  // Update GUI Elements
  // ------------------------------------------------
  
  //TODO - Add update code for any text, gauges, or sliders
  
  // ------------------------------------------------
  // Periodically call GUIslice update function
  // ------------------------------------------------
  gslc_Update(&m_gui);
    
}
