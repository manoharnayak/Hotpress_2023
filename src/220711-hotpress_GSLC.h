//<File !Start!>
// FILE: [220711-hotpress_GSLC.h]
// Created by GUIslice Builder version: [0.17.b11]
//
// GUIslice Builder Generated GUI Framework File
//
// For the latest guides, updates and support view:
// https://github.com/ImpulseAdventure/GUIslice
//
//<File !End!>

#ifndef _GUISLICE_GEN_H
#define _GUISLICE_GEN_H

// ------------------------------------------------
// Headers to include
// ------------------------------------------------
#include "GUIslice.h"
#include "GUIslice_drv.h"

// Include any extended elements
//<Includes !Start!>
//<Includes !End!>

// ------------------------------------------------
// Headers and Defines for fonts
// Note that font files are located within the Adafruit-GFX library folder:
// ------------------------------------------------
//<Fonts !Start!>
#if defined(DRV_DISP_TFT_ESPI)
  #error Project tab->Target Platform should be tft_espi
#endif
#include <Adafruit_GFX.h>
//<Fonts !End!>

// ------------------------------------------------
// Defines for resources
// ------------------------------------------------
//<Resources !Start!>
extern "C" const unsigned short IFM110x110[] PROGMEM;
//<Resources !End!>

// ------------------------------------------------
// Enumerations for pages, elements, fonts, images
// ------------------------------------------------
//<Enum !Start!>
enum {E_PG_MAIN};
enum {E_ELEM_BTN10_COOLER,E_ELEM_BTN11_HEATING,E_ELEM_BTN12_TTOPSET
      ,E_ELEM_BTN13_TBOTSET,E_ELEM_BTN14_SETP,E_ELEM_BTN7_PUP
      ,E_ELEM_BTN8_PDOWN,E_ELEM_BTN9_PNULL,E_ELEM_IMAGE5
      ,E_ELEM_TEXT10_TBOT2,E_ELEM_TEXT11_K3,E_ELEM_TEXT12_K4
      ,E_ELEM_TEXT13_K5,E_ELEM_TEXT14_K6,E_ELEM_TEXT15_TPISTLABEL
      ,E_ELEM_TEXT16_TTOPLABEL,E_ELEM_TEXT17_TTOPEXLABEL
      ,E_ELEM_TEXT18_TBOTEXLABEL,E_ELEM_TEXT19_TBOT,E_ELEM_TEXT20_TBOT2
      ,E_ELEM_TEXT21_TTOPSETLABEL,E_ELEM_TEXT22_TBOTSETLABEL
      ,E_ELEM_TEXT23_SETPLABEL,E_ELEM_TEXT2_TTOP,E_ELEM_TEXT3_TBOT
      ,E_ELEM_TEXT5_K1,E_ELEM_TEXT6_K2,E_ELEM_TEXT7_TTOPEX
      ,E_ELEM_TEXT8_TBOTEX,E_ELEM_TEXT9_TPIST};
// Must use separate enum for fonts with MAX_FONT at end to use gslc_FontSet.
enum {E_BUILTIN10X16,E_BUILTIN25X40,MAX_FONT};
//<Enum !End!>

// ------------------------------------------------
// Instantiate the GUI
// ------------------------------------------------

// ------------------------------------------------
// Define the maximum number of elements and pages
// ------------------------------------------------
//<ElementDefines !Start!>
#define MAX_PAGE                1

#define MAX_ELEM_PG_MAIN 30 // # Elems total on page
#define MAX_ELEM_PG_MAIN_RAM MAX_ELEM_PG_MAIN // # Elems in RAM
//<ElementDefines !End!>

// ------------------------------------------------
// Create element storage
// ------------------------------------------------
gslc_tsGui                      m_gui;
gslc_tsDriver                   m_drv;
gslc_tsFont                     m_asFont[MAX_FONT];
gslc_tsPage                     m_asPage[MAX_PAGE];

//<GUI_Extra_Elements !Start!>
gslc_tsElem                     m_asPage1Elem[MAX_ELEM_PG_MAIN_RAM];
gslc_tsElemRef                  m_asPage1ElemRef[MAX_ELEM_PG_MAIN];

#define MAX_STR                 200

//<GUI_Extra_Elements !End!>

// ------------------------------------------------
// Program Globals
// ------------------------------------------------

// Element References for direct access
//<Extern_References !Start!>
extern gslc_tsElemRef* HEATING;
extern gslc_tsElemRef* K1;
extern gslc_tsElemRef* K2;
extern gslc_tsElemRef* K3;
extern gslc_tsElemRef* K4;
extern gslc_tsElemRef* K5;
extern gslc_tsElemRef* K6;
extern gslc_tsElemRef* Pdown;
extern gslc_tsElemRef* Pnull;
extern gslc_tsElemRef* Psetp;
extern gslc_tsElemRef* Pup;
extern gslc_tsElemRef* SETPLABEL;
extern gslc_tsElemRef* TBOTSETLABEL;
extern gslc_tsElemRef* TTOPSETLABEL;
extern gslc_tsElemRef* Tbot;
extern gslc_tsElemRef* Tbot2;
extern gslc_tsElemRef* Tbotex;
extern gslc_tsElemRef* Tbotset;
extern gslc_tsElemRef* Tpist;
extern gslc_tsElemRef* Ttop;
extern gslc_tsElemRef* Ttopex;
extern gslc_tsElemRef* Ttopset;
extern gslc_tsElemRef* cooler;
//<Extern_References !End!>

// Define debug message function
static int16_t DebugOut(char ch);

// ------------------------------------------------
// Callback Methods
// ------------------------------------------------
bool CbBtnCommon(void* pvGui,void *pvElemRef,gslc_teTouch eTouch,int16_t nX,int16_t nY);
bool CbCheckbox(void* pvGui, void* pvElemRef, int16_t nSelId, bool bState);
bool CbDrawScanner(void* pvGui,void* pvElemRef,gslc_teRedrawType eRedraw);
bool CbKeypad(void* pvGui, void *pvElemRef, int16_t nState, void* pvData);
bool CbListbox(void* pvGui, void* pvElemRef, int16_t nSelId);
bool CbSlidePos(void* pvGui,void* pvElemRef,int16_t nPos);
bool CbSpinner(void* pvGui, void *pvElemRef, int16_t nState, void* pvData);
bool CbTickScanner(void* pvGui,void* pvScope);

// ------------------------------------------------
// Create page elements
// ------------------------------------------------
void InitGUIslice_gen()
{
  gslc_tsElemRef* pElemRef = NULL;

  if (!gslc_Init(&m_gui,&m_drv,m_asPage,MAX_PAGE,m_asFont,MAX_FONT)) { return; }

  // ------------------------------------------------
  // Load Fonts
  // ------------------------------------------------
//<Load_Fonts !Start!>
    if (!gslc_FontSet(&m_gui,E_BUILTIN10X16,GSLC_FONTREF_PTR,NULL,2)) { return; }
    if (!gslc_FontSet(&m_gui,E_BUILTIN25X40,GSLC_FONTREF_PTR,NULL,5)) { return; }
//<Load_Fonts !End!>

//<InitGUI !Start!>
  gslc_PageAdd(&m_gui,E_PG_MAIN,m_asPage1Elem,MAX_ELEM_PG_MAIN_RAM,m_asPage1ElemRef,MAX_ELEM_PG_MAIN);

  // NOTE: The current page defaults to the first page added. Here we explicitly
  //       ensure that the main page is the correct page no matter the add order.
  gslc_SetPageCur(&m_gui,E_PG_MAIN);
  
  // Set Background to a flat color
  gslc_SetBkgndColor(&m_gui,GSLC_COL_BLACK);

  // -----------------------------------
  // PAGE: E_PG_MAIN
  
  
  // Create E_ELEM_TEXT15_TPISTLABEL text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT15_TPISTLABEL,E_PG_MAIN,(gslc_tsRect){224,0,192,32},
    (char*)"Piston T (C)",0,E_BUILTIN10X16);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLUE_DK4,GSLC_COL_BLACK,GSLC_COL_BLACK);
  
  // Create E_ELEM_TEXT16_TTOPLABEL text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT16_TTOPLABEL,E_PG_MAIN,(gslc_tsRect){224,32,192,32},
    (char*)"Top Plate T (C)",0,E_BUILTIN10X16);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLUE_DK4,GSLC_COL_BLACK,GSLC_COL_BLACK);
  
  // Create E_ELEM_TEXT17_TTOPEXLABEL text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT17_TTOPEXLABEL,E_PG_MAIN,(gslc_tsRect){224,64,192,32},
    (char*)"Tool Top T (C)",0,E_BUILTIN10X16);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_PURPLE);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLUE_DK4,GSLC_COL_BLACK,GSLC_COL_BLACK);
  
  // Create E_ELEM_TEXT18_TBOTEXLABEL text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT18_TBOTEXLABEL,E_PG_MAIN,(gslc_tsRect){224,96,192,32},
    (char*)"Tool Bot T (C)",0,E_BUILTIN10X16);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_RED);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLUE_DK4,GSLC_COL_BLACK,GSLC_COL_BLACK);
  
  // Create E_ELEM_TEXT19_TBOT text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT19_TBOT,E_PG_MAIN,(gslc_tsRect){224,128,192,32},
    (char*)"Bot Plate T (C)",0,E_BUILTIN10X16);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_ORANGE);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLUE_DK4,GSLC_COL_BLACK,GSLC_COL_BLACK);
  
  // Create E_ELEM_TEXT20_TBOT2 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT20_TBOT2,E_PG_MAIN,(gslc_tsRect){224,160,192,32},
    (char*)"Water Tank T (C)",0,E_BUILTIN10X16);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLUE_DK4,GSLC_COL_BLACK,GSLC_COL_BLACK);
  
  // Create E_ELEM_TEXT21_TTOPSETLABEL runtime modifiable text
  static char m_sDisplayText21[15] = "Set Top T (C)";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT21_TTOPSETLABEL,E_PG_MAIN,(gslc_tsRect){128,192,160,42},
    (char*)m_sDisplayText21,15,E_BUILTIN10X16);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLUE_DK4,GSLC_COL_BLACK,GSLC_COL_BLACK);
  TTOPSETLABEL = pElemRef;
  
  // Create E_ELEM_TEXT22_TBOTSETLABEL runtime modifiable text
  static char m_sDisplayText22[15] = "Set Bot T (C)";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT22_TBOTSETLABEL,E_PG_MAIN,(gslc_tsRect){128,235,160,42},
    (char*)m_sDisplayText22,15,E_BUILTIN10X16);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_ORANGE);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLUE_DK4,GSLC_COL_BLACK,GSLC_COL_BLACK);
  TBOTSETLABEL = pElemRef;
  
  // Create E_ELEM_TEXT23_SETPLABEL runtime modifiable text
  static char m_sDisplayText23[16] = "Pressure(Bar)";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT23_SETPLABEL,E_PG_MAIN,(gslc_tsRect){128,278,160,42},
    (char*)m_sDisplayText23,16,E_BUILTIN10X16);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_TEAL);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLUE_DK4,GSLC_COL_BLACK,GSLC_COL_BLACK);
  SETPLABEL = pElemRef;
  
  // Create E_ELEM_TEXT9_TPIST runtime modifiable text
  static char m_sDisplayText9[5] = "260";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT9_TPIST,E_PG_MAIN,(gslc_tsRect){416,0,64,32},
    (char*)m_sDisplayText9,5,E_BUILTIN10X16);
  gslc_ElemSetTxtMargin(&m_gui,pElemRef,5);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLUE_DK4,GSLC_COL_BLACK,GSLC_COL_BLUE_DK4);
  Tpist = pElemRef;
  
  // Create E_ELEM_TEXT2_TTOP runtime modifiable text
  static char m_sDisplayText2[5] = "260";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT2_TTOP,E_PG_MAIN,(gslc_tsRect){416,32,64,32},
    (char*)m_sDisplayText2,5,E_BUILTIN10X16);
  gslc_ElemSetTxtMargin(&m_gui,pElemRef,5);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLUE_DK4,GSLC_COL_BLACK,GSLC_COL_BLUE_DK4);
  Ttop = pElemRef;
  
  // Create E_ELEM_TEXT7_TTOPEX runtime modifiable text
  static char m_sDisplayText7[5] = "260";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT7_TTOPEX,E_PG_MAIN,(gslc_tsRect){416,64,64,32},
    (char*)m_sDisplayText7,5,E_BUILTIN10X16);
  gslc_ElemSetTxtMargin(&m_gui,pElemRef,5);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_PURPLE);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLUE_DK4,GSLC_COL_BLACK,GSLC_COL_BLUE_DK4);
  Ttopex = pElemRef;
  
  // Create E_ELEM_TEXT8_TBOTEX runtime modifiable text
  static char m_sDisplayText8[5] = "260";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT8_TBOTEX,E_PG_MAIN,(gslc_tsRect){416,96,64,32},
    (char*)m_sDisplayText8,5,E_BUILTIN10X16);
  gslc_ElemSetTxtMargin(&m_gui,pElemRef,5);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_RED);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLUE_DK4,GSLC_COL_BLACK,GSLC_COL_BLUE_DK4);
  Tbotex = pElemRef;
  
  // Create E_ELEM_TEXT3_TBOT runtime modifiable text
  static char m_sDisplayText3[5] = "260";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT3_TBOT,E_PG_MAIN,(gslc_tsRect){416,128,64,32},
    (char*)m_sDisplayText3,5,E_BUILTIN10X16);
  gslc_ElemSetTxtMargin(&m_gui,pElemRef,5);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_ORANGE);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLUE_DK4,GSLC_COL_BLACK,GSLC_COL_BLUE_DK4);
  Tbot = pElemRef;
  
  // Create E_ELEM_TEXT10_TBOT2 runtime modifiable text
  static char m_sDisplayText10[5] = "260";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT10_TBOT2,E_PG_MAIN,(gslc_tsRect){416,160,64,32},
    (char*)m_sDisplayText10,5,E_BUILTIN10X16);
  gslc_ElemSetTxtMargin(&m_gui,pElemRef,5);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLUE_DK4,GSLC_COL_BLACK,GSLC_COL_BLUE_DK4);
  Tbot2 = pElemRef;
  
  // Create E_ELEM_TEXT5_K1 runtime modifiable text
  static char m_sDisplayText5[3] = "K1";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT5_K1,E_PG_MAIN,(gslc_tsRect){0,0,32,32},
    (char*)m_sDisplayText5,3,E_BUILTIN10X16);
  gslc_ElemSetTxtMargin(&m_gui,pElemRef,5);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLUE_DK4,GSLC_COL_BROWN,GSLC_COL_BLUE_DK4);
  K1 = pElemRef;
  
  // Create E_ELEM_TEXT6_K2 runtime modifiable text
  static char m_sDisplayText6[3] = "K2";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT6_K2,E_PG_MAIN,(gslc_tsRect){0,32,32,32},
    (char*)m_sDisplayText6,3,E_BUILTIN10X16);
  gslc_ElemSetTxtMargin(&m_gui,pElemRef,5);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLUE_DK4,GSLC_COL_BROWN,GSLC_COL_BLUE_DK4);
  K2 = pElemRef;
  
  // Create E_ELEM_TEXT11_K3 runtime modifiable text
  static char m_sDisplayText11[3] = "K3";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT11_K3,E_PG_MAIN,(gslc_tsRect){0,64,32,32},
    (char*)m_sDisplayText11,3,E_BUILTIN10X16);
  gslc_ElemSetTxtMargin(&m_gui,pElemRef,5);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLUE_DK4,GSLC_COL_BROWN,GSLC_COL_BLUE_DK4);
  K3 = pElemRef;
  
  // Create E_ELEM_TEXT12_K4 runtime modifiable text
  static char m_sDisplayText12[3] = "K4";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT12_K4,E_PG_MAIN,(gslc_tsRect){0,96,32,32},
    (char*)m_sDisplayText12,3,E_BUILTIN10X16);
  gslc_ElemSetTxtMargin(&m_gui,pElemRef,5);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLUE_DK4,GSLC_COL_BROWN,GSLC_COL_BLUE_DK4);
  K4 = pElemRef;
  
  // Create E_ELEM_TEXT13_K5 runtime modifiable text
  static char m_sDisplayText13[3] = "K5";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT13_K5,E_PG_MAIN,(gslc_tsRect){0,128,32,32},
    (char*)m_sDisplayText13,3,E_BUILTIN10X16);
  gslc_ElemSetTxtMargin(&m_gui,pElemRef,5);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLUE_DK4,GSLC_COL_BROWN,GSLC_COL_BLUE_DK4);
  K5 = pElemRef;
  
  // Create E_ELEM_TEXT14_K6 runtime modifiable text
  static char m_sDisplayText14[3] = "K6";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT14_K6,E_PG_MAIN,(gslc_tsRect){0,160,32,32},
    (char*)m_sDisplayText14,3,E_BUILTIN10X16);
  gslc_ElemSetTxtMargin(&m_gui,pElemRef,5);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLUE_DK4,GSLC_COL_BROWN,GSLC_COL_BLUE_DK4);
  K6 = pElemRef;
  
  // create E_ELEM_BTN7_PUP button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN7_PUP,E_PG_MAIN,
    (gslc_tsRect){32,0,96,96},(char*)"\x18",0,E_BUILTIN25X40,&CbBtnCommon);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_BLUE_DK4);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLUE_DK4,GSLC_COL_GRAY,GSLC_COL_BLUE_LT4);
  Pup = pElemRef;
  
  // create E_ELEM_BTN8_PDOWN button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN8_PDOWN,E_PG_MAIN,
    (gslc_tsRect){32,96,96,96},(char*)"\x19",0,E_BUILTIN25X40,&CbBtnCommon);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_BLUE_DK4);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLUE_DK4,GSLC_COL_GRAY,GSLC_COL_BLUE_LT4);
  Pdown = pElemRef;
  
  // create E_ELEM_BTN9_PNULL button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN9_PNULL,E_PG_MAIN,
    (gslc_tsRect){128,96,96,96},(char*)"o",0,E_BUILTIN25X40,&CbBtnCommon);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_BLUE_DK4);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLUE_DK4,GSLC_COL_GRAY,GSLC_COL_BLUE_LT4);
  Pnull = pElemRef;
  
  // create E_ELEM_BTN10_COOLER button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN10_COOLER,E_PG_MAIN,
    (gslc_tsRect){128,0,96,96},(char*)"C",0,E_BUILTIN25X40,&CbBtnCommon);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_BLUE_DK4);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLUE_DK4,GSLC_COL_GRAY,GSLC_COL_BLUE_LT4);
  cooler = pElemRef;
  
  // Create E_ELEM_BTN11_HEATING button with modifiable text label
  static char m_strbtn11[4] = "H";
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN11_HEATING,E_PG_MAIN,
    (gslc_tsRect){0,192,128,128},
    (char*)m_strbtn11,4,E_BUILTIN25X40,&CbBtnCommon);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_RED);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLUE_DK4,GSLC_COL_GRAY,GSLC_COL_BLUE_LT4);
  HEATING = pElemRef;
  
  // Create E_ELEM_BTN12_TTOPSET button with modifiable text label
  static char m_strbtn12[5] = "25";
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN12_TTOPSET,E_PG_MAIN,
    (gslc_tsRect){288,192,64,42},
    (char*)m_strbtn12,5,E_BUILTIN10X16,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLUE_DK4,GSLC_COL_BLACK,GSLC_COL_BLUE_LT4);
  Ttopset = pElemRef;
  
  // Create E_ELEM_BTN13_TBOTSET button with modifiable text label
  static char m_strbtn13[5] = "25";
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN13_TBOTSET,E_PG_MAIN,
    (gslc_tsRect){288,235,64,42},
    (char*)m_strbtn13,5,E_BUILTIN10X16,&CbBtnCommon);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_ORANGE);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLUE_DK4,GSLC_COL_BLACK,GSLC_COL_BLUE_LT4);
  Tbotset = pElemRef;
  
  // Create E_ELEM_BTN14_SETP button with modifiable text label
  static char m_strbtn14[6] = "2.5";
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN14_SETP,E_PG_MAIN,
    (gslc_tsRect){288,278,64,42},
    (char*)m_strbtn14,6,E_BUILTIN10X16,&CbBtnCommon);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_TEAL);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLUE_DK4,GSLC_COL_BLACK,GSLC_COL_BLUE_LT4);
  Psetp = pElemRef;
 
  // Create E_ELEM_IMAGE5 using Image 
  pElemRef = gslc_ElemCreateImg(&m_gui,E_ELEM_IMAGE5,E_PG_MAIN,(gslc_tsRect){361,201,110,110},
    gslc_GetImageFromProg((const unsigned char*)IFM110x110,GSLC_IMGREF_FMT_BMP24));
//<InitGUI !End!>

//<Startup !Start!>
  gslc_GuiRotate(&m_gui, 3);
//<Startup !End!>

}

#endif // end _GUISLICE_GEN_H