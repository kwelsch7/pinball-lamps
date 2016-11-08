#include <BallyLib.h>
#define CR_ROW   0
#define CR_COL   5
#define COIN_ROW 1
#define COIN_COL 0
#define DISPLAY 0

Bally bally;
int curRow = 0;
int curCol = 0;

void creditPressed()
{
  turnEmOff();
  // Advance column, cycle back to 0 if exceeds number of cols
  curCol++;
  curCol %= N_LAMP_COLS;
}
void coinPressed()
{
  turnEmOff();
  // Advance row, cycle back to 0 if exceeds number of rows
  curRow++;
  curRow %= N_LAMP_ROWS;
}
void testPressed()
{
  turnEmOff();
  // Reset row and col to 0, 0
  curRow = 0;
  curCol = 0;
}
void turnEmOff()
{
  //Turns of current lamp; called immediately before advancing to the new one
  bally.setLamp(curRow, curCol, false);
}
void lightEmUp()
{
  // Lights up the appropriate lamp
  bally.setLamp(curRow, curCol, true);
}
void displayRC()
{
  bally.setDisplay(DISPLAY, 4, '-');
  bally.setDisplay(DISPLAY, 5, '-');
  //Displays the current lamp location (row, col) on player1 score display
  if(curRow < 10)
  {
    bally.setDisplay(DISPLAY, 3, '0');
    bally.setDisplay(DISPLAY, 2, curRow);
    bally.setDisplay(DISPLAY, 1, '~');
    bally.setDisplay(DISPLAY, 0, curCol);
  }
  else
  {
    bally.setDisplay(DISPLAY, 3, '1');
    bally.setDisplay(DISPLAY, 2, curRow - 10);
    bally.setDisplay(DISPLAY, 1, '~');
    bally.setDisplay(DISPLAY, 0, curCol);
  }
}

void setup()
{
  // put your setup code here, to run once:s
  
}

void loop()
{
  lightEmUp();
  displayRC();
  int button = bally.waitForTestCreditCoin(CR_ROW, CR_COL, COIN_ROW, COIN_COL) ;
  if (button==CREDIT)
  {
    creditPressed();
  }
  else if (button==COIN)
  {
    coinPressed();
  }
  else if (button==TEST)
  {
    testPressed();
  }
}
