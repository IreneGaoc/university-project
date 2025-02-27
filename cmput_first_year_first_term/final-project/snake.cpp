/**
  section:CMPUT 274 A2
  Project Title: Snake Game Arduino
  Team members: Irene(Zihan) Gao and Gaoping Zhou
  referencce:https:Arduino library--
  (//www.arduino.cc/en/Tutorial/JoystickMouseControl)
  (https://www.arduino.cc/en/Reference/TFTLibrary)
  lecture notes
*/


#include "snake.h"



//===================set up joystick button==================================================================
void selection_init() {
  // setup the botton at joystick
  pinMode(SEL, INPUT);
  digitalWrite(SEL, HIGH);
  pinMode(VERT, INPUT);
  pinMode(HORIZ, INPUT);
}
//==================set up LEDs==============================================================================
void led_init() {
  pinMode(LED_1, INPUT     );
  pinMode(LED_2, INPUT     );
  pinMode(LED_3, INPUT     );
}
//=================set up pushbuttons=========================================================================
void push_button_init() {
  // initialize the pushbutton pin as an input:
  pinMode(PUSH, INPUT);
  digitalWrite(PUSH, HIGH);
}

//==================start the game display====================================================================
void start_game_page() {
  tft.fillScreen(ST7735_BLACK);//make the background black

  tft.setTextSize(3);
  tft.setTextColor(ST7735_WHITE);
  tft.setCursor(20, 10);
  tft.print("Snake");

  tft.setTextSize(1);
  tft.setCursor(50, 25);
  tft.println("");
  tft.println("   Created by ");
  tft.println("Irene Gao");
  tft.println("and");
  tft.println("Gaoping Zhou.");

  tft.setTextColor(ST7735_YELLOW);
  tft.setCursor(100, 100);
  tft.println(" ");
  tft.println(" Press joystick to start.");
}
//================== game display size====================================================================
void game_display() {
 // tft.fillScreen(ST7735_BLACK);//make the background black
  tft.drawFastHLine(borderX1,borderY1,borderX2-borderX1,ST7735_RED);
  tft.drawFastHLine(borderX1,borderY2,borderX2-borderX1,ST7735_RED);
  tft.drawFastVLine(borderX1,borderY1,borderY2-borderY1,ST7735_RED);
  tft.drawFastVLine(borderX2,borderY1,borderY2-borderY1,ST7735_RED);
}
//================game over page================================================================================
void game_over_page() {
  tft.fillScreen(ST7735_BLACK);//make the background black

  tft.setTextSize(3);
  tft.setTextColor(ST7735_WHITE);
  tft.setCursor(20, 10);
  tft.print("Game  ");
  tft.print(" Over");

  tft.setTextSize(1);
  tft.setTextColor(ST7735_YELLOW);
  tft.setCursor(10, 60);
  tft.print("your score is: ");
  tft.println(score);

  tft.setTextSize(1);
  tft.setTextColor(ST7735_YELLOW);
  tft.setCursor(10, 90);
  tft.print("Thank you  ");

  tft.setTextSize(1);
  tft.setTextColor(ST7735_WHITE);
  tft.setCursor(10, 140);
  tft.print("press the pushbutton to goodbye ");
}
//================game over page================================================================================
void game_over_page1() {
  tft.fillScreen(ST7735_BLACK);//make the background black

  tft.setTextSize(3);
  tft.setTextColor(ST7735_WHITE);
  tft.setCursor(20, 10);
  tft.print("Game  ");
  tft.print(" Over");

  tft.setTextSize(1);
  tft.setTextColor(ST7735_YELLOW);
  tft.setCursor(10, 60);
  tft.print("your score is: ");
  tft.println(score);

  tft.setTextSize(1);
  tft.setTextColor(ST7735_YELLOW);
  tft.setCursor(10, 90);
  tft.print("you touched the wall! ");

  tft.setTextSize(1);
  tft.setTextColor(ST7735_WHITE);
  tft.setCursor(10, 140);
  tft.print("press the restartbutton to restart ");
}


void game_over_page2() {
  tft.fillScreen(ST7735_BLACK);//make the background black

  tft.setTextSize(3);
  tft.setTextColor(ST7735_WHITE);
  tft.setCursor(20, 10);
  tft.print("Game  ");
  tft.print(" Over");

  tft.setTextSize(1);
  tft.setTextColor(ST7735_YELLOW);
  tft.setCursor(10, 60);
  tft.print("your score is: ");
  tft.println(score);
  tft.setTextSize(1);
  tft.setTextColor(ST7735_YELLOW);
  tft.setCursor(10, 90);
  tft.print("you ate your tail!  ");

  tft.setTextSize(1);
  tft.setTextColor(ST7735_WHITE);
  tft.setCursor(10, 140);
  tft.print("press the restartbutton to restart ");
}
void game_over_page3() {
  tft.fillScreen(ST7735_BLACK);//make the background black

  tft.setTextSize(3);
  tft.setTextColor(ST7735_WHITE);
  tft.setCursor(20, 10);
  tft.print("Game  ");
  tft.print(" Over");

  tft.setTextSize(1);
  tft.setTextColor(ST7735_YELLOW);
  tft.setCursor(10, 60);
  tft.print("your score is: ");
  tft.println(score);
  tft.setTextSize(1);
  tft.setTextColor(ST7735_YELLOW);
  tft.setCursor(10, 90);
  tft.print("you touched the block!  ");

  tft.setTextSize(1);
  tft.setTextColor(ST7735_WHITE);
  tft.setCursor(10, 140);
  tft.print("press the restartbutton to restart ");
}
//================game over============================================================================
void game_over() {

  push_button_init();
  //score = 0;

  game_over_page();
  delay(800);
  pinMode(PUSH, INPUT); //new

    while (true) {
     //game_over_page();
     //delay(200);
     Serial.print("game_over_page");
     while (true) {
       if (digitalRead(PUSH) == 0) { // if the restart button is pressed, go to restart the game
        // playthegame();
         Serial.print("game over");
       }
     }
     //game_over_page();
     Serial.print("there is another loop");
    }
}
//================game over============================================================================
void game_over1() {// for snake touch the wall

  push_button_init();
  //score = 0;

  game_over_page1();
  delay(800);
  pinMode(PUSH, INPUT);

}

void game_over2() {// for snake eats its tail

  push_button_init();
  //score = 0;

  game_over_page2();
  delay(800);
  pinMode(PUSH, INPUT);

}

void game_over3() {// for snake touch the block

  push_button_init();
  //score = 0;

  game_over_page3();
  delay(800);
  pinMode(PUSH, INPUT);

}

//======== initialize the snake and food position =================================================
void init_snake_food() {

  // // initialize the snake position
  snake_x[0] = 20;            // snake head init x
  snake_y[0] = 20;            // snake head init y
  snakelength = initial_snakelength;
  for ( int i = 1; i < snakelength ; i++)     //snake body x,y
  {
    snake_x[i] = snake_x[i - 1] + 1;// suppose the sanke is in horizontal at the beginning
    snake_y[i] = snake_y[i - 1];
  }
  snake_dir = LEFT ; //initialize LEFT
  // initialize the score
  //score = 0;
  //get orginal joystick x and y
  init_vertical = analogRead(VERT);
  init_horizontal = analogRead(HORIZ);
  for ( int i = 0 ; i < foodNum ; i++)
  {
    food_x[i] = 0;
    food_y[i] = 0;
  }
  for ( int i = 0 ; i < blockNum ; i++)
  {
    block_x[i] = -100;
    block_y[i] = -100;
  }

}

//===============update food================================================================================
void update_food(int num) {

  int j = 0 ;
  int flag = 1 ; // the flag of the success/ fail 0==success; 1==fail

  while (j < num )                  //food posistion not in snake position
    {
    foodX = random(10, screen_width-10);
    foodY = random(10, screen_height-10);
    for (int i = 0; i < snakelength; i++)      //the random food cannot coninside the snake
    {
      if ((foodX == snake_x[i]) && (foodY == snake_y[i]))
      {
        break;
      }

      flag = 0;
    }
    for (int i = 0; i < num; i++)      //the random food cannot coninside the previous food
    {
      if ((foodX == food_x[i]) && (foodY == food_y[i]))
      {
        break;
      }
      if ( flag == 0 ) { //  the food is correct
        food_x[j] = foodX;
        food_y[j] = foodY;
        j++ ;
        flag = 1;
      }


    }

    }
    Serial.println("FOODX");
    Serial.println(foodX);
    Serial.println("FOODY");
    Serial.println(foodY);
    for (int i = 0 ; i < num ; i++)
    {
    tft.fillRect(food_x[i], food_y[i], food_size, food_size, ST7735_YELLOW);
    }
}
//===============update block================================================================================
void update_block(int num) {
  int flag = 1  ;
  int flag1 = 1  ;
  int j = 0 ;

  for ( int i = 0 ; i < num ; i++)
  {
    block_x[i] = -100;
    block_y[i] = -100;
  }

  while (j < num )                  //food posistion not in snake position
  {
    blockX = random(30, screen_width - 20);
    blockY = random(30, screen_height - 20);

    // judge whether the snake touch the BLOCKX
    for (int i = 0 ; i < snakelength; i++)
    {
      if ( (blockY + block_width >= snake_y[i]) && (blockY <= snake_y[i] + snake_body_width) ) //if the coordinate of food and snake is equal
      {
        if ((blockX + block_length >= snake_x[i]) && (blockX  <= snake_x[i] + snake_body_width)  )
        {
          break ;
        }
      }
      if ( (blockX + block_length >= snake_x[i]) && (blockX <= snake_x[i] + snake_body_width) ) //if the coordinate of food and snake is equal
      {
        if ((blockY + block_width >= snake_y[i]) && (blockY  <= snake_y[i] + snake_body_width)  )
        {
          break ;
        }
      }
      flag  = 0 ;
    }
    for (int i = 0 ; i < foodNum ; i++)
    {
      if ( (blockY + block_width >= food_y[i]) && (blockY <= food_y[i] + food_size) ) //if the coordinate of food and snake is equal
      {
        if ((blockX + block_length >= food_x[i]) && (blockX  <= food_x[i] + food_size)  )
        {
          break ;
        }
      }
      if ( (blockX + block_length >= food_x[i]) && (blockX <= food_x[i] + food_size) ) //if the coordinate of food and snake is equal
      {
        if ((blockY + block_width >= food_y[i]) && (blockY  <= food_y[i] + food_size)  )
        {
          break ;
        }
      }
      flag1  = 0 ;
    }
    for (int i = 0; i < num; i++)      //the random food cannot coninside the previous food
    {

      if ( flag == 0 && flag1 ==0) { // if the new block position is not hte same as the food and the snake
        block_x[j] = blockX;// save to the block array
        block_y[j] = blockY;
        j++ ;
        flag = 1;
        flag1 = 1;
      }


    }

  }
  Serial.println("BLOCKX");
  Serial.println(foodX);
  Serial.println("BLOCKY");
  Serial.println(foodY);
  for (int i = 0 ; i < num ; i++)
  {
    if(block_y[i]+block_length>borderY2)
      tft.fillRect(block_x[i], block_y[i], block_width, borderY2-block_y[i], ST7735_WHITE);
    else
      tft.fillRect(block_x[i], block_y[i], block_width, block_length, ST7735_WHITE);

  }
}
//===============update snake==============================================================
void update_snake() {
  for (int i = 0; i < snakelength; i++)  //display snake
  {
    if (i == 0)
    {
      tft.fillRect(snake_x[i], snake_y[i], snake_body_width, snake_body_width, ST7735_RED); //snake head

    }
    else
    {
      tft.drawRect(snake_x[i], snake_y[i], snake_body_width, snake_body_width, ST7735_GREEN); //snake body
    }
  }

  Serial.print("snake_x value is: ");
  Serial.println(snake_x[0]);
  Serial.print("snake_y value is: ");
  Serial.println(snake_y[0]);
  Serial.print("snakelength value is: ");
  Serial.println(snakelength);


}
//===============snake move direct=====================================================
int snake_direct(int initX, int currentX, int initY , int currentY) {
  int DIRECT ;
  // if the current x position smaller than the last position - 10(to make the joystick easy to control)
  // the movement position is left
  if ( initX < currentX - 10 ) {
    DIRECT = LEFT ;
    return DIRECT ;
  }
  // if the current x position greater than the last position +10
  // the movement position is right
  if ( initX  > currentX + 10 ) {
    DIRECT = RIGHT ;
    return DIRECT ;
  }
  // if the current y position greater than the last position +10
  // the movement position is down
  if (initY > currentY + 10 ) {
    DIRECT = DOWN  ;
    return DIRECT ;
  }
  //// if the current y position smaller than the last position +10
  // the movement position is up
  if (initY < currentY - 10 ) {
    DIRECT = UP  ;
    return DIRECT ;
  }
  return 0 ;
}

//==============update snake's movement=====================================================================

int snake_move() { // judge the movement of the sanke. whether it eats the food, touch the
                  // wall, touvh the block or eat itself
  snake_body_width;
  select;
  snake_x, snake_y;

  vertical, horizontal;

  delta_vert, delta_horiz;

  vertical = analogRead(VERT); //read the joystick on y axis
  horizontal = analogRead(HORIZ); // read the joystick on x axis
  push_button_init();
  pinMode(PUSH, INPUT); //
  if (digitalRead(PUSH) == 0) //restart
    return 5 ;

  // judge the position of snakes head
  int direct = snake_direct(init_horizontal, horizontal, init_vertical, vertical);
  //if the movement position and the snake's head's position is
  // corresponding to the moement statement
  if (direct == 0 ) {
    direct = snake_dir ;         //keep it direct
  }
  // init_horizontal = horizontal;
  //init_vertical = vertical ;
  switch (direct)
  {
    case UP:                    //if the current position is up
      //and the snake's position is down, the snake can move forward to up
      if (snake_dir != DOWN)
      {
        snake_dir = UP;
        // init_vertical-= 10 ;
        break;
      }
    case DOWN:                  //if the current position is down
      //and the snake's position is up, the snake can move forward to down
      if (snake_dir != UP)
      {
        snake_dir = DOWN;
        //init_vertical += 10;
        break;
      }
    case LEFT:              //if the current position is left
      //and the snake's position is right, the snake can move forward to left
      if (snake_dir != RIGHT)
      {
        snake_dir = LEFT;
        //init_horizontal -= 10;
        break;
      }
    case RIGHT:            //if the current position is right
      //and the snake's position is left, the snake can move forward to right
      if (snake_dir != LEFT)
      {
        snake_dir = RIGHT;
        //init_horizontal += 10;
        break;
      }
    default: break; // movement position and the snake's
      //head's position is not corresponding to the moement statement
  }
  Serial.println("MOVE");
  //judge if the the snake eats the food
  if (eat_food(snake_dir) == 1) {
    score++;
    update_food(1 );

  }
  else {
    if (touch_the_block(snake_dir) == 1) //if the snake touch the block
         return 3 ;

    if (touch_the_wall(snake_dir) == 1) //if the snake touch the wall
        return 1 ;
    if (eat_tail(snake_dir) == 1 )      // if the snake eats its tail
         return 2 ;
    move_position(snake_dir);         // update the new position
  }

  update_snake(); // redraw the snake
  // }
  return 0 ;
}
//========================snake move position ==========================================
void move_position(int DIR) {// according to the sanke's movement, get the new position after each times the snake moves
  int temp_x[snakelength + 2];
  int temp_y[snakelength + 2];
  for (int i = 0; i < snakelength - 1; i++)
  {
    temp_x[i] = snake_x[i];  //save the old position of snake to the temporary array,and if the snake
    temp_y[i] = snake_y[i]; // change its position ,re-calculate the value of the position
  }
  switch (DIR)
  { // the movement:
    case RIGHT: {
        snake_x[0] += 1; // x coordinate get larger
        break;
      }
    case LEFT: {
        snake_x[0] -= 1; // x coordinate get smaller
        break;
      }
    case UP: {
        snake_y[0] -= 1; // y coordinate get smaller
        break;
      }
    case DOWN: {
        snake_y[0] += 1; // y coordinate get larger
        break;
      }
  }
  //black the snake's last position
  tft.fillRect(snake_x[snakelength - 1], snake_y[snakelength - 1], snake_body_width, snake_body_width+6, ST7735_BLACK); //snake body
    //update_food(1);
    game_display();
  for (int i = 1; i < snakelength; i++)
  {
    snake_x[i] = temp_x[i - 1];
    snake_y[i] = temp_y[i - 1];
  }

}
//============================ eat food position is changed======================

void eat_position() {
  int temp_x[snakelength + 2];
  int temp_y[snakelength + 2];
  for (int i = 0; i < snakelength - 1; i++)  // save the old position of snake to the tempporary array
  {
    temp_x[i] = snake_x[i];
    temp_y[i] = snake_y[i];
  }
  snake_x[0] = foodX;                //the position of food x willbe given to the
  snake_y[0] = foodY;               // new snake head's position
  for (int i = 1; i < snakelength; i++)
  { //give the new snale'sbody position
    snake_x[i] = temp_x[i - 1];
    snake_y[i] = temp_y[i - 1];
  }
}


//===============snake eat the food=============================================================================

int eat_food( int dir ) {

  int x_temp = snake_x[0];              //get snake head x
  int y_temp = snake_y[0];              //get snake head y
  switch (dir)
  {
    case UP : y_temp -= 1; break;
    case DOWN : y_temp += 1; break;
    case LEFT : x_temp -= 1; break;
    case RIGHT : x_temp += 1; break;
  }
   for (int i = 0 ; i < foodNum; i++)
  {
    if ( y_temp+snake_body_width >= food_y[i] && (y_temp <= (food_y[i]+food_size))) //if the coordinate of food and snake is equal
    {
      if ((x_temp  >= food_x[i]) && (x_temp <= (food_x[i] + food_size) ))
      {

        return 1;
      }
    }

    if (x_temp+snake_body_width >= food_x[i] && (x_temp <=(food_x[i]+food_size))) //if the coordinate of food and snake is equal
    {
      if ( (y_temp >= food_y[i]) && (y_temp  <= (food_y[i] + food_size) ) )
      {

        return 1;
      }
    }

  }

  return 0 ;



}

//===============snake eats its tail===================================================
int  eat_tail(int dir) {
  int x_temp = snake_x[0];                       //get snake head x
  int y_temp = snake_y[0];                       //get snake head y
  Serial.print("DIR");
  Serial.println(dir);
  switch (dir)
  {
    case UP : y_temp -= 1; break;
    case DOWN : y_temp += 1; break;
    case LEFT : x_temp -= 1; break;
    case RIGHT : x_temp += 1; break;
  }
  for (int i = 1; i < snakelength; i++)
  {

    if ((x_temp == snake_x[i]) && (y_temp == snake_y[i]))
    {
      Serial.print("sankex"); Serial.print(x_temp);
      Serial.print("sankey"); Serial.print(y_temp);
      Serial.print("sanki"); Serial.print(i);
      Serial.print("X"); Serial.println(snake_x[i]);
      Serial.print("Y"); Serial.println(snake_y[i]);
      return 1;
    }
  }
  return 0 ;
}

//==============snake touch the wall==============================================================================
int  touch_the_wall(int dir) {
  int x_temp = snake_x[0];
  int y_temp = snake_y[0];
  switch (dir)
  {
    case UP : y_temp -= 1; break;
    case DOWN : y_temp += 1; break;
    case LEFT : x_temp -= 1; break;
    case RIGHT : x_temp += 1; break;
  }
  if (x_temp <= borderX1 || x_temp >= borderX2-1)
  {
    Serial.println("DEAD1");
    //game_over1();
    return 1;
  }
  if (y_temp <= borderY1 || y_temp >= borderY2-1)
  {
    //Serial.println("DEAD2");
    //game_over1();
    return 1;
  }
  return 0 ;
}
//==============snake touch the block==============================================================================
int  touch_the_block(int dir) {
  int x_temp = snake_x[0];
  int y_temp = snake_y[0];
  switch (dir)
  {
    case UP : y_temp -= 1; break;
    case DOWN : y_temp += 1; break;
    case LEFT : x_temp -= 1; break;
    case RIGHT : x_temp += 1; break;
  }
  for (int i = 0 ; i < blockNum; i++)
  {
    if ( y_temp  >= block_y[i] && (y_temp <= (block_y[i]+block_length))) //if the coordinate of food and snake is equal
    {
      if ((x_temp  >= block_x[i]) && (x_temp <= (block_x[i] + block_width)) )
      {

        return 1;
      }
    }

    if (x_temp+snake_body_width >= block_x[i] && (x_temp <=(block_x[i]+block_width))) //if the coordinate of food and snake is equal
    {
      if ( (y_temp >= block_y[i]) && (y_temp  <= (block_y[i] + block_length) ) )
      {

        return 1;
      }
    }
  }
  return 0 ;
}
//===============mode1==========================================================================================mode0涓绘帶=====================
int mode1() {
  pinMode(LED_1, OUTPUT);
  digitalWrite(LED_1, HIGH);
  delay(2);
  pinMode(LED_2, OUTPUT);
  digitalWrite(LED_2, LOW);
  pinMode(LED_3, OUTPUT);
  digitalWrite(LED_3, LOW);
  mode = 1 ;
  int rtId = 0;         //return value
  update_food(1);       //the number of food is only one
  update_snake();
  update_block(mode) ;
  while (score <=2  ) {
    delay(80);            // speed
    rtId = snake_move();
    if ( rtId != 0  )
      return rtId ;



  }
}
//==============mode2============================================================================================

int mode2() {
  pinMode(LED_1, OUTPUT);
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, OUTPUT);
  digitalWrite(LED_2, HIGH);
  delay(2);
  pinMode(LED_3, OUTPUT);
  digitalWrite(LED_3, LOW);
  int rtId = 0 ;          //return value
  mode = 2 ;
  update_food(1);
   update_block(mode) ;
  //update_snake();
  while (score > 2  && score <= 4) {
    delay(20);            //speed
    rtId = snake_move();
    if ( rtId != 0 )
      return rtId ;
  }

}
//===============mode3==========================================================================================
int mode3() {
  pinMode(LED_1, OUTPUT);
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, OUTPUT);
  digitalWrite(LED_2, LOW);
  pinMode(LED_3, OUTPUT);
  digitalWrite(LED_3, HIGH);
  delay(2);
  int rtId = 0;           //return value
  mode = 3 ;
  update_food( 1 );
  update_block(mode) ;
  // update_snake();
  while (score > 4) {

    delay(game_speed1 / mode);   //when score is high ,speed is very rapid
    rtId = snake_move();
    if ( rtId != 0 )
      return rtId ;




  }
}

//===============playthegame===========================================================

int playthegame() {
  //init();
  //show the main background of the game site
  tft.fillScreen(ST7735_BLACK);
  game_display();
  init_snake_food();
  // fisrt mode
  score = 0;
  int id = 0 ;
  //update_snake();
  if (score <= 2 ) {
  tft.setTextSize(1);
  tft.setTextColor(ST7735_WHITE);
  tft.setCursor(60, 150);
  tft.print("MODE:1");
    id = mode1();

  }
  tft.fillScreen(ST7735_BLACK);
  game_display();
  init_snake_food();
  if (score > 2 && score <= 4) {
  tft.setTextSize(1);
  tft.setTextColor(ST7735_WHITE);
  tft.setCursor(60, 150);
  tft.print("MODE:2");
    id = mode2();
  }

  tft.fillScreen(ST7735_BLACK);
  game_display();
  init_snake_food();
  if ( score > 4)  {
    tft.setTextSize(1);
  tft.setTextColor(ST7735_WHITE);
  tft.setCursor(60, 150);
  tft.print("MODE:3");
    id = mode3();
  }
  return id ;
}
//===================mian function====================================================
int main() {

  init();
  // Attach USB for applicable processors
#ifdef USBCON
  USBDevice.attach();
#endif
  tft.initR(INITR_BLACKTAB);
  // customize initilization
  // serial start
  Serial.begin(9600);

  selection_init();
  led_init();
  //push_button_init();
  // initialize the food position
  //initialize the food and snake
  init_snake_food();


  score = 0;

  snakelength = initial_snakelength;
  int successId = 0 ;      //run return Id
  int flag = 1 ;
  while (true &&  flag ) {

    start_game_page();
    Serial.print("strat game is running ");
    // if the joystick button is pressed
    while (true) {
      //delay(100);
      if (digitalRead(SEL) == 0) {   // push the joystick to enter the game
        successId = playthegame();
       if ( successId == 0 && mode == 3 )//game is right over
      {
       flag = 0  ;
      }
      if (successId == 1)
      {
        init_snake_food();
          game_over1();
          push_button_init();
          pinMode(PUSH, INPUT);
        }
        if (successId == 2)
      {
        init_snake_food();
          game_over2();
          push_button_init();
          pinMode(PUSH, INPUT);
        }
        if (successId == 3)
      {
          init_snake_food();
          game_over3();
          push_button_init();
          pinMode(PUSH, INPUT);
        }

        if ( successId == 5)            //restart
        {
         start_game_page();
         init_snake_food();
        }

        Serial.print("game is playing");
      }

    }
    start_game_page();
    Serial.print("there is a loop");
  }
   game_over();
  // end the Project
  Serial.end();
  return 0;                 //end the game
}
