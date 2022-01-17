/*
Wiring PIN
   Panel HUB75  PIN ESP32
    R1_PIN       GPIO_NUM_19     
    G1_PIN       GPIO_NUM_13    
    B1_PIN       GPIO_NUM_18   
    R2_PIN       GPIO_NUM_5    
    G2_PIN       GPIO_NUM_12   
    B2_PIN       GPIO_NUM_17    
    A_PIN        GPIO_NUM_16    
    B_PIN        GPIO_NUM_14   
    C_PIN        GPIO_NUM_4    
    D_PIN        GPIO_NUM_27    
    E_PIN        GPIO_NUM_0    
    LAT_PIN      GPIO_NUM_26    
    OE_PIN       GPIO_NUM_15    
    CLK_PIN      GPIO_NUM_2    
*/ 

#define USE_ADAFRUIT_GFX_LAYERS
#include <MatrixHardware_ESP32_V0.h>   
#include <SmartMatrix.h>

#include <Fonts/Picopixel.h>
#include <Fonts/TomThumb.h>
#include <Fonts/FreeMono12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBoldOblique24pt7b.h>
#include <Fonts/FreeSerif24pt7b.h>
#include <Fonts/Org_01.h>
#include <Fonts/Tiny3x3a2pt7b.h>
#include <Fonts/FreeSerifItalic9pt7b.h>
#include <Fonts/FreeSansOblique24pt7b.h>
#include <Fonts/FreeSansBold12pt7b.h>
#include <Fonts/FreeMonoBoldOblique9pt7b.h>
#include <Fonts/FreeMonoBold9pt7b.h>
           
#define COLOR_DEPTH 24            
const uint16_t kMatrixWidth = 64;       
const uint16_t kMatrixHeight =32;     
const uint8_t kRefreshDepth = 36;    
const uint8_t kDmaBufferRows = 4;      
// const uint8_t kPanelType = SM_PANELTYPE_HUB75_16ROW_32COL_MOD4SCAN_V2; //typeScan p10 RGB
const uint8_t kPanelType = SMARTMATRIX_HUB75_32ROW_MOD16SCAN; //Type panel P5 RGB
//const uint8_t kPanelType = SM_PANELTYPE_HUB75_16ROW_32COL_MOD4SCAN_V2; //typeScan p10 RGB
const uint32_t kMatrixOptions = (SM_HUB75_OPTIONS_NONE);      

const uint8_t kIndexedLayerOptions = (SM_INDEXED_OPTIONS_NONE);
const uint8_t kScrollingLayerOptions = (SM_SCROLLING_OPTIONS_NONE);

SMARTMATRIX_ALLOCATE_BUFFERS(matrix, kMatrixWidth, kMatrixHeight, kRefreshDepth, kDmaBufferRows, kPanelType, kMatrixOptions);

#ifdef INCLUDE_FASTLED_BACKGROUND
  const uint8_t kBackgroundLayerOptions = (SM_BACKGROUND_OPTIONS_NONE);
  SMARTMATRIX_ALLOCATE_BACKGROUND_LAYER(backgroundLayer, kMatrixWidth, kMatrixHeight, COLOR_DEPTH, kBackgroundLayerOptions);
#endif

SMARTMATRIX_ALLOCATE_SCROLLING_LAYER(scrollingLayer1, kMatrixWidth, kMatrixHeight, COLOR_DEPTH, kScrollingLayerOptions);
SMARTMATRIX_ALLOCATE_SCROLLING_LAYER(scrollingLayer2, kMatrixWidth, kMatrixHeight, COLOR_DEPTH, kScrollingLayerOptions);
SMARTMATRIX_ALLOCATE_SCROLLING_LAYER(scrollingLayer3, kMatrixWidth, kMatrixHeight, COLOR_DEPTH, kScrollingLayerOptions);
SMARTMATRIX_ALLOCATE_INDEXED_LAYER(indexedLayer1, kMatrixWidth, kMatrixHeight, COLOR_DEPTH, kIndexedLayerOptions);
SMARTMATRIX_ALLOCATE_INDEXED_LAYER(indexedLayer2, kMatrixWidth, kMatrixHeight, COLOR_DEPTH, kIndexedLayerOptions);
SMARTMATRIX_ALLOCATE_INDEXED_LAYER(indexedLayer3, kMatrixWidth, kMatrixHeight, COLOR_DEPTH, kIndexedLayerOptions);

SMARTMATRIX_ALLOCATE_GFX_MONO_LAYER(scrollingLayer5, kMatrixWidth, kMatrixHeight, 6*1024, 1, COLOR_DEPTH, kScrollingLayerOptions);
SMARTMATRIX_ALLOCATE_GFX_MONO_LAYER(scrollingLayer4, kMatrixWidth, kMatrixHeight, 8832, 20, COLOR_DEPTH, kScrollingLayerOptions);

void setup() {
  Serial.begin(115200);
    matrix.addLayer(&scrollingLayer1); 
    matrix.addLayer(&scrollingLayer2);
    matrix.addLayer(&scrollingLayer3);
    matrix.addLayer(&scrollingLayer4);
    matrix.addLayer(&scrollingLayer5);
    matrix.addLayer(&indexedLayer1);
    matrix.addLayer(&indexedLayer2);
    matrix.addLayer(&indexedLayer3);
     
    matrix.begin();
 
 }

void loop() {
 Text1();
 Text2();
 // TextBerjalan();
 TextBerjalan1();
 delay(23000);
 }

//-----------------------------------------------------------
void TextBerjalan(){
  scrollingLayer5.setMode(wrapForward);
  scrollingLayer5.setColor({0xff, 0x00, 0xbf});
  scrollingLayer5.setSpeed(20);
  scrollingLayer5.setFont(&FreeMono12pt7b);
  scrollingLayer5.setOffsetFromTop(0);
  scrollingLayer5.start("SEDIA ALAT-ALAT ELEKTRONIK, ALAT LISTRIK DAN CUTTING STIKER", -1);
  }
  
//-------------------------------------------
void TextBerjalan1(){
  scrollingLayer4.setMode(wrapForward);
  scrollingLayer4.setColor({0xff, 0x00, 0xff});
  scrollingLayer4.setSpeed(40);
  scrollingLayer4.setFont(&FreeMonoBold9pt7b);
  scrollingLayer4.setOffsetFromTop(16);
  scrollingLayer4.start("SEDIA ALAT-ALAT ELEKTRONIK, ALAT LISTRIK DAN CUTTING STIKER", -1);
  }
  
  //------------------------------------
  void Text1(){
    indexedLayer1.fillScreen(0); // Clear layar
    indexedLayer1.setFont(font6x10);
    indexedLayer1.drawString(3,1,1,"TOKO MULTI");
    indexedLayer1.swapBuffers();   
  }

   //------------------------------------
  void Text2(){
    indexedLayer2.fillScreen(0); // Clear layar
    indexedLayer2.setFont(font6x10);
    indexedLayer2.setIndexedColor(1,{0x00, 0xFF, 0x00});
    indexedLayer2.drawString(12,9,1,"KEJAYAN");
    indexedLayer2.swapBuffers();   
  }
