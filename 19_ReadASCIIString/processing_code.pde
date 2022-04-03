import processing.serial.*;

int containerX = 400;
int containerY = 250;
int containerW = 600;
int containerH = 300;

int redValue = 255;
int greenValue = 255;
int yellowValue = 255;
int purpleValue = 255;

int min = 20;
int max = 175;

int redScroll = 329;
int greenScroll = 329;
int yellowScroll = 329;
int purpleScroll = 329;

Serial port;

void setup() {

  size(800, 500);
  
  rectMode(CENTER);

  println(Serial.list());

  port = new Serial(this, Serial.list()[0], 9600);
}

void draw() {

  background(0);
  
  fill(#14213d);
  rect(containerX, containerY, containerW, containerH, 30);
 
  int scrollW = 50;
  int scrollH = containerH - 100;
  int scrollY = containerY;
  int redX = containerX - 150;
  int greenX = containerX - 50;
  int yellowX = containerX + 50;
  int purpleX = containerX + 150;
  
  fill(#ff006d);
  rect(redX, scrollY, scrollW, scrollH, 30);
  fill(#adff02);
  rect(greenX, scrollY, scrollW, scrollH, 30);
  fill(#ffdd00);
  rect(yellowX, scrollY, scrollW, scrollH, 30);
  fill(#8f00ff);
  rect(purpleX, scrollY, scrollW, scrollH, 30);
  
 
  
  int limitTop = scrollY - (scrollH/2);
  int limitBottom = scrollY + (scrollH/2);
  
  if(mouseX > redX - 25 && mouseX < redX + 25 
    && mouseY > limitTop && mouseY < limitBottom){
      
    if(mousePressed){
      int value = mouseY - limitTop;
      int mappedValue = round(map(value, min, max, 0, 255));
      redValue = mappedValue;
      
      if(mouseY > (limitTop + min) && mouseY < (limitBottom - min)){
        redScroll = mouseY;
      }
      
    }
    
  } else if(mouseX > greenX - 25 && mouseX < greenX + 25 
    && mouseY > limitTop && mouseY < limitBottom){
    
    if(mousePressed){
      int value = mouseY - limitTop;
      int mappedValue = round(map(value, min, max, 0, 255));
      greenValue = mappedValue;
      
      if(mouseY > (limitTop + min) && mouseY < (limitBottom - min)){
        greenScroll = mouseY;
      }
      
    }
    
  } else if(mouseX > yellowX - 25 && mouseX < yellowX + 25 
    && mouseY > limitTop && mouseY < limitBottom){
     
    if(mousePressed){
      int value = mouseY - limitTop;
      int mappedValue = round(map(value, min, max, 0, 255));
      yellowValue = mappedValue;
      
      if(mouseY > (limitTop + min) && mouseY < (limitBottom - min)){
        yellowScroll = mouseY;
      }
      
    }
    
  } else if(mouseX > purpleX - 25 && mouseX < purpleX + 25 
    && mouseY > limitTop && mouseY < limitBottom){
    
    if(mousePressed){
      int value = mouseY - limitTop;
      int mappedValue = round(map(value, min, max, 0, 255));
      purpleValue = mappedValue;
      
      if(mouseY > (limitTop + min) && mouseY < (limitBottom - min)){
        purpleScroll = mouseY;
      }
      
    }
    
  } else {
    stroke(0);
  }
  
        
  scrollButton(redX, redScroll);
  scrollButton(greenX, greenScroll);
  scrollButton(yellowX, yellowScroll);
  scrollButton(purpleX, purpleScroll);
  
  port.write("" + redValue + ',' + greenValue + ',' + yellowValue + ',' + purpleValue + "\n");
  
}


void scrollButton(int posX, int posY){
  fill(#edf2f4);
  rect(posX, posY, 30, 30, 30); 
}
