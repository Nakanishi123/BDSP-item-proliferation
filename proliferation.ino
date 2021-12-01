#include <SwitchControlLibrary.h>

#define CLICK_DELAY 50
#define SHORT_DELAY 250
#define SEMI_SHORT_DELAY 300
#define MIDDLE_DELAY 400
#define LONG_DELAY 1000
#define LOOP_TIMES 300

void setup()
{
  // put your setup code here, to run once:
  SwitchControlLibrary(); // 初期化
}

void loop()
{
  //最初の認識のためのボタン
  for (int i = 0; i < 5; i++)
  {
    click_button(Button::L);
    delay(SHORT_DELAY);
  }
  delay(800);

  for (int times = 0; times < LOOP_TIMES; times++)
  {
    //メニューバグ
    click_button(Button::X);
    delay(LONG_DELAY);
    click_button(Button::A);
    delay(LONG_DELAY);
    click_button(Button::A);
    delay(LONG_DELAY);
    click_button(Button::A);
    delay(LONG_DELAY);
    click_button(Button::ZL);
    click_button(Button::ZR);
    click_button(Button::A);
    delay(LONG_DELAY);

    //ボックスに行く
    for (int i = 0; i < 6; i++)
    {
      click_button(Button::B);
      delay(LONG_DELAY);
    }
    click_button(Button::R);
    delay(2000);

    // X→B→X→B→X→A + ボックスに入る
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
    for (int i = 0; i < 5; i++)
    {
      for (int i = 0; i < 6; i++)
      {
        mochimono();
        click_hatbutton(HatButton::RIGHT);
        delay(SHORT_DELAY);
      }
      delay(MIDDLE_DELAY);
      click_hatbutton(HatButton::RIGHT);
      delay(MIDDLE_DELAY);
      click_hatbutton(HatButton::DOWN);
      delay(MIDDLE_DELAY);
    }

    //後処理
    delay(LONG_DELAY);
    for (int i = 0; i < 3; i++)
    {
      click_button(Button::B);
      delay(LONG_DELAY);
    }
    click_button(Button::A);
    delay(MIDDLE_DELAY);
    click_hatbutton(HatButton::DOWN);
    delay(SHORT_DELAY);
    click_button(Button::A);
    delay(LONG_DELAY);
    for (int i = 0; i < 100; i++)
    {
      click_button(Button::B);
      delay(CLICK_DELAY);
    }
  }
}

void click_button(uint16_t button)
{
  SwitchControlLibrary().pressButton(button); // Aボタンを押す
  SwitchControlLibrary().sendReport();        // Aボタンを押したことを反映
  delay(CLICK_DELAY);
  SwitchControlLibrary().releaseButton(button); // Aボタンを離す
  SwitchControlLibrary().sendReport();          // Aボタンを離したことを反映
}

void click_hatbutton(uint8_t button)
{
  SwitchControlLibrary().pressHatButton(button);
  SwitchControlLibrary().sendReport();
  delay(CLICK_DELAY);
  SwitchControlLibrary().releaseHatButton(button);
  SwitchControlLibrary().sendReport();
}

void mochimono()
{
  click_button(Button::A);
  delay(550);
  click_hatbutton(HatButton::DOWN);
  delay(SHORT_DELAY);
  click_hatbutton(HatButton::DOWN);
  delay(SHORT_DELAY);
  click_button(Button::A);
  delay(MIDDLE_DELAY);
  click_button(Button::A);
  delay(MIDDLE_DELAY);
  click_button(Button::A);
  delay(SHORT_DELAY);
}
