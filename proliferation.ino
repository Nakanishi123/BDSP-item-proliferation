#include <SwitchControlLibrary.h>

#define CLICK_DELAY 50
#define LOOP_TIMES 300

void setup() {
  // put your setup code here, to run once:
  SwitchControlLibrary(); // 初期化
}

void loop() {
  //最初の認識のためのボタン
  for (int i = 0; i < 5; i++) {
    click_button(Button::L);
    delay(100);
  }
  delay(800);
  
  for (int times = 0; times < LOOP_TIMES; times++) {
    //メニューバグ
    click_button(Button::X);
    delay(1000);
    click_button(Button::A);
    delay(1000);
    click_button(Button::A);
    delay(400);
    click_button(Button::A);
    delay(1000);
    click_button(Button::ZL);
    click_button(Button::ZR);
    click_button(Button::A);
    delay(1000);

    //ボックスに行く
    for (int i = 0; i < 6; i++) {
      click_button(Button::B);
      delay(1000);
    }
    click_button(Button::R);
    delay(2000);

    //X→B→X→B→X→A + ボックスに入る
    click_button(Button::X);
    delay(800);
    click_button(Button::B);
    delay(800);
    click_button(Button::X);
    delay(800);
    click_button(Button::B);
    delay(800);
    click_button(Button::X);
    delay(800);
    click_button(Button::A);
    delay(1800);
    click_button(Button::R);
    delay(2000);

    //持ち物回収
    for (int i = 0; i < 5; i++) {
      for (int i = 0; i < 6; i++) {
        mochimono();
        click_hatbutton(HatButton::RIGHT);
        delay(90);
      }
      delay(130);
      click_hatbutton(HatButton::RIGHT);
      delay(200);
      click_hatbutton(HatButton::DOWN);
      delay(90);
    }

    //後処理
    delay(1000);
    for (int i = 0; i < 3; i++) {
      click_button(Button::B);
      delay(1000);
    }
    click_button(Button::A);
    delay(400);
    click_hatbutton(HatButton::DOWN);
    delay(90);
    click_button(Button::A);
    delay(1000);
    for (int i = 0; i < 100; i++) {
      click_button(Button::B);
      delay(50);
    }
  }
}

void click_button(uint16_t button) {
  SwitchControlLibrary().pressButton(button); // Aボタンを押す
  SwitchControlLibrary().sendReport(); // Aボタンを押したことを反映
  delay(CLICK_DELAY);
  SwitchControlLibrary().releaseButton(button); // Aボタンを離す
  SwitchControlLibrary().sendReport(); // Aボタンを離したことを反映
}

void click_hatbutton(uint8_t button) {
  SwitchControlLibrary().pressHatButton(button);
  SwitchControlLibrary().sendReport();
  delay(CLICK_DELAY);
  SwitchControlLibrary().releaseHatButton(button);
  SwitchControlLibrary().sendReport();
}

void mochimono() {
  click_button(Button::A);
  delay(400);
  click_hatbutton(HatButton::DOWN);
  delay(90);
  click_hatbutton(HatButton::DOWN);
  delay(90);
  click_button(Button::A);
  delay(300);
  click_button(Button::A);
  delay(400);
  click_button(Button::A);
  delay(100);
}
