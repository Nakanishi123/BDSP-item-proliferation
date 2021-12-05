#include <SwitchControlLibrary.h>

#define CLICK_DELAY 60
#define SHORT_DELAY 350
#define MIDDLE_DELAY 500
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
    delay(2500);

    // X→B→X→B→X→A + ボックスに入る
    click_button(Button::X);
    delay(LONG_DELAY);
    click_button(Button::B);
    delay(LONG_DELAY);
    click_button(Button::X);
    delay(LONG_DELAY);
    click_button(Button::B);
    delay(LONG_DELAY);
    click_button(Button::X);
    delay(LONG_DELAY);
    click_button(Button::A);
    delay(2500);
    click_button(Button::R);
    delay(2500);

    //持ち物回収
    click_button(Button::X);
    delay(SHORT_DELAY);

    for (int j = 0; j < 5; j++)
    {
      for (int i = 0; i < 5; i++)
      {
        mochimono_x();
        if (j % 2 == 0)
        {
          click_hatbutton(HatButton::RIGHT);
        }
        else
        {
          click_hatbutton(HatButton::LEFT);
        }
        delay(SHORT_DELAY);
      }
      mochimono_x();
      delay(SHORT_DELAY);
      click_hatbutton(HatButton::DOWN);
      delay(SHORT_DELAY);
    }
    click_button(Button::X);
    delay(SHORT_DELAY);
    click_button(Button::X);
    delay(SHORT_DELAY);

    //後処理
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
  delay(800);
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

void mochimono_x()
{
  click_button(Button::A);
  delay(800);
  click_hatbutton(HatButton::DOWN);
  delay(SHORT_DELAY);
  click_button(Button::A);
  delay(MIDDLE_DELAY);
  click_button(Button::A);
  delay(MIDDLE_DELAY);
  click_button(Button::A);
  delay(SHORT_DELAY);
}
