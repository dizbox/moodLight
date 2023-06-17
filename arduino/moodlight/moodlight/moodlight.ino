#include <Adafruit_NeoPixel.h>

#define DEBUG 1

#define LED_PIN 6
#define LED_COUNT 8
Adafruit_NeoPixel pixels(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

const int knock = A0;
int sensorVal = 0;
int color[] = {255,0,0 ,0,255,0 ,0,0,255 ,255,0,255 ,255,255,0 ,0,255,255 , 255,255,255};

void setup() {
  Serial.begin(9600);
  setupNeopixel();
}

void loop() {
  while ((sensorVal = analogRead(knock)) < 10) {
  }
  Serial.println(sensorVal); 
  knockSound();
  changeColor();
  delay(500);
  // rainbow(10);             // Flowing rainbow cycle along the whole strip
}

void changeColor() {

  int randomColor = random(7)+1;

  if (DEBUG) Serial.println("changeColor : " + String(randomColor));

  for (int i = 0; i < LED_COUNT; i++) {
    pixels.setPixelColor(i, pixels.Color(color[(randomColor*3)-3], color[(randomColor*3)-2], color[(randomColor*3)-1]));
    pixels.show();
    delay(10);
  }
}

void knockSound() {
  if (DEBUG) Serial.println("knockSound");
  tone(knock,1000,80);
  delay(80);
  noTone(knock); 
  pinMode(knock, INPUT);
}



/*
  NeoPixel 
*/



void setupNeopixel() {
  pixels.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.show();            // Turn OFF all pixels ASAP
  pixels.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
}

// Rainbow cycle along whole strip. Pass delay time (in ms) between frames.
void rainbow(int wait) {
  // Hue of first pixel runs 5 complete loops through the color wheel.
  // Color wheel has a range of 65536 but it's OK if we roll over, so
  // just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
  // means we'll make 5*65536/256 = 1280 passes through this loop:
  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
    // strip.rainbow() can take a single argument (first pixel hue) or
    // optionally a few extras: number of rainbow repetitions (default 1),
    // saturation and value (brightness) (both 0-255, similar to the
    // ColorHSV() function, default 255), and a true/false flag for whether
    // to apply gamma correction to provide 'truer' colors (default true).
    pixels.rainbow(firstPixelHue);
    // Above line is equivalent to:
    // strip.rainbow(firstPixelHue, 1, 255, 255, true);
    pixels.show(); // Update strip with new contents
    delay(wait);  // Pause for a moment
  }

}