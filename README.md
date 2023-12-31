# moodLight
Audio Equalizer with Neopixel on Arduino 


# 부품 스펙
## 피에죠
* 3.3V
## LM393
* 3.3V~5V
## Neopixel
* 5V
## OLED
* 3.3V

# 회로구성
* A0 - 피에조
* A1 - 소리감지
* A4 - OLED SDA
* A5 - OLED SCL
* D6(output) - neopixel input

# 이슈 해결
* Adafruit_NeoPixel, Adafruit_SSD1306 충둘
    * https://community.platformio.org/t/adafruit-library-conflicts-ssd1306-and-neopixel/15598

# 참고문서
* 코코아팸
    * [슈퍼문 무드등](https://kocoafab.cc/make/view/686)
    * [피에조부저노크](https://kocoafab.cc/tutorial/view/461)
* [spectrum analyzer](https://akuzechie.blogspot.com/2020/12/arduino-based-spectrum-analyzer.html)
* [FFT library](https://www.arduino.cc/reference/en/libraries/fix_fft/)
* [LM393](https://increase-life.tistory.com/35)
* [0.96인치OLED](https://blog.naver.com/PostView.naver?blogId=emperonics&logNo=222081054316&categoryNo=0&parentCategoryNo=0)
* [WS2812 Datasheet](https://vctec.co.kr/web/product/adafruit/pdf/WS2812.pdf)
* [아두이노 네오픽셀](https://blog.naver.com/roboholic84/222358916122)
* [fastled](https://github.com/FastLED/FastLED)